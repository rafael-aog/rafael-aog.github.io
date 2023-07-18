#include <iostream>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <cmath>

double alt, alp;
int alt_slider = 0;
int alt_slider_max = 100;

int dec_slider = 0;
int dec_slider_max = 100;

int foco_slider = 0;
int foco_slider_max = 100;

cv::Mat image1, image2, blended;
cv::Mat imageTop; 

char TrackbarName[50];

double alfa(double x, double l1, double l2, double d)
{
  double aux1, aux2;

  aux1 = tanh((x-l1)/d);
  aux2 = tanh((x-l2)/d);

  return 0.5*(aux1 - aux2);
}

void on_trackbar_alt(int, void*){
 alt = (double) alt_slider/alt_slider_max;

  for(int i=0; i<image1.rows; i++)
  {
    alp = alfa(i,dec_slider, foco_slider, alt);
    addWeighted(image1, 1-alp, imageTop, alp, 0.0, blended);
  }
 cv::imshow("tilshift", blended);
}

void on_trackbar_dec(int, void*){
 for(int i=0; i<image1.rows; i++)
  {
    alp = alfa(i,dec_slider, foco_slider, alt);
    addWeighted(image1, 1-alp, imageTop, alp, 0.0, blended);
  }
 cv::imshow("tilshift", blended);
}

void on_trackbar_foco(int, void*){
 for(int i=0; i<image1.rows; i++)
  {
    alp = alfa(i,dec_slider, foco_slider, alt);
    addWeighted(image1, 1-alp, imageTop, alp, 0.0, blended);
  }
 cv::imshow("tilshift", blended);
}

int main(int argvc, char** argv){
  image1 = cv::imread("ponderacao.png",cv::IMREAD_GRAYSCALE);
  image2 = cv::imread("Multidao.png",cv::IMREAD_GRAYSCALE);

  image2.copyTo(imageTop);
  cv::namedWindow("tiltshift", 1);

  std::sprintf( TrackbarName, "Altura x %d", alt_slider_max );
  cv::createTrackbar( TrackbarName, "tiltshift", &alt_slider, alt_slider_max, on_trackbar_alt);
  on_trackbar_alt(alt_slider, 0 );
  
  std::sprintf( TrackbarName, "Decaimento x %d", dec_slider_max );
  cv::createTrackbar( TrackbarName, "tiltshift", &dec_slider, dec_slider_max, on_trackbar_dec);
  on_trackbar_dec(dec_slider, 0 );

  std::sprintf( TrackbarName, "Foco x %d", foco_slider_max );
  cv::createTrackbar( TrackbarName, "tiltshift", &foco_slider, foco_slider_max, on_trackbar_foco);
  on_trackbar_foco(foco_slider, 0 );

  cv::waitKey(0);
  return 0;
}
