// Beakjoon 3665 - 최종 순위
// https://www.acmicpc.net/problem/3665


#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 500;
// variables
int N, M;
bool adj[MAX_N + 1][MAX_N + 1];
int inDeg[MAX_N + 1];
ivec sorted;

int rank[MAX_N];


int topologicalSort(){
    std::queue<int> q;
    for(int u = 1; u <= N; ++u) { // init.
        if(inDeg[u] == 0){
            q.push(u);
        }
    }
    
    while(!q.empty()){
        if(q.size() >= 2) return 1; 

        int u = q.front(); q.pop();
        sorted.push_back(u);
        for(int v = 1; v <= N; ++v){
            if(!adj[u][v])  continue;
            inDeg[v] -= 1;
            if(inDeg[v] == 0) q.push(v);
        }
    }
    
    if(sorted.size() != N) // cycle
        return 2; 
    return 0;
}

void solve(){
    int ret = topologicalSort();
    if(ret == 0){
        for(int v : sorted) std::cout << v << ' ';
        std::cout << '\n';
    } else if(ret == 1){
        std::cout << "?\n";
    } else {
        std::cout << "IMPOSSIBLE\n";
    }
    
}

int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        std::memset(adj, 0x00, sizeof(adj));
        std::memset(inDeg, 0x00, sizeof(inDeg));
        sorted.clear();

        std::cin >> N;
        for(int i = 0; i < N; ++i) std::cin >> rank[i];
        for(int i = 0; i < N; ++i){
            int u = rank[i];
            for(int j = i + 1; j < N; ++j){
                int v = rank[j];
                adj[u][v] = 1;
                inDeg[v] += 1;
            }
        }

        std::cin >> M;
        while(M--){
            int u, v;
            std::cin >> u >> v;
            std::swap(adj[u][v], adj[v][u]);
            if(adj[u][v]){
                inDeg[v] += 1;
                inDeg[u] -= 1;
            } else{
                inDeg[v] -= 1;
                inDeg[u] += 1;
            }
        }
        solve();
    }

    return 0;
}