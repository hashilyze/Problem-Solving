// Beakjoon 16561 - 3의 배수
// https://www.acmicpc.net/problem/16561

#include <iostream>

int main(void) {
	
    int N;
    std::cin >> N;
    if(N < 9) {
        std::cout << 0;
    } else {
        // (n/3-3)H3 = mH3 = (m + 2)C(2) = (m + 2) * (m + 1) / 2
        N = N / 3 - 3;
        std::cout << (N + 2) * (N + 1) / 2;
    }

	return 0;
}