#include <opencv2/opencv.hpp>
#include <iostream>
#include "include/preMethod.h"

using namespace std;
using namespace cv;

// 自适应阈值计算参数
const double MAX_VALUE = 255;
const int ADAPTIVE_METHOD = static_cast<int>(ADAPTIVE_THRESH_GAUSSIAN_C);
const int THRESHOLD_TYPE = static_cast<int>(THRESH_BINARY);
const int BLOCKSIZE = 11;
const double C = 2;

// 大津法阈值计算参数
const double THRESH = 127;
const double MAXVAL = 255;
const int TYPE = THRESH_BINARY | THRESH_OTSU;

// 滤波操作参数
const int D = 5;
const int SIGMA_COLOR = 150;
const double SIGMA_SPACE = 10;

// 卷积操作参数
// const Mat KERNEL = (Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
const Mat KERNEL = (Mat_<float>(5, 5) << -1, 1, 0, 1, -1,
                    -1, 1, 0, 1, -1,
                    -1, 1, 0, 1, -1,
                    -1, 1, 0, 1, -1,
                    -1, 1, 0, 1, -1);

// 灰度转换
void cvt2gray(Mat frame, Mat &result)
{
    cvtColor(frame, result, COLOR_BGR2GRAY);
}

// // 直方图均衡化
// void histOperation(Mat frame, Mat result)
// {
//     equalizeHist(frame, result);
// }

// 滤波方法
void blurMethod(Mat frame, Mat &result)
{
    result = Mat(frame.size(), CV_8UC1);
    bilateralFilter(frame, result, D, SIGMA_COLOR, SIGMA_SPACE);
}

// 卷积
void filter(Mat frame, Mat &result)
{
    result = Mat(frame.size(), CV_8UC1);
    filter2D(frame, result, -1, KERNEL);
}

// 自适应阈值计算 二值化
void binaryThreshold(Mat frame, Mat &result)
{
    result = Mat(frame.size(), CV_8UC1);
    // adaptiveThreshold(frame, result, MAX_VALUE, ADAPTIVE_METHOD, THRESHOLD_TYPE, BLOCKSIZE, C);
    threshold(frame, result, THRESH, MAXVAL, TYPE);
}

// // 开运算
// void openOperation(Mat frame, Mat &result)
// {
//     Mat se = getStructuringElement(MORPH_RECT, Size(9, 9), Point(-1, -1));
//     erode(frame, result, se);
//     dilate(result, result, se);
// }

// // 闭运算
// void closeOperation(Mat frame, Mat &result)
// {
//     Mat se = getStructuringElement(MORPH_RECT, Size(9, 9), Point(-1, -1));
//     dilate(frame, result, se);
//     erode(result, result, se);
// }

// // 连通组件
// int connectComponets(Mat frame, Mat &result, Mat stats, Mat centroids)
// {
//     int nbComponents = connectedComponentsWithStats(frame, result, stats, centroids);
//     return nbComponents;
// }
