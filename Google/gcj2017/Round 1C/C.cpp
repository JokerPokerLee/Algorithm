#include <bits/stdc++.h>

#define PII pair<int, int>
#define MP make_pair

const double PI = acos(-1.0);

using namespace std;

bool cmp1(PII a, PII b) {
	if (a.first > b.first) return true;
	if (a.first < b.first) return false;
	return a.second > b.second;
}

bool cmp2(PII a, PII b) {
	return 1LL * a.first * a.second > 1LL * b.first * b.second;
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		int n, k;
		scanf("%d %d", &n, &k);
		double u;
		scanf("%lf", &u);
		vector<double> p;
		for (int i = 0; i < n; i++) {
			double x;
			scanf("%lf", &x);
			p.push_back(x);
		}
		double l = 0, r = 1;
		for (int i = 0; i < 100; i++) {
			double m = (l + r) / 2.0;
			double tmp = 0.0;
			for (int j = 0; j < n; j++) {
				tmp += max(0.0, m - p[j]);
			}
			if (tmp < u) {
				l = m;
			} else {
				r = m;
			}
		}
		double ans = 1.0;
		for (int i = 0; i < n; i++) {
			if (p[i] < l) {
				p[i] = l;
			}
			ans *= p[i];
		}
		printf("%.10f\n", ans);
	}
	return 0;
}