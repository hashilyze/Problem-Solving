// Beakjoon 1708번 - 볼록 껍질

#include <iostream>


// === Solution ====
// type
using ll = long long;
// class
struct Vector2{
    Vector2() = default;
    Vector2(int _x, int _y) : x(_x), y(_y) { }
    Vector2 operator-(const Vector2& rhs) { return Vector2(this->x - rhs.x, this->y - rhs.y); }

    int x, y;
};
// constants
constexpr int MAX_N = 100'000;
// variables
int n, m;
Vector2 points[MAX_N];
int hull[MAX_N];

int direction(int p1, int p2, int p3){
    Vector2 v1 = points[p2] - points[p1];
    Vector2 v2 = points[p3] - points[p2];
    ll ret = (ll)v1.x * v2.y - (ll)v1.y * v2.x;
    if(ret < 0) return -1;
    else if(ret > 0) return 1;
    else return 0;
}
ll sqrDist(int p1, int p2){
    Vector2 v1 = points[p2] - points[p1];
    return (ll)v1.x * v1.x + (ll)v1.y * v1.y;
}

void makeConvexHull(int start){
    int prev = start;
    int next = -1;
    while(next != start){
        hull[m++] = prev;
        next = (prev + 1) % n;
        for(int i = 0; i < n; ++i){
            if(i != prev && i != next){
                if(direction(prev, next, i) < 0){
                    next = i;
                } else if(direction(prev, next, i) == 0
                    && sqrDist(prev, i) > sqrDist(prev, next)){
                    next = i;
                }
            }
        }
        prev = next;
    }
}

int main(void){
    std::istream& in = std::cin;
    std::ostream& out = std::cout;

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
    return 0;
}