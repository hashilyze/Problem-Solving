// Beakjoon 1260번 - DFS와 BFS
// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 1'000;
// variables
int n;
bool isVisited[MAX_N + 1];
std::vector<int> adj[MAX_N + 1];


void dfs(int s){
    if(isVisited[s]) return;
    isVisited[s] = true;

    std::cout << s << ' ';
    for(int v : adj[s]) dfs(v);
}
void bfs(int s){
    std::queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        if(isVisited[u]) continue;
        isVisited[u] = true;

        std::cout << u << ' ';
        for(int v : adj[u]) q.push(v);
    }
}


int main(void){
    FASTIO

    int m, s;
    std::cin >> n >> m >> s;

    while(m--){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) std::sort(adj[i].begin(), adj[i].end());

    // DFS
    dfs(s);
    std::cout << '\n';

    std::memset(isVisited, 0x00, sizeof(isVisited));
    // BFS
    bfs(s);
    std::cout << '\n';

    return 0;
}