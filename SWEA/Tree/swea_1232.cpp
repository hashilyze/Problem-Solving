// [SWEA] 1232. [S/W 문제해결 기본] 9일차 - 사칙연산

#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 1000;
// variables
int N;
char op[MAX_N + 1];
int num[MAX_N + 1];
int left[MAX_N + 1];
int right[MAX_N + 1];
std::string buffer;


int calc(int node){
   if(op[node] == 0) return num[node];
   
   int lhs = calc(left[node]); 
   int rhs = calc(right[node]);
   switch (op[node]) {
   case '+': return lhs + rhs;
   case '-': return lhs - rhs;
   case '*': return lhs * rhs;
   case '/': return lhs / rhs;
   }
   return 0;
}

int main(int argc, char **argv) {
   FASTIO

   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::memset(op, 0x00, sizeof(op));

      std::getline(std::cin, buffer);
      N = std::stoi(buffer);
      for(int i = 0; i < N; ++i){
         std::getline(std::cin, buffer);
         std::istringstream sin(buffer);

         int node;
         sin >> node;

         char ch;
         sin >> ch;
         if(std::isdigit(ch)){ 
            sin.putback(ch);
            sin >> num[node];
         } else{
            op[node] = ch;
            sin >> left[node] >> right[node];
         }
      }
      std::cout << '#' << t << ' ' << calc(1) << '\n';
   }

   return 0;
}