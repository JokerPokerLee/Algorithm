#include <bits/stdc++.h>

#define MP make_pair

using namespace std;

struct Next {
	int n, s, w, e;
};

void update(set<pair<int, int>> &s, auto &p, int nl, int nr) {
	s.erase(p);
	p = s.insert(MP(nl, nr)).first;
}

auto add(set<pair<int, int>> &s, int p) {
	auto it = s.upper_bound(MP(p, p));
	if (it != s.end() && it -> first == p) {
		return it;
	}
	if (it != s.begin()) {
		auto pre = it;
		pre--;
		if (pre -> second == p - 1) {
			update(s, pre, pre -> first, p);
		}
		if (pre -> second == p && it != s.end() && it -> first == p + 1) {
			update(s, it, pre -> first, it -> second);
			int l = it -> first, r = it -> second;
			s.erase(pre);
			return s.find(MP(l, r));
		}
		if (pre -> second >= p) {
			return pre;
		}
	}
	if (it != s.end() && it -> first == p + 1) {
		update(s, it, p, it -> second);
		return it;
	}
	return s.insert(MP(p, p)).first;
}

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n, r, c, x, y;
		cin >> n >> r >> c >> x >> y;
		string command;
		cin >> command;
		vector<set<pair<int, int>>> row(r + 1), col(c + 1);
		auto cur_r = row[x].insert(MP(y, y)).first;
		auto cur_c = col[y].insert(MP(x, x)).first;
		for (int i = 0; i < n; i++) {
			// cout << "col:" << endl;
			// for (auto &p: col[y]) {
			// 	cout << "(" << p.first << ", " << p.second << ")" << endl;
			// }
			// cout << "row:" << endl;
			// for (auto &p: row[x]) {
			// 	cout << "(" << p.first << ", " << p.second << ")" << endl;
			// }
			switch (command[i]) {
				case 'N': {
						int dx = cur_c -> second;
						x = cur_c -> first;
						while (cur_c != col[y].begin()) {
							auto it = cur_c;
							it--;
							if (x - 1 > it -> second) {
								break;
							}
							x = it -> first;
							update(col[y], cur_c, x, dx);
							col[y].erase(it);
							cur_c = col[y].find(MP(x, dx));
						}
						x--;
						update(col[y], cur_c, x, dx);
						cur_r = add(row[x], y);
					}
					break;
				case 'S': {
						int dx = cur_c -> first;
						x = cur_c -> second;
						while (cur_c != col[y].end()) {
							auto it = cur_c;
							it++;
							if (it == col[y].end()) {
								break;
							}
							if (x + 1 < it -> first) {
								break;
							}
							x = it -> second;
							update(col[y], cur_c, dx, x);
							col[y].erase(it);
							cur_c = col[y].find(MP(dx, x));
						}
						x++;
						update(col[y], cur_c, dx, x);
						cur_r = add(row[x], y);
					}
					break;
				case 'W': {
						int dy = cur_r -> second;
						y = cur_r -> first;
						while (cur_r != row[x].begin()) {
							auto it = cur_r;
							it--;
							if (y - 1 > it -> second) {
								break;
							}
							y = it -> first;
							update(row[x], cur_r, y, dy);
							row[x].erase(it);
							cur_r = row[x].find(MP(y, dy));
						}
						y--;
						update(row[x], cur_r, y, dy);
						cur_c = add(col[y], x);
					}
					break;
				case 'E': {
						int dy = cur_r -> first;
						y = cur_r -> second;
						while (cur_r != row[x].end()) {
							auto it = cur_r;
							it++;
							if (it == row[x].end()) {
								break;
							}
							if (y + 1 < it -> first) {
								break;
							}
							y = it -> second;
							update(row[x], cur_r, dy, y);
							row[x].erase(it);
							cur_r = row[x].find(MP(dy, y));
						}
						y++;
						update(row[x], cur_r, dy, y);
						cur_c = add(col[y], x);
					}
					break;
			}
			// cout << x << " " << y << endl;
		}
		cout << "Case #" << tt << ": " << x << " " << y << endl;
	}
	return 0;
}