#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
using namespace std;
#define x first
#define y second

typedef long long llint;
typedef pair<llint, llint> point;
point operator-(const point &l, const point &r) {
  return point(l.first-r.first, l.second-r.second);
}
llint ccw(const point &a, const point &b, const point &c) {
  point p1 = b-a;
  point p2 = c-a;
  return p1.first*p2.second - p1.second*p2.first;
} // tich co huong cua hai vec to AB va vecto AC cung diem dau A
const int MAX_N = 100010;
point ships[MAX_N]; int n;
vector <point> poly; int m;

pair<int, int> find_tangent(const point &P) {
  point prev = poly[m-1];
  int left_t = -1, right_t = -1;
  for (int i = 0; i < m; i++) {
    point curr = poly[i];
    point next = poly[i+1];

    if ((ccw(prev, curr, P)<=0) && ccw(curr, next, P)>=0) {
     
      right_t = i;
    }
    if ((ccw(prev, curr, P)>=0) && (ccw(curr, next, P)<=0 )){
      
      left_t = i;
    }
    prev = curr;
  }
  return {left_t, right_t};// vi tri tiep tuyen trai va phai
}
// chu y cac diem cua da giac duyet cung chieu kim dong ho
//dau bang trong ccw xay ra khi tiep tuyen di qua canh
int prev(int x) {
  if (x == 0) return m-1;
  return x-1;
}

int next(int x) {
  return (x+1)%m;
}
int main() {
  freopen("sendinfor.inp","r",stdin);
  freopen("sendinfor.ok","w",stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &ships[i].x, &ships[i].y);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    point curr;
    scanf("%lld %lld", &curr.x, &curr.y);
    poly.push_back(curr);
  }
  poly.push_back(poly.front());

  point P = ships[0];
  point tangents = find_tangent(P);
  int R=tangents.second;
  int L=tangents.first;
  cerr << L << " " << R << "\n";

  int l_tangent = tangents.first, r_tangent = tangents.second;
  point l = P, r = P;
  set <point> s;
  set<point>::iterator it;
  for (int i = 1; i < n; i++) {
    point T = ships[i];
    if (ccw(P, poly[L], ships[i]) >= 0 || ccw(P, poly[R], ships[i]) <= 0) {
      s.insert(ships[i]);
    } else if (ccw(P, poly[L], ships[i]) < 0 &&
        ccw(P, poly[R], ships[i]) > 0 &&
        ccw(poly[L], poly[R], ships[i]) <= 0) {
      s.insert(ships[i]);// trong tam giac PRL
    }

    if (ccw(P, poly[L], T) >= 0) {
    // diem T nam ngoai duoi tt
      while(true) {
        int next_e = prev(l_tangent);
        if (ccw(poly[next_e], poly[l_tangent], T)<=0) {
          l_tangent = next_e;
          l = T;
        } else {
          break;
        }
      }
      if (ccw(l, poly[l_tangent], T) > 0) {
        l = T;
      }
    }

    if (ccw(P, poly[R], T) <= 0) {

      while(true) {
        int next_e = next(r_tangent);
        if (ccw(poly[r_tangent], poly[next_e], T)<=0) {
          r_tangent = next_e;
          r = T;
        } else {
          break;
        }
      }
      if (ccw(r, poly[r_tangent], T) < 0) {
        r = T;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    point p = ships[i];
    if (ccw(l, poly[l_tangent], p) >= 0) {
      s.insert(p);
    } else if (ccw(l, P, p) >= 0 && ccw(P, poly[l_tangent], p) >= 0) {
      s.insert(p);
    }

    if (ccw(r, poly[r_tangent], p) <= 0) {
      s.insert(p);
    } else if (ccw(P, r, p) >= 0 && ccw(poly[r_tangent], P, p) >= 0) {
      s.insert(p);
    }
  }
  s.erase(P);
  // for (it = s.begin(); it != s.end(); it ++) {
    // cerr << it -> x << " " << it -> y << "\n";
  // }
  printf("%lu\n", s.size());
  return 0;
}
