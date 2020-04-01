#include <cstdio>
#include <iostream>
using namespace std;
#define task "street"

vector<long long> v;
void backTrack(int i, int j, int k) {
    int num = lt[3][i] * lt[5][j] * lt[7][k];
    if (num >= 1e18 || num <= 0) return;
    if (i || j || k) v.push_back(num);
    backTrack(i + 1, j, k);
    backTrack(i, j + 1, k);
    backTrack(i, j, k + 1);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    backTrack(0, 0, 0);
    sort(v.begin(), v.end());
    v.resize(4000);
    while (scanf("%lld", &num) != EOF) {
        if (binary_search(v.begin(), v.end(), num)) {

        } else printf("N\n");
    }
}
