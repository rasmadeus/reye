#ifndef HISTOGRAM_H
#define HISTOGRAM_H

void show_histogram(const char* path_to_img)
{
    auto src = cvLoadImage(path_to_img);
    auto hsv = cvCreateImage(cvGetSize(src), 8, 3);
    cvCvtColor(src, hsv, CV_BGR2HSV);
    auto h_plane = cvCreateImage(cvGetSize(src), 8, 1);
    auto s_plane = cvCreateImage(cvGetSize(src), 8, 1);
    auto v_plane = cvCreateImage(cvGetSize(src), 8, 1);
    IplImage* planes[] = {h_plane, s_plane};
    cvCvtPixToPlane(hsv, h_plane, s_plane, v_plane, 0);
    int h_bins = 30;
    int s_bins = 32;
    CvHistogram* hist;

    {
        int hist_size[] = {h_bins, s_bins};
        float h_ranges[] = {0, 180};
        float s_ranges[] = {0, 255};
        float* ranges[] = {h_ranges, s_ranges};
        hist = cvCreateHist(2, hist_size, CV_HIST_ARRAY,ranges, 1);
    }
    cvCalcHist(planes, hist, 0, 0);
    cvNormalizeHist(hist, 1.0);
    int scale = 10;
    auto hist_img = cvCreateImage(cvSize(h_bins * scale, s_bins * scale), 8, 3);
    cvZero(hist_img);

    float max_value = 0;
    cvGetMinMaxHistValue(hist, 0, &max_value, 0, 0);
    for(int h = 0; h < h_bins; ++h){
        for(int s = 0; s < s_bins; ++s) {
            float bin_val = cvQueryHistValue_2D(hist, h, s);
            int intensity = cvRound(bin_val * 255 / max_value);
            cvRectangle(hist_img, cvPoint(h*scale, s*scale), cvPoint((h+1)*scale - 1, (s+1)*scale -1), CV_RGB(intensity, intensity, intensity), CV_FILLED);
        }
    }

    cvNamedWindow("w", 1);
    cvShowImage("w", src);
    cvNamedWindow("h", 1);
    cvShowImage("h", hist_img);
    cvWaitKey(0);
}

#endif // HISTOGRAM_H
