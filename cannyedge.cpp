#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int  x;

void onmove(int a,void* b)
{
	Mat img1=imread("square.png",0);
	Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	Canny(img1,img2,x,x*2.5);
	imwrite("squarecan.jpg",img2);
	imshow("win",img2);
}

int main()
{
	
	namedWindow("win",1);
	
	createTrackbar("threshold","win",&x,255,onmove);
	waitKey(0);
	return 0;
}
