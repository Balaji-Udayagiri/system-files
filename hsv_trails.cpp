#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{ 	
	Mat img=imread("jb.png",1);
	Mat HSVimg("fruits.jpg",1);
	cvtColor (img,HSVimg,COLOR_BGR2HSV);
	imshow(HSVimg);
}
