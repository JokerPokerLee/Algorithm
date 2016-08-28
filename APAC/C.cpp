#include <bits/stdc++.h>

#define LL long long
#define PLL pair<LL , LL>
#define MP make_pair

using namespace std;

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("C-small-attempt3.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n;
		LL x, y, A, B, C1, C2, M;
		cin >> n >> x >> y >> A >> B >> C1 >> C2 >> M;
		LL range = max(y, M);
		set<PLL>::iterator it;
		set<PLL> zero, one;
		vector<LL> L, R;
		zero.insert(MP(-1, range));
		for (int i = 0; i < n; i++) {
			// cout << "Round " << i << endl;
			LL l = min(x, y), r = max(x, y);
			L.push_back(l), R.push_back(r);
			// cout << l << " " << r << endl;
			PLL itv = MP(l, r);
			if (one.begin() != one.end()) {
				it = one.lower_bound(itv);
				while (it != one.begin()) {
					it--;
					if ((*it).second < l) {
						it++;
						break;
					}
				}
				if (it != one.end() && (*it).first < l) {
					LL tl = (*it).first;
					LL tr = (*it).second;
					one.erase(it);
					one.insert(MP(tl, l - 1));
					if (tr > r) {
						one.insert(MP(r + 1, tr));
					}
				}
				it = one.lower_bound(itv);
				while (it != one.end() && (*it).first <= r) {
					if ((*it).second <= r) {
						one.erase(it);
					} else {
						LL tmp = (*it).second;
						one.erase(it);
						one.insert(MP(r + 1, tmp));
						break;
					}
					it = one.lower_bound(itv);
				}
			}
			// cout << "one:" << endl;
			// it = one.begin();
			// while (it != one.end()) {
			// 	cout << (*it).first << " " << (*it).second << endl;
			// 	it++;
			// }
			it = zero.lower_bound(itv);
			while (it != zero.begin()) {
				it--;
				if ((*it).second < l) {
					it++;
					break;
				}
			}
			if (it != zero.end() && (*it).first < l) {
				LL tl = (*it).first;
				LL tr = (*it).second;
				one.insert(MP(l, min(tr, r)));
				zero.erase(it);
				zero.insert(MP(tl, l - 1));
				if (tr > r) {
					zero.insert(MP(r + 1, tr));
				}
			}
			it = zero.lower_bound(itv);
			while (it != zero.end() && (*it).first <= r) {
				if ((*it).second <= r) {
					one.insert((*it));
					zero.erase(it);
				} else {
					LL tl = (*it).first;
					LL tr = (*it).second;
					one.insert(MP(tl, r));
					zero.erase(it);
					zero.insert(MP(r + 1, tr));
					break;
				}
				it = zero.lower_bound(itv);
			}
			// cout << "zero:" << endl;
			// it = zero.begin();
			// while (it != zero.end()) {
			// 	cout << (*it).first << " " << (*it).second << endl;
			// 	it++;
			// }
			// cout << "one:" << endl;
			// it = one.begin();
			// while (it != one.end()) {
			// 	cout << (*it).first << " " << (*it).second << endl;
			// 	it++;
			// }
			LL nx, ny;
			nx = (A * x + B * y + C1) % M;
			ny = (A * y + B * x + C2) % M;
			x = nx, y = ny;
		}
		// cout << "---answer---" << endl;
		LL ans = 0;
		it = zero.begin();
		while (it != zero.end()) {
			ans += (*it).second - (*it).first + 1;
			// cout << (*it).first << " " << (*it).second << endl;
			// cout << ans << endl;
			it++;
		}
		LL tmp = 0;
		for (int i = 0; i < n; i++) {
			LL l = L[i], r = R[i];
			it = one.lower_bound(MP(l, r));
			LL sum = 0;
			while (it != one.end() && (*it).first <= r) {
				sum += min((*it).second, r) - (*it).first + 1;
				it++;
			}
			tmp = max(tmp, sum);
		}
		// it = one.begin();
		// while (it != one.end()) {
		// 	tmp = max(tmp, (*it).second - (*it).first + 1);
		// 	// cout << (*it).first << " " << (*it).second << endl;
		// 	// cout << tmp << endl;
		// 	it++;
		// }
		ans += tmp;
		cout << "Case #" << tt << ": " << (range + 2 - ans) << endl;
	}
	return 0;
}