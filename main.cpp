#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "timer.h"
#include "brightnesseffect.h"
#include "keyboardrhythmsource.h"

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

    namedWindow("Zmienione", WINDOW_NORMAL); // Create a window for display.

    Mat working_image, original_hls;
    cvtColor(image, original_hls, cv::COLOR_BGR2HLS); // convert image ho HLS format

    std::vector<Effect*> effects;
    // We only have one effect for testing purposes
    effects.push_back(new BrightnessEffect(500, -50));
    KeyboardRhythmSource rhythm_source;
    RhythmData rhythm_data;

    Timer timer("loop");
    while (true) {
        timer.start();
        rhythm_data = rhythm_source.get_data();
        //for testing check if user pressed 'q'
        if (int(rhythm_data.carrier_frequency) == 113) { // 113 = ASCII for q
            break;
        }
        if (int(rhythm_data.carrier_frequency) == 98){ // 98 = ASCII b
            effects[0]->start();
        }
        original_hls.copyTo(working_image);
        for(int i = 0; i < effects.size(); i++){
            effects[i]->apply(working_image);
        }
        cvtColor(working_image, image, cv::COLOR_HLS2BGR);
        imshow("Zmienione", image);
        timer.stop();
    }
    for(int i = 0; i < effects.size(); i++){
        delete effects[i];
    }
    timer.print_statistics();
	return 0;
}
