#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

using namespace std;

int main() {
	Mat image;
	image = imread("picture.jpg");
	namedWindow("Display window");
	imshow("Display window", image);
	waitKey(0);
	return 0;
}