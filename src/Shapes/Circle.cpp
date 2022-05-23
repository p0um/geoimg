#include "Circle.h"

#include <opencv2/core.hpp>
#include <cstdint>
#include <cmath>

#include "../Utilities.h"

Circle::Circle(int row, int col, double radius, const uint8_t *color) :
                row(row), col(col), radius(radius), color{color[0], color[1], color[2]} {}

int Circle::draw(cv::Mat &canvas, const cv::Mat &sourceImg, bool dry) {
    int width = canvas.cols, height = canvas.rows;
    double rr = radius * radius;

    // Create range of drawing
    int rMin = std::max(0, (int)std::floor(row-radius));
    int rMax = std::min(height, (int)std::ceil(row+radius));
    int cMin = std::max(0, (int)std::floor(col-radius));
    int cMax = std::min(width, (int)std::ceil(col+radius));
    for (int r = rMin; r < rMax; r++) {
        for (int c = cMin; c < cMax; c++) {
            auto distanceSquared = (r - row)*(r-row) + (c-col)*(c-col);
            if (distanceSquared <= rr) {
                // TODO Calculate how writing this pixel modifies canvas score, return diff
                writeColor(canvas, r, c, color, dry);
            }
        }
    }
    return 0;
}
