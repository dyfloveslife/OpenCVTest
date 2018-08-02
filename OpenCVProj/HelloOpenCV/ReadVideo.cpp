#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	VideoCapture capture(0);
	Mat edges;
	while (true)
	{
		Mat frame;
		capture >> frame;
		cvtColor(frame, edges, CV_BGR2GRAY);  // ��BGRת��Ϊ�Ҷ�ͼ
		blur(edges, edges, Size(7, 7));
		Canny(edges, edges, 0, 30, 3);
		imshow("Read video", edges);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}