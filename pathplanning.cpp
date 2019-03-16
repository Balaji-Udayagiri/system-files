#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

typedef struct Pixel
	{
		int x;
		int y;
	}pixel;

float distance(pixel a,pixel b)
{
	return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)(a.y-b.y)));
}
int ifVisited(pixel p, pixel* visited)
{
	for(i=0;i<img.rows*img.cols;i++)
		if(p==visited[i])
			return 1;
	return 0;
}
neighbour(pixel p,pixel visited)
{
	for(int l=0;l<3;l++)
		for(int m=0;m<3;m++)
			if(shortest_distance[p.(x+l-1)][p.(y+m-1)]=-1)
				continue;
			else
				
}

int main()
{
	Mat img=imread("name",0);
	
	
	float shortest_distance[img.rows][img.cols];
	for(int i=0;i<img.rows;i++)
		for(int =0;j<img.rows;j++)
			shortest_distance[i][j]=100000000;
	shortest_distance[0][0]=0;

	for(int i=0;i<img.rows;i++)
		for(int =0;j<img.rows;j++)
			if(img.at<uchar>(i,j)>128)
				shortest_distance[i][j]=-1;
	pixel visited[img.rows*img.cols];
	
	
}
