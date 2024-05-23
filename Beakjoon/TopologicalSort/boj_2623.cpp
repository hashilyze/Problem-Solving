// Beakjoon 2623 - 음악프로그램
// https://www.acmicpc.net/problem/2623

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 1'000;
// variables
int n, m;
ivec adj[MAX_N + 1];
int inDeg[MAX_N + 1];


void topologicalSort(ivec &result){
    std::queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(inDeg[i] > 0) continue;
        q.push(i);
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        result.push_back(u);

        for(int v : adj[u]){
            inDeg[v] -= 1;
            if(inDeg[v] == 0) q.push(v);
        }
    }
}

bool solve(ivec &result){
    topologicalSort(result);
    for(int i = 1; i <= n; ++i) {
        if(inDeg[i] > 0) return false;
    }
    return true;
}

int main(void){
    FASTIO
    
    std::cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int k, u, v;
        std::cin >> k >> u;
        for(int j = 1; j < k; ++j){
            std::cin >> v;
            adj[u].push_back(v);
            inDeg[v] += 1;
            u = v;
        }
    }
    ivec result;
    if(solve(result)){
        for(int v : result) std::cout << v << '\n';
    } else{
        std::cout << "0\n";
    }

    return 0;
}