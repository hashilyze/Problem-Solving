// Beakjoon 7562 - 나이트의 이동
// https://www.acmicpc.net/problem/7562

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
constexpr int MAX_L = 300;
// variables
int l;
pii parents[MAX_L][MAX_L];


void bfs(const pii &s, const pii &t){
    std::memset(parents, 0xFF, sizeof(parents));

    std::queue<pii> q;
    q.push(s);
    parents[s.second][s.first] = s;
    while(!q.empty()){
        pii u = q.front(); q.pop();
        pii offsets[] ={
            {1, 2},
            {1, -2},
            {-1, 2},
            {-1, -2},
            {2, 1},
            {2, -1},
            {-2, 1},
            {-2, -1},
        };
        
        for(const pii &off : offsets){
            pii v = {u.first + off.first, u.second + off.second};
            if(v.first < 0 || l <= v.first || v.second < 0 || l <= v.second) continue;
            if(parents[v.second][v.first].first != -1) continue;

            parents[v.second][v.first] = u;
            if(v == t) return;
            q.push(v);
        }
    }
}
int pathLength(const pii &s, const pii &t){
    int cnt = 0;
    pii v = t;
    while(parents[v.second][v.first] != v){
        ++cnt;
        v = parents[v.second][v.first];
    }
    return cnt;
}

int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        std::cin >> l;
        
        pii s, t;
        std::cin >> s.first >> s.second
            >> t.first >> t.second;
        bfs(s, t);
        std::cout << pathLength(s, t) << '\n';
    }

    return 0;
}