#ifndef LOG_POLAR_H
#define LOG_POLAR_H

void log_polar(const char* path_to_img)
{
    auto src = cvLoadImage(path_to_img);
    const double M = 9.0;

    auto dst = cvCreateImage(cvGetSize(src), 8, 3);
    auto buf = cvCreateImage(cvGetSize(src), 8, 3);

    cvLogPolar(src, dst, cvPoint2D32f(src->width / 4, src->height / 2), M, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
    cvLogPolar(dst, buf, cvPoint2D32f(src->width / 4, src->height / 2), M, CV_INTER_LINEAR | CV_WARP_INVERSE_MAP);

    cvNamedWindow("w");
    cvShowImage("w", dst);
    cvNamedWindow("b");
    cvShowImage("b", buf);
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    cvReleaseImage(&buf);
    cvWaitKey();
    cvDestroyWindow("w");
    cvDestroyWindow("b");
}

#endif // LOG_POLAR_H
