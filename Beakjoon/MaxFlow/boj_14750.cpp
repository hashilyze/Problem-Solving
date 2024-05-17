// Beakjoon 14750 - Jerry and Tom
// https://www.acmicpc.net/problem/14750

#include <iostream>
#include <cstring>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;

struct Vec{
    Vec() = default;
    Vec(int x, int y) : x(x), y(y) { }
    int x, y;
};
ll cross(const Vec &lhs, const Vec &rhs) { return (ll)lhs.x * rhs.y - (ll)lhs.y * rhs.x; }
ll cross(const Vec &p1, const Vec &p2, const Vec &p3) { 
    return cross({ p2.x - p1.x, p2.y - p1.y }, { p3.x - p2.x, p3.y - p2.y });
}
int direction(const Vec &p1, const Vec &p2, const Vec &p3){
    ll v = cross(p1, p2, p3);
    if(v < 0) return -1;
    else if(v > 0) return 1;
    return 0;
}
bool isIntersect(const Vec &a, const Vec &b, const Vec &c, const Vec &d){
    return direction(c, b, d) != 0 // hole not on edge
        && direction(a, b, c) * direction(a, b, d) <= 0
        && direction(c, d, a) * direction(c, d, b) <= 0;
}

// constants
constexpr int MAX_N = 1000;
constexpr int MAX_K = 5;
constexpr int MAX_H = 50;
constexpr int MAX_M = MAX_K * MAX_H;
// variables
int n, k, h, m;
Vec room[MAX_N];
Vec holes[MAX_H];
Vec mouses[MAX_M];

int rGraph[MAX_M + MAX_H + 2][MAX_M + MAX_H + 2];
int parents[MAX_M + MAX_H + 2];


bool bfs(int s, int t){
    std::memset(parents, 0xFF, sizeof(parents));

    std::queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(int v = 0; v < m + h + 2; ++v){
            if((v != s && parents[v] == -1) && rGraph[u][v] > 0){
                q.push(v);
                parents[v] = u;
                if(v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}
int maxflow(int s, int t){
    int mf = 0;
    while(bfs(s, t)){
        static constexpr int f = 1;
        mf += f;

        int v = t;
        while(parents[v] != -1){
            rGraph[parents[v]][v] -= f;
            rGraph[v][parents[v]] += f;
            v = parents[v];
        }
    }
    return mf;
}


void initGraph(){
    for(int i = 0; i < m; ++i){
        const Vec &mouse = mouses[i];
        for(int j = 0; j < h; ++j){
            const Vec &hole = holes[j];

            bool pass = true;
            for(int k = 0; k < n; ++k){
                const Vec &p1 = room[k], &p2 = room[(k + 1) % n];
                if(isIntersect(mouse, hole, p1, p2)){
                   pass = false;
                   break; 
                }
            }

            if(pass) rGraph[i + 1][j + m + 1] = 1;
        }
    }
    for(int i = 1; i <= m; ++i) rGraph[0][i] = 1;
    for(int i = 1; i <= h; ++i) rGraph[m + i][m + h + 1] = k;
}

int main(void){
    FASTIO

    std::cin >> n >> k >> h >> m;
    for(int i = 0; i < n; ++i) std::cin >> room[i].x >> room[i].y;
    for(int i = 0; i < h; ++i) std::cin >> holes[i].x >> holes[i].y;
    for(int i = 0; i < m; ++i) std::cin >> mouses[i].x >> mouses[i].y;
    initGraph();
    std::cout << (maxflow(0, m + h + 1) == m ? "Possible\n" : "Impossible\n");

    return 0;
}