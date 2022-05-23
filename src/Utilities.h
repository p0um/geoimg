#ifndef GEOIMG_UTILITIES_H
#define GEOIMG_UTILITIES_H

#include <opencv2/core/mat.hpp>

void getColorAt(const cv::Mat &img, int row, int col, uint8_t *color) {
    // OpenCV stores colors using GBR instead of RGB, so store color in reverse
    color[2] = img.data[row*img.cols*3 + col*3];  // B
    color[1] = img.data[row*img.cols*3 + col*3 + 1];  // G
    color[0] = img.data[row*img.cols*3 + col*3 + 2];  // R
}

#endif //GEOIMG_UTILITIES_H
