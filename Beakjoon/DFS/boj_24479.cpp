// Beakjoon 24479번 - 알고리즘 수업 - 깊이 우선 탐색 1
// https://www.acmicpc.net/problem/24479

#include <iostream>
#include <vector>
#include <algorithm>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100'000;
// variables
bool isVisited[MAX_N + 1];
std::vector<int> adj[MAX_N + 1];

int i = 0;
int seq[MAX_N + 1];


void dfs(int u){
    if(isVisited[u]) return;
    isVisited[u] = true;

    seq[u] = ++i;
    for(int v : adj[u]) dfs(v);
}


int main(void){
    FASTIO

    int n, m, r;
    std::cin >> n >> m >> r;

    for(int i = 0; i < m;++ i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n;++ i) {
        std::sort(adj[i].begin(), adj[i].end());
    }

    dfs(r);

    for(int i = 1; i <= n; ++i){
        std::cout << seq[i] << '\n';
    }

    return 0;
}