// 문제해결 기법 과제-22

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// === File Control ====
const std::string FILE_NAME = "area";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// === Solution ====
using pdd = std::pair<double, double>;

struct Circle {
    Circle() = default;
    Circle(double x, double y, double r) : x(x), y(y), r(r) { }

    double x, y, r;
};

struct Vector { 
    Vector() = default;
    Vector(double x, double y) : x(x), y(y) { }
    double x, y; 
};

Vector operator+(const Vector& lhs, const Vector& rhs) { return { lhs.x + rhs.x, lhs.y + rhs.y }; }
Vector operator-(const Vector& lhs, const Vector& rhs) { return { lhs.x - rhs.x, lhs.y - rhs.y }; }
Vector operator*(double lhs, const Vector& rhs) { return { lhs * rhs.x, lhs * rhs.y }; }
Vector operator*(const Vector& lhs, double rhs) { return { lhs.x * rhs, lhs.y * rhs }; }

double distance(const Vector& p1, const Vector& p2){
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double area(const Vector& v, const Vector& u){
    return std::abs(v.x * u.y - u.x * v.y) * 0.5;
}


std::pair<Vector, Vector> intersect(const Circle& c1, const Circle& c2){
    Vector p0(c1.x, c1.y);
    Vector p1(c2.x, c2.y);

    double d = distance(p0, p1);
    double a = ((c1.r * c1.r) - (c2.r  * c2.r) + (d * d)) / (2 * d);
    double h = std::sqrt(c1.r * c1.r - a * a);

    Vector p2 = p0 + (a / d) * (p1 - p0);

    Vector p3 = { p2.x + h * (p1.y - p0.y) / d, p2.y - h * (p1.x - p0.x) / d };
    Vector p4 = { p2.x - h * (p1.y - p0.y) / d, p2.y + h * (p1.x - p0.x) / d };
    return { p3, p4 };
}

Vector intersect(const Circle& c1, const Circle& c2, const Circle& c3){
    auto points = intersect(c1, c2);
    Vector p;
    if(distance({c3.x, c3.y}, points.first) <= c3.r){
        p = points.first;
    } else if(distance({c3.x, c3.y}, points.second) <= c3.r){
        p = points.second;
    }
    return p;
}

double commonArea(const Circle& c1, const Circle& c2, const Circle& c3){
    Vector p1, p2, p3;
    p1 = intersect(c1, c2, c3);
    p2 = intersect(c2, c3, c1);
    p3 = intersect(c3, c1, c2);

    return area(p2 - p1, p3 - p1);
}




int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    int t;
    in >> t;
    out << std::fixed << std::setprecision(2);
    while(t--){
        Circle c1, c2, c3;
        
        in >> c1.x >> c1.y >> c1.r
            >> c2.x >> c2.y >> c2.r
            >> c3.x >> c3.y >> c3.r;
        
        out << commonArea(c1, c2, c3) << '\n';
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}