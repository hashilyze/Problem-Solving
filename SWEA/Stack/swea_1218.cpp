// [SWEA] 1218. [S/W 문제해결 기본] 4일차 - 괄호 짝짓기
#include <iostream>
#include <stack>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int main(int argc, char **argv) {
   FASTIO
   
   int T = 10;
   //std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int N;
      std::string line;
      std::cin >> N >> line;
      
      int ret = -1;
      if(N % 2){
         ret = 0;
      } else{
         bool flag = true;
         std::stack<char> stk;
         for(char ch : line){
            if(ch == ')' || ch == ']' || ch == '}' || ch == '>'){
               if(stk.empty()) { // 여는 괄호 없음
                  flag = false;
                  break;
               }
               
               switch (ch) { // 괄호 일치 검사
               case ')': flag = stk.top() == '('; break;
               case ']': flag = stk.top() == '['; break;
               case '}': flag = stk.top() == '{'; break;
               case '>': flag = stk.top() == '<'; break;
               }
               if(!flag) break;

               stk.pop();
            } else{
               stk.push(ch);
            }
         }

         ret = flag && stk.empty() ? 1 : 0;
      }

      std::cout << '#' << t << ' ' << ret << '\n';
   }

   return 0;
}