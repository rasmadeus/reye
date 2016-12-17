#ifndef THRESHOLD_H
#define THRESHOLD_H

void sum_rgb(IplImage* src, IplImage* dst)
{
    auto r = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    auto g = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    auto b = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

    cvSplit(src, r, g, b, nullptr);
    auto temp = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

    cvAddWeighted(r, 1.0/3.0, g, 1.0/3.0, 0.0, temp);
    cvAddWeighted(temp, 2.0/3.0, b, 1.0/3.0, 0.0, temp);

    cvThreshold(temp, dst, 100, 100, CV_THRESH_TRUNC);
    cvReleaseImage(&r);
    cvReleaseImage(&g);
    cvReleaseImage(&b);
    cvReleaseImage(&temp);
}

void show_threshold(const char* path_to_img)
{
    cvNamedWindow("w");
    auto src = cvLoadImage(path_to_img);
    auto dst = cvCreateImage(cvGetSize(src), src->depth, 1);
    sum_rgb(src, dst);
    cvShowImage("w", dst);
    while(true)
    {
        const char c = cvWaitKey(10);
        if (27 == c)
            break;
    }
    cvDestroyWindow("w");
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
}

#endif // THRESHOLD_H
