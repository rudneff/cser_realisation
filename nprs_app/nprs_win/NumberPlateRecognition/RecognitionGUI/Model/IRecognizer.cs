using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NprsCppApi;

namespace RecognitionGUI.Model
{
	public interface IRecognizer
	{
		void PerformRecognition(byte[] image, int width, int height, Action<RecognitionResults, Exception> callback);
	}
}
