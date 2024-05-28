// Beakjoon 4196 - 도미노
// https://www.acmicpc.net/problem/4196


#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 100'000;
// variables
int N, M;
ivec adj[MAX_N + 1];

int discoverd[MAX_N + 1];
bool finished[MAX_N + 1];
std::stack<int> s;
int sccCnt = 0;
int sccId[MAX_N + 1];
int inDeg[MAX_N + 1];

int dfs(int u, int &d){
    discoverd[u] = ++d;
    s.push(u);
    
    int min = discoverd[u];
    for(int v : adj[u]){
        if(discoverd[v] == 0){ 
            min = std::min(min, dfs(v, d));
        } else if(!finished[v]){
            min = std::min(min, discoverd[v]);
        }
    }

    if(discoverd[u] == min){ // make SCC
        ++sccCnt;
        while(true){
            int v = s.top(); s.pop();
            sccId[v] = sccCnt;
            finished[v] = true;
            if(u == v) break;
        }
    }
    return min;
}

void tarjan(){
    int d = 0;
    for(int u = 1; u <= N; ++u){
        if(discoverd[u] != 0) continue;
        dfs(u, d);
    }
}

void init(){
    sccCnt = 0;
    for(auto &vec : adj) vec.clear();
    std::memset(discoverd, 0x00, sizeof(discoverd));
    std::memset(finished, 0x00, sizeof(finished));
    std::memset(inDeg, 0x00, sizeof(inDeg));
}

int main(void){
    FASTIO
    
    int t;
    std::cin >> t;
    while(t--){
        init();

        std::cin >> N >> M;
        while(M--){
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
        }
        tarjan();
        for(int u = 1; u <= N; ++u){
            for(int v : adj[u]){
                if(sccId[u] == sccId[v]) continue;
                ++inDeg[sccId[v]];
            }
        }
        std::cout << std::count(&inDeg[1], &inDeg[sccCnt + 1], 0) << '\n';
    }

    return 0;
}