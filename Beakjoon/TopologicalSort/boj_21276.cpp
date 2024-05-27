// Beakjoon 21276 - 계보 복원가 호석
// https://www.acmicpc.net/problem/21276


#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 1'000;
// variables
int N, M;
ivec adj[MAX_N];
int inDeg[MAX_N];
int depth[MAX_N];
std::string id2Name[MAX_N];
std::unordered_map<std::string, int> name2Id;


void kahn(){
    std::queue<int> q;
    for(int u = 0; u < N; ++u) {
        if(inDeg[u] == 0){
            q.push(u);
            depth[u] = 1;
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            depth[v] = std::max(depth[u] + 1, depth[v]);
            if(--inDeg[v] == 0){
                q.push(v);
            }
        }
    }
}

int main(void){
    FASTIO
    
    // input: names
    std::cin >> N;
    for(int i = 0; i < N; ++i) std::cin >> id2Name[i];
    std::sort(id2Name, id2Name + N);
    for(int i = 0; i < N; ++i) name2Id.insert({id2Name[i], i});

    // input: pedigree
    std::cin >> M;
    while(M--){
        std::string nameX, nameY;
        std::cin >> nameX >> nameY;

        int X = name2Id[nameX], Y = name2Id[nameY];
        adj[Y].push_back(X);
        ++inDeg[X];
    }
    for(int i = 0; i < N; ++i) std::sort(adj[i].begin(), adj[i].end());

    kahn();

    // output: progenitor
    std::cout << std::count(depth, depth + N, 1) << '\n';
    for(int i = 0; i < N; ++i) {
        if(depth[i] != 1) continue;
        std::cout << id2Name[i] << ' ';
    }
    std::cout << '\n';

    // output: parent-child
    for(int i = 0; i < N; ++i) {
        int u = name2Id[id2Name[i]];
        std::cout << id2Name[i] << ' ';

        int cnt = std::count_if(
            adj[u].begin(), adj[u].end(), [&u](int v) {
            return depth[v] - 1 == depth[u];
        });
        std::cout << cnt;
        for(int v : adj[u]){
            if(depth[v] - 1 == depth[u]) {
                std::cout << ' ' << id2Name[v];
            }
        }
        std::cout << '\n';
    }

    return 0;
}