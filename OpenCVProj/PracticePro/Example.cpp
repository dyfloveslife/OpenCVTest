#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
//#define WINDOW_WIDTH 600

/*
void DrawEllipse(Mat image, double angle) {
	int thickness = 2;
	int lineType = 8;
	ellipse(image,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),
		angle,
		0,
		360,
		Scalar(255, 129, 0),
		thickness,
		lineType);
}
*/

/*
void colorReduce(Mat & inputImage, Mat& outputImage, int div);

void colorReduce(Mat & inputImage, Mat& outputImage, int div) {
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols*outputImage.channels();

	for (int i = 0; i < rowNumber; i++)
	{
		uchar* data = outputImage.ptr<uchar>(i);
		for (int j = 0; j < colNumber; j++)
		{
			data[j] = data[j] / div * div + div / 2;
		}
	}
}
*/

//bool  ROI_AddImage();
//bool  MultiChannelBlending();
 //static void ContrastAndBright(int, void *);

//int g_nContrastValue; //�Աȶ�ֵ
//int g_nBrightValue;  //����ֵ
//Mat g_srcImage, g_dstImage;

int main() {
	/*
	//�ı����̨ǰ��ɫ�ͱ���ɫ
	system("color 2F");

	// �����û��ṩ��ͼ��
	g_srcImage = imread("1.jpg");
	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

	//�趨�ԱȶȺ����ȵĳ�ֵ
	g_nContrastValue = 80;
	g_nBrightValue = 80;

	//��������
	namedWindow("123", 1);

	//�����켣��
	createTrackbar("�Աȶȣ�", "123", &g_nContrastValue, 300, ContrastAndBright);
	createTrackbar("��   �ȣ�", "123", &g_nBrightValue, 200, ContrastAndBright);

	//���ûص�����
	ContrastAndBright(g_nContrastValue, 0);
	ContrastAndBright(g_nBrightValue, 0);

	//���һЩ������Ϣ
	cout << endl << "\t���гɹ���������������۲�ͼ��Ч��\n\n"
		<< "\t���¡�q����ʱ�������˳�\n";

	//���¡�q����ʱ�������˳�
	while (char(waitKey(1)) != 'q') {}
	return 0;
	*/
	/*
	Mat image = imread("1.jpg");

	namedWindow("src image");
	namedWindow("dst image");
	imshow("src image", image);

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat out;
	morphologyEx(image, image,MORPH_GRADIENT,element);
	imshow("dst image", image);
	while (char(waitKey(1)) != 27) {}
	*/

	Mat srcImage = imread("1.jpg");
	Mat tmpImage, dstImage1, dstImage2;
	tmpImage = srcImage;

	imshow("src image", srcImage);
	resize(tmpImage, dstImage1, Size(tmpImage.cols / 2, tmpImage.rows / 2), (0, 0), (0, 0), 3);
	resize(tmpImage, dstImage2, Size(tmpImage.cols * 2, tmpImage.rows * 2), (0, 0), (0, 0), 3);

	imshow("dst image1", dstImage1);
	imshow("dst image2", dstImage2);
	while (char(waitKey(1) != 27)) {}

}
/*
bool  ROI_AddImage()
{

	// ��1������ͼ��
	Mat srcImage = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");
	if (!srcImage.data) {
		printf("��ȡsrcImage1����~�� \n");
		return false;
	}
	if (!logoImage.data) {
		printf("��ȡlogoImage����~�� \n");
		return false;
	}

	// ��2������һ��Mat���Ͳ������趨ROI����
	Mat imageROI = srcImage(Rect(200, 250, logoImage.cols, logoImage.rows));

	// ��3��������ģ�������ǻҶ�ͼ��
	Mat mask = imread("dota_logo.jpg", 0);

	//��4������Ĥ������ROI
	logoImage.copyTo(imageROI, mask);

	// ��5����ʾ���
	namedWindow("<1>����ROIʵ��ͼ�����ʾ������");
	imshow("<1>����ROIʵ��ͼ�����ʾ������", srcImage);

	return true;
}
*/
/*
bool  MultiChannelBlending()
{
	//��0��������ر���
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat  imageBlueChannel;

	//=================����ɫͨ�����֡�=================
	//	��������ͨ�����-��ɫ��������
	//============================================

	// ��1������ͼƬ
	logoImage = imread("dota_logo.jpg", 0);
	srcImage = imread("dota_jugg.jpg");

	if (!logoImage.data) { printf("Oh��no����ȡlogoImage����~�� \n"); return false; }
	if (!srcImage.data) { printf("Oh��no����ȡsrcImage����~�� \n"); return false; }

	//��2����һ��3ͨ��ͼ��ת����3����ͨ��ͼ��
	split(srcImage, channels);//����ɫ��ͨ��

	//��3����ԭͼ����ɫͨ�����÷��ظ�imageBlueChannel��ע�������ã��൱�����ߵȼۣ��޸�����һ����һ�����ű�
	imageBlueChannel = channels.at(0);
	//��4����ԭͼ����ɫͨ���ģ�500,250�����괦���·���һ�������logoͼ���м�Ȩ���������õ��Ļ�Ͻ���浽imageBlueChannel��
	addWeighted(imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));

	//��5����������ͨ�����ºϲ���һ����ͨ��
	merge(channels, srcImage);

	//��6����ʾЧ��ͼ
	imshow(" <1>��Ϸԭ��+logo��ɫͨ��", srcImage);


	//=================����ɫͨ�����֡�=================
	//	��������ͨ�����-��ɫ��������
	//============================================

	//��0��������ر���
	Mat  imageGreenChannel;

	//��1�����¶���ͼƬ
	logoImage = imread("dota_logo.jpg", 0);
	srcImage = imread("dota_jugg.jpg");

	if (!logoImage.data) { printf("��ȡlogoImage����~�� \n"); return false; }
	if (!srcImage.data) { printf("��ȡsrcImage����~�� \n"); return false; }

	//��2����һ����ͨ��ͼ��ת����������ͨ��ͼ��
	split(srcImage, channels);//����ɫ��ͨ��

	//��3����ԭͼ����ɫͨ�������÷��ظ�imageBlueChannel��ע�������ã��൱�����ߵȼۣ��޸�����һ����һ�����ű�
	imageGreenChannel = channels.at(1);
	//��4����ԭͼ����ɫͨ���ģ�500,250�����괦���·���һ�������logoͼ���м�Ȩ���������õ��Ļ�Ͻ���浽imageGreenChannel��
	addWeighted(imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0., imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));

	//��5�������������ĵ�ͨ�����ºϲ���һ����ͨ��
	merge(channels, srcImage);

	//��6����ʾЧ��ͼ
	imshow("<2>��Ϸԭ��+logo��ɫͨ��", srcImage);



	//=================����ɫͨ�����֡�=================
	//	��������ͨ�����-��ɫ��������
	//============================================

	//��0��������ر���
	Mat  imageRedChannel;

	//��1�����¶���ͼƬ
	logoImage = imread("dota_logo.jpg", 0);
	srcImage = imread("dota_jugg.jpg");

	if (!logoImage.data) { printf("Oh��no����ȡlogoImage����~�� \n"); return false; }
	if (!srcImage.data) { printf("Oh��no����ȡsrcImage����~�� \n"); return false; }

	//��2����һ����ͨ��ͼ��ת����������ͨ��ͼ��
	split(srcImage, channels);//����ɫ��ͨ��

	//��3����ԭͼ�ĺ�ɫͨ�����÷��ظ�imageBlueChannel��ע�������ã��൱�����ߵȼۣ��޸�����һ����һ�����ű�
	imageRedChannel = channels.at(2);
	//��4����ԭͼ�ĺ�ɫͨ���ģ�500,250�����괦���·���һ�������logoͼ���м�Ȩ���������õ��Ļ�Ͻ���浽imageRedChannel��
	addWeighted(imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0., imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));

	//��5�������������ĵ�ͨ�����ºϲ���һ����ͨ��
	merge(channels, srcImage);

	//��6����ʾЧ��ͼ
	imshow("<3>��Ϸԭ��+logo��ɫͨ�� ", srcImage);

	return true;
}
*/

/*
static void ContrastAndBright(int, void *){
	// ��������
	namedWindow("123", 1);

	// ����forѭ����ִ������ g_dstImage(i,j) = a*g_srcImage(i,j) + b
	for (int y = 0; y < g_srcImage.rows; y++)
	{
		for (int x = 0; x < g_srcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}
		}
	}

	// ��ʾͼ��
	imshow("ԭͼ", g_srcImage);
	imshow("123", g_dstImage);
}
*/