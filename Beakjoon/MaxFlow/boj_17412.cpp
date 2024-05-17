// Beakjoon 17412 - 도시 왕복하기(1)
// https://www.acmicpc.net/problem/17412

#include <iostream>
#include <cstring>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types

// constants
constexpr int MAX_N = 400;
constexpr int SOURCE = 0, SINK = 1;
// variables
int n, p;
int rGraph[MAX_N][MAX_N];
int parents[MAX_N];


bool bfs(int s, int t){
    std::memset(parents, 0xFF, sizeof(parents));

    std::queue<int> q;
    q.push(s);

    while(!q.empty()){
        int v1 = q.front(); q.pop();

        for(int v2 = 0; v2 < n; ++v2){
            if((v2 != s && parents[v2] == -1) && rGraph[v1][v2] > 0){
                q.push(v2);
                parents[v2] = v1;
                if(v2 == t) return true;
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

int main(void){
    FASTIO

    std::cin >> n >> p;
    for(int i = 0; i < p; ++i){
        int u, v;
        std::cin >> u >> v;
        rGraph[u - 1][v - 1] = 1;
    }
    std::cout << maxflow(SOURCE, SINK) << '\n';

    return 0;
}