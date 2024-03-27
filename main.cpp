#include <iostream>
#include <opencv2/opencv.hpp>
#include "include/videoCapture.h"
#include "include/preprocess.h"
#include "include/preMethod.h"
#include "include/analysis.h"

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap;
    Mat frame, result, mix_frame;

    // Read video and create window
    readAndDisplayVideo("Inputs/video/test2.mp4", cap);

    while (cap.read(frame))
    {
        // Preprocess video frame
        process(frame, result);

        // Search the train lines
        drawLines(frame, result, mix_frame);

        // Show the result
        imshow("video", mix_frame);

        if (waitKey(0) == 27)
            break;
    }

    // Release video capture and close window
    releaseCap(cap);

    return 0;
}
