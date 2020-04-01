#include <bits/stdc++.h>
using namespace std;

long long l1, r1, t1;
long long l2, r2, t2;
long long res, delta, c, deltaL, len1, len2, tmp1, tmp2;

void calc() {
	c = __gcd(t1, t2);
	deltaL = l2 - l1;
	len1 = r1 - l1 + 1;
	len2 = r2 - l2 + 1;

	tmp1 = deltaL / c * c;
	if (tmp1 < l2 - l1) tmp2 = tmp1 + c;
	else tmp2 = tmp1 - c;
	
	delta = tmp1 - (l2 - l1);

	if (delta >= 0) res = max(res, min(len2 - delta, len1));
	else res = max(res, min(len1 + delta, len2));

	delta = tmp2 - (l2 - l1);

	if (delta >= 0) res = max(res, min(len2 - delta, len1));
	else res = max(res, min(len1 + delta, len2));
}

int main() {
	cin >> l1 >> r1 >> t1;
	cin >> l2 >> r2 >> t2;
	calc();
	l1 = - l1;
	l2 = - l2;
	r1 = - r1;
	r2 = - r2;
	swap(l1, r1);
	swap(l2, r2);
	calc();
	cout << res;
}