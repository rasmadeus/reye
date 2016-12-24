#ifndef WARP_AFFINE_H
#define WARP_AFFINE_H

void warp_affine(const char* path_to_img)
{
    CvPoint2D32f src_tri[3];
    CvPoint2D32f dst_tri[3];
    auto rot = cvCreateMat(2, 3, CV_32FC1);
    auto warp = cvCreateMat(2, 3, CV_32FC1);
    auto src = cvLoadImage(path_to_img, 1);
    auto dst = cvCloneImage(src);
    dst->origin = src->origin;
    cvZero(dst);

    src_tri[0].x = 0;
    src_tri[0].y = 0;
    src_tri[1].x = src->width - 1;
    src_tri[1].y = 0;
    src_tri[2].x = 0;
    src_tri[2].y = src->height - 1;

    dst_tri[0].x = src->width * 0.0;
    dst_tri[0].y = src->height * 0.33;
    dst_tri[1].x = src->width * 0.85;
    dst_tri[1].y = src->height * 0.25;
    dst_tri[2].x = src->width * 0.15;
    dst_tri[2].y = src->height * 0.7;

    cvGetAffineTransform(src_tri, dst_tri, warp);
    cvWarpAffine(src, dst, warp);
    cvCopy(dst, src);

    const auto center = cvPoint2D32f(src->width / 2, src->height / 2);
    double angle{-50.0};
    double scale{0.6};
    cv2DRotationMatrix(center, angle,scale, rot);
    cvWarpAffine(src, dst, rot);

    cvNamedWindow("2");
    cvShowImage("w", dst);
    cvWaitKey();
    cvReleaseImage(&dst);
    cvReleaseMat(&rot);
    cvReleaseMat(&warp);
}

#endif // WARP_AFFINE_H
