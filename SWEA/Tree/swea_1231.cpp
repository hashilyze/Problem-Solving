// [SWEA] 1231. [S/W 문제해결 기본] 9일차 - 중위순회

#include <cstring>
#include <iostream>
#include <sstream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 100;
// variables
int N;
char values[MAX_N + 1];
int lefts[MAX_N + 1];
int rights[MAX_N + 1];
std::string buffer;

void inorder(int node){
   if(node == 0) return;

   inorder(lefts[node]);
   std::cout << values[node];
   inorder(rights[node]);
}

int main(int argc, char **argv) {
   FASTIO

   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::memset(lefts, 0x00, sizeof(lefts));
      std::memset(rights, 0x00, sizeof(rights));

      std::getline(std::cin, buffer);
      N = std::stoi(buffer);
      for(int i = 0; i < N; ++i){
         std::getline(std::cin, buffer);
         std::istringstream sin(buffer);

         int node;
         sin >> node >> values[node] >> lefts[node] >> rights[node];
      }
      std::cout << '#' << t << ' ';
      inorder(1);
      std::cout << '\n';
   }

   return 0;
}