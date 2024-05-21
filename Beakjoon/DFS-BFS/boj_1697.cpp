// Beakjoon 1697 - 숨바꼭질
// https://www.acmicpc.net/problem/1697

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100'001;
// variables
int parents[MAX_N];


void bfs(int s, int t){
    std::queue<int> q;
    q.push(s);
    parents[s] = s;

    while(!q.empty()){
        int u = q.front(); q.pop();
        
        int next[] = {  u - 1, u + 1, 2 * u };
        for(int v : next){
            if(v < 0 || MAX_N <= v) continue;
            if(parents[v] != -1) continue;

            parents[v] = u;
            if(v == t) return;
            q.push(v);
        }
    }
}


int main(void){
    FASTIO

    std::memset(parents, 0xFF, sizeof(parents));

    int s, t;
    std::cin >> s >> t;

    bfs(s, t);
    
    int cnt = 0;
    int v = t;
    while(parents[v] != v){
        ++cnt;
        v = parents[v];
    }
    std::cout << cnt << '\n';

    return 0;
}