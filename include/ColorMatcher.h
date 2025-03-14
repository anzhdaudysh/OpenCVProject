#ifndef COLORMATCHER_H
#define COLORMATCHER_H

#include <opencv2/opencv.hpp>
#include <vector>

class ColorMatcher {
public:
    // Возвращает цвета, которые сочетаются с заданным цветом

    static cv::Scalar getComplementaryColor(const cv::Scalar& color);

    // Преобразует цвет в дополнительный (complementary color)
    static cv::Vec3b getComplementaryColor(const cv::Vec3b& color);
};

#endif