//#include <vector>
//#include <opencv2/core/core.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//#include <opencv2/highgui/highgui.hpp>
//
//using namespace cv;
//
//int main()
//{
//	Mat image = imread("lenna.png");
//	Mat logo = imread("lenna_text.jpg");
//	if (!image.data)
//		return 0;
//	if (!logo.data)
//		return 0;
//
//	Mat result;
//
//	Mat imageROI;
//
//	imageROI = image(Rect(10, 10, logo.cols, logo.rows));
//
//	addWeighted(imageROI, 1.0, logo, 0.3, 0., imageROI);
//
//	namedWindow("with logo");
//	imshow("with logo", image);
//
//	image = imread("lenna.png");
//	logo = imread("logo.bmp");
//
//	imageROI = image(Rect(10, 10, logo.cols, logo.rows));
//	Mat mask = imread("logo.bmp", 0);
//	logo.copyTo(imageROI, mask);
//
//	namedWindow("with logo 2");
//	imshow("with logo 2", image);
//
//	waitKey();
//}
//
////int main()
////{
////	Mat image = imread("lenna.png");
////	Mat logo = imread("lenna_text.jpg");
////
////	if (!image.data)
////		return 0;
////	if (!logo.data)
////		return 0;
////
////	threshold(logo, logo, 150, 255, 0);
////	imwrite("logo.bmp", logo);
////
////	Mat test = imread("logo.bmp", 0);
////	if (!test.data)
////		return 0;
////
////	return 0;
////}