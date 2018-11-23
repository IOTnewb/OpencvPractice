#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("lenna.png");
	namedWindow("My Image");
	imshow("My Image", image);
	waitKey(5000);

	return 1;
}