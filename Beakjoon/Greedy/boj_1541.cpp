// Beakjoon 1541 - 잃어버린 괄호 
// https://www.acmicpc.net/problem/1541

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int main() { 
   FASTIO
   
   int ret = 0;
   std::cin >> ret;

   bool flag = false;
   char op = '\0';
   int num = 0;
   while(std::cin >> op >> num){
      if(op == '-') flag = true;
      ret = ret + (flag ? -num : num);
   }
   std::cout << ret;

   return 0; 
}