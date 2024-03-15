
// 문제해결 기법 과제-2

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// File Control
#define READ_FROM_FILE

const std::string FILE_NAME = "trip";
const std::string INPUT_FORMAT = ".inp";
const std::string OUTPUT_FORMAT = ".out";
const std::string INPUT_FILE = FILE_NAME + INPUT_FORMAT;
const std::string OUTPUT_FILE = FILE_NAME + OUTPUT_FORMAT;


constexpr int SIZE = 1000;
int moneies[SIZE];
int n;


void solution(int& change){
    int sum = 0;
    for(int i = 0; i < n; ++i) sum += moneies[i];
    int mean = sum / n, remainder = sum % n;

    change = 0;
    int high = 0, low = 0;
    for(int i = 0; i < n; ++i){
        const int& money = moneies[i];
        if(mean < money) {
            ++high;
        } else {
            ++low;
            change += mean - money;
        }
    }
    change += std::max(remainder - high, 0);
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

    // Solution
    while(in >> n && n){
        double money;
        for(int i = 0; i < n; ++i){
            in >> money;
            moneies[i] = (int)(money * 100 + 0.1);
        }
        int change = 0;
        solution(change);

        int dollar = change / 100;
        int cent = change % 100;
        out << '$' << dollar 
            << '.' << std::setfill('0') << std::setw(2) 
            << cent << '\n';
    }

#ifdef READ_FROM_FILE
    fin.close();
    fout.close();
#endif
    return 0;
}