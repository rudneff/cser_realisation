package com.nprs.app.activities;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.RectF;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;

import com.nprs.app.R;
import com.nprs.app.recognition.Recognizer;
import com.nprs.app.recognition.common_structures.NumberPlate;
import com.nprs.app.recognition.common_structures.RecognitionResults;
import com.nprs.app.recognition.common_structures.Rectangle;
import com.nprs.app.recognition.jni.NativeRecognizer;

public class ResultsActivity extends Activity {
    private final Recognizer _recognizer = new NativeRecognizer();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_results);

        String extra = getIntent().getStringExtra("test");
        byte[] imageBytes = getIntent().getByteArrayExtra("image");

        if (imageBytes != null) {
            ImageView imageView = (ImageView) findViewById(R.id.frame_view);

            Bitmap inputBmp = Bitmap.createBitmap(BitmapFactory.decodeByteArray(imageBytes, 0, imageBytes.length)).copy(Bitmap.Config.ARGB_8888, true);
            Matrix rotate = new Matrix();
            rotate.postRotate(90);
            inputBmp = Bitmap.createBitmap(inputBmp, 0, 0, inputBmp.getWidth(), inputBmp.getHeight(), rotate, true);

            long before = System.currentTimeMillis();
            RecognitionResults results = _recognizer.recognize(inputBmp);
            long after = System.currentTimeMillis();
            Log.d("debug", String.format("recognition performed in %d ms", after - before));
            Log.d("debug", String.format("got %d results.", results.getNumberPlates().size()));

            Canvas canvas = new Canvas(inputBmp);
            drawResults(canvas, results);

            imageView.setImageBitmap(inputBmp);
        }
    }

    public void drawResults(Canvas canvas, RecognitionResults recognitionResults) {
        Paint paint = new Paint();
        paint.setColor(Color.argb(255, 255, 0, 0));
        paint.setStrokeWidth(1.0f);
        paint.setStyle(Paint.Style.STROKE);

        for (NumberPlate np : recognitionResults.getNumberPlates()) {
            Rectangle bounds = np.getBounds();
            canvas.drawRect(bounds.x(), bounds.y(), bounds.x() + bounds.width(), bounds.y() + bounds.height(), paint);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.results, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
