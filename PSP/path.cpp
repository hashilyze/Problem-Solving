// 문제해결 기법 과제-35

#include <algorithm>
#include <cstring>
#include <iostream>

// types
using pii = std::pair<int, int>;
// constants
constexpr int MAX_N = 100000;
// variabels
int N;
int parent[MAX_N];
int left[MAX_N];
int right[MAX_N];
int value[MAX_N];

int preorder[MAX_N];
int inorder[MAX_N];

int build(int inLeft, int inRight, int preLeft, int preRight){
    if(inLeft == inRight) return -1;
    
    int root = preorder[preLeft];
    int leftSize = std::find(inorder + inLeft, inorder + inRight, root) - (inorder + inLeft);

    int lroot = build(inLeft, inLeft + leftSize, preLeft + 1, preLeft + leftSize + 1);
    int rroot = build(inLeft + leftSize + 1, inRight, preLeft + leftSize + 1, preRight);
    
    if(lroot != -1) parent[lroot] = root;
    left[root] = lroot;
    if(rroot != -1) parent[rroot] = root;
    right[root] = rroot;

    return root;
}

pii maxPath(int p){
    if(left[p] == -1 && right[p] == -1) return {value[p], value[p]};
    if(left[p] != -1 && right[p] != -1) {
        auto retLeft = maxPath(left[p]);
        auto retRight = maxPath(right[p]);
        int sum = std::max({retLeft.first, retRight.first, retLeft.second + retRight.second + value[p]});
        int path = std::max(retLeft.second, retRight.second) + value[p];
        return { sum, path };
    }
    if(left[p] != -1){
        auto ret = maxPath(left[p]);
        return {ret.first, ret.second + value[p]};
    }
    if(right[p] != -1){
        auto ret = maxPath(right[p]);
        return {ret.first, ret.second + value[p]};
    }
    return {0, 0};
}

int main(void){
#ifndef ONLINE_JUDGE
    std::freopen("path.inp", "r", stdin);
    std::freopen("path.out", "w", stdout);
#endif
    int T;
    std::cin >> T;
    while(T--){
        std::memset(parent, 0xFF, sizeof(parent));
        std::memset(left, 0xFF, sizeof(left));
        std::memset(right, 0xFF, sizeof(right));

        std::cin >> N;
        for(int i = 0; i < N; ++i) std::cin >> value[i];
        for(int i = 0; i < N; ++i) std::cin >> preorder[i];
        for(int i = 0; i < N; ++i) inorder[i] = i;
        int root = build(0, N, 0, N);
        auto ret = maxPath(root);
        std::cout << ret.first << '\n';
    }
    return 0;
}