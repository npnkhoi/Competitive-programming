#include <bits/stdc++.h>
using namespace std;

string line, current_project;
map<string, pair<string, bool> > record;
map<string, int> cnt;
vector<pair<int, string> > stat;

void process() {
	// after read all students for one projects
	for (pair<string, pair<string, bool> > item : record) {
		if (item.second.second) cnt[item.second.first] += 1;
	}
	for (auto item : cnt) {
		stat.push_back({-item.second, item.first});
	}
	sort(stat.begin(), stat.end());
	for (auto item : stat) {
		printf("%s %d\n", item.second.c_str(), -item.first);
	}
	// reset data for next testcase
	record.clear();
	cnt.clear();
	stat.clear();
}

int main() {
	while (getline(cin, line)) {
		if (line == "0") break;
		else if (line == "1") process();
		else if ('A' <= line[0] && line[0] <= 'Z') {
			// add project
			current_project = line;
			cnt[line] = 0;
		} else {
			// add student (= line)
			if (record.find(line) != record.end()) {
				if (record[line].first != current_project) record[line].second = false;
			} else {
				record[line] = {current_project, true};
			}
		}
	}
}