using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;
using NprsCppApi;

namespace ConsoleTest
{
	class Program
	{
		static void Main(string[] args)
		{
			var bitmapImage = new WriteableBitmap(new BitmapImage(new Uri(@"file:\\C:\numplates\mul.jpg")));
			NativeRecognizer recognizer = new NativeRecognizer();

			Stopwatch sw = new Stopwatch();
			sw.Start();
			byte[] pixels = new byte[bitmapImage.PixelHeight * bitmapImage.PixelWidth * bitmapImage.Format.BitsPerPixel / 8];
			bitmapImage.CopyPixels(pixels, bitmapImage.PixelWidth * bitmapImage.Format.BitsPerPixel / 8, 0);
			RecognitionResults res = recognizer.Recognize(pixels, PixelFormat.BGRA32, bitmapImage.PixelWidth, bitmapImage.PixelHeight);
			sw.Stop();
			
			Console.WriteLine(sw.ElapsedMilliseconds);
			Console.ReadLine();
		}
	}
}
