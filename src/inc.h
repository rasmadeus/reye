#ifndef INC_H
#define INC_H

void inc(const char* path_to_img, int x, int y, int width, int height, int add)
{
    auto img = cvLoadImage(path_to_img);
    cvSetImageROI(img, cvRect(x, y, width, height));
    cvAddS(img, cvScalar(add), img);
    cvResetImageROI(img);

    cvNamedWindow("inc", 1);
    cvShowImage("inc", img);
    cvReleaseImage(&img);
    cvWaitKey();
}


#endif // INC_H
