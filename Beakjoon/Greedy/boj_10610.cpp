// Beakjoon 10610 - 30 
// https://www.acmicpc.net/problem/10610

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int digits[10];

int main(void){
   FASTIO

   int sum = 0;
   char ch = '\0';
   while(std::cin >> ch) {
      sum += ch - '0';
      ++digits[ch - '0'];
   }
   if(digits[0] == 0 || sum % 3) std::cout << -1;
   else {
      for(int d = 9; d >= 0; --d){
         while (digits[d]--) std::cout << (char)(d + '0');
      }
   }

   return 0;
}   