#include <opencv2/opencv.hpp>
#include <iostream>
#include "include/preMethod.h"

using namespace std;
using namespace cv;

void process(Mat frame, Mat &binaryFrame)
{
    Mat grayFrame, histFrame, blurFrame, filterFrame;

    // 灰度转换
    cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

    // 边缘保留滤波
    blurMethod(grayFrame, blurFrame);

    // 卷积操作
    filter(blurFrame, filterFrame);

    // 自适应阈值二值化
    binaryThreshold(filterFrame, binaryFrame);

    // 显示图像
    // imshow("Original Frame", frame);
    // imshow("Gray Frame", grayFrame);
    // imshow("Blur Frame", blurFrame);
    imshow("Binary Frame", binaryFrame);
}
