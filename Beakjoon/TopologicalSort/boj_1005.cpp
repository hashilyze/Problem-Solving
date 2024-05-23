// Beakjoon 1005 - ACM Craft
// https://www.acmicpc.net/problem/1005

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 1'000;
// variables
int n, k;
ivec adj[MAX_N];
int delay[MAX_N];
bool isVisited[MAX_N];


void dfs(int u, ivec &result){
    if(isVisited[u]) return;
    isVisited[u] = true;

    for(int v : adj[u]) dfs(v, result);
    result.push_back(u);
}
void topologicalSort(ivec &result){
    for(int i = 0; i < n; ++i) dfs(i, result);
    std::reverse(result.begin(), result.end());
}

int solve(int w){
    ivec sorted;
    topologicalSort(sorted);

    int pathDelay[MAX_N] = { 0, };
    for(int i = 0; i < n; ++i){
        int u = sorted[i];
        pathDelay[u] += delay[u];
        if(u == w) return pathDelay[w];
        for(int v : adj[u]){
            pathDelay[v] = std::max(pathDelay[v], pathDelay[u]);
        }
    }
    return -1;
}


int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        // init
        for(int i = 0; i < n; ++i) adj[i].clear();
        std::memset(isVisited, 0x00, sizeof(isVisited));
        // input
        std::cin >> n >> k;
        for(int i = 0; i < n; ++i) std::cin >> delay[i];

        for(int i = 0; i < k; ++i){
            int u, v;
            std::cin >> u >> v;
            adj[u - 1].push_back(v - 1);
        }
        int w;
        std::cin >> w;
        // solve
        int total = solve(w - 1);
        // output
        std::cout << total << '\n';
    }
    

    return 0;
}