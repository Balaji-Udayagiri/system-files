#include "opencv2/core/core.hpp"
#inlcude "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespaced cv;
using namespace std;

Mat img1=imread("jb.png",1);

void callbackfunc(int event, int x,int y,int flags, void* a)
{
	
	
	if(event==EVENT_RBUTTON)
	{
		int i,j;
 
 		Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));

 		 namedWindow("win2",1);
 	
		 for(i=0;i<img1.rows;i++)
			for(j=0;j<img1.cols;j++)
 				img2.at<uchar>(i,j)=(img1.at<Vec3b>(i,j)[0]+img1.at<Vec3b>(i,j)[1]+img1.at<Vec3b>(i,j)[2])/3;
	}
	
}
 
 
 imshow("win2",img2);
 
 	
	
}

int main()
{
	
	
	namedWindow("win",1);
	setMouseCallback("win",callbackfunc,NULL);
	imshow("win",img1);
	waitKey(0);
}
