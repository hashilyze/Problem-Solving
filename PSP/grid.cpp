// 문제해결 기법 과제-4

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// File Control
#define READ_FROM_FILE

const std::string FILE_NAME = "grid";
const std::string INPUT_FORMAT = ".inp";
const std::string OUTPUT_FORMAT = ".out";
const std::string INPUT_FILE = FILE_NAME + INPUT_FORMAT;
const std::string OUTPUT_FILE = FILE_NAME + OUTPUT_FORMAT;


constexpr int MAX_SIZE = 1000;      // 격자의 최대 길이
constexpr int MAX_THRESHOLD = 10;   // k의 최대값
constexpr int MOD = 1000000007;


struct Node {
    bool isBlock = false;
    bool isFlag = false;
    int counts[MAX_THRESHOLD + 1] = { 0, };
} grid[MAX_SIZE][MAX_SIZE];

int x, y, a, b, k;

int addTo(int lhs, int rhs){
    return (lhs % MOD + rhs % MOD) % MOD;
}

int solution(){
    // 초기화
    // 출발점
    if(grid[0][0].isFlag){
        grid[0][0].counts[1] = 1; 
    } else if(grid[0][0].isBlock) {
        // set 0
    } else{
        grid[0][0].counts[0] = 1; 
    }
    
    for(int cx = 1; cx <= x; ++cx){ // Y = 0
        Node& node = grid[cx][0];
        Node& left = grid[cx - 1][0];

        if(!node.isBlock){
            std::memcpy(node.counts, left.counts, sizeof(int) * (k + 1));
            if(node.isFlag){
                node.counts[k - 1] = addTo(node.counts[k - 1], node.counts[k]);
                std::memmove(node.counts + 1, node.counts, sizeof(int) * k);
                node.counts[0] = 0;
            }
        } 
    }
    for(int cy = 1; cy <= y; ++cy){ // X = 0
        Node& node = grid[0][cy];
        Node& bottom = grid[0][cy - 1];

        if(!node.isBlock){
            std::memcpy(node.counts, bottom.counts, sizeof(int) * (k + 1));
            if(node.isFlag){
                node.counts[k - 1] = addTo(node.counts[k - 1], node.counts[k]);
                std::memmove(node.counts + 1, node.counts, sizeof(int) * k);
                node.counts[0] = 0;
            }
        }
    }

    // 동적계획법 적용
    for(int cy = 1; cy <= y; ++cy){
        for(int cx = 1; cx <= x; ++cx){
            Node& node = grid[cx][cy];
            Node& bottom = grid[cx][cy - 1];
            Node& left = grid[cx - 1][cy];

            if(!node.isBlock){
                std::memcpy(node.counts, left.counts, sizeof(int) * (k + 1));
                for(int i = 0; i <= k; ++i) {
                    node.counts[i] = addTo(node.counts[i], bottom.counts[i]);
                }

                if(node.isFlag){
                    node.counts[k - 1] = addTo(node.counts[k - 1], node.counts[k]);
                    std::memmove(node.counts + 1, node.counts, sizeof(int) * k);
                    node.counts[0] = 0;
                }
            }
        }
    }
    return grid[x][y].counts[k];
}


int main(void){
#ifdef READ_FROM_FILE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);

    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    // Init.
    int t;
    in >> t;
    // Solution
    while(t--){
        std::memset(grid, 0x00, sizeof(grid));

        in >> x >> y >> a >> b >> k;
        for(int i = 0; i < a; ++i){
            int tx, ty;
            in >> tx >> ty;
            grid[tx][ty].isFlag = true;
        }
        for(int i = 0; i < b; ++i){
            int tx, ty;
            in >> tx >> ty;
            grid[tx][ty].isBlock = true;
        }

        int result = solution();
        out << result << '\n';
    }
    
#ifdef READ_FROM_FILE
    fin.close();
    fout.close();
#endif
    return 0;
}