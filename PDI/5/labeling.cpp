#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
  cv::Mat image, realce;
  int width, height;
  int nobjects, undentify;

  cv::Point p;
  image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

  if (!image.data) {
    std::cout << "imagem nao carregou corretamente\n";
    return (-1);
  }

  width = image.cols;
  height = image.rows;
  std::cout << width << "x" << height << std::endl;

  p.x = 0;
  p.y = 0;

  // busca objetos presentes
  undentify = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if(i == 0 || j == 0 || i == height-1 || j == width-1) {
        if (image.at<uchar>(i, j) == 255) {
          // achou um objeto na borda
          undentify++;
          // para o floodfill as coordenadas
          // x e y são trocadas.
          p.x = j;
          p.y = i;
          // preenche o objeto com o contador
          cv::floodFill(image, p, 0);
        }
      }
    }
  }
  cv::imshow("image2", image);
  cv::imwrite("bordaslisas.png", image);

  p.x = 0;
  p.y = 0;

  cv::floodFill(image, p, 155);

  // busca objetos presentes
  nobjects = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (image.at<uchar>(i, j) == 0) {
        // achou um objeto
        nobjects++;
        // para o floodfill as coordenadas
        // x e y são trocadas.
        p.x = j;
        p.y = i;
        // preenche o objeto com o contador
        cv::floodFill(image, p, 255);
      }
    }
  }

  std::cout << "a figura tinha " << undentify << " objetos nas bordas\n";
  std::cout << "a figura tem " << nobjects << " bolhas\n";
  cv::imshow("image", image);
  cv::imwrite("labeling.png", image);
  cv::waitKey();
  return 0;
}
