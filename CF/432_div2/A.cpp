#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n, k, t;
	cin >> n >> k >> t;
	if (t <= k) {
		cout << t << endl;
	} else {
		if (t > n) {
			cout << max(0, k - t + n) << endl;;
		} else {
			cout << k << endl;
		}
	}
	return 0;
}