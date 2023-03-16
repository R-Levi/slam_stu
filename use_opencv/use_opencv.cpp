#include<opencv2/opencv.hpp>
#include<iomanip>
#include<iostream>
#include<vector>

using namespace std;
using namespace cv;


int main(int argc, char const *argv[])
{
    Mat img1 = imread("",CV_LOAD_IMAGE_COLOR);
    cout<<img1.size<<endl;
    return 0;
}
