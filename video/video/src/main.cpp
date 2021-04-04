#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>



//////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char ** argv)
{
   // check arguments
  if(argc > 2){
    std::cerr << "usage: " << argv[0] << " [optional] video.mp4" << std::endl;
    exit(0); 
  }
  
  // input video stream
  cv::VideoCapture capture;

  // load a video
  if(argc == 2){
    capture = cv::VideoCapture(argv[1]);
    if(!capture.isOpened()){
      std::cerr << "failed to open video file : " << argv[1] << std::endl;
      return -1;
    }
  }
  
  // or open a web cam stream
  if(argc == 1){
    std::cout << "   open video stream ..." << std::endl;
    capture = cv::VideoCapture(0);
    capture.set(cv::CAP_PROP_FRAME_WIDTH,800);
    std::cout << "video width  : " << capture.get(cv::CAP_PROP_FRAME_WIDTH) << std::endl;
    std::cout << "video height : " << capture.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl;
  }

  // grab a frame to get the video resolution
  cv::Mat frame;
  capture >> frame;
 
  // display window
  cv::namedWindow("video");
  cv::moveWindow("video",0, 50);

  // read video stream
  std::cout << "   read video stream ..." << std::endl;
  bool loop = true;
  while(loop){
 
    // get the next frame
    capture >> frame;

    // display the image
    cv::imshow("video",frame);

    // events (quit)
    switch(char(cv::waitKey(10))){
      case 27  : loop=false; break;
      case 'Q' :
      case 'q' : loop=false; break;
      case 's' : cv::imwrite("monImage.jpg",frame); break;
    }

  } // main loop end


  // close the video streaming
  std::cout << "   close video stream ..." << std::endl;
  capture.release();

  return 0;
}
