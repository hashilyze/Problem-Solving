// 문제해결 기법 과제-28

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <string>

// === File Control ====
const std::string FILE_NAME = "scc";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// types
using ivec = std::vector<int>;
//constants
constexpr int MAX_N = 10000;
// variables
int V, E;
ivec adj[MAX_N];

int d = 0;
int discovered[MAX_N];
bool isSCC[MAX_N];
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
    
    for(int u = 0; u < V; ++u){
        if(discovered[u] == -1) scc(u, result);
    }
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
    in >> V >> E;
    for(int i = 0; i < E; ++i){
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
    }

    std::vector<ivec> sccGroup;
    tarjan(sccGroup);
    
    out << sccGroup.size() << '\n';
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}