// 문제해결기법 - 29

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

// === File Control ====
const std::string FILE_NAME = "tree";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 2000;
const int MAX_LEVEL = std::floor(std::log2(MAX_N)) + 0.1;
// variables
int n;
ivec graph[MAX_N + 1];
int depth[MAX_N + 1] = { -1, };
int parents[MAX_N + 1][20];
std::map<std::string, int> name2Id;

void build(int u, int p){
    depth[u] = depth[p] + 1;
    parents[u][0] = p;
    
    for(int i = 1; i <= MAX_LEVEL; ++i){
        parents[u][i] = parents[parents[u][i - 1]][i - 1];
    }
    for(int v : graph[u]){
        build(v, u);
    }
}

int LCA(int u, int v){
    if(depth[u] != depth[v]){
        if(depth[u] > depth[v]) std::swap(u, v);
        int b = depth[v] - depth[u];
        for(int i = 0; i <= MAX_LEVEL; ++i){
            if((b >> i) & 1){
                v = parents[v][i];
            }
        }
    }

    int lca = u;
    if(u != v){
        for(int i = MAX_LEVEL; i >= 0; --i){
            if(parents[u][i] != parents[v][i]){
                u = parents[u][i];
                v = parents[v][i];
            }
        }

        if(parents[u][0] == parents[v][0]){
            lca = parents[u][0];
        } else{
            lca = 0;
        }
    }
    return lca;
}

inline int getId(const std::string& name){
    auto it = name2Id.find(name);
    if(it == name2Id.end()){
        name2Id.insert({name, name2Id.size() + 1});
        return name2Id.size();
    }
    return it->second;
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
    // build.
    std::string child, parent;
    while(in >> child >> parent){
        if(child == "no.child") break;

        int childId = getId(child);
        int parentId = getId(parent);

        graph[parentId].push_back(childId);
        parents[childId][0] = parentId;
    }
    int n = name2Id.size();
    for(int i = 1; i <= n; ++i){
        if(parents[i][0] == 0){
            build(i, 0);
        }
    }
    // query.
    while(in >> child >> parent){
        int leftId = getId(child);
        int rightId = getId(parent);
        
        int lca = LCA(leftId, rightId);

        if(lca == 0){
            out << "no relation\n";
        } else {
            int leftDiff = depth[leftId] - depth[lca];
            int rightDiff = depth[rightId] - depth[lca];

            if(leftDiff == 0){ // parent
                while(rightDiff > 2) {
                    --rightDiff;
                    out << "great ";
                }
                if(rightDiff == 2){
                    out << "grand ";
                }
                out << "parent\n";
            } else if(rightDiff == 0){ // child
                while(leftDiff > 2) {
                    --leftDiff;
                    out << "great ";
                }
                if(leftDiff == 2){
                    out << "grand ";
                }
                out << "child\n";
            } else{
                if(leftDiff == 1 && rightDiff == 1){ // sibling
                    out << "sibling\n";
                } else{    // cousin
                    int i = std::min(leftDiff, rightDiff) - 1;
                    int j = std::abs(leftDiff - rightDiff);
                    out << i << " cousin ";
                    if(j) out << "removed " << j;
                    out << '\n';
                }
            }
        }
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}