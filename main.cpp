#include "Voronoi.h"

const int height = 600;
const int width = 600;
const string window_name = "Voronoi Diagram";
cv::Mat img(height, width, CV_8UC3, {255, 255, 255});

vector<Point> points;
vector<Color> colors;
int n_points = 5;

void key_handler() {
    char c;
    do {
        c = (char)cv::waitKey(0);
        switch (c) {
            case 'z': 
                draw_voronoi(img, points, colors, &euclidean);
                break;
            case 'x':
                draw_voronoi(img, points, colors, &manhattan);
                break;
            case 'c':
                draw_voronoi(img, points, colors, &chebyshev);
                break;
            case 'a':
                if (n_points > 1) {
                    n_points--;
                    points = generate_points(n_points, height, width);
                    colors = generate_colors(n_points);
                    img = cv::Scalar(255,255,255);
                }
                break;
            case 's':
                n_points++;
                points = generate_points(n_points, height, width);
                colors = generate_colors(n_points);
                img = cv::Scalar(255,255,255);
                break;
            case 32:
                points = generate_points(n_points, height, width);
                img = cv::Scalar(255,255,255);
                break;
            default: continue;
        }
        draw_points(img, points);
        cv::imshow(window_name, img);
    } while (c != 'q');
}


int main() {
    srand((unsigned int)time(NULL));
    points = generate_points(n_points, height, width);
    colors = generate_colors(n_points);
    draw_points(img, points);

    cv::imshow(window_name, img);
    key_handler();

    return 0;
}