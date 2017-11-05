#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image;
	image = imread("color.jpg", 0);
	threshold(image, image, 128, 255, CV_THRESH_BINARY);
	imshow("20135352최대한", image);

	Mat vertMat, horzMat;
	Scalar black(0, 0, 0);
	Scalar white = Scalar(255, 255, 255);
	///////////////////////////////////////////////////////////
	reduce(image, horzMat, 0, CV_REDUCE_SUM, CV_32S);           /////
																/////
	Mat Image2(700, image.cols, CV_8UC3, black);			    /////          수평히스토그램
	for (int i = 0; i < horzMat.cols; i++) {					/////
		Point pt1(i, 0);										/////
		Point pt2(i, (horzMat.at<int>(1, i) / 100));			/////
		rectangle(Image2, pt1, pt2, white);						/////
	}															/////
	flip(Image2, Image2, 0);									/////
	imshow("Horz_Projec_histogram", Image2);					/////
	///////////////////////////////////////////////////////////
	reduce(image, vertMat, 1, CV_REDUCE_SUM, CV_32S);			/////
																/////
	Mat Image(image.rows, 700, CV_8UC3, black);					/////          수직히스토그램
																/////         
	for (int i = 0; i < vertMat.rows; i++) {					/////
		Point pt1(0, i);										/////
		Point pt2(((vertMat.at<int>(i, 1) / 100)), i);			/////
		rectangle(Image, pt1, pt2, white);						/////
	}															/////
	imshow("Verti_Projec_histogram", Image);					/////
	///////////////////////////////////////////////////////////

	waitKey(0);
	return 0;
}
