// 문제해결 기법 과제-1

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>

// File Control
#define READ_FROM_FILE

const std::string FILE_NAME = "3nplus1";
const std::string INPUT_FORMAT = ".inp";
const std::string OUTPUT_FORMAT = ".out";
const std::string INPUT_FILE = FILE_NAME + INPUT_FORMAT;
const std::string OUTPUT_FILE = FILE_NAME + OUTPUT_FORMAT;


using num_ty = long long;
const num_ty SIZE = 1000000 + 100;
num_ty* dp;

num_ty getLength(num_ty num){
    // Check dp
    if(num <= SIZE && dp[num] != 0){
        return dp[num];
    }
    // Calc
    int count = 0;
    if(num % 2){
      count = getLength(3 * num + 1) + 1;
    } else {
      count = getLength(num / 2) + 1;
    }
    // Update dp
    if(num <= SIZE){
        dp[num] = count;
    }
    return count;
}

void solution(num_ty num1, num_ty num2, num_ty& result){
    if(num1 > num2) std::swap(num1, num2);

    result = 0;
    for(num_ty n = num1; n <= num2; ++n){
        result = std::max(result, getLength(n));
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
    // Init.
    dp = (num_ty*)std::malloc(SIZE * sizeof(num_ty));
    std::memset(dp, 0x00, SIZE * sizeof(num_ty));
    dp[1] = 1;

    // Solution
    num_ty num1, num2, result;
    while(in >> num1 >> num2){
        solution(num1, num2, result);
        out << num1 << ' ' << num2 << ' ' << result << '\n';
    }

#ifdef READ_FROM_FILE
    fin.close();
    fout.close();
#endif
    return 0;
}