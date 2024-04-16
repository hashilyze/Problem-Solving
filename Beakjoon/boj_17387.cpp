// Beakjoon 17387번 - 선분교차 2
// https://www.acmicpc.net/problem/17387

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;

struct Vector2{
    Vector2() = default;
    Vector2(ll _x, ll _y) : x(_x), y(_y) { };
    bool operator <=(const Vector2& rhs) {
        if(this->x == rhs.x) return this->y <= rhs.y;
        return this->x <= rhs.x;
    }

    ll x, y;
};

ll cross(const Vector2& lhs, const Vector2& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }
ll cross(const Vector2& p1, const Vector2& p2, const Vector2& p3) { 
    return cross({ p2.x - p1.x, p2.y - p1.y}, {p3.x - p1.x, p3.y - p1.y });
}
ll direction(const Vector2& p1, const Vector2& p2, const Vector2& p3){
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
    
    ll ret1 = direction(a, b, c) * direction(a, b, d);
    ll ret2 = direction(c, d, a) * direction(c, d, b);

    if(ret1 <= 0 && ret2 <= 0){
        if(ret1 == 0 && ret2 == 0){
            if(b <= a) std::swap(a, b);
            if(d <= c) std::swap(c, d);
            if(a <= d && c <= b){
                std::cout << 1 << '\n';
                return 0;
            }
        } else{
            std::cout << 1 << '\n';
            return 0;
        }
    }
    std::cout << 0 << '\n';

    return 0;
}