#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-small-attempt0.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		int n;
		double d;
		scanf("%lf %d", &d, &n);
		vector<double> p, v;
		for (int i = 0; i < n; i++) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			p.push_back(x);
			v.push_back(y);
		}
		double ans = 0;
		for (int i = 0; i < n; i++) {
			bool merge = false;
			for (int j = 0; j < n; j++) {
				if (p[j] > p[i]) {
					double dt = (p[j] - p[i]) / (v[i] - v[j]);
					if (dt < 0) {
						continue;
					}
					double pos = v[j] * dt + p[j];
					// cout << dt << " " << pos << endl;
					if (pos < d) {
						merge = true;
						break;
					}
				}
			}
			// cout << merge << endl;
			// cout << d << " " << p[i] << " " << v[i] << endl;
			if (!merge) {
				ans = max((d - p[i]) / v[i], ans);
				// cout << ans << endl;
			}
		}
		printf("%.6f\n", d / ans);
	}
	return 0;
}