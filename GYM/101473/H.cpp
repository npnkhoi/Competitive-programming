using namespace std;
#include <iostream>
#include <stdio.h>
#include <cassert>
#define ll long long
const ll md = 1e6;

struct matrix { ll mat[2][2]; };

matrix matMul(matrix a, matrix b, int m, int n, int p) {
    //cout << "mul\n";
    matrix res;
    for (int i = 0; i < m; i++)
    for (int j = 0; j < p; j++)
    for (ll k = res.mat[i][j] = 0; k < n; k++)
        res.mat[i][j] = (res.mat[i][j] + a.mat[i][k] * (b.mat[k][j] % md)) % md;
    return res;

}

matrix matExp(matrix a, ll ex, int siz) {
    //cout << "exp\n";
    if (ex == 1) return a;
    matrix tmp = matExp(a, ex/2, siz);
    matrix res = matMul(tmp, tmp, siz, siz, siz);
    if (ex % 2) res = matMul(res, a, siz, siz, siz);
    return res;
}

int main() {
    ll n, k, l;
    cin >> n >> k >> l;
    if (n == 0) cout << "1", assert(0);

    n /= 5; k %= md; l %= md;

    matrix a, b;
    a.mat[0][0] = 0;
    a.mat[0][1] = 1;
    a.mat[1][0] = l;
    a.mat[1][1] = k;

    b.mat[0][0] = 1;
    b.mat[1][0] = k;
    b.mat[0][1] = 0;
    b.mat[1][1] = 0;

    //cout << "ok";

    matrix res = matMul(matExp(a, n, 2), b, 2, 2, 1);


    /*for (int k = 1; k <= 5; k++) {
        matrix tmp = matExp(a, 2, k);

        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) cout << tmp.mat[i][j] << " \n"[j == 1];
        cout << endl;
    }*/

    printf("%06lld", res.mat[0][0]);
}
