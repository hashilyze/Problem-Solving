// Beakjoon 2150 - Stronly Connected Component
// https://www.acmicpc.net/problem/2150

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
using ivec = std::vector<int>;
//constants
constexpr int MAX_N = 10'000;
// variables
int V, E;
ivec adj[MAX_N + 1];

int d = 0;
int discovered[MAX_N + 1];
bool isSCC[MAX_N + 1];
std::stack<int> st;

int scc(int u, std::vector<ivec> &result){
    discovered[u] = ++d;
    st.push(u);
    
    int min = discovered[u];
    for(int v : adj[u]){
        if(discovered[v] == -1){
            min = std::min(min, scc(v, result));
        } else if(!isSCC[v]){
            min = std::min(min, discovered[v]);
        }
    }
    if(min == discovered[u]){
        result.push_back(ivec());
        while(true){
            int v = st.top(); st.pop();
            result.back().push_back(v);
            isSCC[v] = true;
            if(u == v) break;
        }
    }
    return min;
}

void tarjan(std::vector<ivec> &result){
    std::memset(discovered, 0xFF, sizeof(discovered));
    std::memset(isSCC, 0x00, sizeof(isSCC));
    
    for(int u = 1; u <= V; ++u){
        if(discovered[u] == -1) scc(u, result);
    }
}

int main(void){
    FASTIO
    
    std::cin >> V >> E;
    for(int i = 0; i < E; ++i){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    std::vector<ivec> sccGroup;
    tarjan(sccGroup);

    for(auto& s : sccGroup){
        std::sort(s.begin(), s.end());
    }
    std::sort(sccGroup.begin(), sccGroup.end(), 
        [](const ivec& lhs, const ivec& rhs) { return lhs[0] < rhs[0]; });
    
    std::cout << sccGroup.size() << '\n';
    for(auto s : sccGroup){
        for(int v : s) std::cout << v << ' ';
        std::cout << "-1\n";
    }

    return 0;
}