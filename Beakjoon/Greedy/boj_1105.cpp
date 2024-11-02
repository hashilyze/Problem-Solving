// Beakjoon 1105 - 팔
// https://www.acmicpc.net/problem/1105

#include <iostream>
#include <stack>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
std::string str;


int solution(){
   int cnt = 0;
   std::stack<char> stk;
   for(char ch : str){
      if(ch == '{'){
         stk.push(ch);
      } else{ // ch == '}'
         if(stk.empty()){
            stk.push('{');
            ++cnt;
         } else{
            stk.pop();
         }
      }
   }
   cnt += stk.size() >> 1;
   return cnt;
}

int main() { 
   FASTIO

   int i = 0;
   while(std::cin >> str){
      if(str[0] == '-') break;
      std::cout << ++i << ". " << solution() << '\n';
   }

   return 0; 
}