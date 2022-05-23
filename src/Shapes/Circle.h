#ifndef GEOIMG_CIRCLE_H
#define GEOIMG_CIRCLE_H


#include "Shape.h"

typedef unsigned char uint8_t;

class Circle : public Shape {
public:
    Circle(int row, int col, double radius, const uint8_t *color);
    int draw(cv::Mat &canvas, const cv::Mat &sourceImg, bool dry = false) override;
private:
    const int row, col;
    const double radius;
    const uint8_t color[3];
};


#endif //GEOIMG_CIRCLE_H
