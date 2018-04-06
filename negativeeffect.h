#include "effect.h"

class NegativeEffect : public Effect
{
public:
	NegativeEffect(int duration);
	~NegativeEffect();
	void apply(cv::Mat& m);
	void start();
private:
	int duration;
	bool is_running;
};
