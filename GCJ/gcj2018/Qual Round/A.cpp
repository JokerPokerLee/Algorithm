#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		int d;
		string str;
		cin >> d >> str;
		vector<int> c;
		int len = 1, sum = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'C') {
				len <<= 1;
			} else {
				c.push_back(len);
				sum += len;
			}
		}
		int cnt = 0;
		while (sum > d) {
			int pre = sum;
			for (int i = c.size() - 1; i >= 0; i--) {
				if (c[i] > 1) {
					if (i == 0 || c[i] > c[i - 1]) {
						c[i] >>= 1;
						sum -= c[i];
						cnt++;
						break;
					}
				}
			}
			if (pre == sum) {
				break;
			}
		}
		if (sum > d) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << cnt << endl;
		}
	}
	return 0;
}