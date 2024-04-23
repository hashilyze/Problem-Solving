#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// === File Control ====
const std::string FILE_NAME = "point";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;

// === Vector ===
struct Vector2{
    Vector2() = default;
    Vector2(ll _x, ll _y) : x(_x), y(_y) { };
    // bool operator <=(const Vector2& rhs) {
    //     if(this->x == rhs.x) return this->y <= rhs.y;
    //     return this->x <= rhs.x;
    // }

    ll x, y;
};
// arithmetic
Vector2 operator+(const Vector2& lhs, const Vector2& rhs) { return { lhs.x + rhs.x, lhs.y + rhs.y }; }
Vector2 operator-(const Vector2& lhs, const Vector2& rhs) { return { lhs.x - rhs.x, lhs.y - rhs.y }; }
Vector2 operator*(int scalar, const Vector2& vector) { return { scalar * vector.x, scalar * vector.y }; }
Vector2 operator*(const Vector2& vector, int scalar) { return scalar * vector; }
// arithmetic-assign
Vector2& operator+=(Vector2& lhs, const Vector2& rhs) { lhs.x += rhs.x; lhs.y += rhs.y;  return lhs; }
Vector2& operator-=(Vector2& lhs, const Vector2& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y;  return lhs; }
Vector2& operator*=(Vector2& vector, int scalar) { vector.x *= scalar; vector.y *= scalar;  return vector; }
// compare
bool operator <(const Vector2& lhs, const Vector2& rhs) { return (lhs.x != rhs.x) ? lhs.x < rhs.x : lhs.y < rhs.y; }
bool operator <=(const Vector2& lhs, const Vector2& rhs) { return (lhs.x != rhs.x) ? lhs.x <= rhs.x : lhs.y <= rhs.y; }
bool operator >(const Vector2& lhs, const Vector2& rhs) { return (lhs.x != rhs.x) ? lhs.x > rhs.x : lhs.y > rhs.y; }
bool operator >=(const Vector2& lhs, const Vector2& rhs) { return (lhs.x != rhs.x) ? lhs.x >= rhs.x : lhs.y >= rhs.y; }
// cross
ll cross(const Vector2& lhs, const Vector2& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }
ll cross(const Vector2& p1, const Vector2& p2, const Vector2& p3) { return cross(p2 - p1, p3 - p1); }

ll direction(const Vector2& p1, const Vector2& p2, const Vector2& p3){
    ll v = cross(p1, p2, p3);
    if(v < 0) return -1;
    else if(v > 0) return 1;
    return 0;
}
ll sqrDist(const Vector2 &p1, const Vector2 &p2){
    Vector2 v1 = p2 - p1;
    return v1.x * v1.x + v1.y * v1.y;
}

bool isIntersect(Vector2 a, Vector2 b, Vector2 c, Vector2 d){
    ll ret1 = direction(a, b, c) * direction(a, b, d);
    ll ret2 = direction(c, d, a) * direction(c, d, b);

    if(ret1 == 0 && ret2 == 0){
        if(b <= a) std::swap(a, b);
        if(d <= c) std::swap(c, d);
        return a <= d && c <= b;
    }
    return ret1 <= 0 && ret2 <= 0;
}

int getConvexHull(int n, Vector2* points, int* convex){
    int start = std::min_element(points, points + n) - points;
    int prev = start;
    int next = -1;
    
    int k = 0;
    while(next != start){
        convex[k++] = prev;

        next = prev != 0 ? 0 : 1;
        for(int  i = 0; i < n; ++i){
            if(i != prev && i != next){
                ll ccw = cross(points[prev], points[next], points[i]);
                if(ccw < 0 || ccw == 0 && sqrDist(points[prev], points[next]) < sqrDist(points[prev], points[i])){
                    next = i;
                }
            }
        }
        prev = next;
    }
    return k;
}


// variables
Vector2 p[4];
int c[4];

int solution(){
    if(isIntersect(p[0], p[1], p[2], p[3]) || isIntersect(p[0], p[3], p[1], p[2])) return 1;
    int k = getConvexHull(4, p, c);
    if(k == 4) return 3;
    return 2;
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

    while(t--){
        for(int i = 0; i < 4; ++i) in >> p[i].x >> p[i].y;
        out << solution() << '\n';
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}