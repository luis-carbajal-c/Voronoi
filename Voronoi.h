#include <opencv2/opencv.hpp>
using namespace std;

using Point = cv::Point;
using Color = cv::Vec3b;

double euclidean(Point p0, Point p1);
double manhattan(Point p0, Point p1);
double chebyshev(Point p0, Point p1);

vector<Point> generate_points(int n, int height, int width);
vector<Color> generate_colors(int n);

void draw_points(cv::InputOutputArray& img, vector<Point> points);
void draw_voronoi(cv::Mat& img, vector<Point> points, vector<Color> colors, function<double(Point, Point)> dist_func);