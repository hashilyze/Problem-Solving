// 문제해결기법 과제-31

#include <cstring>
#include <iostream>
#include <fstream>
#include <set>
#include <stack>

// === File Control ====
const std::string FILE_NAME = "show";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// constants
constexpr int MAX_N = 5000;
// variables
int N, M;
std::set<int> adj[MAX_N * 2 + 1];

int discoverd[MAX_N * 2 + 1];
bool finished[MAX_N * 2 + 1];
std::stack<int> s;
int sccCnt = 0;
int sccId[MAX_N * 2 + 1];

int dfs(int u, int &d){
    discoverd[u] = ++d;
    s.push(u);
    
    int min = discoverd[u];
    for(int v : adj[u]){
        if(discoverd[v] == 0){ 
            min = std::min(min, dfs(v, d));
        } else if(!finished[v]){
            min = std::min(min, discoverd[v]);
        }
    }

    if(discoverd[u] == min){ // make SCC
        ++sccCnt;
        while(true){
            int v = s.top(); s.pop();
            finished[v] = true;
            sccId[v] = sccCnt;
            if(u == v) break;
        }
    }
    return min;
}

void tarjan(){
    int d = 0;
    for(int u = 1; u <= N * 2; ++u){
        if(discoverd[u] != 0) continue;
        dfs(u, d);
    }
}

inline int getid(int num){ return num >= 0 ? num : -num + N; }

void init(){
    for(auto &vec : adj) vec.clear();
    std::memset(discoverd, 0x00, sizeof(discoverd));
    std::memset(finished, 0x00, sizeof(finished));
    std::memset(sccId, 0x00, sizeof(sccId));
}

int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    
    int t;
    in >> t;
    while(t--){
        init();
        in >> N >> M;
        while(M--){
            char c1, c2, c3;
            int u1, u2, u3;
            in >> u1 >> c1 >> u2 >> c2 >> u3 >> c3;
            if(c1 == 'B') u1 = -u1;
            if(c2 == 'B') u2 = -u2;
            if(c3 == 'B') u3 = -u3;

            // (u1, u2)
            adj[getid(-u1)].insert(getid(u2));
            adj[getid(-u2)].insert(getid(u1));
            // (u2, u3)
            adj[getid(-u2)].insert(getid(u3));
            adj[getid(-u3)].insert(getid(u2));
            // (u3, u1)
            adj[getid(-u3)].insert(getid(u1));
            adj[getid(-u1)].insert(getid(u3));
        }

        tarjan();
        bool enabled = true;
        for(int u = 1; u <= N; ++u){
            if(sccId[getid(u)] == sccId[getid(-u)]){
                enabled = false;
                break;
            }
        }
        out << (enabled ? "1\n" : "-1\n");
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}