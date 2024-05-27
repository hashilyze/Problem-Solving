// Beakjoon 9470 - Strahler 순서
// https://www.acmicpc.net/problem/9470


#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 1'000;
// variables
int K, N, M;
ivec adj[MAX_N + 1];
int inDeg[MAX_N + 1];
pii order[MAX_N + 1];


void kahn(){
    std::queue<int> q;
    for(int u = 1; u <= N; ++u) {
        if(inDeg[u] == 0) {
            q.push(u);
            order[u] = {1, 1};
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        if(order[u].second >= 2) order[u] = { order[u].first + 1, 1 };

        for(int v : adj[u]){
            if(order[v].first < order[u].first){
                order[v] = { order[u].first, 1 };
            } else if(order[v].first > order[u].first){
                // do nothing
            } else{
                ++order[v].second;
            }

            if(--inDeg[v] == 0){
                q.push(v);
            }
        }
    }

}


int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        std::memset(adj, 0x00, sizeof(adj));
        std::memset(inDeg, 0x00, sizeof(inDeg));
        std::memset(order, 0x00, sizeof(order));

        std::cin >> K >> N >> M;
        while(M--){
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            ++inDeg[v];
        }
        kahn();
        std::cout << K << ' ' << order[N].first << '\n';
    }


    return 0;
}