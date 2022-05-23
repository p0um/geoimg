#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

const char* IMG_PATH = "./images/apples.jpg";

int main() {
    auto img = cv::imread(IMG_PATH);

    cv::imshow("Original", img);
    cv::waitKey();
}