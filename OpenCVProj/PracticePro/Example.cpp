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

//int g_nContrastValue; //对比度值
//int g_nBrightValue;  //亮度值
//Mat g_srcImage, g_dstImage;

int main() {
	/*
	//改变控制台前景色和背景色
	system("color 2F");

	// 读入用户提供的图像
	g_srcImage = imread("1.jpg");
	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

	//设定对比度和亮度的初值
	g_nContrastValue = 80;
	g_nBrightValue = 80;

	//创建窗口
	namedWindow("123", 1);

	//创建轨迹条
	createTrackbar("对比度：", "123", &g_nContrastValue, 300, ContrastAndBright);
	createTrackbar("亮   度：", "123", &g_nBrightValue, 200, ContrastAndBright);

	//调用回调函数
	ContrastAndBright(g_nContrastValue, 0);
	ContrastAndBright(g_nBrightValue, 0);

	//输出一些帮助信息
	cout << endl << "\t运行成功，请调整滚动条观察图像效果\n\n"
		<< "\t按下“q”键时，程序退出\n";

	//按下“q”键时，程序退出
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

	// 【1】读入图像
	Mat srcImage = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");
	if (!srcImage.data) {
		printf("读取srcImage1错误~！ \n");
		return false;
	}
	if (!logoImage.data) {
		printf("读取logoImage错误~！ \n");
		return false;
	}

	// 【2】定义一个Mat类型并给其设定ROI区域
	Mat imageROI = srcImage(Rect(200, 250, logoImage.cols, logoImage.rows));

	// 【3】加载掩模（必须是灰度图）
	Mat mask = imread("dota_logo.jpg", 0);

	//【4】将掩膜拷贝到ROI
	logoImage.copyTo(imageROI, mask);

	// 【5】显示结果
	namedWindow("<1>利用ROI实现图像叠加示例窗口");
	imshow("<1>利用ROI实现图像叠加示例窗口", srcImage);

	return true;
}
*/
/*
bool  MultiChannelBlending()
{
	//【0】定义相关变量
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat  imageBlueChannel;

	//=================【蓝色通道部分】=================
	//	描述：多通道混合-蓝色分量部分
	//============================================

	// 【1】读入图片
	logoImage = imread("dota_logo.jpg", 0);
	srcImage = imread("dota_jugg.jpg");

	if (!logoImage.data) { printf("Oh，no，读取logoImage错误~！ \n"); return false; }
	if (!srcImage.data) { printf("Oh，no，读取srcImage错误~！ \n"); return false; }

	//【2】把一个3通道图像转换成3个单通道图像
	split(srcImage, channels);//分离色彩通道

	//【3】将原图的蓝色通道引用返回给imageBlueChannel，注意是引用，相当于两者等价，修改其中一个另一个跟着变
	imageBlueChannel = channels.at(0);
	//【4】将原图的蓝色通道的（500,250）坐标处右下方的一块区域和logo图进行加权操作，将得到的混合结果存到imageBlueChannel中
	addWeighted(imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));

	//【5】将三个单通道重新合并成一个三通道
	merge(channels, srcImage);

	//【6】显示效果图
	imshow(" <1>游戏原画+logo蓝色通道", srcImage);


	//=================【绿色通道部分】=================
	//	描述：多通道混合-绿色分量部分
	//============================================

	//【0】定义相关变量
	Mat  imageGreenChannel;

	//【1】重新读入图片
	logoImage = imread("dota_logo.jpg", 0);
	srcImage = imread("dota_jugg.jpg");

	if (!logoImage.data) { printf("读取logoImage错误~！ \n"); return false; }
	if (!srcImage.data) { printf("读取srcImage错误~！ \n"); return false; }

	//【2】将一个三通道图像转换成三个单通道图像
	split(srcImage, channels);//分离色彩通道

	//【3】将原图的绿色通道的引用返回给imageBlueChannel，注意是引用，相当于两者等价，修改其中一个另一个跟着变
	imageGreenChannel = channels.at(1);
	//【4】将原图的绿色通道的（500,250）坐标处右下方的一块区域和logo图进行加权操作，将得到的混合结果存到imageGreenChannel中
	addWeighted(imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0., imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));

	//【5】将三个独立的单通道重新合并成一个三通道
	merge(channels, srcImage);

	//【6】显示效果图
	imshow("<2>游戏原画+logo绿色通道", srcImage);



	//=================【红色通道部分】=================
	//	描述：多通道混合-红色分量部分
	//============================================

	//【0】定义相关变量
	Mat  imageRedChannel;

	//【1】重新读入图片
	logoImage = imread("dota_logo.jpg", 0);
	srcImage = imread("dota_jugg.jpg");

	if (!logoImage.data) { printf("Oh，no，读取logoImage错误~！ \n"); return false; }
	if (!srcImage.data) { printf("Oh，no，读取srcImage错误~！ \n"); return false; }

	//【2】将一个三通道图像转换成三个单通道图像
	split(srcImage, channels);//分离色彩通道

	//【3】将原图的红色通道引用返回给imageBlueChannel，注意是引用，相当于两者等价，修改其中一个另一个跟着变
	imageRedChannel = channels.at(2);
	//【4】将原图的红色通道的（500,250）坐标处右下方的一块区域和logo图进行加权操作，将得到的混合结果存到imageRedChannel中
	addWeighted(imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0., imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));

	//【5】将三个独立的单通道重新合并成一个三通道
	merge(channels, srcImage);

	//【6】显示效果图
	imshow("<3>游戏原画+logo红色通道 ", srcImage);

	return true;
}
*/

/*
static void ContrastAndBright(int, void *){
	// 创建窗口
	namedWindow("123", 1);

	// 三个for循环，执行运算 g_dstImage(i,j) = a*g_srcImage(i,j) + b
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

	// 显示图像
	imshow("原图", g_srcImage);
	imshow("123", g_dstImage);
}
*/