using System;
using System.Threading.Tasks;
using NprsCppApi;

namespace RecognitionGUI.Model
{ 
	public class Recognizer : IRecognizer, IDisposable
	{
		private readonly NativeRecognizer _recognizer = new NativeRecognizer();

		public void PerformRecognition(byte[] image, int width, int height, Action<RecognitionResults, Exception> callback)
		 {
			Task.Factory.StartNew(
				() =>
				{
					var results = _recognizer.Recognize(image, width, height);
					callback(results, null);
				}
			);

		}

		public void Dispose()
		{
			_recognizer.Dispose();
		}
	}
}