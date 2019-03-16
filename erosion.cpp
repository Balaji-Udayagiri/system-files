#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;
using namespace std;




int main()
{
	namedWindow("win",1);
	namedWindow("win2",1);
	Mat img1=imread("erode.png",0);
	Mat img2=imread("erode.png",0);
	
	for(int i=1;i<img1.rows-1;i++)
		for(int j=1;j<img1.cols-1;j++)
		{
			if(img1.at<uchar>(i,j)==255)
				for(int l=0;l<3;l++)
					for(int m=0;m<3;m++)
						if(img1.at<uchar>(i-1+l,j-1+m)==0)
							{
								img2.at<uchar>(i,j)=0;	
							}
		}
	imshow("win",img1);
	imshow("win2",img2);
	waitKey(0);
}
