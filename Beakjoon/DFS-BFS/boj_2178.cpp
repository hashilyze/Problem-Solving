// Beakjoon 2178 - 미로 탐색
// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int ,int>;
// constants
constexpr int MAX_N = 100;
constexpr int MAX_M = 100;

constexpr int EMPTY = -1;
constexpr int BLOCK = -2;
// variables
int n, m;
pii parents[MAX_N][MAX_M];


bool bfs(const pii &s, const pii &t){
    std::queue<pii> q;
    q.push(s);
    parents[s.second][s.first] = s;

    while(!q.empty()){
        pii u = q.front(); q.pop();
        
        static const pii offsets[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(const auto &off : offsets){
            pii v = {u.first + off.first, u.second + off.second}; 
            if(v.first < 0 || m <= v.first || v.second < 0 || n <= v.second) continue; // out_of_range
            if(parents[v.second][v.first].first != -1) continue; // visited or blocked
            parents[v.second][v.first] = u;
            if(v == t) return true;
            q.push(v);
        }
    }
    return false;
}

int main(void){
    FASTIO

    std::cin >> n >> m;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < m; ++x){
            char ch;
            std::cin >> ch;
            parents[y][x].first = ch == '1' ? EMPTY : BLOCK;
        }
    }

    bfs({0, 0}, {m - 1, n - 1});

    int cnt = 1;
    pii v = {m - 1, n - 1};
    while(parents[v.second][v.first] != v){
        ++cnt;
        v = parents[v.second][v.first];
    }
    std::cout << cnt << '\n';

    return 0;
}