#include "Voronoi.h"

const int height = 700;
const int width = 700;
const string windowName = "Voronoi Diagram";
cv::Mat img(height, width, CV_8UC3, {255, 255, 255});

vector<Point> points;
vector<Color> colors;
int n_points = 6;

int main() {
    srand((unsigned int)time(NULL));
    points = generate_points(n_points, height, width);
    colors = generate_colors(n_points);
    draw_voronoi(img, points, colors, &euclidean);
    draw_points(img, points);

    cv::imshow(windowName, img);
    cv::waitKey(1);

    char c;
    do {
        c = (char)cv::waitKey(0);
    } while (c != 'q');

    return 0;
}