// Beakjoon 2042번 - 구간 합 구하기 (Segment)

#include <iostream>

void setFastIO(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

// type
using BigInt = long long;
// const
constexpr BigInt MAX_N = 1'000'000 + 10;
// variable
BigInt arr[MAX_N] = { 0, };
BigInt segment[MAX_N << 2] = { 0, };
int n, m, k;
// function

BigInt initSegment(int nodeL, int nodeR, int index){
    if(nodeL == nodeR) return segment[index] = arr[nodeL];

    int mid = (nodeL + nodeR) / 2;
    BigInt leftSum = initSegment(nodeL, mid, index * 2);
    BigInt rightSum = initSegment(mid + 1, nodeR, index * 2 + 1);
    return segment[index] = leftSum + rightSum;
}
BigInt querySegment(int left, int right, int nodeL, int nodeR, int index){
    if(right < nodeL || nodeR < left) return 0LL;
    if(left <= nodeL && nodeR <= right) return segment[index];

    int mid = (nodeL + nodeR) / 2;
    BigInt leftSum = querySegment(left, right, nodeL, mid, index * 2);
    BigInt rightSum = querySegment(left, right, mid + 1, nodeR, index * 2 + 1);
    return leftSum + rightSum;
}
BigInt updateSegment(int pos, BigInt val, int nodeL, int nodeR, int index){
    if(pos < nodeL || nodeR < pos) return segment[index];
    if(nodeL == nodeR && nodeL == pos) return segment[index] = arr[pos] = val;
    
    int mid = (nodeL + nodeR) / 2;
    BigInt leftSum = updateSegment(pos, val, nodeL, mid, index * 2);
    BigInt rightSum = updateSegment(pos, val, mid + 1, nodeR, index * 2 + 1);
    return segment[index] = leftSum + rightSum;
}


int main(void){
    setFastIO();
    std::cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) std::cin >> arr[i];
    initSegment(1, n, 1);

    for(int i = 0, e = m + k; i < e; ++i){
        int a, b;
        BigInt c;
        std::cin >> a >> b >> c;
        switch(a){ // update
        case 1:{
            updateSegment(b, c, 1, n, 1);
        } break;
        case 2:{ // sub sum
            std::cout << querySegment(b, (int)c, 1, n, 1) << '\n';
        } break;
        }
    }

    return 0;
}