// [SWEA] 1223. [S/W 문제해결 기본] 6일차 - 계산기2

#include <iostream>
#include <map>
#include <stack>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
std::map<char, int> opOrder = {{'+', 1}, {'*', 0} };
// variables

void calc(std::stack<int>& valStk, std::stack<char>& opStk){
   int rhs = valStk.top(); valStk.pop();
   int lhs = valStk.top(); valStk.pop();
   char op = opStk.top(); opStk.pop();
   switch (op) {
   case '+': valStk.push(lhs + rhs); break;
   case '*': valStk.push(lhs * rhs); break;
   }
}

int main(int argc, char **argv) {
   FASTIO
   
   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::stack<int> valStk;
      std::stack<char> opStk;

      int N;
      std::cin >> N;

      char ch;
      for(int i = 0; i < N; ++i){
         std::cin >> ch;
         if(opOrder.find(ch) != opOrder.end()){
            while(!opStk.empty() && opOrder[opStk.top()] <= opOrder[ch]) calc(valStk, opStk);
            opStk.push(ch);
         } else{
            valStk.push(ch - '0');
         }
      }
      while (!opStk.empty()) {
         calc(valStk, opStk);
      }

      std::cout << '#' << t << ' ' << valStk.top() << '\n';
   }

   return 0;
}