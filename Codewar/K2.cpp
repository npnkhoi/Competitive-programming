#include <bits/stdc++.h>
using namespace std;

const int END_OF_DAY = 24 * 60;
const int mon_len[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef pair<pair<int, int>, int> Pack;

vector<vector<Pack>> day;
map<int, int> id;
int dp[END_OF_DAY + 3];
int cnt_date = 0;

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

int next_day(int date) {
	int d = date / 1000000;
	int m = date % 1000000 / 10000;
	int y = date % 10000;
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
	return d * 1000000 + m * 10000 + y;
}

int get_id(int date) {
	if (id.find(date) == id.end()) {
		id[date] = cnt_date;
		cnt_date ++;
		day.push_back({});
	}
	return id[date];
}

void parsing(vector<vector<string>> &taskList) {
	// get task from taskList
	// eliminate invalid task

	for (int ii = 0; ii < taskList.size(); ++ ii) {
		#define start_time taskList[ii][0]
		#define end_time taskList[ii][1]
		#define wage taskList[ii][2]

		int time1 = (f(start_time[0]) * 10 + f(start_time[1])) * 60 + (f(start_time[2]) * 10 + f(start_time[3]));
		int date1 = 0;
		for (int i = 5; i <= 12; ++ i) date1 = 10 * date1 + f(start_time[i]);
		int time2 = (f(end_time[0]) * 10 + f(end_time[1])) * 60 + (f(end_time[2]) * 10 + f(end_time[3]));
		int date2 = 0;
		for (int i = 5; i <= 12; ++ i) date2 = 10 * date2 + f(end_time[i]);

		if (date1 != date2) {
			if (time2 == 0 && next_day(date1) == date2) {
				time2 = END_OF_DAY;
			} else continue; // because this is an invalid task
		}

		if (collide(time1, time2, 0, 480) || collide(time1, time2, 720, 780)) {
			continue;
		}

		int cost = (time2 - time1) * str_to_num(wage) / 60;

		day[get_id(date1)].push_back({{time1, time2}, cost});
	}
}

int process() {
	// dp
	int res = 0;
	for (int i = 0; i < day.size(); ++ i) {
		// cerr << "day " << i << '\n';
		#define tasks day[i]

		// cerr << "number of tasks in day: " << tasks.size() << '\n';

		if (tasks.size() == 1) {
			res += tasks[0].second;
			continue;
		}
		else if (tasks.size() == 2) {
			if (collide(tasks[0].first.first, tasks[0].first.second, tasks[1].first.first, tasks[1].first.second)) {
				res += max(tasks[1].second, tasks[0].second);
			} else {
				res += tasks[1].second + tasks[0].second;
			}
			continue;
		}

		sort(tasks.begin(), tasks.end(), [](Pack task1, Pack task2) {
			return task1.first.second < task2.first.second;
		});

		// for (int j = 0; j < tasks.size(); ++ j) {
		// 	cerr << j << '\n';
		// 	cerr << tasks[j].first.first << ' ' << tasks[j].first.second << ' ' << tasks[j].second << '\n';
		// }
		// cerr << "safe\n";

		dp[0] = 0;
		int idx = 0;
		int tmp = 0;

		for (int j = 0; j < tasks.size(); ++ j) {
			while (idx + 1 <= tasks[j].first.second) {
				++ idx;
				dp[idx] = dp[idx - 1];
			}
			dp[tasks[j].first.second] = max(dp[tasks[j].first.second], dp[tasks[j].first.first] + tasks[j].second);
			// ++ idx;
		}
		res += dp[tasks[tasks.size() - 1].first.second];
	}
	return res;
}

int maximumEarning(std::vector<std::vector<std::string>> taskList) {
	parsing(taskList);
	// cerr << "safe\n";
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