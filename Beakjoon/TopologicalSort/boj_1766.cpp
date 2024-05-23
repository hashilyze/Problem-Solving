// Beakjoon 1766 - 문제집
// https://www.acmicpc.net/problem/1766

#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
using minHap = std::priority_queue<int, ivec, std::greater<int>>;
// constants
constexpr int MAX_N = 32'000;
// variables
int n, m;
ivec adj[MAX_N];
int inDeg[MAX_N];


void solve(ivec& result){
    minHap heap;
    for(int i = 0; i < n; ++i){
        if(inDeg[i] == 0){
            heap.push(i);
        }
    }
    
    while(!heap.empty()){
        int u = heap.top(); heap.pop();
        result.push_back(u);
        
        for(int v : adj[u]){
            inDeg[v] -= 1;
            if(inDeg[v] == 0){
                heap.push(v);
            }
        }
    }
}

int main(void){
    FASTIO
    
    std::cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        std::cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        inDeg[v - 1] += 1;
    }
    ivec result;
    solve(result);
    for(int v : result) std::cout << v + 1 << ' ';
    std::cout << '\n';

    return 0;
}