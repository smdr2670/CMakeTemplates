#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(void) {

	Mat lena = imread("..\\lena.png");

	if (lena.empty()) {
		std::cerr << "Could not find image!" << std::endl;
		std::cerr << "Make sure that the given path to the image is correct." << std::endl;
	} else {
		imshow("Playboy November 1972", lena);
		waitKey();
	}
	
	return 0;
}