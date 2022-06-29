#include "Voronoi.h"

double euclidean(Point p0, Point p1) {
    return sqrt(pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2));
}

double manhattan(Point p0, Point p1) {
    return fabs(p1.x - p0.x) + fabs(p1.y - p0.y);
}

double chebyshev(Point p0, Point p1) {
    return max(fabs(p1.x - p0.x), fabs(p1.y - p0.y));
}

vector<Point> generate_points(int n, int height, int width) {
    vector<Point> points;
    while(points.size() < n) {
        int x = rand() % (width + 1);
        int y = rand() % (height + 1);
        Point p(x, y);
        if(find(points.begin(), points.end(), p) == points.end()) points.push_back(p);
    }
    return points;
}

vector<Color> generate_colors(int n) {
    vector<Color> colors;
    while(colors.size() < n) {
        int c1 = rand() % (254) + 1;
        int c2 = rand() % (254) + 1;
        int c3 = rand() % (254) + 1;
        Color c(c1, c2, c3);
        if(find(colors.begin(), colors.end(), c) == colors.end()) 
            colors.push_back(c);
    }
    return colors;
}

void draw_points(cv::InputOutputArray& img, vector<Point> points) {
    for (auto p : points) {
        cv::circle(img, p, 3, cv::Scalar(0,0,0), -1);
    }
}

void draw_voronoi(cv::Mat& img, vector<Point> points, vector<Color> colors, function<double(Point, Point)> dist_func) {
    int x = img.cols;
    int y = img.rows;
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            double min_dist = DBL_MAX;
            int idx = 0;
            for(int p = 0; p < points.size(); p++) {
                int curr_dist = dist_func(points[p], {i, j});
                if (curr_dist < min_dist) {
                    min_dist = curr_dist;
                    idx = p;
                }
            }
            img.at<cv::Vec3b>(j, i) = colors[idx];
        }
    }
}