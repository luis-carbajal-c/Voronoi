#include "Voronoi.h"

using namespace std;

const int height = 720;
const int width = 720;
const string windowName = "RTree Visualization";
cv::Mat img(height, width, CV_8UC3, {255, 255, 255});

int main() {
    cv::imshow(windowName, img);
    cv::waitKey(1);

    char c;
    do {
        c = (char)cv::waitKey(0);
    } while (c != 'q');

    return 0;
}