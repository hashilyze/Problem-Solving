// Beakjoon 11758번 - CCW
// https://www.acmicpc.net/problem/11758

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
struct Vector2{
    Vector2() = default;
    Vector2(int _x, int _y) : x(_x), y(_y) { };

    int x, y;
};


int cross(const Vector2& lhs, const Vector2& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }


int main(void){
    FASTIO
    
    constexpr int n = 3;
    Vector2 p[n];
    for(int i = 0; i < n; ++i){
        std::cin >> p[i].x >> p[i].y;
    }
    int v = cross(
        { p[1].x - p[0].x, p[1].y - p[0].y},
        { p[2].x - p[1].x, p[2].y - p[1].y}
        );
    std::cout << (v == 0 ? 0 : (v > 0 ? 1 : -1)) << '\n';

    return 0;
}