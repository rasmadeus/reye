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

#endif // CAPTURE_H
