#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "timer.h"
#include "brightnesseffect.h"

using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
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

    namedWindow("Zmienione", WINDOW_AUTOSIZE); // Create a window for display.

    Mat output_image, temp_image;
    cvtColor(image, temp_image, cv::COLOR_BGR2HLS);
    BrightnessEffect be(600);
    Timer timer("timer");
    while (waitKey(25) == -1) {
        timer.start();
        be.apply(temp_image, output_image);
        cvtColor(output_image, image, cv::COLOR_HLS2BGR);
        imshow("Zmienione", image);
        timer.stop();
    }
    timer.print_statistics();
	return 0;
}
