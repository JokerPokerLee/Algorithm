#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, x;
	scanf("%d %d", &n, &m);
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = vector<int>(m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	vector<int> r(n), c(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			if (x ^ a[i][j]) {
				r[i]++, c[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (r[i] & 1) {
			// cout << "r" << endl;
			// cout << i << endl;
			cout << "No" << endl;
			return 0;
		}
	}
	for (int i = 0; i < m; i++) {
		if (c[i] & 1) {
			// cout << "c" << endl;
			// cout << i << endl;
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}