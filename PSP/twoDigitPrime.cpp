// 문제해결 기법 과제-27

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


// === File Control ====
const std::string FILE_NAME = "twoDigitPrime";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// constants
constexpr int MAX_N = 100;
// variables
bool isPrime[MAX_N + 1];


void initPrimes(int n){    
    std::memset(isPrime, 0x01, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= MAX_N; ++i){
        if(!isPrime[i]) continue;
        for(int j = i * i; j <= MAX_N; j += i){
            isPrime[j] = false;
        }
    }
}

bool countTowTigitPrime(int a){
    for(int i = a; i; i /= 10){
        int left = i % 10;
        if(left == 0) continue;

        for(int j = a; j; j /= 10){
            if(i == j) continue;

            int right = j % 10;
            if(isPrime[left * 10 + right]) return true;
        }
    }
    return false;
}

int countTowTigitPrime(int a, int b){
    int sum = 0;
    for(int i = std::max(a, 10); i <= b; ++i){
        sum += countTowTigitPrime(i) ? 1 : 0;
    }
    return sum;
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

    initPrimes(MAX_N);

    int t;
    in >> t;
    while(t--){
        int a, b;
        in >> a >> b;
        out << countTowTigitPrime(a, b) << '\n';
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}