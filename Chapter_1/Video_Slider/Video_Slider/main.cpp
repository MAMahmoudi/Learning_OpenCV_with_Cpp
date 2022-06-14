
#include <opencv2/highgui.hpp>

using namespace cv;


//First we defi ne a global variable for the slider position.
int g_slider_position = 0;


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

Mat img;

/*
Now we defi ne a callback routine to be used when the user pokes the slider.
function to be called every time the slider changes position.This function should be prototyped as void Foo(int, void*);, 
where the first parameter is the trackbar position and the second parameter is the user data.
*/
void onTrackbarSlide(int position, void* data)
{
	/*
	CV_CAP_PROP_POS_FRAMES indicates that we would like to set the read position
	in units of frames. (We can use AVI_RATIO instead of FRAMES if we want to set the position as a fraction of the overall video length).
	Finally, we pass in the new value of the position.
	*/
	capture.set(CAP_PROP_POS_FRAMES, position);
}

int main()
{
	namedWindow("Video_Slider", WINDOW_AUTOSIZE);
	
	/*
	cv::VideoCapture::get (int propId)	In this case, we want to find out how many frames are in the video
	so that we can calibrate the slider (in the next step).
	*/
	int frames = (int) capture.get(CAP_PROP_FRAME_COUNT);

	if (frames != 0)
	{
		createTrackbar("Trackbar", "Video_Slider", &g_slider_position, frames, onTrackbarSlide);
	}

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
		imshow("Video_Slider", img);

		/*
		void cv::setTrackbarPos	(const String &	trackbarname, const String & winname, int position)	
		This function sets the position of the specified trackbar in the specified window.
		*/
		setTrackbarPos("Trackbar", "Video_Slider", g_slider_position);
		// Increment the slider position after reading each frame.
		g_slider_position =  (int)capture.get(CAP_PROP_POS_FRAMES);

	}

	capture.release();
	destroyAllWindows();
	return 0;

}