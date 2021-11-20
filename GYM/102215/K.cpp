#include <bits/stdc++.h>
using namespace std;

/*
dp[i][l][r] (i: position, l: left pile, r: right pile)
S: "RGBRGB"

Left: 012, 321 -> (max: 63)

initital: dp[0][0][0] = True

dp[i][l][r] = True/False 
  -> dp[i+1][l'][r] = True
  -> dp[i+1][l][r'] = True

dp[n-1][l][r]
*/

const int N = 1005, M = 65;
bool dp[N][M][M];

int getId(int color) {
  if (color == 'R') return 1;
  else if (color == 'G') return 2;
  else return 3;
}

int getNewPile(int oldPile, int card) {
  if (card == oldPile % 4) {
    return oldPile;
  } else if (oldPile > 3*4+3) {
    return -1;
  } else {
    return oldPile * 4 + card;
  }
}

int length(int pile) {
  if (pile == 0) return 0;
  return 1 + length(pile / 4);
}

string getPile(int pile) {
  if (pile == 0) return "";
  else return getPile(pile/4) + char('0' + pile%4);
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  string s;
  cin >> s;
  int n = s.size();
  dp[0][0][0] = true;
  for (int i = 0; i < n; ++ i) {
    int card = getId(s[i]);
    for (int l = 0; l < 64; ++ l) {
      for (int r = 0; r < 64; ++ r) {
        if (!dp[i][l][r]) continue;
        // Left
        int newPile = getNewPile(l, card);
        if (newPile != -1) {
          dp[i+1][newPile][r] = true;
        }
        // Right
        newPile = getNewPile(r, card);
        if (newPile != -1) {
          dp[i+1][l][newPile] = true;
        }
      } 
    }
  }
  for (int l = 0; l < 64; ++ l) {
    string leftPile = getPile(l);
    for (int r = 0; r < 64; ++ r) {
      if (!dp[n][l][r]) continue;
      string rightPile = getPile(r);
      int lenLeft = leftPile.size(), lenRight = rightPile.size();
      int len = lenLeft + lenRight;
      if (lenLeft != 0 && lenRight != 0) {
        if (leftPile[lenLeft - 1] == rightPile[0] || rightPile[lenRight - 1] == leftPile[0]) {
          len -= 1;
        }
      }
      if (len <= 3) {
        // cout << leftPile << ' ' << rightPile << '\n';
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}