#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


// === File Control ====
const std::string FILE_NAME = "triangle";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;

struct Vector2{
    Vector2() = default;
    Vector2(ll _x, ll _y) : x(_x), y(_y) { };

    ll x, y;
};
// arithmetic
Vector2 operator+(const Vector2& lhs, const Vector2& rhs) { return { lhs.x + rhs.x, lhs.y + rhs.y }; }
Vector2 operator-(const Vector2& lhs, const Vector2& rhs) { return { lhs.x - rhs.x, lhs.y - rhs.y }; }
Vector2 operator*(int scalar, const Vector2& vector) { return { scalar * vector.x, scalar * vector.y }; }
Vector2 operator*(const Vector2& vector, int scalar) { return scalar * vector; }

Vector2& operator+=(Vector2& lhs, const Vector2& rhs) { lhs.x += rhs.x; lhs.y += rhs.y;  return lhs; }
Vector2& operator-=(Vector2& lhs, const Vector2& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y;  return lhs; }
Vector2& operator*=(Vector2& vector, int scalar) { vector.x *= scalar; vector.y *= scalar;  return vector; }

ll sqrNorm(const Vector2& v) { return v.x * v.x + v.y * v.y; }

Vector2 p[3];
ll d[3];

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
        for(int i = 0; i < 3; ++i){
            in >> p[i].x >> p[i].y;
        }
        d[0] = sqrNorm(p[1] - p[0]);
        d[1] = sqrNorm(p[2] - p[1]);
        d[2] = sqrNorm(p[0] - p[2]);
        std::sort(d, d + 3);
        
        if(d[0] + d[1]  < d[2]){
            out << 2 << '\n';
        } else if(d[0] + d[1] > d[2]){
            out << 0 << '\n';
        } else{
            out << 1 << '\n';
        }
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}