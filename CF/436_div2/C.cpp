#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	long long a, b, f, k;
	cin >> a >> b >> f >> k;
	long long ff = 2 * f, rf = 2 * (a - f);
	if (b < f || b < a - f) {
		cout << "-1" << endl;
		return 0;
	}
	if (k == 2 && b < rf) {
		cout << "-1" << endl;
		return 0;
	}
	if (k > 2 && (b < ff || b < rf)) {
		cout << "-1" << endl;
		return 0;
	}
	long long cur = b - f;
	int ans = 0;
	for (int i = 0; i < k - 1; i++) {
		long long ahead = (i & 1) ? ff : rf;
		// cout << ahead << " " << cur << endl;
		if (cur < ahead) {
			cur = b;
			ans++;
		}
		cur -= ahead;
	}
	if (cur < ((k & 1) ? (a - f) : f)) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}