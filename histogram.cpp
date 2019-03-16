#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	int intensity[256];

        for (int k=0;k<256;k++)
	intensity[k]=0;
	int i,j,max;
	Mat img=imread("test2.jpeg",0);
	namedWindow("win",1);
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			++intensity[img.at<uchar>(i,j)];		
		}	
	}
	for(i=0,max=intensity[0];i<256;i++)
	{
		if(intensity[i]>max)
		max=intensity[i];
			
	}
	Mat hist(max,256,CV_8UC1,Scalar(0));
	
	for(i=0;i<256;i++)
		{				
		for(j=max-1;j>=max-intensity[i];j--)
		hist.at<uchar>(j,i)=255;
		}	
	
	imshow("win",hist);
	waitKey();
	return 0;
}
