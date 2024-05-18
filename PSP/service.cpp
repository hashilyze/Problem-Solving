// 문제해결 기법 과제-26

#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>
#include <string>
#include <vector>

// === File Control ====
const std::string FILE_NAME = "service";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100;
constexpr int MAX_P = 50;
constexpr int MAX_L = MAX_N * MAX_P;
constexpr int MAX_SIZE = 2 + MAX_N + MAX_L;

constexpr int SOURCE = 0;
constexpr int SINK = MAX_SIZE - 1;
// variables
int n, p, m;
std::vector<int> adj[MAX_SIZE];
int rGraph[MAX_SIZE][MAX_SIZE];
int parents[MAX_SIZE];

int locations[MAX_P + 1];


bool bfs(int n, int s, int t){
    std::memset(parents, 0xFF, sizeof(parents));

    std::queue<int> q;
    q.push(s); parents[s] = s;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : adj[u]){
            if(parents[v] == -1 && rGraph[u][v] > 0){
                q.push(v);
                parents[v] = u;
                if(v == t) return true;
            }
        }
    }
    return false;
}

int maxflow(int n, int s, int t){
    int mf = 0;
    while(bfs(n, s, t)){
        static constexpr int f = 1;
        mf += f;

        int v = t;
        while(parents[v] != v){
            rGraph[parents[v]][v] -= f;
            rGraph[v][parents[v]] += f;
            v = parents[v];
        }
    }
    return mf;
}

// team
inline int team(int teamNo) { return 1 + teamNo; }

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
        std::memset(rGraph, 0x00, sizeof(rGraph));
        for(int i = 0; i < MAX_SIZE; ++i) adj[i].clear();

        in >> n >> p >> m;
        // Source - Team
        for(int teamNo = 1; teamNo <= n; ++teamNo) {
            rGraph[SOURCE][teamNo] = m;
            
            adj[SOURCE].push_back(teamNo);
            adj[teamNo].push_back(SOURCE);
        }
        // Location - Sink
        for(int cycleNo = 1; cycleNo <= p; ++cycleNo) {
            in >> locations[cycleNo];
            locations[cycleNo] += locations[cycleNo - 1];
        }
        for(int locNo = 1; locNo <= locations[p]; ++locNo){
            int nodeNo = locNo + MAX_N;
            rGraph[nodeNo][SINK] = 1;

            adj[nodeNo].push_back(SINK);
            adj[SINK].push_back(nodeNo);
        }
        // Team - Location
        for(int teamNo = 1; teamNo <= n; ++teamNo){ 
            int service;
            in >> service;

            for(int i = 0; i < service; ++i){
                int cycleNo, locNo;
                in >> cycleNo >> locNo;
                if(locNo > locations[cycleNo] - locations[cycleNo - 1]) continue;

                int nodeNo = MAX_N + locations[cycleNo - 1] + locNo;
                rGraph[teamNo][nodeNo] = 1;

                adj[teamNo].push_back(nodeNo);
                adj[nodeNo].push_back(teamNo);
            }
        }
        //out << maxflow(MAX_SIZE, SOURCE, SINK) << '\n';
        if(maxflow(MAX_SIZE, SOURCE, SINK) == locations[p]) out << "1\n";
        else out << "0\n";
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}