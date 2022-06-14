#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

void Gaussian_Smoothing(Mat img)
{
	/*
	NamedWindow() opens a window on the screen that can contain and display an image.
	It also assigns a name to the window that future HighGUI calls interact with this window will refer to it by this name.
	It may be set either to 0 (the default value) or to CV_WINDOW_AUTOSIZE.
	In the former case, the size of the window will be the same regardless of the image size, and the image will be scaled to fit within the window.
	*/
	namedWindow("Input image", WINDOW_AUTOSIZE);
	namedWindow("Gaussian Smoothing", WINDOW_AUTOSIZE);

	/*
	#include <opencv2/imgproc.hpp> 
	GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY = 0, int borderType = BORDER_DEFAULT )

	The function convolves the source image with the specified Gaussian kernel. In-place filtering is supported.
	Parameters:
		src	input image; the image can have any number of channels, which are processed independently,
		
		but the depth should be CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
		
		dst	output image of the same size and type as src.
		
		ksize	Gaussian kernel size. ksize.width and ksize.height can differ but they both must be positive and odd.
		Or, they can be zero's and then they are computed from sigma.
		
		sigmaX	Gaussian kernel standard deviation in X direction.
		
		sigmaY	Gaussian kernel standard deviation in Y direction; if sigmaY is zero, it is set to be equal to sigmaX,
		if both sigmas are zeros, they are computed from ksize.width and ksize.height, respectively (see getGaussianKernel for details); to fully control the result regardless of possible future modifications of all this semantics, it is recommended to specify all of ksize, sigmaX, and sigmaY.
		
		borderType	pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
	*/

	Mat Gaussian_Smoothed_Image;

	GaussianBlur(img, Gaussian_Smoothed_Image, Size(7, 7), 0);

	/*
	The imshow() function requires that a named 	window already exist(created by cvNamedWindow()).
	*/
	imshow("Input image", img);
	imshow("Gaussian Smoothing", Gaussian_Smoothed_Image);

	img.release();
	Gaussian_Smoothed_Image.release();
}

int main()
{
	Mat img = imread("../../../images/me.jpg");
	Gaussian_Smoothing(img);
	
	waitKey(0);
	destroyAllWindows();
	return 0;
}