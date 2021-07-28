#include <opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int, char** argv) {
    // Create the writer
    FileStorage fs("./data/test.yml", FileStorage::WRITE);

    // Save an int
    int fps = 5;
    fs << "fps" << fps;

    // Create some mat sample
    Mat m1 = Mat::eye(2, 3, CV_32F);
    Mat m2 = Mat::ones(3, 2, CV_32F);
    Mat result = (m1 + 1).mul(m1 + 3);

    // Write the result
    fs << "Result" << result;

    // Release the file
    fs.release();
    
    FileStorage fs2("./data/test.yml", FileStorage::READ);
    Mat r;
    fs2["Result"] >> r;
    cout << r << endl;

    fs2.release();

    return 0;
}