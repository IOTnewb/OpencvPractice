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



#if !defined MORPHOF

#define MORPHOF



#include <opencv2/core/core.hpp>

#include <opencv2/imgproc/imgproc.hpp>



class MorphoFeatures {



private:



	// 이진 영상을 만들기 위한 경계값 

	int threshold;

	// 코너 감지에 사용하는 구조 요소

	cv::Mat cross;

	cv::Mat diamond;

	cv::Mat square;

	cv::Mat x;



	void applyThreshold(cv::Mat& result) {



		// 결과에 경계값 적용

		if (threshold>0)

			cv::threshold(result, result, threshold, 255, cv::THRESH_BINARY_INV);

	}



public:



	MorphoFeatures() : threshold(-1), cross(5, 5, CV_8U, cv::Scalar(0)),

		diamond(5, 5, CV_8U, cv::Scalar(1)),

		square(5, 5, CV_8U, cv::Scalar(1)),

		x(5, 5, CV_8U, cv::Scalar(0)) {



		// 십자가 모양을 갖는 구조 요소 생성

		for (int i = 0; i<5; i++) {



			cross.at<uchar>(2, i) = 1;

			cross.at<uchar>(i, 2) = 1;

		}



		// 다이아몬드 모양을 갖는 구조 요소 생성

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



		// Creating the x-shaped structuring element

		for (int i = 0; i<5; i++) {



			x.at<uchar>(i, i) = 1;

			x.at<uchar>(4 - i, i) = 1;

		}

	}



	void setThreshold(int t) {



		threshold = t;

	}



	int getThreshold() const {



		return threshold;

	}



	cv::Mat getEdges(const cv::Mat &image) {



		// 그레디언트 영상 가져오기

		cv::Mat result;

		cv::morphologyEx(image, result, cv::MORPH_GRADIENT, cv::Mat());



		// 이진 영상을 얻기 위한 경계값 적용

		applyThreshold(result);



		return result;

	}



	cv::Mat getCorners(const cv::Mat &image) {



		cv::Mat result;



		// 십자가로 팽창	

		cv::dilate(image, result, cross);



		// 다이아몬드로 침식

		cv::erode(result, result, diamond);



		cv::Mat result2;

		// X로 팽창

		cv::dilate(image, result2, x);



		// 사각형으로 침식

		cv::erode(result2, result2, square);



		// 두 닫힘 영상 간의 차이값으로 코너 얻기

		cv::absdiff(result2, result, result);



		// 이진 영상을 얻기 위한 경계값 적용

		applyThreshold(result);



		return result;

	}



	void drawOnImage(const cv::Mat& binary, cv::Mat& image) {



		cv::Mat_<uchar>::const_iterator it = binary.begin<uchar>();

		cv::Mat_<uchar>::const_iterator itend = binary.end<uchar>();



		// 각 화소별로 

		for (int i = 0; it != itend; ++it, ++i) {

			if (!*it)

				cv::circle(image, cv::Point(i%image.step, i / image.step), 5, cv::Scalar(255, 0, 0));

		}

	}

};





#endif



