#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "helper.h"

using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	cv::setUseOptimized(true);
	String imageName("resources/happy-fish.jpg"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}
	Mat image;
	image = imread(imageName, IMREAD_COLOR); // Read the file
	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat image_hsv;
	Mat image_tmp;
	cvtColor(image, image_hsv, COLOR_BGR2HSV);
/*	for (int i = 0; i < image_hsv.rows; i++)
	{
		for (int j = 0; j < image_hsv.cols; j++)
		{
			image_hsv.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(image_hsv.at<Vec3b>(i, j)[2] * 2);
		}
	}*/

	namedWindow("... ", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("... ", image); // Show our image inside it.


	
	
	int k = 0;
	int l = 1;
	namedWindow("Zmienione ", WINDOW_AUTOSIZE); // Create a window for display.
	Timer t_przetwarzanie("Przetwarzanie");
	Timer t_imshow("imshow");
	Timer t_petla("Pêtla");
	Timer t_konwersja("Konwersja");
	while (cv::waitKey(1) == -1) {
		//
		//		for (int i = 0; i < image_hsv.rows; i++)
		//		{
		//			for (int j = 0; j < image_hsv.cols; j++)
		//			{
		//				image_hsv.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(image_hsv.at<Vec3b>(i, j)[2] +2);
		//			}
		//	}
		t_petla.start();
		
		t_przetwarzanie.start();
		if (k == 10)
		{
			l = -l;
		}
		
		//image_hsv += Scalar(0, 0, l);
		image += Scalar(0, 0, 5 * l);
		k = (k+1) % 11;
		t_przetwarzanie.stop();
		
		t_konwersja.start();
		//cvtColor(image_hsv, image, COLOR_HSV2BGR);
		t_konwersja.stop();
		
		t_imshow.start();
		imshow("Zmienione ", image);
		t_imshow.stop();
		t_petla.stop();
	} // Wait for a keystroke in the window
	t_petla.print_results();
	t_przetwarzanie.print_results();
	t_konwersja.print_results();
	t_imshow.print_results();
	cv::waitKey(0);
	return 0;
}
