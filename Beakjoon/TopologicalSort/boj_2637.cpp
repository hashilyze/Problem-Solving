// Beakjoon 2637 - 장난감 조립
// https://www.acmicpc.net/problem/2637


#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 100;
// variables
int N, M;
ivec adj[MAX_N + 1];
int inDeg[MAX_N + 1];

int parts[MAX_N + 1][MAX_N + 1];
int baseParts[MAX_N + 1][MAX_N + 1];
ivec sorted;


void topologicalSort(){
    std::queue<int> q;
    for(int u = 1; u <= N; ++u){
        if(inDeg[u] != 0) continue;
        q.push(u);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        sorted.push_back(u);
        for(int v : adj[u]){
            inDeg[v] -= 1;
            if(inDeg[v] == 0) q.push(v);
        }
    }
}

void solve(){
    for(int i = 1; i < N; ++i){
        if(inDeg[i] != 0) continue;
        baseParts[i][i] = 1;
    }
    topologicalSort();
    for(int u : sorted){
        for(int v : adj[u]){
            for(int i = 1; i < N; ++i){
                baseParts[v][i] += baseParts[u][i] * parts[v][u];
            }
        }
    }
}


int main(void){
    FASTIO

    std::cin >> N >> M;
    while(M--){
        int X, Y, K;
        std::cin >> X >> Y >> K;

        adj[Y].push_back(X);
        ++inDeg[X];
        parts[X][Y] = K;
    }
    solve();
    for(int i = 1; i < N; ++i){
        if(baseParts[N][i]){
            std::cout << i << ' ' << baseParts[N][i] << '\n';
        }
    }

    return 0;
}