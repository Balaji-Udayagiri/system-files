#include<iostream>
#include<list>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

struct coordinates
{
	int x;
	int y;
}


/*class Graph
{
	int V;		//no. of vertices
	
	list<coordinates>adj[];

	void checkVertices(list<coordinates>*adj)
	{
		for(int i=-1;i<2;i++)
			for(int j=-1;j<2;j++)
			{
				if(img.at<uchar>(p+i,q+j)==(255))
					adj[v].
			}	
	}
}*/
bool visited(coordinates a)
{
	
	
}

int main()
{
	Mat mazeImage=imread("image name",1);	
	stack<Point>
 
}
