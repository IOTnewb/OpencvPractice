/*------------------------------------------------------------------------------------------*\

This file contains material supporting chapter 5 of the cookbook:

Computer Vision Programming using the OpenCV Library.

by Robert Laganiere, Packt Publishing, 2011.



This program is free software; permission is hereby granted to use, copy, modify,

and distribute this source code, or portions thereof, for any purpose, without fee,

subject to the restriction that the copyright notice may not be removed

or altered from any source or altered source distribution.

The software is released on an as-is basis and without any warranties of any kind.

In particular, the software is not guaranteed to be fault-tolerant or free from failure.

The author disclaims all warranties with regard to this software, any use,

and any consequent failure, is purely the responsibility of the user.



Copyright (C) 2010-2011 Robert Laganiere, www.laganiere.name

\*------------------------------------------------------------------------------------------*/



#include <opencv2/core/core.hpp>

#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/highgui/highgui.hpp>

#include "step5_1.h"



int main()

{

	// 입력 영상 읽기

	cv::Mat image = cv::imread("example.png", 0);
	if (!image.data)
		return 0;

	// 영상 띄워 보기
	cv::namedWindow("Image");
	cv::imshow("Image", image);

	// 모폴로지 특징 인스턴스 생성
	MorphoFeatures morpho;
	morpho.setThreshold(40);


	// 에지 가져오기
	cv::Mat edges;
	edges = morpho.getEdges(image);



	// 에지 영상 띄워 보기
	cv::namedWindow("Edge Image");
	cv::imshow("Edge Image", edges);

	// 코너 가져오기
	morpho.setThreshold(-1);
	cv::Mat corners;
	corners = morpho.getCorners(image);
	cv::morphologyEx(corners, corners, cv::MORPH_TOPHAT, cv::Mat());
	cv::threshold(corners, corners, 40, 255, cv::THRESH_BINARY_INV);

	// 코너 영상 띄워 보기
	cv::namedWindow("Corner Image");
	cv::imshow("Corner Image", corners);
		
	// 영상 내 코너가 있는 영상 띄워 보기
	morpho.drawOnImage(corners, image);
	cv::namedWindow("Corners on Image");
	cv::imshow("Corners on Image", image);
	
	//// 사각형 영상을 읽고 띄워 보기
	//image = cv::imread("example.png", 0);
	//cv::namedWindow("Square Image");
	//cv::imshow("Square Image", image);
	
	// 십자가 모양의 구조 요소 생성
	cv::Mat cross(5, 5, CV_8U, cv::Scalar(0));
	for (int i = 0; i<5; i++) 
	{
		cross.at<uchar>(2, i) = 1;
		cross.at<uchar>(i, 2) = 1;
	}

	// 십자가로 팽창	
	cv::Mat result;
	cv::dilate(image, result, cross);

	//// 결과 띄워 보기
	//cv::namedWindow("Dilated square with cross");
	//cv::imshow("Dilated square with cross", result);

	// 다이아몬드 모양의 구조요소 생성
	cv::Mat diamond(5, 5, CV_8U, cv::Scalar(1));
	diamond.at<uchar>(0, 0) = 0;
	diamond.at<uchar>(0, 1) = 0;
	diamond.at<uchar>(1, 0) = 0;
	diamond.at<uchar>(4, 4) = 0;
	diamond.at<uchar>(3, 4) = 0;
	diamond.at<uchar>(4, 3) = 0;
	diamond.at<uchar>(4, 0) = 0;
	diamond.at<uchar>(4, 1) = 0;
	diamond.at<uchar>(3, 0) = 0;
	diamond.at<uchar>(0, 4) = 0;
	diamond.at<uchar>(0, 3) = 0;
	diamond.at<uchar>(1, 4) = 0;

	// 다이아몬드로 팽창
	cv::Mat result2;
	cv::erode(result, result2, diamond);

	// 결과 띄워 보기
	cv::namedWindow("Eroded square with diamond");
	cv::imshow("Eroded square with diamond", result2);

	// 영상을 하나로 조합하기
	cv::Mat final(100, 300, CV_8U);
	cv::Mat window = final(cv::Rect(0, 0, 100, 100));
	image.copyTo(window);
	window = final(cv::Rect(100, 0, 100, 100));
	result.copyTo(window);
	window = final(cv::Rect(200, 0, 100, 100));
	result2.copyTo(window);

	// 조합 결과를 띄워 보기
	cv::namedWindow("Combined");
	cv::imshow("Combined", final);

	// 조합 결과 저장
	cv::imwrite("squares.bmp", final);
	cv::waitKey();
	return 0;

}



