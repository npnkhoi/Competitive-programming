#include <bits/stdc++.h>
using namespace std;

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int START_YEAR = 1900;

int count_mul(int start, int end, int divisor) {
	return end / divisor - (start - 1) / divisor;
}

bool leap(int y) {
	if (y % 4 != 0) return false;
	if (y % 100 != 0) return true;
	if (y % 400 != 0) return false;
	return true;
}

int get_id(int year, int month, int day) {
	int ret = 0;
	for (int y = START_YEAR; y < year; ++ y) {
		ret += 365 + leap(y);
	}
	ret += days_in_month[month - 1] + (leap(year) && month > 2);
	ret += day;
	return ret;
}

int day_in_week(int id) {
	// id = 1 => Monday
	return (id + 1) % 7;
}

void init() {
	for (int i = 2; i <= 12; ++ i) {
		days_in_month[i] += days_in_month[i - 1];
	}
}

int main() {
	init();
	int y1, m1, d1, y2, m2, d2, x, n;
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2 >> x;
	x %= 7;
	int start_id = get_id(y1, m1, d1);
	int end_id = get_id(y2, m2, d2);
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		int y, m, d;
		cin >> y >> m >> d;
		int id = get_id(y, m, d);
		if (start_id <= id && id <= end_id && day_in_week(id) == x) {
			cout << "VALID\n";
		} else {
			cout << "INVALID\n";
		}
	}
}