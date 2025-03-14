#include <iostream>
#include <opencv2/opencv.hpp>
#include "../include/ImageLoader.h"
#include "../include/ImageProcessor.h"
#include "../include/ColorMatcher.h"

// Глобальные переменные для хранения координат выбора области
cv::Point startPoint, endPoint;
bool selecting = false;
cv::Mat image;
cv::Mat displayImage; // Копия изображения для отображения
cv::Scalar avgColor;
cv::Scalar complementaryColor;

void showColorSquare(const cv::Scalar& color, const std::string& windowName = "Complementary Color") {
    int size = 300; // Размер изображения
    cv::Mat colorSquare(size, size, CV_8UC3, color); // Создаем изображение
    cv::imshow(windowName, colorSquare); // Отображаем изображение
    cv::waitKey(0); // Ждем нажатия клавиши
}


// Функция обработки событий мыши
void onMouse(int event, int x, int y, int flags, void* userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        // Начало выбора области
        startPoint = cv::Point(x, y);
        endPoint = startPoint;
        selecting = true;
    } else if (event == cv::EVENT_MOUSEMOVE && selecting) {
        // Обновление конечной точки при перемещении мыши
        endPoint = cv::Point(x, y);
        // Отображение прямоугольника на изображении
        displayImage = image.clone();
        cv::rectangle(displayImage, startPoint, endPoint, cv::Scalar(0, 255, 0), 2);
        cv::imshow("Image", displayImage);
    } else if (event == cv::EVENT_LBUTTONUP) {
        // Завершение выбора области
        endPoint = cv::Point(x, y);
        selecting = false;

        // Проверка, что область корректна
        if (startPoint.x < 0 || startPoint.y < 0 || endPoint.x > image.cols || endPoint.y > image.rows) {
            std::cerr << "Ошибка: область выходит за пределы изображения!" << std::endl;
            return;
        }

        // Создаем прямоугольник
        cv::Rect region(startPoint, endPoint);

        avgColor = ImageProcessor::calculateAverageColor(image, region);

        std::cout << "Средний цвет в выбранной области: " << avgColor << std::endl;

        complementaryColor = ColorMatcher::getComplementaryColor(avgColor);

        showColorSquare(complementaryColor);
        showColorSquare(avgColor, "Average color");

        // Отображение финального прямоугольника
        cv::rectangle(image, startPoint, endPoint, cv::Scalar(0, 255, 0), 2);
        cv::imshow("Image", image);
        cv::waitKey(0);
    }
}

int main() {
    std::string imagePath = "../images/test_image.jpg"; // Укажите путь к изображению
    ImageLoader imageLodaer;
    image = imageLodaer.loadImage(imagePath);

    if (image.empty()) {
        std::cerr << "Не удалось загрузить изображение!" << std::endl;
        return -1;
    }

    // Создаем копию изображения для отображения
    displayImage = image.clone();

    // Создаем окно для отображения изображения
    cv::namedWindow("Image");
    cv::imshow("Image", displayImage);

    // Устанавливаем обработчик событий мыши
    cv::setMouseCallback("Image", onMouse, nullptr);

    // Ожидание нажатия клавиши для выхода
    cv::waitKey(0);
    cv::destroyAllWindows();

    

    return 0;
}