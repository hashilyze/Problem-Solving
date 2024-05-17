// Beakjoon 11375 - 열혈강호
// https://www.acmicpc.net/problem/11375

#include <iostream>
#include <cstring>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;
// variables
int n, m;
std::vector<int> rGraph[MAX_N];
bool isVisited[MAX_N];
int lMatched[MAX_M], rMatched[MAX_M];


bool dfs(int u){
    if(isVisited[u]) return false;
    isVisited[u] = true;

    for(int v : rGraph[u]){
        if(rMatched[v] == -1 || dfs(rMatched[v])){
            lMatched[u] = v;
            rMatched[v] = u;
            return true;
        }
    }
    return false;
}

int bpm(){
    std::memset(lMatched, 0xFF, sizeof(lMatched));
    std::memset(rMatched, 0xFF, sizeof(rMatched));

    int cnt = 0;
    for(int u = 0; u < n; ++u){
        std::memset(isVisited, 0x00, sizeof(isVisited));
        if(dfs(u)) ++cnt;
    }
    return cnt;
}

int main(void){
    FASTIO

    std::cin >> n >> m;
    for(int u = 0; u < n; ++u){
        int l; std::cin >> l; rGraph[u].reserve(l);
        for(int i = 0; i < l; ++i) {
            int v; std::cin >> v;
            rGraph[u].push_back(v - 1);
        }
    }
    std::cout << bpm() << '\n';

    return 0;
}