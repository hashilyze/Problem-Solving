// Beakjoon 2667번 - 단지번호붙이기
// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
constexpr int MAX_N = 25;
// variables
int n;
bool isVisited[MAX_N][MAX_N];
std::vector<int> counts;


int dfs(int x, int y){
    if(isVisited[y][x]) return 0;
    isVisited[y][x] = true;

    int cnt = 1;
    if(0 <= x - 1) cnt += dfs(x - 1, y);
    if(x + 1 < n)  cnt += dfs(x + 1, y);
    if(0 <= y - 1) cnt += dfs(x, y - 1);
    if(y + 1 < n)  cnt += dfs(x, y + 1);

    return cnt;
}

void dfsAll(){
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            if(!isVisited[y][x]){
                counts.push_back(dfs(x, y));
            }
        }
    }
}

int main(void){
    FASTIO

    std::cin >> n;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            char ch;
            std::cin >> ch;
            isVisited[y][x] = !(ch - '0');
        }
    }

    dfsAll();
    std::sort(counts.begin(), counts.end());
    std::cout << counts.size() << '\n';
    for(int cnt : counts) std::cout << cnt << '\n';

    return 0;
}