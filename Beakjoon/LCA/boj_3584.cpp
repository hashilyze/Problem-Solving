// Beakjoon 3584 - 가장 가까운 공통 조상
// https://www.acmicpc.net/problem/3584


#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;

struct Node {
    Node() = default;
    Node(int p, int d) : parent(p), depth(d) { }
    int parent = -1;
    int depth = -1;
};
// constants
constexpr int MAX_N = 10'000;
// variables
int n;
ivec adj[MAX_N + 1];
Node nodes[MAX_N + 1];


int LCA(int u, int v){
    if(u == -1 || v == -1) return -1;

    const Node &nodeU = nodes[u], &nodeV = nodes[v];
    if(nodeU.depth < nodeV.depth){
        return LCA(u, nodeV.parent);
    } else if(nodeU.depth > nodeV.depth){
        return LCA(nodeU.parent, v);
    } else{
        if(u == v) return u;
        else return LCA(nodeU.parent, nodeV.parent);
    }
}


void dfs(int u, int d){
    for(int v : adj[u]) {
        nodes[v] = {u, d + 1};
        dfs(v, d + 1);
    }
}
void dfsAll(){
    for(int u = 1; u <= n; ++u) {
        if(nodes[u].depth == -1) {
            nodes[u] = {u, 1};
            dfs(u, 1);
        }
    }
}

int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        // init.
        for(auto &vec : adj) vec.clear();
        std::memset(nodes, 0xFF, sizeof(nodes));
        // input.
        std::cin >> n;
        int u, v;
        for(int i = 1; i < n; ++i){
            std::cin >> u >> v;
            adj[u].push_back(v);
        }
        dfsAll();
        // output.
        std::cin >> u >> v;
        int lca = LCA(u, v);
        std::cout << lca << '\n';
    }

    return 0;
}