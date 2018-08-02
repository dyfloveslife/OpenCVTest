#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "mainTOP.h"

using namespace cv;

int ImageCorrosion() {
	Mat srcImg = imread("lena.jpg");
	imshow("Ô­Í¼£º", srcImg);
	Mat element = getStructuringElement(MORPH_RECT, Size(10, 10));
	Mat dstImage;
	erode(srcImg, dstImage, element);
	imshow("¸¯Ê´ºóµÄÍ¼Ïñ£º", dstImage);
	waitKey(0);
	return 0;
}