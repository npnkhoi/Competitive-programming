#include <bits/stdc++.h>
using namespace std;

const int END_OF_DAY = 24 * 60;
const int mon_len[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef pair<pair<int, int>, int> Pack;

map<int, vector<Pack>> day;
int dp[END_OF_DAY + 3];

int f(char ch) {
	return ch - '0';
}

int str_to_num(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); ++ i) {
		ret = ret * 10 + s[i] - '0';
	}
	return ret;
}

string num_to_str(int n) {
	string ret = "";
	while (n) {
		ret = (char)(n % 10 + '0') + ret;
	}
	return ret;
}

bool collide(int x, int y, int u, int v) {
	if ((v <= x) || (y <= u)) return false;
	return true;
}

int len(int mon, int leap) {
	if (mon != 2) return mon_len[mon];
	else return mon_len[mon] + leap;
}

string next_day(string str) {
	int d = f(str[0]) * 10 + f(str[1]);
	int m = f(str[2]) * 10 + f(str[3]);
	int y = f(str[4]) * 10 + f(str[5]);
	bool leap = ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0));
	if (d == len(m, leap)) {
		d = 1;
		if (m == 12) {
			m = 1;
			y ++;
		} else {
			m ++;
		}
	} else {
		d ++;
	}
	return num_to_str(d) + num_to_str(m) + num_to_str(y);
}

void parsing(vector<vector<string>> &taskList) {
	// get task from taskList
	// eliminate invalid task

	for (int ii = 0; ii < taskList.size(); ++ ii) {
		#define task taskList[ii]
		// task: "hhmm ddMMyyyy
		string day1, day2;

		for (int i = 5; i < 9; ++ i) day1 += task[0][i];
		for (int i = 5; i < 9; ++ i) day2 += task[1][i];
		// cerr << "day12 " << day1 << ' ' << day2 << '\n';

		int time1 = (f(task[0][0]) * 10 + f(task[0][1])) * 60 + (f(task[0][2]) * 10 + f(task[0][3]));
		int time2 = (f(task[1][0]) * 10 + f(task[1][1])) * 60 + (f(task[1][2]) * 10 + f(task[1][3]));
		// cerr << "time12 " << time1 << ' ' << time2 << '\n';
		if (day1 != day2) {
			if (time2 == 0 && next_day(day1) == day2) {
				time2 = END_OF_DAY;
			} else continue;
		}

		if (collide(time1, time2, 0, 480) || collide(time1, time2, 720, 780)) {
			continue;
		}

		int cost = (time2 - time1) * str_to_num(task[2]) / 60;

		day[str_to_num(day1)].push_back({{time1, time2}, cost});
	}
}

int process() {
	// dp
	int res = 0;
	for (map<int, vector<Pack>>::iterator it = day.begin(); it != day.end(); ++ it) {
		#define tasks it->second

		if (tasks.size() == 1) {
			res += tasks[0].second;
			continue;
		}
		else if (tasks.size() == 2) {
			if (collide(tasks[0].first.first, tasks[0].first.second, tasks[1].first.first, tasks[1].first.second)) {
				res += (max(tasks[1].second, tasks[0].second));
			} else {
				res += tasks[1].second + tasks[0].second;
			}
			continue;
		}

		sort(tasks.begin(), tasks.end(), [](Pack task1, Pack task2) {
			return task1.first.second < task2.first.second;
		});

		// for (int i = 0; i < tasks.size(); ++ i) {
		// 	cerr << tasks[i].first.first << ' ' << tasks[i].first.second << ' ' << tasks[i].second << '\n';
		// }
		// cerr << '\n';

		dp[0] = 0;
		int idx = 0;

		for (int i = 0; i < tasks.size(); ++ i) {
			while (idx + 1 < tasks[i].first.second) {
				++ idx;
				dp[idx] = dp[idx - 1];
			}
			dp[tasks[i].first.second] = max(dp[tasks[i].first.second], dp[tasks[i].first.first] + tasks[i].second);
			++ idx;
		}
		res += dp[tasks[tasks.size() - 1].first.second];
	}
	return res;
}

int maximumEarning(std::vector<std::vector<std::string>> taskList) {
	parsing(taskList);
	return process();
}


int main() {
	vector<vector<string>> test = {
		{"0800 24092018", "0900 24092018", "15"},  
		{"0800 24092018", "0900 24092018", "25"}, 
		{"0845 24092018", "1000 24092018", "50"}, 
		{"0900 24092018", "1000 24092018", "50"} ,
		{"1200 24092018", "1230 24092018", "150"}, 
		{"2300 24092018", "0015 25092018", "1000"} };
	cerr << maximumEarning(test);
}