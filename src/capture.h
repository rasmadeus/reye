#ifndef CAPTURE_H
#define CAPTURE_H

void showVideoFromCam(int cam)
{
    auto capture = cvCreateCameraCapture(cam);
    if (capture)
    {
        IplImage* frame = nullptr;
        cvNamedWindow("cam", CV_WINDOW_AUTOSIZE);
        while(true)
        {
            frame = cvQueryFrame(capture);
            if (!frame)
                break;
            cvShowImage("cam", frame);
            char c = cvWaitKey(33);
            if (27 == c)
                break;
        }
        cvDestroyWindow("cam");
    }
    cvReleaseCapture(&capture);
}


void removeColors()
{
    auto capture = cvCreateFileCapture("res/rra.avi");
    if (!capture)
        return;

    auto bgr_frame = cvQueryFrame(capture);
    const double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    const auto size = cvSize(static_cast<int>(cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH)), static_cast<int>(cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)));
    auto writer = cvCreateVideoWriter("res/rra_out.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
    auto logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);

    while((bgr_frame = cvQueryFrame(capture)))
    {
        cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width / 2, bgr_frame->height / 2), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
        cvWriteFrame(writer, logpolar_frame);
    }

    cvReleaseImage(&logpolar_frame);
    cvReleaseVideoWriter(&writer);
    cvReleaseCapture(&capture);
}

#endif // CAPTURE_H
