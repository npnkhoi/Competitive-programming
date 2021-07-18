#include <bits/stdc++.h>
using namespace std;

const int K = 5e4, LEN=19;

string num;
int k;
long long memo[2][LEN+2][2][K+2], expOf[LEN];


long long f(int type, int pos, int lim, bool hasLeading, int len) {
  // printf("at %d, %d, %d\n", type, pos, lim);
  long long ret = 0;
  if (lim <= K && memo[type][pos][hasLeading][lim] != -1) {
    return memo[type][pos][hasLeading][lim];
  } else if (pos == len - 1) {
    if (type == 0) {
      ret = 1 + min(lim, num[pos] - '0');
    } else {
      ret = 10;
    }
  } else {
    int currentDigit = num[pos] - '0';
    // printf("at %d, %d, %d\n", type, pos, lim);

    if (hasLeading) {
      if (type == 0) {
        ret += expOf[len - pos]; // pick 0
      } else {
        ret += f(type, pos + 1, lim, )  
      }
    } else {
      ret += f(type, pos + 1, lim, true, len);
    }
    // printf("at %d, %d, %d\n", type, pos, lim);

    if (type == 0) {
      // cerr << "prepare\n";
      for (int d = 1; d < currentDigit; ++ d) {
        ret += f(1, pos + 1, lim / d, true, len);
      }
      // cerr << "done 1\n";
      // printf("current digit: %d\n", currentDigit);
      if (currentDigit != 0) {
        ret += f(0, pos + 1, lim / currentDigit, true, len);
      }
      // cerr << "done 2\n";
    } else {
      for (int d = 1; d <= 9; ++ d) {
        ret += f(1, pos + 1, lim / d, true, len);
      }
    }
    // printf("at %d, %d, %d\n", type, pos, lim);
  }
  if (lim <= K) {
    // cerr << "still here";
    memo[type][pos][hasLeading][lim] = ret;
    // cerr << "and here!";
  }
  printf("f(%d, %d, %d, %d) = %lld\n", type, pos, lim, hasLeading, ret);
  return ret;
}

int main() {
  expOf[0] = 1;
  for (int i = 1; i <= LEN - 1; ++ i) {
    expOf[i] = expOf[i - 1] * 10;
  }
  memset(memo, -1, sizeof memo);
  cin >> num >> k;
  cout << f(0, 0, k, false, num.size()) - 1;
}