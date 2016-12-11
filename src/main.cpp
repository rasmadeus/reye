IplImage* doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5)
{
    auto out = cvCreateImage(cvSize(in->width / 2, in->height / 2), in->depth, in->nChannels);
    cvPyrDown(in, out, filter);
    return out;
}

IplImage* doCanny(IplImage* in, double lowThresh, double highTresh, double aperture)
{
    auto out = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);
    cvCanny(in, out, lowThresh, highTresh, aperture);
    return out;
}


int main(int argc, char *argv[])
{
    cvNamedWindow("out");
    auto in = cvLoadImage("res/rra.jpg");
    auto out = doPyrDown(in);
    out = doPyrDown(out);
    out = doCanny(out, 10, 100, 3);
    cvShowImage("out", out);
    cvReleaseImage(&out);
    cvReleaseImage(&in);
    cvWaitKey(0);
    cvDestroyWindow("out");
}
