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
constexpr int MAX_SIZE = MAX_N * (MAX_P + 1) + 2;

constexpr int SOURCE = 0;
constexpr int SINK = MAX_SIZE - 1;
// variables
int n, p, m;
std::vector<int> adj[MAX_SIZE];
int rGraph[MAX_SIZE][MAX_SIZE];
int parents[MAX_SIZE];

int locations[MAX_P];
int services[MAX_N];


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
inline int team(int t) { return 1 + t; }
// location, day
inline int location(int l, int d) { return MAX_N * (1 + d) + l + 1; }

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

        in >> n >> p >> m;
        for(int i = 0; i < n; ++i) {
            rGraph[SOURCE][team(i)] = m;
            
            adj[SOURCE].push_back(team(i));
            adj[team(i)].push_back(SOURCE);
        }

        int sum = 0;
        for(int d = 0; d < p; ++d) {
            in >> locations[d];
            sum += locations[d];
            for(int l = 0; l < locations[d]; ++l){
                rGraph[location(l, d)][SINK] = 1;
                
                adj[location(l, d)].push_back(SINK);
                adj[SINK].push_back(location(l, d));
            }
        }

        for(int t = 0; t < n; ++t){
            in >> services[t];
            for(int i = 0; i < services[t]; ++i){
                int d, l;
                in >> d >> l;
                rGraph[team(t)][location(l - 1, d - 1)] = 1;

                adj[team(t)].push_back(location(l - 1, d - 1));
                adj[location(l - 1, d - 1)].push_back(team(t));
            }
        }
        if(maxflow(MAX_SIZE, SOURCE, SINK) == sum) out << "1\n";
        else out << "0\n";
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}