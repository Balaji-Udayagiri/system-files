#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
using namespace std; 
using namespace cv;	
void onmove (int a, void* b)
{
	Mat img (500,500,CV_8UC1,Scalar(a));
	imshow("win",img);
}
int main()
{
	int th=0;
	Mat img1(500,500,CV_8UC1,Scalar(255));
	Mat img=imread("jb.png",1);
 	namedWindow("win",0);
	createTrackbar ("Tracky","win",&th,255,onmove);
	waitKey(0);
	
	return 0;
}

