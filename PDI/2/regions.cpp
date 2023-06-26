#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**){
  cv::Mat image;
  cv::Vec3b val;

  int P1x, P1y, P2x, P2y;

  image= cv::imread("biel.png",cv::IMREAD_GRAYSCALE);
  if(!image.data)
    std::cout << "nao abriu biel.png" << std::endl;

  std::cout << "Insira um valor para a linha de P1" << std::endl;
  std::cin >> P1x;

  std::cout << "Insira um valor para a coluna de P1" << std::endl;
  std::cin >> P1y;

  std::cout << "Insira um valor para a linha de P2" << std::endl;
  std::cin >> P2x;

  std::cout << "Insira um valor para a coluna de P2" << std::endl;
  std::cin >> P2y;

  cv::namedWindow("janela", cv::WINDOW_AUTOSIZE);

  for(int i=P1x;i<P2x;i++){
    for(int j=P1y;j<P2y;j++){
      image.at<uchar>(i,j)=255 - image.at<uchar>(i,j);
    }
  }
  
  cv::imshow("janela", image);  
  cv::waitKey();

  imwrite("bielinversa.png", image);

  return 0;
}
