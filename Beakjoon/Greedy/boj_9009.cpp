// Beakjoon 9009 - 피보나치 
// https://www.acmicpc.net/problem/9009

#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int FIB_SIZE = 45;
// variables
int T, N;
int fib[FIB_SIZE];


void init(){
   fib[1] = fib[2] = 1;
   for(int i = 3; i < FIB_SIZE; ++i){
      fib[i] = fib[i - 1] + fib[i - 2];
   }
}

void solution(int n){
   std::vector<int> result;
   for(int i = FIB_SIZE - 1; i >= 1; --i){
      if(fib[i] <= n) {
         result.push_back(fib[i]);
         n -= fib[i];
      }
   }
   
   for(auto rbeg = result.crbegin(), rend = result.crend(); rbeg != rend; ++rbeg){
      std::cout << *rbeg << ' ';
   }
   std::cout << '\n';
}

int main() { 
   FASTIO

   init();
   std::cin >> T;
   while(T--){
      std::cin >> N;
      solution(N);
   }

   return 0; 
}