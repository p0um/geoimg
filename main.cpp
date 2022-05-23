#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

#include "src/Utilities.h"
#include "src/Shapes/Circle.h"

const char* IMG_PATH = "./images/apples.jpg";

void getMeanColor(const cv::Mat &img, uint8_t *color);

int main() {
    auto sourceImg = cv::imread(IMG_PATH, cv::IMREAD_COLOR);

    if (sourceImg.empty() || sourceImg.channels() != 3) {
        std::cerr << "Error trying to open the specified image in color.";
        return 1;
    }
    cv::imshow("Original", sourceImg);

    uint8_t meanColor[3];
    getMeanColor(sourceImg, meanColor);


    auto canvas = cv::Mat(sourceImg.rows, sourceImg.cols, CV_8UC3);

    for (int row = 0; row < canvas.rows; row++) {
        for (int col = 0; col < canvas.cols; col++) {
            writeColor(canvas, row, col, meanColor);
        }
    }

    // Test writing circle
    Circle circle(128, 128, 50, (const uint8_t []){128, 255, 255});
    circle.draw(canvas, sourceImg);

    cv::imshow("Canvas", canvas);
    cv::waitKey();
}

void getMeanColor(const cv::Mat &img, uint8_t *color) {
    for (int c = 0; c < 3; c++) {
        unsigned long sum = 0;
        for (int row = 0; row < img.rows; row++) {
            for (int col = 0; col < img.cols; col++) {
                sum += img.data[row*img.cols*3 + col*3 + c];
            }
        }
        color[2-c] = sum / (img.rows*img.cols);  // Store in reverse (BGR->RGB conversion)
    }
}