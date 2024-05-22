// Beakjoon 2252 - 줄 세우기
// https://www.acmicpc.net/problem/2252

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 32'000;
constexpr int MAX_M = 100'000;
// variables
int n, m;
std::vector<int> adj[MAX_N + 1];
int indegree[MAX_N + 1];
bool isVisited[MAX_N + 1];
std::vector<int> sorted;

void dfs(int u){
    isVisited[u] = true;
    for(int v : adj[u]){
        if(isVisited[v]) continue;
        dfs(v);
    }
    sorted.push_back(u);
}

void topologicalSort(){
    std::memset(isVisited, 0x00, sizeof(isVisited));
    for(int v = 1; v <= n; ++v){
        if(isVisited[v] || indegree[v] > 0) continue;
        dfs(v);
    }
    std::reverse(sorted.begin(), sorted.end());
}

int main(void){
    FASTIO

    std::cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        indegree[v] += 1;
    }

    topologicalSort();

    for(int elem : sorted) std::cout << elem << ' ';
    std::cout << '\n';

    return 0;
}