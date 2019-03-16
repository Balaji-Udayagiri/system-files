#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

int th=0, a=0;
float r=0.0;

Mat img((int)sqrt((img1.rows)*(img1.rows)+(img1.cols)*(img1.cols)),180,CV_8UC1,Scalar(255));
Mat img1=imread("fruits.jpg",0);

void callbackfunc(int event,int x,int y,int flag, void* a)
{
	if(event==EVENT_LBUTTONDOWN)
		for(a=0;a<180;a++)
			{
				r=x*cos((float)a*3.14/180)+y*sin((float)a*3.14/180);
				//int r1=(int)r; 
				img.at<uchar>(r,a)=0;
			}
}

void onMove(int a, void* b)
{
	
	Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	Canny(img1,img2,th,th*2.5);
	imshow("win",img2);
	setMouseCallback("win",callbackfunc,NULL);
}
int main()
{
	namedWindow("win",1);
	createTrackbar("threshold","win",&th,255,onMove);
	waitKey(0);
	return 0;
}
