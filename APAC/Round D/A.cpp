#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("1.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		double n, m;
		cin >> n >> m;
		double ans = n / (n + m);
		ans *= 1.0 - m / n;
		cout << "Case #" << tt << ": " << setprecision(10) << ans << endl;
	}
	return 0;
}