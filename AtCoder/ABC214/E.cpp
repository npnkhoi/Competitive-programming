#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

pair<int, int> a[N];

int main() {
  int tc; cin >> tc;
  while (tc --) {
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);

    int ptr = a[0].first, idx = 0;
    bool answer = true;
    priority_queue<int, vector<int>, greater<int>> heap;
    while (true) {
      while (idx < n && a[idx].first == ptr) {
        heap.push(a[idx].second);
        idx ++;
      }

      if (!heap.empty()) {
        int top = heap.top(); heap.pop();
        if (top < ptr) {
          answer = false;
          break;
        }
        ptr ++;
      } else if (idx < n) {
        ptr = a[idx].first;
      } else {
        break;
      }
    }
    cout << (answer ? "Yes" : "No") << '\n';
  }
}

/*
For each coordinate:
  add requests (put r to heap)
  get the most urgent out
    if the deadline is over -> No
  
  if the heap is empty, jump to the nearest L[i] on the right
  
*/