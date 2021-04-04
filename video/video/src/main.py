import sys
import cv2


def main(argv):
    if(len(argv) > 2 ):
        print("usage "+argv[0]+" [optional] video.mp4")
        return

    capture = None
    #load a video
    if(len(argv) == 2):
        capture = cv2.VideoCapture(argv[1])
        if(not capture.isOpened()):
            print("failed to open video file : "+argv[1])
            return


    #or open a web cam stream
    if(len(argv) == 1):
        print("open video stream ...")
        #webcam = Webcam()
        #webcam.start()
        
        capture = cv2.VideoCapture(0)

        capture.set(cv2.CAP_PROP_FRAME_WIDTH, 800)
        print("video width  :"+str(capture.get(cv2.CAP_PROP_FRAME_WIDTH)))
        print("video height  :"+str(capture.get(cv2.CAP_PROP_FRAME_HEIGHT)))

    # grab a frame to get the video resolution
    frame = capture.read()[1]
    cv2.namedWindow("video")
    cv2.moveWindow("video", 0, 50)

    # read video stream
    print(" read video stream ...")
    #loop = True
    while(True):
        #get the next frame
        frame = capture.read()[1]

        cv2.imshow("video",frame)
        c = char(cv2.waitKey(10))
        if(c=='s'):
            cv2.imwrite("monImage.jpg",frame)
            break
        elif(c == 'q'):
            break
        elif (c == char(27)):
            break
        elif (c == 'Q'):
            print("Q")

    print("  close video stream ...")
    capture.release()
    return




if __name__ == "__main__":
    main(sys.argv)