using System;
using System.Windows;
using System.Windows.Media.Imaging;
using Microsoft.Win32;
using RecognitionGUI.ViewModel;

namespace RecognitionGUI
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		/// <summary>
		/// Initializes a new instance of the MainWindow class.
		/// </summary>
		public MainWindow()
		{
			InitializeComponent();
			Closing += (s, e) => ViewModelLocator.Cleanup();
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			OpenFileDialog dlg = new OpenFileDialog();
			dlg.FileOk += (s, es) => (DataContext as MainViewModel).Image = new WriteableBitmap(new BitmapImage(new Uri(dlg.FileName)));
			dlg.ShowDialog();
		}
	}
}