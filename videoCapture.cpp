#include "include/videoCapture.h"

// Function to read video file
void readAndDisplayVideo(const std::string &filename, cv::VideoCapture &cap, double &fps)
{
    // Open the video file
    cap.open(filename);

    // Check if the video is opened successfully
    if (!cap.isOpened())
    {
        std::cerr << "Error: Unable to open the video file." << std::endl;
        exit(-1);
    }

    // Get the frame rate of the video
    fps = cap.get(cv::CAP_PROP_FPS);
}

// Function to create window for displaying video
void createWindow(cv::VideoCapture &cap)
{
    cv::namedWindow("Video", cv::WINDOW_NORMAL);
}

// Function to release video capture and close window
void releaseCap(cv::VideoCapture &cap)
{
    cap.release();
    cv::destroyAllWindows();
}
