#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**){
  cv::Mat image;
  cv::Vec3b val;

  image= cv::imread("biel.png",cv::IMREAD_GRAYSCALE);
  if(!image.data)
    std::cout << "nao abriu biel.png" << std::endl;

  cv:: Size tam = image.size();
  
  cv::imshow("janela 1", image);  
  cv::waitKey();

  cv:: Mat q1 = image(cv::Rect(0, 0, tam.width/2, tam.height/2));
  cv:: Mat q2 = image(cv::Rect(0, tam.width/2, tam.width/2, tam.height/2));
  cv:: Mat q3 = image(cv::Rect(tam.height/2, 0, tam.width/2, tam.height/2));
  cv:: Mat q4 = image(cv::Rect(tam.height/2, tam.width/2, tam.width/2, tam.height/2));

  cv::Mat l1, l2, imgtrocada;
  cv::hconcat(q4, q2, l1);
  cv::hconcat(q3, q1, l2);
  cv::vconcat(l1, l2, imgtrocada);

  cv::imshow("janela 2", imgtrocada);
  cv::waitKey();

  imwrite("trocada.png", imgtrocada);

  return 0;
}
