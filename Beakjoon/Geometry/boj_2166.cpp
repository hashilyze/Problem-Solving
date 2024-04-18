// Beakjoon 2166번 - 다각형의 면적
// https://www.acmicpc.net/problem/2166

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
// constants
constexpr int MAX_N = 10'000;
// variables
int n;
Vector2 points[MAX_N];

ll cross(const Vector2& lhs, const Vector2& rhs) { return (ll)lhs.x * rhs.y - (ll)lhs.y * rhs.x; }
ll cross(const Vector2& p1, const Vector2& p2, const Vector2& p3) { 
    return cross({ p2.x - p1.x, p2.y - p1.y}, {p3.x - p2.x, p3.y - p2.y });
}


int main(void){
    FASTIO

    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> points[i].x >> points[i].y;

    ll area = 0LL;
    for(int i = 2; i < n; ++i) area += cross(points[0], points[i - 1], points[i]);
    area = std::abs(area);
    std::cout << (area / 2LL) << (area % 2LL ? ".5\n" : ".0\n");

    return 0;
}