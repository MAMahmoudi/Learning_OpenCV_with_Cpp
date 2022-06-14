#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

Mat DoPyrDown(Mat in)
{
	// Make sure the image is divisible by two
	assert(in.cols % 2 == 0 && in.rows % 2 == 0);
	Mat out;

	/*
	#include <opencv2/imgproc.hpp> -->	pyrDown() : Blurs an image and downsamples it.
	Parameters:
	src	input image.
	dst	output image; it has the specified size and the same type as src.
	dstsize	size of the output image.
	borderType	Pixel extrapolation method
	*/
	pyrDown(in, out, Size(in.cols / 2, in.rows / 2));
	return out;
	
}

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
	namedWindow("PyrDown Program", WINDOW_AUTOSIZE);
	/*
	The imshow() function requires that a named 	window already exist(created by cvNamedWindow()).
	*/
	imshow("PyrDown Program", DoPyrDown(img));
	waitKey(0);
	destroyAllWindows();
	return 0;
}