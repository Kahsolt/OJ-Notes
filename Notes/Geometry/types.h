#include <cmath>
#define OUT
#define MAX_POLYGON_VERTEX 100

typedef struct point {  // 点、自由向量(原点向量)
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) { }
  point(point &p) : x(p.x), y(p.y) { }
  point operator+ (point &p) { return point(x + p.x, y + p.y); }
  point operator- (point &p) { return point(x - p.x, y - p.y); }
  point operator* (double a) { return point(a * x, a * y); }
  double operator* (point &p) { return x * p.x +  y * p.y; }
  double operator^ (point &p) { return x * p.y -  y * p.x; }
  double modulo2 () { return x * x + y * y; }
  double modulo () { return sqrt(this->modulo2); }
} Point, Vector;

typedef struct vector { // 直线、线段、固定向量
  Point s, t;
  vector() {}
  vector(point _s, point _t) : s(_s), t(_t) { }
  vector(double _x1, double _y1, double _x2, double _y2)
    : s(point(_x1, _y1)), t(point(_x2, _y2)) { }
  vector(vector &v) : s(v.s), t(v.t) { }
  point intersect_line(vector& v1, vector& v2) {
    double k = -((v1.s - v2.s) * (v2.t - v2.s)) 
      / ((v1.t - v1.s) * (v2.t - v2.s));
    return v1.s + (v1.t - v1.s) * k;
  }
  bool intersect_segment(vector& v1, vector& v2, OUT point p) {
    point p = intersect_line(v1, v2);
    if ( > 0) return false;
  }
} Segment, Line, FixedVector;

typedef struct polygon {
  int n;
  Point p[MAX_POLYGON_VERTEX];
} Polygon;

typedef struct circle {
  double r;
  Point o;
} Circle;

typedef struct triangle {
  Point a, b, c;  // 三个定点
  Point u，v;     // 保持两个边向量，方便计算
  triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c)
  { u = a - b; v = a - c;}
  double area() { return (u ^ v) / 2;}
} Triangle;