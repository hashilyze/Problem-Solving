// Beakjoon 11280 - 2-SAT - 3
// https://www.acmicpc.net/problem/11280


#include <iostream>
#include <stack>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 10'000;
// variables
int N, M;
ivec adj[MAX_N * 2 + 1];

int discoverd[MAX_N * 2 + 1];
bool finished[MAX_N * 2 + 1];
std::stack<int> s;
int sccCnt = 0;
int sccId[MAX_N * 2 + 1];

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
            finished[v] = true;
            sccId[v] = sccCnt;
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

inline int getid(int u){ return u >= 0 ? u : -u + N; }

int main(void){
    FASTIO
    
    std::cin >> N >> M;
    while(M--){
        int u, v;
        std::cin >> u >> v;
        adj[getid(-u)].push_back(getid(v));
        adj[getid(-v)].push_back(getid(u));
    }
    tarjan();
    for(int u = 1; u <= N; ++u){
        if(sccId[getid(u)] == sccId[getid(-u)]) {
            std::cout << "0\n";
            return 0;
        }
    }
    std::cout << "1\n";
    return 0;
}