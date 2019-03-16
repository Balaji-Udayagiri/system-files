#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<cmath>

using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("66.jpg",0);
	Mat img_binary(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img_canny(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img_gaussian(img.rows,img.cols,CV_8UC1,Scalar(0));
	
	int r;
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			if(img.at<uchar>(i,j)<50)
				img_binary.at<uchar>(i,j)=0;
			else
				img_binary.at<uchar>(i,j)=255;
	
	imwrite("ihp.jpg",img_binary);
	GaussianBlur(img_binary,img_gaussian,Size(5,5),0,0);
	Canny(img_gaussian,img_canny,100,150);
	//namedWindow("dow",1);
	imwrite("pih.jpg",img_canny);
	//Mat img=imread("squarecan.jpg",0);
 	Mat img2(2*sqrt(img.rows*img.rows+img.cols*img.cols),400,CV_8UC1,Scalar(0));
	int max1=0,max2=0,th1=0,th2=0,r1,r2;
	 for(int x=0;x<img.rows;x++)
  	{
  		for(int y=0;y<img.cols;y++)
  		 {
   			if(img_canny.at<uchar>(x,y)>250)
    			{
	            	        for(int th=10;th<170;th+=1)
     				{
					
     					r=y*cos(th*(CV_PI/180))+x*sin(th*(CV_PI/180));
    					 img2.at<uchar>(sqrt(img.rows*img.rows+img.cols*img.cols)+r,th)+=1;
					 if( img2.at<uchar>(r+sqrt(img.rows*img.rows+img.cols*img.cols),th)>=max1)
						{
							max2=max1;
							max1= img2.at<uchar>(r+sqrt(img.rows*img.rows+img.cols*img.cols),th);
							th2=th1;
							th1=th;
						}
     				}
   			 }
   		}
  	}
	namedWindow("win",1);
	imwrite("hip.jpg",img2);	
	imshow("win",img2);
	waitKey(90000);
	
	float angle;

	if(max1-max2>50)
	{
			cout<<max1<<endl;
			cout<<max2<<endl;
			angle=atan((tan(th1)+tan(th2))/(1-tan(th1)*tan(th2)))/2;
			angle=angle*180/3.14;
	}
	else
	{
		angle=th1;
		cout<<th2 ;
	}
	cout<<angle<<endl;

	
}









/*findContours( img_canny, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE, Point(0, 0) );
	 drawContours( dst, contours, idx, color, CV_FILLED, 8, hierarchy );

	Mat drawing(img.rows,img.cols,CV_8UC1,0);
	for( int i = 0; i< contours.size(); i++ )
        {
           	drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
     	}*/
