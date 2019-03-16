#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img;

void update_img(int t,void *a)
	{
		int i,j,u;
		Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
		for(i=0;i<img.rows;i++)
			{
				for(j=0;j<img.cols;j++)
					{
						u=img.at<uchar>(i,j);
						if(u>t)
							img2.at<uchar>(i,j)=255;
						else
							img2.at<uchar>(i,j)=0;
					}
			}
		imshow("win",img2);
	}

int main()
	{
		img=imread("lenna.png",0);
		int th=127;
		namedWindow("win",WINDOW_NORMAL);
    
		createTrackbar("change_it", "win", &th, 255, update_img);
		waitKey(0);
		return 0;
	}
