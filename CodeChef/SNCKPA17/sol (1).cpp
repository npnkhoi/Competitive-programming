#include <bits/stdc++.h>
using namespace std;
const int MAX = 11;
int main() {
  freopen("gameball.out", "r", stdin);
  freopen("gameball_funny.out", "w", stdout);
  int testcase, xx;
  cin >> testcase;
  xx = testcase;
  while (testcase--) {
    int n, m;
    char a[MAX][MAX];
    int _u, _v;
    cin >> n >> m >> _u >> _v;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] = '*';

    a[_u][_v] = '.';

    int Request;
    cin >> Request;
    bool kt;
    kt = true;
    for (int l = 1; l <= Request; l++) {
      int x, y, u, v;
      cin >> x >> y >> u >> v;
      if (a[x][y] == '*' && a[u][v] == '.') {
        if (x == u) {
          if (abs(v-y) <= 2) {
            if (y < v) {
              //trai sang phai
              for (int i = y; i <= v-1; i++) {
                a[x][i] = '.';
              }  
              a[u][v] = '*';

            } else {
              //phai sang trai
              for (int i = y; i >= v+1; i--) {
                a[x][i] = '.';    
              }
              a[u][v] = '*';
            }
            cout << "Di chuyen lan " << l << endl; 
            //print
            for (int i = 1; i <= n; i++) {
              for (int j = 1; j <= m; j++)
                cout << a[i][j];
              cout << endl;
            }
          } else {
            kt = false;
            cout << "NO" << endl;
            break;
          }
        } else
        if (y == v) {
          if (x < u) {
            //tren xuong duoi
            //cout << x << " " << u << endl;
            for (int i = x; i <= u-1; i++) {
              a[i][y] = '.';
            }

            a[u][v] = '*';
          } else {
            //duoi len tren
            for (int i = x; i >= u+1; i--)
              a[i][y] = '.';
            
            a[u][v] = '*'; 
          } 
          //print
          cout << "Di chuyen lan " << l << endl;
          for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
              cout << a[i][j];
            cout << endl;
          }
        }  
      } else {
        kt = false;
        cout << "NO" << endl;
        break;
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (a[i][j] == '*')
          cnt++;
    if (kt == true && cnt == 1) {
      cout << "TESTCASE " << xx-testcase << " ===>> YES" << endl;  
    } else {
      cout << "TESTCASE" << xx-testcase << "NO" << endl;
    }
  }
  return 0;
}