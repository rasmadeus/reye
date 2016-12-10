int slider_pos = 0;
CvCapture* capture = nullptr;


void onTrackbarSlide(int pos)
{
    cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, char *argv[])
{
    cvNamedWindow("TrackBar", CV_WINDOW_AUTOSIZE);
    capture = cvCreateFileCapture("res/rra.avi");

    const auto frames = static_cast<int>(cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT));
    if (0 != frames)
        cvCreateTrackbar("Position", "TrackBar", &slider_pos, frames, onTrackbarSlide);

    IplImage* frame;
    while(true)
    {
        frame = cvQueryFrame(capture);
        if (!frame)
            break;

        cvShowImage("TrackBar", frame);
        const char c = cvWaitKey(33);
        if (27 == c)
            break;
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow("TrackBar");
}
