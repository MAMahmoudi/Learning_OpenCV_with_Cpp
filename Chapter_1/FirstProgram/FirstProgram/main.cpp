#include <opencv2/highgui.hpp>

using namespace cv;

int main()
{
	//This propgram will read an image from a specific location and displays it
	Mat img = imread("../../../images/me.jpg");
	/* 
	NamedWindow() opens a window on the screen that can contain and display an image. 
	It also assigns a name to the window that future HighGUI calls interact with this window will refer to it by this name.
	It may be set either to 0 (the default value) or to CV_WINDOW_AUTOSIZE. 
	In the former case, the size of the window will be the same regardless of the image size, and the image will be scaled to fit within the window.
	*/
	if (img.empty()) return -1;

	namedWindow("First Program",WINDOW_AUTOSIZE);
	/*
	The imshow() function requires that a named 	window already exist(created by cvNamedWindow()).
	*/
	imshow("First Program", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}