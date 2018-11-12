#include <iostream>
#include <string>
#include <sstream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
  // Read images.
  Mat color = imread("../weige.jpg");
  Mat gray = imread("../weige.jpg", 0);

  // Write images.
  imwrite("weigeGray.jpg", gray);

  // Get same pixel with opencv function.
  int myRow = color.cols - 1;
  int myCol = color.rows - 1;
  Vec3b pixel = color.at<Vec3b>(myRow, myCol);
  cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;

  // Show images.
  imshow("Weige BGR", color);
  imshow("Weige Gray", gray);

  waitKey(0);

  return 0;
}
