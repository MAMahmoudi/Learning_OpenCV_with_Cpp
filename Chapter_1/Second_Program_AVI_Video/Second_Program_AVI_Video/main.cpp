//#include <opencv2/core.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
//#include <iostream>
using namespace cv;

int main()
{
	//This propgram will play a video from a specific location and displays it
	Mat img;
	/*
	NamedWindow() opens a window on the screen that can contain and display an image.
	It also assigns a name to the window that future HighGUI calls interact with this window will refer to it by this name.
	It may be set either to 0 (the default value) or to CV_WINDOW_AUTOSIZE.
	In the former case, the size of the window will be the same regardless of the image size, and the image will be scaled to fit within the window.
	*/
	namedWindow("Second_Program_AVI_Video", WINDOW_AUTOSIZE);

	/*
	
	cv::VideoCapture::VideoCapture	(	const String & 	filename	)	

	Open video file or a capturing device or a IP video stream for video capturing with API Preference.
	Parameters: filename	it can be:
	1- name of video file (eg. video.avi)
	2- or image sequence (eg. img_%02d.jpg, which will read samples like img_00.jpg, img_01.jpg, img_02.jpg, ...)
	3- or URL of video stream (eg. protocol://host:port/script_name?script_params|auth)
	4- or GStreamer pipeline string in gst-launch tool format in case if GStreamer is used as backend Note that each video stream
	   or IP camera feed has its own URL scheme. Please refer to the documentation of source stream to know the right URL.
	*/

	VideoCapture capture("../../../videos/Mahrez.mp4");
	

	while (true) 
	{
		/*
		We then wait for 25 ms.* If the user hits a key, then c will be set to the ASCII value of that key; 
		if not, then it will be set to –1. If the user hits the Esc key (ASCII 27), then we will exit the read loop.
		Otherwise, 25 ms will pass and we will just execute the loop again.

		We can control the speed of the video by adjusting the waitKey(25). It waits 25 ms to read the next frame.
		*/
		char c = waitKey(25);
		if (c == 27) break;

		bool bSuccess = capture.read(img); // read a new frame from video 
		//Breaking the while loop at the end of the video
		if (bSuccess == false) break;
		
		/*
		 The imshow() function requires that a named window already exist(created by cvNamedWindow()).
		 */
		imshow("Second_Program_AVI_Video", img);
		
	}

	capture.release();
	destroyAllWindows();
	return 0;
}