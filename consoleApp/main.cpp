#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace cv;
using namespace std;

atomic<bool> recording{true}, snapRequested{false};
mutex frameMutex;
Mat sharedFrame;

void snapshotThread() {
    while (recording) {
        if (snapRequested) {
            Mat frameCopy;
            {
                lock_guard<mutex> lock(frameMutex);
                sharedFrame.copyTo(frameCopy);
            }
            if (!frameCopy.empty()) {
                string filename = "snap_" + to_string(time(nullptr)) + ".jpg";
                imwrite(filename, frameCopy);
                cout << "[Snapshot saved] " << filename << endl;
            }
            snapRequested = false;
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void recordThread(VideoWriter &writer) {
    while (recording) {
        Mat frameCopy;
        {
            lock_guard<mutex> lock(frameMutex);
            sharedFrame.copyTo(frameCopy);
        }
        if (!frameCopy.empty()) writer.write(frameCopy);
        this_thread::sleep_for(chrono::milliseconds(33));
    }
}

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) { cerr<<"ERR opening camera\n"; return -1; }

    int w = cap.get(CAP_PROP_FRAME_WIDTH), h = cap.get(CAP_PROP_FRAME_HEIGHT);
    VideoWriter writer("output.avi", VideoWriter::fourcc('M','J','P','G'), 30, Size(w,h));

    thread snapThread(snapshotThread);
    thread recThread(recordThread, ref(writer));

    cout << "Press 's' to snapshot, 'q' to quit\n";
    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        {
            lock_guard<mutex> lock(frameMutex);
            frame.copyTo(sharedFrame);
        }
        imshow("Live Feed", frame);
        char c = (char)waitKey(1);
        if (c == 'q') break;
        if (c == 's') snapRequested = true;
    }

    recording = false;
    snapThread.join();
    recThread.join();

    cap.release();
    writer.release();
    destroyAllWindows();
    return 0;
}
