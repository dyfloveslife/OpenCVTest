#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "mainTOP.h"
using namespace cv;

void TransColor() {
	Mat srcImage = imread("lena.jpg"), dstImage;
	cvtColor(srcImage, dstImage, COLOR_BGR2Lab);
	imshow("show", dstImage);
	waitKey();
}

int camshiftdemo()
{
	return 0;
}
