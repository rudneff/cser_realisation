package com.nprs.app;

import android.app.Activity;
import android.content.Intent;
import android.hardware.Camera;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;

import com.nprs.app.activities.ResultsActivity;
import com.nprs.app.controls.CameraPreview;
import com.nprs.app.controls.FrameView;


public class MainActivity extends Activity implements Camera.PictureCallback {
    private CameraPreview _cameraPreview;
    private FrameView _frameView;
    private Camera.PictureCallback _pictureCallback;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_number_plate_recognition);
        getApplicationContext();

        Button button = (Button) findViewById(R.id.btn_recognize);

        _cameraPreview = new CameraPreview(this);
        FrameLayout frameView = (FrameLayout) findViewById(R.id.frame_output);
        frameView.addView(_cameraPreview);

        CameraHolder.instance().getCamera();

        _pictureCallback = new Camera.PictureCallback() {
            @Override
            public void onPictureTaken(byte[] bytes, Camera camera) {
                Intent intent = new Intent(MainActivity.this, ResultsActivity.class);
                intent.putExtra("test", "hello from intent extra");

                byte[] bytesCopy = bytes.clone();
                intent.putExtra("image", bytesCopy);
                startActivity(intent);

                CameraHolder.instance().getCamera().startPreview();
                Log.d("debug", "start preview..");
            }
        };

        findViewById(R.id.btn_recognize).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.d("debug", "start autofocus");
                CameraHolder.instance().getCamera().autoFocus(new Camera.AutoFocusCallback() {
                    @Override
                    public void onAutoFocus(boolean b, Camera camera) {
                        Log.d("debug", "stop auto focus");
                        CameraHolder.instance().getCamera().takePicture(null, null, _pictureCallback);
                    }
                });
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.number_plate_recognition, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        return id == R.id.action_settings || super.onOptionsItemSelected(item);
    }

    @Override
    public void onPictureTaken(byte[] bytes, Camera camera) {

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        CameraHolder.instance().releaseCamera();
    }
}
