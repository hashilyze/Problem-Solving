// Beakjoon 17386번 - 선분교차 1
// https://www.acmicpc.net/problem/17386

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;

struct Vector2{
    Vector2() = default;
    Vector2(int _x, int _y) : x(_x), y(_y) { };

    int x, y;
};

ll cross(const Vector2& lhs, const Vector2& rhs) { return (ll)lhs.x * rhs.y - (ll)lhs.y * rhs.x; }
ll cross(const Vector2& p1, const Vector2& p2, const Vector2& p3) { 
    return cross({ p2.x - p1.x, p2.y - p1.y}, {p3.x - p2.x, p3.y - p2.y });
}
int direction(const Vector2& p1, const Vector2& p2, const Vector2& p3){
    ll v = cross(p1, p2, p3);
    if(v < 0) return -1;
    else if(v > 0) return 1;
    return 0;
}


int main(void){
    FASTIO

    Vector2 a, b, c, d;
    std::cin >> a.x >> a.y >> b.x >> b.y
        >> c.x >> c.y >> d.x >> d.y;
    
    if(direction(a, b, c) * direction(a, b, d) < 0 
        && direction(c, d, a) * direction(c, d, b) < 0) {
        std::cout << 1 << '\n';
    } else{
        std::cout << 0 << '\n';
    }


    return 0;
}