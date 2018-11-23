//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//
//using namespace cv;
//
//int main()
//{
//	Mat image = imread("test.jpg");
//	if (!image.data)
//		return 0;
//
//	namedWindow("Image");
//	imshow("Image", image);
//
//	Mat eroded;
//	erode(image, eroded, Mat());
//
//	namedWindow("Eroded Image");
//	imshow("Eroded Image", eroded);
//
//	Mat Dilated;
//	dilate(image, Dilated, Mat());
//
//	namedWindow("Dilated Image");
//	imshow("Dilated Image", Dilated);
//
//	Mat element(7, 7, CV_8U, Scalar(1));
//	erode(image, eroded, element);
//
//	namedWindow("Eroded image (7x7)");
//	imshow("Eroded image (7x7)", eroded);
//
//	erode(image, eroded, Mat(), Point(-1, -1), 3);
//
//	namedWindow("Eroded image (3 times)");
//	imshow("Eroded image (3 times)", eroded);
//
//	Mat element5(5, 5, CV_8U, Scalar(1));
//	Mat closed;
//	morphologyEx(image, closed, MORPH_CLOSE, element5);
//
//	namedWindow("Closed image");
//	imshow("Closed image", closed);
//
//	Mat opened;
//	morphologyEx(image, opened, MORPH_OPEN, element5);
//
//	namedWindow("Opened image");
//	imshow("Opened image", opened);
//
//	morphologyEx(image, image, MORPH_CLOSE, element5);
//	morphologyEx(image, image, MORPH_OPEN, element5);
//
//	namedWindow("Closed and Opened image");
//	imshow("Closed and Opened image", image);
//	imwrite("binaryGroup.bmp", image);
//
//	image = imread("binaryGroup.bmp");
//
//	morphologyEx(image, image, MORPH_OPEN, element5);
//	morphologyEx(image, image, MORPH_CLOSE, element5);
//
//	namedWindow("Opened and Closed image");
//	imshow("Opened and Closed image", image);
//
//	waitKey();
//
//	return 0;
//
//}