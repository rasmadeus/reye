void transform(IplImage* img)
{
    cvNamedWindow("in");
    cvNamedWindow("out");
    cvShowImage("in", img);

    auto out = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
    cvSmooth(img, out, CV_BLUR_NO_SCALE, 3, 3);

    cvShowImage("out", out);
    cvReleaseImage(&out);

    cvWaitKey(0);
    cvDestroyWindow("out");
    cvDestroyWindow("in");
}


int main(int argc, char *argv[])
{
    auto img = cvLoadImage("res/rra.jpg");
    transform(img);
    cvReleaseImage(&img);
}
