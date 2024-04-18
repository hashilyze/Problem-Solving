// Beakjoon 1708 - 볼록 껍질
// https://www.acmicpc.net/problem/1708

#include <iostream>
#include <vector>
#include <algorithm>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
using ll = long long;
// types
struct Vector2{
    Vector2() = default;
    Vector2(ll _x, ll _y) : x(_x), y(_y) { };
    
    bool operator<(const Vector2& rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; }
    Vector2 operator+(const Vector2& rhs) const { return { x + rhs.x , y + rhs.y }; }
    Vector2 operator-(const Vector2& rhs) const { return { x - rhs.x , y - rhs.y }; }

    ll x, y;
};
// constants
constexpr int MAX_N = 100'000;
// variables
int n;
Vector2 points[MAX_N];
int convex[MAX_N];

inline ll cross(const Vector2& v, const Vector2& u) { return v.x * u.y - u.x * v.y; }
inline ll cross(const Vector2& p1, const Vector2& p2, const Vector2& p3) { return cross(p2 - p1, p3 - p1); }

inline ll sqrNorm(const Vector2& p) { return p.x * p.x + p.y * p.y; }
inline ll sqrDist(const Vector2& p1, const Vector2& p2) { return sqrNorm(p2 - p1); }

int getConvexHull(){
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



int main(void){
    FASTIO
    
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> points[i].x >> points[i].y;

    int k = getConvexHull();
    std::cout << k << '\n';
    for(int i = 0; i < k; ++i) std::cout << points[convex[i]].x << ' ' << points[convex[i]].y << '\n';

    return 0;
}