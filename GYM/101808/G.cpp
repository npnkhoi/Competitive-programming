#include <bits/stdc++.h>
using namespace std;

long long lcm(int a, int b) {
  return 1LL * a * b / __gcd(a, b);
}

const int N = 1e5 + 5;

int a[N], n;
int gcd_left[N], gcd_right[N], lcm_left[N], lcm_right[N];

// int gcd(int a, int b) {
//   if (a == 0) return b;
//   return 
// }

int get_gcd(int arr[], int i) {
  if (i < 0 || i >= n) return 0;
  return arr[i];
}

int get_lcm(int arr[], int i) {
  if (i < 0 || i >= n) return 1;
  return arr[i];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc; cin >> tc;

  while (tc --) {
    int x, y, cur_gcd = 0, cnt_invalid = 0, val, change_lcm = 0, change_gcd = 0;
    long long cur_lcm = 1;

    cin >> n >> x >> y;
    for (int i = 0; i < n; ++ i) {
      cin >> val;
      a[i] = val;
      if (val % x == 0 && y % val == 0) {
        int new_lcm = lcm(cur_lcm, val);
        if (new_lcm != cur_lcm) {
          cur_lcm = new_lcm;
          change_lcm ++;
        }

        int new_gcd = __gcd(cur_gcd, val);
        if (new_gcd != cur_gcd) {
          cur_gcd = new_gcd;
          change_gcd ++;
        }
      } else {
        cnt_invalid ++;
      }
    }

    // cerr << "hello\n";
    gcd_left[0] = lcm_left[0] = a[0];
    for (int i = 1; i < n; ++ i) {
      gcd_left[i] = __gcd(gcd_left[i-1], a[i]);
      lcm_left[i] = lcm(lcm_left[i-1], a[i]);
    }
    // cerr << "hello\n";

    gcd_right[n-1] = lcm_right[n-1] = a[n-1];
    for (int i = n-2; i >= 0; -- i) {
      // if (a[i] % x != 0 || y != a[i] != 0) continue;
      gcd_right[i] = __gcd(gcd_right[i+1], a[i]);
      lcm_right[i] = lcm(lcm_right[i+1], a[i]);
    }
    // cerr << "hello\n";


    int not_met = (cur_gcd != x) + (cur_lcm != y);
    
    int res;
    if (y % x != 0) {
      res = -1;
    } else if (n == 1) {
      if (x == y) {
        res = (cur_gcd != x);
      } else {
        res = -1;
      }
    }
    if (cnt_invalid >= 2) {
      res = cnt_invalid;
    } else if (not_met == 0) {
      res = cnt_invalid;
    } else if (not_met == 1) {
      if (cnt_invalid == 1) {
        res = 1;
      } else {
        // cerr << "hell\n"s;
        bool ok = false;
        for (int i = 0; i < n; ++ i) {

          int new_gcd = __gcd(get_gcd(gcd_left, i-1), get_gcd(gcd_right, i+1));
          int new_lcm = lcm(get_lcm(lcm_left, i-1), get_lcm(lcm_right, i+1));
          if (__gcd(y, new_gcd) == x || lcm(x, new_lcm) == y) ok = true;
        }
        if (ok) res = 1; else res = 2;
      }
    } else {
      if (lcm(cur_lcm, x) == y) {
        res = 1;
      } else {
        res = 2;
      }
    }

    cout << res << '\n';
  }
}