// Beakjoon 1564번 - 팩토리얼5
// https://www.acmicpc.net/problem/1564

#include <cstdio>

using ll = long long;

constexpr ll MOD = 100'000;

int solution(int n){
    ll ans = 1LL;

    ll cnt2 = 0, cnt5 = 0;
    for(int i = 2; i <= n; ++i){
        int j = i;
        while(j % 2 == 0) { ++cnt2; j /= 2; }
        while(j % 5 == 0) { ++cnt5; j /= 5; }
        ans = (ans * j) % MOD;
    }
    cnt2 -= cnt5;
    cnt5 = 0;
    while(cnt2--) ans = (ans * 2) % MOD;
    return ans;
}

int main(void) {
	int N;
	std::scanf("%d", &N);
	std::printf("%05d", solution(N));

	return 0;
}