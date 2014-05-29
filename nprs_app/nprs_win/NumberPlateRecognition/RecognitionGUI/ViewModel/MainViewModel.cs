using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Threading;
using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using RecognitionGUI.Model;
using System.Windows.Media.Imaging;
using System.Windows;

namespace RecognitionGUI.ViewModel
{
	public class MainViewModel : ViewModelBase
	{
		private readonly IRecognizer _recognizer;

		private string _welcomeTitle = string.Empty;
		private WriteableBitmap _image;
		private ICommand _recognizeCommand;
		private Dispatcher _dispatcher = Dispatcher.CurrentDispatcher;

		#region Commands
		public ICommand RecognizeCommand
		{
			get
			{
				_recognizeCommand = new RelayCommand(() =>
				{
					if (_image == null)
						return;

					byte[] pixels = new byte[_image.PixelWidth * _image.PixelHeight * _image.Format.BitsPerPixel / 8];
					_image.CopyPixels(pixels, _image.PixelWidth * _image.Format.BitsPerPixel / 8, 0);

					_recognizer.PerformRecognition(
						pixels, _image.PixelWidth, _image.PixelHeight,
						(res, e) => _dispatcher.Invoke(() =>
						{
							foreach (var numPlate in res.NumberPlates)
							{
								_image.DrawRectangle((int)numPlate.Bounds.X, (int)numPlate.Bounds.Y, (int)(numPlate.Bounds.X + numPlate.Bounds.Width), (int)(numPlate.Bounds.Y + numPlate.Bounds.Height), Colors.Red);

								foreach (var c in numPlate.Characters)
								{
									_image.DrawRectangle((int)c.Bounds.X, (int)c.Bounds.Y, (int)(c.Bounds.X + c.Bounds.Width), (int)(c.Bounds.Y + c.Bounds.Height), Colors.Blue);
								}
							}
						}));
				});

				return _recognizeCommand;
			}
		}
		#endregion

		#region properties
		public string WelcomeTitle
		{
			get
			{
				return _welcomeTitle;
			}

			set
			{
				if (_welcomeTitle == value)
				{
					return;
				}

				_welcomeTitle = value;
				RaisePropertyChanged("WelcomeTitle");
			}
		}

		public WriteableBitmap Image
		{
			get
			{
				return _image;
			}

			set
			{
				_image = BitmapFactory.ConvertToPbgra32Format(value);
				RaisePropertyChanged("Image");
			}
		}
		#endregion

		#region constructors
		public MainViewModel(IRecognizer recognizer)
		{
			_recognizer = recognizer;
		}
		#endregion
	}
}