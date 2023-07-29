#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    freopen("Test.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    map<int, unordered_set<int>> expectedCourse;

    for(int i = 0; i < n; i++) {
        int id; cin >> id;
        int nCourse; cin >> nCourse;
        unordered_set<int> expectedCourseSet;
        for(int j = 0; j < nCourse; j++) {
            int course; cin >> course;
            expectedCourseSet.insert(course);
        }

        expectedCourse[id] = expectedCourseSet;
    }

    map<int, unordered_set<int>> actualCourse;
    for(int i = 0; i < m; i++) {
        int id; cin >> id;
        int nCourse; cin >> nCourse;
        unordered_set<int> actualCourseSet;
        for(int j = 0; j < nCourse; j++) {
            int course; cin >> course;
            actualCourseSet.insert(course);
        }

        actualCourse[id] = actualCourseSet;
    }

    map<int, vector<pii>> judgeMap;

    // Traverse the expected map and find from the actual map to see whether it satisfies the condition
    for(auto ele: expectedCourse) {
        int id = ele.first;
        unordered_set<int> expectedCourseSet = ele.second;
        // Cannot find the student in the actual course list
        if(actualCourse.find(id) == actualCourse.end()) {
            vector<pii> temp;
            for(auto course: expectedCourseSet)
                temp.push_back({course, 1});
            judgeMap[id] = temp;
        } else {
            unordered_set<int> actualCourseSet = actualCourse[id];
            vector<pii> temp;
            for(auto course: expectedCourseSet) {
                if(actualCourseSet.find(course) == actualCourseSet.end()) {
                    temp.push_back({course, 1});
                }
            }

            judgeMap[id] = temp;
        }
    }

    // Traverse the expected map and find from the actual map to see whether it satisfies the condition
    for(auto ele: actualCourse) {
        int id = ele.first;
        unordered_set<int> actualCourseSet = ele.second;
        // Cannot find the student in the actual course list
        if(expectedCourse.find(id) == expectedCourse.end()) {
            vector<pii> temp = judgeMap[id];
            for(auto course: actualCourseSet)
                temp.push_back({course, -1});
            judgeMap[id] = temp;
        } else {
            unordered_set<int> expectedCourseSet = expectedCourse[id];
            for(auto course: actualCourseSet) {
                if(expectedCourseSet.find(course) == expectedCourseSet.end()) {
                    judgeMap[id].push_back({course, -1});
                }
            }
        }
    }

    int cntPlus = 0, cntMinus = 0;
    int cntStudent = 0;
    for(auto ele: judgeMap) {
        int id = ele.first;
        vector<pii> ans = ele.second;
        if(ans.size() == 0) continue;
        cntStudent++;
        sort(ans.begin(), ans.end());
        cout << id << ' ';
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i].second == 1) cntPlus++;
            if(ans[i].second == -1) cntMinus++;
            cout << (ans[i].second == 1 ? '+' : '-') << ans[i].first << ' ';
        }
        cout << '\n';
    }

    if(cntPlus == 0 && cntMinus == 0) cout << "GREAT WORK! NO MISTAKES FOUND!";
    else cout << "MISTAKES IN " <<  cntStudent <<  " STUDENTS: " << cntMinus << " NOT REQUESTED, "  << cntPlus <<  " MISSED";


    return 0;
}
