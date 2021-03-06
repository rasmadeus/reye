#ifndef INC_H
#define INC_H

void inc(const char* path_to_img, int x, int y, int width, int height, int add)
{
    auto img = cvLoadImage(path_to_img);
    cvSetImageROI(img, cvRect(x, y, width, height));
    cvAddS(img, cvScalar(add), img);
    cvResetImageROI(img);

    cvNamedWindow("inc");
    cvShowImage("inc", img);
    cvReleaseImage(&img);
    cvWaitKey();
    cvDestroyWindow("inc");
}

void blend(const char* first, const char* second, double alpha, double beta)
{
    auto img_first = cvLoadImage(first);
    auto img_second = cvLoadImage(second);

    cvSetImageROI(img_first, cvRect(350, 460, img_second->width, img_second->height));

    cvAddWeighted(img_first, alpha, img_second, beta, 0.0, img_first);
    cvResetImageROI(img_first);

    cvNamedWindow("img_first");
    cvShowImage("img_first", img_first);

    cvReleaseImage(&img_second);
    cvReleaseImage(&img_first);

    cvWaitKey();
    cvDestroyWindow("img_first");
}


#endif // INC_H
