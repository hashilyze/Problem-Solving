// Beakjoon 1948 - 임계경로
// https://www.acmicpc.net/problem/1948


#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
using piib = std::tuple<int, int, bool>;
using piivec = std::vector<pii>;
using piibvec = std::vector<piib>;
// constants
constexpr int MAX_N = 10'000;
// variables
int N, M;
piivec adj[MAX_N + 1];
piibvec tAdj[MAX_N + 1];
int inDeg[MAX_N + 1];
int arrived[MAX_N + 1];


void kahn(){
    std::queue<int> q;
    for(int u = 1; u <= N; ++u) {
        if(inDeg[u] == 0){
            q.push(u);
        }
    }
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(const pii &p : adj[u]){
            int v, t;
            std::tie(v, t) = p;
            arrived[v] = std::max(arrived[v], arrived[u] + t);
            if(--inDeg[v] == 0){
                q.push(v);
            }
        }
    }
}

int countEdge(int u, int a){
    int cnt = 0;
    for(piib &p : tAdj[u]){
        int v, t, b;
        std::tie(v, t, b) = p;
        if(arrived[v] + t == a && !b){
            cnt += countEdge(v, a - t) + 1;
            std::get<2>(p) = true;
        }
    }
    return cnt;
}

int main(void){
    FASTIO
    
    std::cin >> N >> M;
    while(M--){
        int u, v, t;
        std::cin >> u >> v >> t;
        adj[u].push_back({v, t});
        tAdj[v].push_back({u, t, 0});
        ++inDeg[v];
    }
    kahn();

    int s, t;
    std::cin >> s >> t;
    std::cout << arrived[t] << '\n';
    std::cout << countEdge(t, arrived[t]) << '\n';


    return 0;
}