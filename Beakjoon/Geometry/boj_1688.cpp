// Beakjoon 1688 - 지민이의 테러
// https://www.acmicpc.net/problem/1688

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
using ll = long long;
// types
struct Vector2{
    Vector2() = default;
    Vector2(ll _x, ll _y) : x(_x), y(_y) { };

    ll x, y;
};
Vector2 operator+(const Vector2& lhs, const Vector2& rhs) { return { lhs.x + rhs.x , lhs.y + rhs.y }; }
Vector2 operator-(const Vector2& lhs, const Vector2& rhs) { return { lhs.x - rhs.x , lhs.y - rhs.y }; }

ll cross(const Vector2& lhs, const Vector2& rhs) { return lhs.x * rhs.y - rhs.x * lhs.y; }

// constants
constexpr int MAX_N = 10'000;
constexpr int MAX_M = 3;
// variables
int n;
Vector2 polygon[MAX_N];

bool between(const Vector2& edge1, const Vector2& edge2, const Vector2& target){
    if(cross(edge1 - target, edge2 - target) != 0) return false;
    if(edge1.x != edge2.x)
        return (edge1.x <= target.x && target.x <= edge2.x) 
        || (edge2.x <= target.x && target.x <= edge1.x);
    return (edge1.y <= target.y && target.y <= edge2.y) 
        || (edge2.y <= target.y && target.y <= edge1.y);
}

bool solution(const Vector2& target){
    bool inside = false;
    for(int i = 0; i < n; ++i){
        int j = (i + 1) % n;
        const Vector2 &p1 = polygon[i], &p2 = polygon[j];
        if(between(p1, p2, target)) return true;
        if(p1.y < target.y && target.y <= p2.y && cross(p2 - p1, target - p1) > 0
            || p2.y < target.y && target.y <= p1.y && cross(p1 - p2, target - p2) > 0
            ){
            inside = !inside;
        }
    }
    return inside;
}

int main(void){
    FASTIO

    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> polygon[i].x >> polygon[i].y;

    for(int i = 0; i < MAX_M; ++i){
        Vector2 target;
        std::cin >> target.x >> target.y;
        std::cout << (solution(target) ? 1 : 0) << '\n';
    }

    return 0;
}