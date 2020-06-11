#include <bits/stdc++.h>

using namespace std;

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int n;
		cin >> n;
		vector<int> s, e, l;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			s.push_back(x);
			e.push_back(y);
			l.push_back(z);
		}
		bool diff = false;
		for (int i = 1; i < n; i++) {
			if (s[i] != s[i - 1]) {
				diff = true;
				break;
			}
		}
		int ans = 0;
		vector<vector<int>> val(n);
		for (int i = 0; i < n; i++) {
			val[i] = vector<int>(n, 0);
			val[i][0] = e[i];
			ans += e[i];
			for (int j = 1; val[i][j - 1] && j < n; j++) {
				val[i][j] = max(val[i][j - 1] - l[i] * s[i], 0);
			}
		}
	}
	return 0;
}