#include <bits/stdc++.h>
using namespace std;

const int N = 200;

typedef double Mat[N][N];

Mat a, t;

void show(Mat &a, int m, int n) {
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j) {
      cerr << fixed << setprecision(9);
      cerr << a[i][j] << ' ';
    }
    cerr << '\n';
  }
  cerr << '\n';
}

void ass(Mat &a, Mat &b, int m, int n) {
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j)
     {
      b[i][j] = a[i][j];
    }
  }
} 

void mul(Mat &a, Mat &b, Mat &c, int m, int n, int p) {
  Mat res;
  memset(res, 0, sizeof res);
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < p; ++ j) {
      for (int k = 0; k < n; ++ k) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  ass(res, c, m, p);
}

void add(Mat &a, Mat &b, Mat &c, int m, int n) {
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}

void expo(Mat &a, Mat &b, int sz, int n) {
  Mat tmp;
  // cerr << "hello\n";
  ass(a, tmp, sz, sz);
  // cerr << "hello\n";
  memset(b, 0, sizeof b);
  for (int i = 0; i < sz; ++ i) b[i][i] = 1;

  // cerr << "hello\n";
  while (n > 0) {
    // cerr << "while ...\n";
    // show(tmp, sz, sz);
    // show(b, sz, sz);
    if (n & 1) {
      mul(b, tmp, b, sz, sz, sz);
    }
    n /= 2;
    mul(tmp, tmp, tmp, sz, sz, sz); // CAVEAT: maybe wrong
  }
}

int main() {
  freopen("C.inp", "r", stdin);
  freopen("C.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      cin >> a[i][j];
    }
  }
  t[0][0] = 1;
  // show(t, n, 1);
  // show(a, n, n);
  Mat b, res;
  // cerr << "check 0\n";
  expo(a, b, n, m);
  // show(b, n, n);

  // cerr << "check\n";
  mul(t, b, res, 1, n, n);
  // show(res, n, 1);

  // cerr << "check2\n";
  for (int i = 0; i < n; ++ i) {
    cout << fixed << setprecision(9);
    cout << res[0][i] << '\n';
  }
}