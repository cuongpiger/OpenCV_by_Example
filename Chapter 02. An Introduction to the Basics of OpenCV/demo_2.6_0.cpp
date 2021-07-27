#include <iostream>
#include <string>
#include <sstream>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
    Mat color = imread("./data/lena.png");
    Mat gray = imread("./data/lena.png", 0);

    imwrite("./data/lena_gray.png", gray);

    int myRow = color.cols - 1;
    int myCol = color.rows - 1;

    Vec3b pixel = color.at<Vec3b>(myRow, myCol);

    cout << "Pixel value (B, G, R): (" << (int)pixel[0] << ", " << (int)pixel[1] << ", " << (int)pixel[2] << ")" << endl;

    imshow("Lena BGR", color);
    imshow("Lena Gray", gray);

    waitKey(0);
    return 0;
}