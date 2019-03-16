#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include "opencv2/core/core.hpp"
#include <iostream>
 
using namespace cv;
using namespace std;

long double radian(int angle)
{
	return (angle*CV_PI/180.0);
}

int main(int argc,char* argv[])
{

 int x,y;
 //img1 is the original image and img2 is the rotated image
 Mat img1,img2;
 
 //Take the Input Image in img1
 img1 = imread(argv[1],1);
 
 int diagonal = (int)sqrt(img1.rows*img1.rows+img1.cols*img1.cols);
 //alternative way to declare
 img2 = Mat::zeros(diagonal,diagonal, CV_8UC3);
 
 //Angle by which to rotate an Image
 int Angle = 0;
 while(1)
 {
 //Logic of Image Rotation
 for (float i=0; i<img1.cols ; i++)
 	{
 	for (float j=0 ; j<img1.rows ; j++)
 		{
  			//x'=(x-p)cos(ϴ)-(y-q)sin(ϴ)+p
  			x=(diagonal/2-img1.cols/2)+((i-img1.cols/2)*cos(radian(Angle))-(j-img1.rows/2)*sin(radian(Angle))+img1.cols/2);
   			//y'=(y-q)cos(ϴ)+(x-p)sin(ϴ)+q
   			y=(diagonal/2-img1.rows/2)+((i-img1.cols/2)*sin(radian(Angle))+(j-img1.rows/2)*cos(radian(Angle))+img1.rows/2);
 
   			if((x>=0 && x<img2.cols) && (y>=0 && y<img2.rows))
   			{
   				img2.at<Vec3b>(x,y)[0]=img1.at<Vec3b>(i,j)[0];
   				img2.at<Vec3b>(x,y)[1]=img1.at<Vec3b>(i,j)[1];
   				img2.at<Vec3b>(x,y)[2]=img1.at<Vec3b>(i,j)[2];
   				//alternative way

			  	/*Vec3b color1 = img1.at<Vec3b>(Point(i,j));
  				Vec3b color2 = img2.at<Vec3b>(Point(i,j));
  				color2.val[0] = color1.val[0];
  				color2.val[1] = color1.val[1];
  				color2.val[2] = color1.val[2];
  				img2.at<Vec3b>(Point(x,y)) = color2;*/
   			}
 		}
 	}
	namedWindow("Rotated Image",0); 
	imshow("Rotated Image", img2); 
	namedWindow("Original Image",0); 
	imshow("Original Image", img1);
 	char c=waitKey();
    if(c=='r') Angle+=1;
    if(c=='s') imwrite("rotated.jpg",img2);
    if(c==27) break;
    img2 = Mat::zeros(diagonal,diagonal, CV_8UC3);
} 	
 return 0;
}