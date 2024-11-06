// Beakjoon 16928 - 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100;
// variables
int n, m;
int parents[MAX_N + 1];
int ladderOrSnake[MAX_N + 1];


void bfs(int s, int t){
    std::memset(parents, 0xFF, sizeof(parents));

    std::queue<int> q;
    q.push(s);
    parents[s] = s;

    while(!q.empty()){
        int u = q.front(); q.pop();

        int next[] = { 
            u + 1, u + 2, 
            u + 3, u + 4, 
            u + 5, u + 6
        };
        for(int v : next){
            if(v <= 0 || 100 < v) continue;

            if(ladderOrSnake[v] != 0) v = ladderOrSnake[v];
            if(parents[v] != -1) continue;

            parents[v] = u;
            if(v == t) return;
            q.push(v);
        }
    }
}
int pathLength(int s, int t){
    int cnt = 0;
    int v = t;
    while(v != s){
        v = parents[v];
        ++cnt;
    }
    return cnt;
}

int main(void){
    FASTIO
    
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int from, to;
        std::cin >> from >> to;
        ladderOrSnake[from] = to;
    }
    for(int i = 0; i < m; ++i) {
        int from, to;
        std::cin >> from >> to;
        ladderOrSnake[from] = to;
    }

    bfs(1, 100);
    std::cout << pathLength(1, 100) << '\n';

    return 0;
}