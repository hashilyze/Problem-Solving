// 문제해결 기법 과제-13

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>

// === File Control ====
const std::string FILE_NAME = "Jolly";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// === Solution ====
constexpr int MAX_N = 3000;
bool counts[MAX_N];

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
    int n;
    while(in >> n){
        std::memset(counts, 0x00, sizeof(counts));
        int prev = 0;
        in >> prev;
        for(int i = 1; i < n; ++i){    
            int input;
            in >> input;
            counts[std::abs(input - prev) - 1] = true;
            prev = input;
        }

        bool flag = true;
        for(int i = 0; i < n - 1; ++i) {
            if(!counts[i]){
                flag = false;
                break;
            }
        }
        out << (flag ? "Jolly\n" : "Not Jolly\n");
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}