#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

Mat Function()
{
	Mat ima(240, 320, CV_8U, Scalar(100));
	return ima;
}

int main()
{
	Mat image;

	cout << "size : " << image.size().height << ", " << image.size().width << endl;

	image = imread("lenna.png");

	if (!image.data)
	{
		return 0;
	}

	cout << "size (after reading): " << image.size().height << ", " << image.size().width << endl;

	namedWindow("Original Image");
	imshow("Original Image", image);

	Mat result;
	flip(image, result, 1);

	namedWindow("Output Image");
	imshow("Output Image", result);
	waitKey(0);
	imwrite("output.bmp", result);

	Mat image2, image3;

	image2 = result;
	result.copyTo(image3);

	flip(result, result, 0);

	namedWindow("image 2");
	imshow("image 2", image2);
	namedWindow("image 3");
	imshow("image 3", image3);

	Mat gray = Function();

	namedWindow("Gray Image");
	imshow("Gray Image", gray);

	waitKey(0);

	return 1;


}