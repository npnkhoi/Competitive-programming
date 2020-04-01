#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define task "combin"

const int N = 65;
long long comb[N + 5][N + 5];
int n, k;
long long m;
vector<int> v;
void init() {
    for (int i = 0; i <= N; i++) comb[i][0] = comb[i][i] = 1;
    for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++) comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
    /*for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) cerr << comb[i][j] << " ";
        cerr << "\n";
    }*/
}
int main() {
    init();
    scanf("%d%d%lld", &n, &k, &m);
    //cerr << n << " " << k << " " << m << "\n";
    for (int i = 1; i <= n; i++) v[i] = i;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++)
            if (j * comb[n-i][k-i] < m) tmp = j;
        m -= tmp * comb[n-i][k-i];
        printf("-> %d %lld\n", v[tmp], m);
        v.erase(v.begin() + tmp);
        for (int i = 0; i < v.size(); i++) cerr << v[i] << " ";
        cerr << "\n";
    }
}
