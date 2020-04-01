// Create a folder contain this checker, need-being-checked code and the tests
// Being-checked code must use standard I/O

#include <bits/stdc++.h>
using namespace std;
#define task ""

string toString(int num, int rem) {
	if (rem == 0) return "";
	else return toString(num / 10, rem - 1) + (char) (num % 10 + '0');
}

int main() {
	string codeName = "THANGBOM"; 															// edit here

	int l = 1, r = 20;  																	// edit here
	int score = 0;
	for (int iTest = l; iTest <= r; ++ iTest) {
		string testname = "Test" + toString(iTest, 2) + ""; 					// edit here
		string inp = testname + ".inp";										// edit here
		string out = testname + ".out";										// edit here
		string ans = testname + ".ans";										// edit here

		double Time = clock();
		system((codeName + ".exe < " + inp + " > " + ans).c_str());
		// cerr << "Execution time: " << (clock() - Time) / CLOCKS_PER_SEC << "\n";

		if (!system(("fc " + out + " " + ans).c_str())) {
			score ++;
		} else {
			cerr << "Wrong Answer\n";
			break;
		}
	}
	cerr << "Total Score: " << score << "\n";
}