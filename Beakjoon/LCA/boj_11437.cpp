// Beakjoon 11437 - LCA
// https://www.acmicpc.net/problem/11437


#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 50'000;
// variables
int n;
ivec adj[MAX_N + 1];

int depth[MAX_N + 1] = { -1, };
int parents[MAX_N + 1][16];
int maxLevel = (int)std::floor(std::log2(MAX_N));


void build(int u, int p){
    depth[u] = depth[p] + 1;
    parents[u][0] = p;
    
    for(int i = 1; i <= maxLevel; ++i){
        parents[u][i] = parents[parents[u][i - 1]][i - 1];
    }
    for(int v : adj[u]){
        if(v != p) {
            build(v, u);
        }
    }
}

int LCA(int u, int v){
    if(depth[u] != depth[v]){
        if(depth[u] > depth[v]) std::swap(u, v);

        int b = depth[v] - depth[u];
        for(int i = 0; i <= maxLevel; ++i){
            if((b >> i) & 1){
                v = parents[v][i];
            }
        }
    }

    int lca = u;
    if(u != v){
        for(int i = maxLevel; i >= 0; --i){ 
            if(parents[u][i] != parents[v][i]){
                u = parents[u][i];
                v = parents[v][i];
            }
        }
        lca = parents[u][0];
    }
    return lca;
}

int main(void){
    FASTIO

    int u, v;
    std::cin >> n;
    for(int i = 1; i < n; ++i){
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build(1, 0);

    int m;
    std::cin >> m;
    while(m--){
        std::cin >> u >> v;
        std::cout << LCA(u, v) << '\n';
    }

    return 0;
}