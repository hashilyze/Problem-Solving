// Beakjoon 2056 - 작업
// https://www.acmicpc.net/problem/2056

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 10'000;
// variables
int n;
ivec adj[MAX_N + 1];
bool isVisited[MAX_N + 1];

int workTime[MAX_N + 1];
int totalWorkTime[MAX_N + 1];

void dfs(int u, ivec &result){
    isVisited[u] = true;

    for(int v : adj[u]){
        if(isVisited[v]) continue;
        dfs(v, result);
    }
    result.push_back(u);
}

void topologicalSort(ivec &result){
    for(int u = 1; u <= n; ++u){
        if(isVisited[u]) continue;
        dfs(u, result);
    }
    std::reverse(result.begin(), result.end());
}

int solve(){
    ivec result;
    topologicalSort(result);

    for(int u : result){
        totalWorkTime[u] += workTime[u];
        for(int v : adj[u]){
            totalWorkTime[v] = std::max(totalWorkTime[v], totalWorkTime[u]);
        }
    }
    return *std::max_element(totalWorkTime + 1, totalWorkTime + (n + 1));
}

int main(void){
    FASTIO
    
    std::cin >> n;
    for(int u = 1; u <= n; ++u){
        std::cin >> workTime[u];

        int m;
        std::cin >> m;
        while(m--){
            int v;
            std::cin >> v;
            adj[u].push_back(v);
        }
    }
    std::cout << solve() << '\n';

    return 0;
}