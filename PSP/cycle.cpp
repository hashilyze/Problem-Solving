// 문제해결 기법 과제-10

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// === File Control ====
const std::string FILE_NAME = "cycle";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";


// === Solution ====
// constants
constexpr int MAX_N = 1000 + 10;
// variables
int permutation[MAX_N] = { 0, };
int parents[MAX_N] = { 0, };
int ranks[MAX_N] = { 0, };
int n;

void initDisjointSet(){
    for(int i = 0; i < n; ++i) parents[i] = i;
    std::memset(ranks, 0x00, sizeof(ranks));
}
int getId(int index){
    if(parents[index] == index) return index;
    else return parents[index] = getId(parents[index]);
}
void mergeDisjointSet(int a, int b){
    int aId = getId(a);
    int bId = getId(b);
    if(aId == bId) return;

    if(ranks[aId] < ranks[bId]){
        parents[aId] = bId;
    } else if(ranks[bId] < ranks[aId]){
        parents[bId] = aId;
    } else{
        parents[bId] = aId;
        ranks[aId] += 1;
    }
}

int solution(){
    // Init.
    initDisjointSet();
    // Disjoint Set
    for(int i = 0; i < n; ++i){
        mergeDisjointSet(i, permutation[i]);
    }
    // Count DS
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(parents[i] == i) {
            ++cnt;
        }
    }
    return cnt;
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
        in >> n;
        for(int i = 0; i < n; ++i) {
            in >> permutation[i];
            permutation[i] -= 1;
        }
        out << solution() << '\n';
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}