// 문제해결 기법 과제-5

#include <iostream>
#include <fstream>
#include <string>

// File Control
#define READ_FROM_FILE

const std::string FILE_NAME = "dish";
const std::string INPUT_FORMAT = ".inp";
const std::string OUTPUT_FORMAT = ".out";
const std::string INPUT_FILE = FILE_NAME + INPUT_FORMAT;
const std::string OUTPUT_FILE = FILE_NAME + OUTPUT_FORMAT;

void solution(int n, const std::string& dishes, int& length){
    length = 0;
    char head = 0;
    for(auto beg = dishes.cbegin(), end = dishes.cend(); beg != end; ++beg){
        const char& dish = *beg;
        if(head != dish){
            length += 10;
            head = dish;
        } else{
            length += 5;
        }
    }
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
    int t;
    in >> t;
    while(t--){
        int n, length;
        std::string dishes;
        in >> n >> dishes;
        solution(n, dishes, length);
        out << length << '\n';
    }

#ifdef READ_FROM_FILE
    fin.close();
    fout.close();
#endif
    return 0;
}