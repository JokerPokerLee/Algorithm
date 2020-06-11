#include <bits/stdc++.h>

#define MP make_pair
#define EPS 1e-7

using namespace std;

typedef pair<int, int> PII;

bool cmp(PII s1, PII s2) {
	return s1.first * s2.second > s2.first * s1.second;
}

double cross(double x, vector<PII> &p) {
	int l = 0, r = p.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (p[m].first > x) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	l = r, r = l + 1;
	// if (p[l].first - p[r].first == 0) {

	// }
	double k = 1.0 * (p[l].first - x) / (p[l].first - p[r].first);
	return p[l].second + k * (p[r].second - p[l].second);
}

int main() {
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		int d, s, x, y;
		scanf("%d %d", &d, &s);
		vector<PII> slots;
		int fsum = 0, ssum = 0;
		for (int i = 0; i < s; i++) {
			scanf("%d %d", &x, &y);
			slots.push_back(MP(x, y));
			fsum += x, ssum += y;
		}
		sort(slots.begin(), slots.end(), cmp);
		// for (int i = 0; i < s; i++) {
		// 	cout << slots[i].first << " " << slots[i].second << endl;
		// }
		vector<PII> bl, tr;
		bl.push_back(MP(fsum, 0));
		tr.push_back(MP(0, ssum));
		int fcur = 0, scur = 0;
		for (int i = 0; i < s; i++) {
			fcur += slots[i].first;
			scur += slots[i].second;
			bl.push_back(MP(fsum - fcur, scur));
			tr.push_back(MP(fcur, ssum - scur));
		}
		reverse(tr.begin(), tr.end());
		// cout << "bl" << endl;
		// for (int i = 0; i <= s; i++) {
		// 	cout << bl[i].first << " " << bl[i].second << endl;
		// }
		// cout << "tr" << endl;
		// for (int i = 0; i <= s; i++) {
		// 	cout << tr[i].first << " " << tr[i].second << endl;
		// }
		string res = "";
		for (int i = 0; i < d; i++) {
			scanf("%d %d", &x, &y);
			if (x > tr[0].first) {
				res += 'N';
				continue;
			}
			double l = cross(x, bl);
			double r = cross(x, tr);
			// cout << x << " " << y << ": " << l << " " << r << endl;
			// res += "YN"[l - EPS <= y && y <= r + EPS];
			res += "NY"[y <= r + EPS];
		}
		printf("Case #%d: %s\n", tt, res.c_str());
	}
	return 0;
}