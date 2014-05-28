package com.nprs.app;

import android.hardware.Camera;
import android.util.Log;

public class CameraHolder {
    private static CameraHolder ourInstance = new CameraHolder();

    public static CameraHolder instance() {
        return ourInstance;
    }

    private Camera _camera;
    private boolean _released;

    private CameraHolder() {
        _released = true;
    }

    public Camera getCamera() {
        if (_released)
            initCamera();

        return _camera;
    }

    public void initCamera() {
        try {
            _camera = Camera.open();
            configure();
            _released = false;
        } catch (Exception e) {
            _camera = null;
            Log.d("error", "Cannot create camera instance");
        }
    }

    public void releaseCamera() {
        _camera.release();
        _released = true;
    }

    private void configure() {
        Camera.Parameters params = _camera.getParameters();
        params.setFocusMode(Camera.Parameters.FOCUS_MODE_CONTINUOUS_VIDEO);
        params.setPictureSize(1920, 1080);
        _camera.setParameters(params);
    }
}
