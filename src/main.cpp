int main(int argc, char *argv[])
{
    auto capture = cvCreateCameraCapture(0);
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
