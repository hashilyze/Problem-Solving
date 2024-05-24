// Beakjoon 3584 - 가장 가까운 공통 조상
// https://www.acmicpc.net/problem/3584


#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 10'000;
const int MAX_LEVEL = std::floor(std::log2(MAX_N)) + 0.1;
// variables
int n;
ivec graph[MAX_N + 1];
int depth[MAX_N + 1] = { -1, };
int parents[MAX_N + 1][20];


void build(int u, int p){
    depth[u] = depth[p] + 1;
    parents[u][0] = p;
    
    for(int i = 1; i <= MAX_LEVEL; ++i){
        parents[u][i] = parents[parents[u][i - 1]][i - 1];
    }
    for(int v : graph[u]){
        build(v, u);
    }
}

int LCA(int u, int v){
    if(depth[u] != depth[v]){
        if(depth[u] > depth[v]) std::swap(u, v);
        int b = depth[v] - depth[u];
        for(int i = 0; i <= MAX_LEVEL; ++i){
            if((b >> i) & 1){
                v = parents[v][i];
            }
        }
    }

    int lca = u;
    if(u != v){
        for(int i = MAX_LEVEL; i >= 0; --i){
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

    int t;
    std::cin >> t;
    while(t--){
        std::memset(depth, 0x00, sizeof(depth)); depth[0] = -1;
        std::memset(parents, 0x00, sizeof(parents));
        for(int i = 1; i <= MAX_N; ++i) graph[i].clear();

        int u, v;
        std::cin >> n;
        for(int i = 1; i < n; ++i){
            std::cin >> u >> v;
            graph[u].push_back(v);
            parents[v][0] = u;
        }
        for(int i = 1; i <= MAX_N; ++i){
            if(parents[i][0] == 0){
                build(i, 0);
                break;
            }
        }
        
        std::cin >> u >> v;
        std::cout << LCA(u, v) << '\n';
    }

    return 0;
}