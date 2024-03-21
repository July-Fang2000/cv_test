#include <opencv2/opencv.hpp>
#include <iostream>
#include "include/preMethod.h"

using namespace std;
using namespace cv;

void process(Mat frame, Mat result)
{
    Mat grayFrame, histFrame, binaryFrame, blurFrame, filterFrame;

    // 灰度转换
    cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

    // 边缘保留滤波
    blurFrame = Mat(grayFrame.size(), CV_8UC1);
    blurMethod(grayFrame, blurFrame);

    // 卷积操作
    filterFrame = Mat(grayFrame.size(), CV_8UC1);
    filter(blurFrame, filterFrame);

    // 自适应阈值二值化
    binaryFrame = Mat(grayFrame.size(), CV_8UC1);
    binaryThreshold(filterFrame, binaryFrame);

    binaryFrame.copyTo(result);

    // 显示图像
    // imshow("Original Frame", frame);
    // imshow("Gray Frame", grayFrame);
    // imshow("Blur Frame", blurFrame);
    // imshow("Binary Frame", binaryFrame);
    imshow("result Frame", result);
}
