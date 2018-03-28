// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	String imageName("happy-fish.jpg"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}
	Mat image;
	image = imread(imageName, IMREAD_COLOR); // Read the file
	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}


	Mat image_hsv;
	cvtColor(image, image_hsv, COLOR_BGR2HSV);
	for (int i = 0; i < image_hsv.rows; i++)
	{
		for (int j = 0; j < image_hsv.cols; j++)
		{
			image_hsv.at<Vec3b>(i, j)[2] += 1;
			if (image_hsv.at<Vec3b>(i, j)[2] > 250) 
			{
				image_hsv.at<Vec3b>(i, j)[2] = 250;
			}
		}
	}




	namedWindow("... ", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("... ", image);      // Show our image inside it.
	cvtColor(image_hsv, image, COLOR_HSV2BGR);

	namedWindow("Zmienione ", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Zmienione ", image);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}