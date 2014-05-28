package com.nprs.app.controls;

import android.content.Context;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import com.nprs.app.CameraHolder;

import java.io.IOException;

public class CameraPreview extends SurfaceView implements SurfaceHolder.Callback {
    private SurfaceHolder _holder;

    public CameraPreview(Context context) {
        super(context);
        CameraHolder.instance().getCamera().setDisplayOrientation(90);

        // Install a SurfaceHolder.Callback so we get notified when the
        // underlying surface is created and destroyed.
        _holder = getHolder();
        _holder.addCallback(this);
    }

    public void surfaceCreated(SurfaceHolder holder) {
        // The Surface has been created, now tell the camera where to draw the preview.
        try {
            CameraHolder.instance().getCamera().setPreviewDisplay(holder);
            CameraHolder.instance().getCamera().startPreview();
        } catch (IOException e) {
            Log.d("debug", "Error setting camera preview: " + e.getMessage());
        }
    }

    public void surfaceDestroyed(SurfaceHolder holder) {
        // empty. Take care of releasing the Camera preview in your activity.
    }

    public void surfaceChanged(SurfaceHolder holder, int format, int w, int h) {
        // If your preview can change or rotate, take care of those events here.
        // Make sure to stop the preview before resizing or reformatting it.

        Log.d("debug", "surfaceChanged call");

        if (_holder.getSurface() == null) {
            // preview surface does not exist
            return;
        }

        // stop preview before making changes
        try {
            CameraHolder.instance().getCamera().stopPreview();
        } catch (Exception e){
            // ignore: tried to stop a non-existent preview
        }

        // set preview size and make any resize, rotate or
        // reformatting changes here

        // start preview with new settings
        try {
            CameraHolder.instance().getCamera().setPreviewDisplay(_holder);
            CameraHolder.instance().getCamera().startPreview();
        } catch (Exception e){
            Log.d("debug", "Error starting camera preview: " + e.getMessage());
        }
    }
}
