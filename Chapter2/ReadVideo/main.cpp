#include <iostream>
#include <string>
#include <sstream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

const char *keys =
    {
        "{help h usage ? | | print this message}"
        "{@video | | Video file, if not defined try to use webcam}"};

int main(int argc, const char **argv)
{
  CommandLineParser parser(argc, argv, keys);
  parser.about("Chapter 2. v1.0.0");

  if (parser.has("help"))
  {
    parser.printMessage();
    return 0;
  }

  String videoFile = parser.get<String>(0);

  // Check if params are correctly parsed.
  if (!parser.check())
  {
    parser.printErrors();
    return -1;
  }

  VideoCapture cap;
  if (videoFile != "")
    cap.open(videoFile);
  else
    cap.open(0);

  if (!cap.isOpened())
    return -1;

  namedWindow("Video", 1);
  for (;;)
  {
    Mat frame;
    cap >> frame;
    imshow("Video", frame);
    if (waitKey(30) >= 0)
      break;
  }

  cap.release();

  return 0;
}
