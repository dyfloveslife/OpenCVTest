#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int ImageBlur() {
	Mat srcImg = imread("lena.jpg");
	imshow("源图像", srcImg);
	Mat dstImg;
	blur(srcImg, dstImg, Size(10, 10));
	imshow("均值滤波-模糊", dstImg);
	waitKey(0);
	return 0;
}