#include <bits/stdc++.h>

using namespace std;

double sqr(double x) {
	return x * x;
}

int main() {
	freopen("1.in", "r", stdin);
	double a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	double ans = 1e10;
	for (int i = 0; i < n; i++) {
		double x, y, v;
		cin >> x >> y >> v;
		ans = min(ans, sqrt(sqr(x - a) + sqr(y - b)) / v);
	}
	cout << setprecision(10) << ans << endl;
	return 0;
}