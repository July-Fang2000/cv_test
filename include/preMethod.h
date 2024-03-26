#ifndef PREMETHOD_H
#define PREMETHOD_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void cvt2gray(Mat frame, Mat &result);
void blurMethod(Mat frame, Mat &result);
void filter(Mat frame, Mat &result);
void binaryThreshold(Mat frame, Mat &result);
// void openOperation(Mat frame, Mat &result);
// void closeOperation(Mat frame, Mat &result);
// int connectComponets(Mat frame, Mat &result, Mat stats, Mat centroids);
// void histOperation(Mat frame, Mat result);

#endif // PROPROCESS_H