// 문제해결 기법 과제-9

#include <iostream>
#include <fstream>
#include <string>

// === File Control ====
const std::string FILE_NAME = "parallelogram";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";


// === Solution ====
using ll = long long;
struct Vector2{
    Vector2() : x(0), y(0) { }
    Vector2(ll _x, ll _y) : x(_x), y(_y) { }

    Vector2 operator+(const Vector2& rhs) { return Vector2(this->x + rhs.x, this->y + rhs.y); }
    Vector2 operator-(const Vector2& rhs) { return Vector2(this->x - rhs.x, this->y - rhs.y); }
    bool operator==(const Vector2& rhs) { return this->x == rhs.x && this->y == rhs.y; }

    ll x;
    ll y;
};
// constants
constexpr int SIZE = 4;
// variables
Vector2 points[SIZE];
// functions
int solution(){
    Vector2 vec[SIZE - 1];
    for(int i = 1; i < SIZE; ++i){
        vec[i - 1] = points[i] - points[0];
    }
    if(vec[0] + vec[1] == vec[2]
        || vec[1] + vec[2] == vec[0]
        || vec[2] + vec[0] == vec[1]
    ) return 1;
    else return 0;
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
    while(true){
        bool exit = true;
        for(int i = 0; i < SIZE; ++i){
            in >> points[i].x >> points[i].y;
            if(points[i].x || points[i].y) exit = false;
        }
        if(exit) break;

        out << solution() << '\n';
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}