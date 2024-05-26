// Beakjoon 14567 - 선수과목
// https://www.acmicpc.net/problem/14567


#include <algorithm>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 1'000;
// variables
int N, M;
ivec adj[MAX_N + 1];
int depth[MAX_N + 1];
ivec sorted;


void dfs(int u){
    depth[u] = 1;
    for(int v : adj[u]) {
        if(depth[v] != 0) continue;
        dfs(v);
    }
    sorted.push_back(u);
}
void topologicalSort(){
    for(int u = 1; u <= N; ++u){
        if(depth[u] != 0) continue;
        dfs(u);
    }
    std::reverse(sorted.begin(), sorted.end());
}

void solve(){
    topologicalSort();
    for(int u : sorted){
        for(int v : adj[u]){
            depth[v] = std::max(depth[v], depth[u] + 1);
        }
        
    }
}

int main(void){
    FASTIO

    std::cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    solve();
    for(int i = 1; i <= N; ++i){
        std::cout << depth[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}