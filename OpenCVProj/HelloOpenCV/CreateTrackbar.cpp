#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

const int g_nMaxAlphaValue = 100;//Alphaֵ�����ֵ
int g_nAlphaValueSlider;//��������Ӧ�ı���
double g_dAlphaValue;
double g_dBetaValue;

//�����洢ͼ��ı���
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;


//-----------------------------------��on_Trackbar( )������--------------------------------
//		��������Ӧ�������Ļص�����
//------------------------------------------------------------------------------------------
void on_Trackbar(int, void*)
{
	//�����ǰalphaֵ��������ֵ�ı���
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	//��betaֵΪ1��ȥalphaֵ
	g_dBetaValue = (1.0 - g_dAlphaValue);

	//����alpha��betaֵ�������Ի��
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

	//��ʾЧ��ͼ
	imshow("picture", g_dstImage);
}

int main(int argc, char** argv)
{
	//����ͼ�� (��ͼ��ĳߴ�����ͬ)
	g_srcImage1 = imread("1.jpg");
	g_srcImage2 = imread("2.jpg");
	if (!g_srcImage1.data) { printf("��ȡ��һ��ͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ��ͼƬ����~�� \n"); return -1; }
	if (!g_srcImage2.data) { printf("��ȡ�ڶ���ͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ��ͼƬ����~��\n"); return -1; }

	//���û�������ֵΪ70
	g_nAlphaValueSlider = 70;

	//��������
	namedWindow("picture", 1);

	//�ڴ����Ĵ����д���һ���������ؼ�
	char TrackbarName[50];
	sprintf_s(TrackbarName, "͸��ֵ %d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, "picture", &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);

	//����ڻص���������ʾ
	on_Trackbar(g_nAlphaValueSlider, 0);

	//��������˳�
	waitKey(0);

	return 0;
}
