int main(int argc, char *argv[])
{
    auto img = cvLoadImage("res/rra.jpg");
    cvNamedWindow("Display picture", CV_WINDOW_AUTOSIZE);
    cvShowImage("Display picture", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Display picture");
}
