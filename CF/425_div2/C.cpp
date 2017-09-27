#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	double s;
	scanf("%d %f", &n, &s);
	vector< pair<int, int> > pl, pr;
	int dir = 0;
	for (int i = 0; i < n; i++) {
		int x, v, t;
		scanf("%d %d %d", &x, &v, &t);
		dir |= t;
		if (t == 1) {
			pl.push_back(make_pair(x, v));
		} else {
			pr.push_back(make_pair(x, v))
		}
	}
	if (dir != 3) {
		printf("-1\n");
		return 0;
	}
	double l = 0, r = 1000000;
	for (int cnt = 30; cnt; cnt--) {
		double m = (l + r) / 2.0;
		memset(cl, 0, sizeof(c));
		for (int i = 0; i < lp.size(); i++) {
			double x = lp[i].first;
			double v = lp[i].second;
			double y = s * m - (v / s) * v * m + (v / s) * x;
			int bor
		}
	}
	return 0;
}