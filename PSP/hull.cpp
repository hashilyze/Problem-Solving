// 문제해결 기법 과제-8

#include <iostream>
#include <fstream>
#include <string>

// === File Control ====
#define ONLINE_JUDGE
const std::string FILE_NAME = "hull";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";


// === Solution ====
// class
struct Vector2{
    Vector2() = default;
    Vector2(int _x, int _y) : x(_x), y(_y) { }
    Vector2 operator-(const Vector2& rhs) { return Vector2(this->x - rhs.x, this->y - rhs.y); }

    int x, y;
};
// constants
constexpr int MAX_N = 20000;
// variables
int n, m;
Vector2 points[MAX_N];
int hull[MAX_N];

int direction(int p1, int p2, int p3){
    Vector2 v1 = points[p2] - points[p1];
    Vector2 v2 = points[p3] - points[p2];
    return v1.x * v2.y - v1.y * v2.x;
}
int dot(int p1, int p2, int p3){
    Vector2 v1 = points[p2] - points[p1];
    Vector2 v2 = points[p3] - points[p2];
    return v1.x * v2.x + v1.y + v2.y;
}

void makeConvexHull(int start){
    int prev = start;
    int next = -1;
    while(next != start){
        hull[m++] = prev;
        next = (prev + 1) % n;
        for(int i = 0; i < n; ++i){
            if(direction(prev, next, i) < 0){
                next = i;
            }
        }
        prev = next;
    }
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
    in >> n;
    for(int i = 0; i < n; ++i) in >> points[i].x >> points[i].y;

    int start = 0;
    for(int i = 1; i < n; ++i){
        if(points[i].x < points[start].x){
            start = i;
        } else if(points[i].x == points[start].x && points[i].y < points[start].y){
            start = i;
        }
    }
    makeConvexHull(start);
    

    out << m << '\n';
    for(int i = 0; i < m; ++i) {
        out << points[hull[i]].x << " " 
            << points[hull[i]].y << "\n";
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}