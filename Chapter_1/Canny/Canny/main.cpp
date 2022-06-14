#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

Mat DoCanny(Mat in)
{
	
	Mat out;

	/*
	#include <opencv2/imgproc.hpp> -->	Canny() : Finds edges in an image using the Canny algorithm.
	Parameters:
	image	8-bit input image.
	edges	output edge map; single channels 8-bit image, which has the same size as image .
	threshold1	first threshold for the hysteresis procedure.
	threshold2	second threshold for the hysteresis procedure.
	apertureSize	aperture size for the Sobel operator.
	L2gradient	a flag, indicating whether a more accurate L2 norm should be used to calculate the image gradient magnitude ( L2gradient=true ),
	or whether the default L1 norm =|dI/dx|+|dI/dy| is enough ( L2gradient=false ).
	*/
	Canny(in, out, 10,100,3,true);
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
	namedWindow("Canny Edge Detector", WINDOW_AUTOSIZE);
	/*
	The imshow() function requires that a named 	window already exist(created by cvNamedWindow()).
	*/
	imshow("Canny Edge Detector", DoCanny(img));
	waitKey(0);
	destroyAllWindows();
	return 0;
}