// 문제해결 기법 과제-24

#include <iostream>
#include <fstream>
#include <cstring>

// === File Control ====
const std::string FILE_NAME = "mail";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// === Solution ====
// constants
constexpr int CODE_NUM = 8;
constexpr int CODE_SIZE = 6;
constexpr int TABLE_SIZE = 0x01 << CODE_SIZE;
const int codeTable[CODE_NUM] = {
    0b000000,
    0b001111,
    0b010011,
    0b011100,
    0b100110,
    0b101001,
    0b110101,
    0b111010
};
// variables
char c[CODE_SIZE + 1];
char restoreTable[TABLE_SIZE];


void init(){
    std::memset(restoreTable, 'X', sizeof(restoreTable));
    for(int i = 0; i < CODE_NUM; ++i){
        char ch = 'A' + i;
        int code = codeTable[i];
        
        restoreTable[code] = ch;
        for(int j = 0; j < CODE_SIZE; ++j){
            restoreTable[code ^ (0b000001 << j)] = ch;
        }
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
    init();

    int t;
    in >> t;
    while(t--){
        int n; 
        in >> n;
        while(n--){
            int idx = 0;
            for(int i = 0; i < CODE_SIZE; ++i){
                char c;
                idx <<= 1;
                in >> c;
                idx += c - '0';
            }
            out << restoreTable[idx];
        }
        out << '\n';
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}