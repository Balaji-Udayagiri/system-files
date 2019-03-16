#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc"

using namespace std;

Mat img=imread("img name",0);

class Graph
{
	public:
		list<Point>**vertices;
		void init_graph(Mat img)
		{
			this->img=img;
			
			for(int i=0;i<img.rows;i++)
				for(int j=0;j<img.cols;j++)
					{
						if(img.at<uchar>(i,j)==255)
							for(int k=-1;k<2;k++)
								for(int l=-1;l<2;l++)
									if(img.at<uchar>(i+k,j+l)==255)
										vertices[i][j].push_back(Point(i+k,j+l));	
					}
		}

		void BFS()
}

int main()
{

}
