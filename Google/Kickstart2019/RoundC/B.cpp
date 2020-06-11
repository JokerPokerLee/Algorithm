#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int r, c, diff;
		cin >> r >> c >> diff;
		vector<vector<int>> v(r), tail(r);
		for (int i = 0; i < r; i++) {
			v[i] = vector<int>(c);
			for (int j = 0; j < c; j++) {
				cin >> v[i][j];
			}
			tail[i] = vector<int>(c);
			for (int j = 0; j < c; j++) {
				tail[i][j] = j;
				int mini = v[i][j];
				int maxi = v[i][j];
				for (int k = j + 1; k < c; k++) {
					mini = min(mini, v[i][k]);
					maxi = max(maxi, v[i][k]);
					if (maxi - mini > diff) {
						break;
					}
					tail[i][j] = k;
				}
			}
		}
		// for (int i = 0; i < r; i++) {
		// 	for (int j = 0; j < c; j++) {
		// 		cout << tail[i][j] << " \n"[j == c - 1];
		// 	}
		// }
		int ans = r;
		for (int le = 0; le < c; le++) {
			for (int ri = le + 1; ri < c; ri++) {
				int pre = -1;
				for (int i = 0; i < r; i++) {
					if (tail[i][le] < ri) {
						pre = i;
						continue;
					} else {
						ans = max(ans, (i - pre) * (ri - le + 1));
						// cout << le << ", " << ri << ": " << i << " - " << ans << endl;
					}
				}
			}
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}