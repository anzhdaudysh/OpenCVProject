
/**
 * @file main.cpp
 * @brief Основной файл программы для определения и подбора цветов на изображении.
 *
 * Этот файл содержит точку входа в программу и логику взаимодействия с пользователем.
 */

#include <iostream>
#include <opencv2/opencv.hpp>
#include "../include/ImageLoader.h"
#include "../include/ImageProcessor.h"
#include "../include/ColorMatcher.h"
#include "../include/ImageProcessor.h"
#include "../include/NormalizeImage.h"
#include "../include/SelectArea.h"
 
//  cv::Point startPoint, endPoint; ///< Начальная и конечная точки выбора области.
//  bool selecting = false;         ///< Флаг, указывающий, что идет процесс выбора области.
//  cv::Mat image;                  ///< Исходное изображение.
//  cv::Mat displayImage;           ///< Копия изображения для отображения.
//  cv::Scalar avgColor;            ///< Средний цвет в выбранной области.
//  cv::Scalar complementaryColor;  ///< Комплиментарный цвет к среднему цвету.
 
//  /**
//   * @brief Отображает квадратное изображение с заданным цветом.
//   * @param color Цвет для отображения.
//   * @param windowName Название окна.
//   */
//  void showColorSquare(const cv::Scalar& color, const std::string& windowName = "Complementary Color") {
//      int size = 300; // Размер изображения
//      cv::Mat colorSquare(size, size, CV_8UC3, color); // Создаем изображение
//      cv::imshow(windowName, colorSquare); // Отображаем изображение
//      cv::waitKey(0); // Ждем нажатия клавиши
//  }
 
//  /**
//   * @brief Обработчик событий мыши для выбора области на изображении.
//   * @param event Тип события мыши.
//   * @param x Координата X курсора мыши.
//   * @param y Координата Y курсора мыши.
//   * @param flags Флаги события мыши.
//   * @param userdata Пользовательские данные (не используются).
//   */
//  void onMouse(int event, int x, int y, int flags, void* userdata) {
//      if (event == cv::EVENT_LBUTTONDOWN) {

//          startPoint = cv::Point(x, y);
//          endPoint = startPoint;
//          selecting = true;
//      } else if (event == cv::EVENT_MOUSEMOVE && selecting) {

//          endPoint = cv::Point(x, y);
//          displayImage = image.clone();
//          cv::rectangle(displayImage, startPoint, endPoint, cv::Scalar(0, 255, 0), 2);
//          cv::imshow("Image", displayImage);
//          endPoint = cv::Point(x, y);
//          selecting = false;

//          if (startPoint.x < 0 || startPoint.y < 0 || endPoint.x > image.cols || endPoint.y > image.rows) {
//              std::cerr << "Ошибка: область выходит за пределы изображения!" << std::endl;
//              return;
//          }
//          cv::Rect region(startPoint, endPoint);

//          avgColor = ImageProcessor::calculateAverageColor(image, region);
//          std::cout << "Средний цвет в выбранной области: " << avgColor << std::endl;
//          complementaryColor = ColorMatcher::getComplementaryColor(avgColor);
 
//          showColorSquare(complementaryColor);
//          showColorSquare(avgColor, "Average color");
 
//          cv::rectangle(image, startPoint, endPoint, cv::Scalar(0, 255, 0), 2);
//          cv::imshow("Image", image);
//          cv::waitKey(0);
//      }
//  }
 
//  /**
//   * @brief Точка входа в программу.
//   * @return Код завершения программы (0 в случае успеха).
//   */
//  int main() {
//      std::string imagePath = "../images/test_image.jpg"; 
//      ImageLoader imageLodaer;
//      image = imageLodaer.loadImage(imagePath);
 
//      if (image.empty()) {
//          std::cerr << "Не удалось загрузить изображение!" << std::endl;
//          return -1;
//      }
//      displayImage = image.clone();
 
//      cv::namedWindow("Image");
//      cv::imshow("Image", displayImage);
 
//      cv::setMouseCallback("Image", onMouse, nullptr);
//      cv::waitKey(0);
//      cv::destroyAllWindows();
 
//      return 0;
//  }



int main() {
    std::string imagePath = "../images/test_image.jpg"; 
    ImageLoader imageLoader;
    cv::Mat image = imageLoader.loadImage(imagePath);

    if (image.empty()) {
        std::cerr << "Не удалось загрузить изображение!" << std::endl;
        return -1;
    }

    // Нормализация изображения
    cv::Mat normalizedImage = NormalizeImage::normalizeImage(image);

    // Выбор области пользователем
    SelectArea selectArea("Image");
    selectArea.setCallback([&normalizedImage](const cv::Rect& region, const cv::Mat& img) {
        try {
            // Вычисляем средний цвет в выбранной области
            cv::Scalar avgColor = NormalizeImage::calculateAverageColor(normalizedImage, region);
            std::cout << "Средний цвет в выбранной области: " << avgColor << std::endl;

            // Отображаем средний цвет
            SelectArea::showColorSquare(avgColor, "Average Color");
        } catch (const std::runtime_error& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    });

    // Запуск выбора области
    selectArea.start(normalizedImage);

    return 0;
}