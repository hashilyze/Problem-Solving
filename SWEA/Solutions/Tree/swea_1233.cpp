// [SWEA] 1233. [S/W 문제해결 기본] 9일차 - 사칙연산 유효성 검사

#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 200;
// variables
int N;
std::string buffer;


int main(int argc, char **argv) {
   FASTIO

   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::getline(std::cin, buffer);
      N = std::stoi(buffer);

      bool flag = true;
      for(int i = 0; i < N; ++i){
         std::getline(std::cin, buffer);
         std::istringstream sin(buffer);

         char op = '\0';
         int node = 0, num = 0, left = 0, right = 0;
         sin >> node;
         
         char ch;
         sin >> ch;
         sin.putback(ch);
         if(std::isdigit(ch)){ 
            sin >> num >> left >> right;
            if(left != 0 || right != 0) flag = false;
         } else{
            sin >> op >> left >> right;
            if(left == 0 || right == 0) flag = false;
         }
         
      }
      std::cout << '#' << t << ' ' << (flag ? 1 : 0) << '\n';
   }

   return 0;
}