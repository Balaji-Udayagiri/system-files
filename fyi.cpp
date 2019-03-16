#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<cmath>

using namespace cv;
using namespace std;

int main()
{
	Mat img(50,50,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<10;i++)
	{
		img.at<Vec3b>(i,25)[0]=255;
		img.at<Vec3b>(i,26)[0]=255;
	}
	namedWindow("win",1);
	imshow("win",img);
	waitKey(0);
}

