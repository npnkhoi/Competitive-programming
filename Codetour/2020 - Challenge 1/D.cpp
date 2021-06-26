#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int, int> User; // (att, id)
#define ordered_set tree<User, null_type,less<User>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set set_id, set_att, set_out;

int idx, n, k;

void add(int att, int idx) {
	set_att.insert({att, idx});
	set_id.insert({idx, att});
}

void del(int id, int att) {
	set_att.erase({att, id});
	set_id.erase({id, att});
	if (set_att.size() < k && !set_out.empty()) {
		int last_idx = int(set_out.size()) - 1;
		ordered_set::iterator user = set_out.find_by_order(last_idx);
		add(user -> first, user -> second);
		set_out.erase(user);
	}
}


void add_user(int att) {
	add(att, idx);
	idx ++;

	if (set_att.size() > k) {
		ordered_set::iterator removed = set_id.find_by_order(0);
		int rem_id = removed -> first, rem_att = removed -> second;
		del(rem_id, rem_att);
		set_out.insert({rem_id, rem_att});
	}
}

int get_best_user() {
	ordered_set::iterator user = set_att.find_by_order(set_att.size() - 1);
	int ret = user -> first;
	del(user -> second, user -> first);
	return ret;
}

int get_pos_user(int pos) {
	int ret;
	if (pos < set_out.size()) {
		ordered_set::iterator user = set_out.find_by_order(pos);
		ret = user -> second;
		set_out.erase(user);
	} else {
		pos -= set_out.size();
		ordered_set::iterator user = set_att.find_by_order(pos);
		ret = user-> first;
		set_id.erase(user);
	}
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++ i) {
		int type;
		cin >> type;
		if (type == 1) {
			int attractiveness;
			cin >> attractiveness;
			add_user(attractiveness);
		} else if (type == 2) {
			cout << get_best_user() << '\n';
		} else {
			int pos; cin >> pos;
			pos --;
			int att = get_pos_user(pos);
			// printf("shifted user: %d\n", att);
			add_user(att);
		}
	}
}