#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char**argv) {
  cv::Mat imagemCodificada, imagemEscondida;
  cv::Vec3b valCodificada, valEscondida;
  int nbits = 3;

  imagemCodificada = cv::imread(argv[1], cv::IMREAD_COLOR);

  if (imagemCodificada.empty()) {
    std::cout << "imagem nao carregou corretamente" << std::endl;
    return (-1);
  }
  
  cv::imshow("image", imagemCodificada);
  cv::waitKey();

  imagemEscondida = imagemCodificada.clone();

  for (int i = 0; i < imagemCodificada.rows; i++) {
    for (int j = 0; j < imagemCodificada.cols; j++) {
      valCodificada = imagemCodificada.at<cv::Vec3b>(i, j);
      valCodificada[1] = valCodificada[1] << (8-nbits);
      valCodificada[0] = valCodificada[0] << (8-nbits);
      valCodificada[2] = valCodificada[2] << (8-nbits);
      valEscondida[0] = valCodificada[0];
      valEscondida[1] = valCodificada[1];
      valEscondida[2] = valCodificada[2];
      imagemEscondida.at<cv::Vec3b>(i, j) = valEscondida;
    }
  }
  imwrite("esteganografia-dec.png", imagemEscondida);

  cv::imshow("image", imagemEscondida);
  cv::waitKey();

  return 0;
}
