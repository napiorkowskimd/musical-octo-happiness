#include "negativeeffect.h"


NegativeEffect::NegativeEffect(int duration) : duration(duration)
{
	is_running = false;
}

NegativeEffect::~NegativeEffect()
{

}

void NegativeEffect::start() {
	is_running = !is_running;
}

void NegativeEffect::apply(cv::Mat & m)
{
	if (is_running) {
		for (int i = 0; i < m.rows; ++i)
		{
			cv::Vec3b* pixel = m.ptr<cv::Vec3b>(i); // point to first pixel in row
			for (int j = 0; j < m.cols; ++j)
			{
				pixel[j][0] = (pixel[j][0] + 90) % 180;
				pixel[j][1] = 255 - pixel[j][1];
			}
		}
	}
}
