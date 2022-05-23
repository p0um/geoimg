#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

#include "src/Utilities.h"

const char* IMG_PATH = "./images/apples.jpg";

int main() {
    auto sourceImg = cv::imread(IMG_PATH, cv::IMREAD_COLOR);

    if (sourceImg.empty() || sourceImg.channels() != 3) {
        std::cerr << "Error trying to open the specified image in color.";
        return 1;
    }

    cv::imshow("Original", sourceImg);

    auto canvas = cv::Mat(sourceImg.rows, sourceImg.cols, CV_8UC3);

    for (int row = 0; row < canvas.rows; row++) {
        for (int col = 0; col < canvas.cols; col++) {
            uint8_t color[3];
            getColorAt(sourceImg, row, col, color);
            canvas.data[row*canvas.cols*3 + col*3] = color[2];
            canvas.data[row*canvas.cols*3 + col*3 + 1] = color[1];
            canvas.data[row*canvas.cols*3 + col*3 + 2] = color[0];
        }
    }

    cv::imshow("Canvas", canvas);
    cv::waitKey();
}