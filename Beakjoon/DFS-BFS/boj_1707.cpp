// Beakjoon 1707 - 이분 그래프
// https://www.acmicpc.net/problem/1707

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_V = 20'000;
constexpr int MAX_E = 200'000;
// variables
int k, v, e;
std::vector<int> adj[MAX_V + 1];
int isVisited[MAX_V + 1];


bool isBipartie(){
    std::memset(isVisited, 0xFF, sizeof(isVisited));

    std::queue<int> q;
    for(int i = 1; i <= v; ++i){
        if(isVisited[i] >= 0) continue;
        q.push(i);
        isVisited[1] = 0;
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            int next = (isVisited[u] + 1) % 2;
            
            for(int v : adj[u]){
                if(isVisited[v] >= 0 && isVisited[v] != next) return false;
                if(isVisited[v] != -1) continue;
                isVisited[v] = next;
                q.push(v);
            }
        }
    }

    return true;
}

int main(void){
    FASTIO

    std::cin >> k;
    while(k--){
        std::cin >> v >> e;
        for(int i = 1; i <= v; ++i) adj[i].clear();

        for(int i = 0; i < e; ++i){
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::cout << (isBipartie() ? "YES\n" : "NO\n");
    }
    

    return 0;
}