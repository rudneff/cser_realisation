using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NprsCppApi;

namespace NumberPlateRecognition.Model
{
	public class Recognizer
	{
		private NativeRecognizer _nativeRecognizer = new NativeRecognizer();

		public void RecognizeAsync(byte[] image, Action<RecognitionResults, Exception> callback)
		{
			Task.Factory.StartNew(
				() => {
				try
				{
					RecognitionResults res = _nativeRecognizer.Recognize(image);
					callback(res, null);
				}
				catch (Exception ex)
				{
					callback(null, ex);
				}
			});
		}
	}
}
