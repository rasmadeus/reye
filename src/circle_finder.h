#ifndef CIRCLE_FINDER_H
#define CIRCLE_FINDER_H

void find_circles(const char* path_to_img)
{
    auto img = cvLoadImage(path_to_img, CV_LOAD_IMAGE_GRAYSCALE);
    auto storage = cvCreateMemStorage(0);
    cvSmooth(img, img, CV_GAUSSIAN, 5, 5);
    auto res = cvHoughCircles(img, storage, CV_HOUGH_GRADIENT, 2, img->width / 10.0);

    for(int i = 0; i < res->total; ++i)
    {
        auto data = (float*)cvGetSeqElem(res, i);
        auto point = cvPoint(cvRound(data[0]), cvRound(data[1]));
        cvCircle(img, point, cvRound(data[2]), CV_RGB(0xff, 0xff, 0xff));
    }

    cvNamedWindow("w");
    cvShowImage("w", img);
    cvReleaseImage(&img);
    cvWaitKey();
    cvDestroyWindow("w");
}

#endif // CIRCLE_FINDER_H
