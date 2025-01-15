// Beakjoon 21919 - 소수 최소 공배수
// https://www.acmicpc.net/problem/21919

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<bool> isPrimes;

void initErathos(int N) {
	isPrimes.resize(N + 1);
	std::fill(isPrimes.begin(), isPrimes.end(), true);
	for (int i = 2; i * i <= N; ++i) {
		if (!isPrimes[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			isPrimes[j] = false;
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	initErathos(1'000'000);

	int N;
	std::cin >> N;
	
	long long ans = 1;
	while (N--) {
		int in;
		std::cin >> in;
		if (isPrimes[in]) {
			ans *= in;
			isPrimes[in] = false;
		}
	}
	std::cout << (ans == 1 ? -1 : ans);

	return 0;
}