#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int n, w, v, u;
	cin >> n >> w >> v >> u;
	vector<int> x, y;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int tx, ty;
		cin >> tx >> ty;
		x.push_back(tx);
		y.push_back(ty);
		double t = 1.0 * x[i] / v;
		if (u * t < y[i] - 1e-9)
			flag = false;
	}
	if (flag) {
		cout << (1.0 * w / u) << endl;
		return 0;
	}
	int p = 0;
	for (int i = 0; i < n; i++)
		if (y[i] < y[p])
			p = i;
	double now = 0.0, ans = 0.0;
	p = (p + n - 1) % n;
	do {
		p = (p + 1) % n;
		double t = 1.0 * x[p] / v;
		now = min(now + u * (t - ans), 1.0 * y[p]);
		ans = t;
	} while (p < n && x[p] < x[(p + 1) % n]);
	ans += (w - now) / u;
	printf("%.10f\n", ans);
	return 0;
}