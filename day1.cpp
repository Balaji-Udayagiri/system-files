#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
using namespace std; 
using namespace cv;
int main()
{
 int i,j;
 Mat img1=imread("test.jpeg",1);
 Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));

  namedWindow("win1",WINDOW_AUTOSIZE);
 
 for(i=0;i<img1.rows;i++)
{
	for(j=0;j<img1.cols;j++)
 	img2.at<uchar>(i,j)=(img1.at<Vec3b>(i,j)[0]+img1.at<Vec3b>(i,j)[1]+img1.at<Vec3b>(i,j)[2])/3;
	
	
}
 imwrite("test.jpeg",img1);
 imshow("win1",img1);
 imshow("win2",img2);
 waitKey(10000);
 
return 0;
}
