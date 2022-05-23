#ifndef GEOIMG_SHAPE_H
#define GEOIMG_SHAPE_H

namespace cv {
    class Mat;
}

class Shape {
public:
    virtual int draw(cv::Mat &canvas, const cv::Mat &sourceImg, bool dry=false) = 0;
};


#endif //GEOIMG_SHAPE_H
