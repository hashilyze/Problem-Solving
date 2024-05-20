// Beakjoon 2606번 - 바이러스
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100;
// variables
int n, m;
bool isVisited[MAX_N];
std::vector<int> adj[MAX_N];

int bfs(int s){
    int cnt = -1;
    std::queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(isVisited[u]) continue;
        isVisited[u] = true;
        ++cnt;
        
        for(int v : adj[u]) q.push(v);
    }

    return cnt;
}

int main(void){
    FASTIO
    
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i) adj[i].reserve(n - 1);
    
    while(m--){
        int u, v;
        std::cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    std::cout << bfs(0) << '\n';
    

    return 0;
}