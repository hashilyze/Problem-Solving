#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

//#define ONLINE_JUDGE

// === File Control ====
const std::string FILE_NAME = "palindrome";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;



ll solution(ll n){
    int index = 0;
    std::string strN = std::to_string(n);
    while(index < 1000){
        int drop = 0;
        for(int pos = strN.size() - 1; pos >= 0; --pos){
            if(strN[pos] == '0') ++drop;
            else break;
        }
        std::string rStrN(strN.crbegin() + drop, strN.crend());
        if(strN == rStrN) return index;
        ++index;

        n = std::abs(n - std::stol(rStrN));
        strN = std::to_string(n);
    }
    return -1;
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
        ll n;
        in >> n;
        out << solution(n) << '\n';
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}