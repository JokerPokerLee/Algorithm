#include <bits/stdc++.h>

using namespace std;

int f[10][50][50];

int main() {
	freopen("1.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("B-small-attempt0.out", "w", stdout);
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		int n, m;
		cin >> n >> m;
		int maxi = (1 << m);
		vector<int> row, peo;
		for (int i = 0; i < maxi; i++) {
			int cnt = 0, comb = 0;
			int tmp = i;
			for (int j = 0; j < m; tmp >>= 1, j++) {
				if (tmp & 1) {
					cnt++, comb++;
					if (comb >= 3) {
						cnt = -1;
						break;
					}
				} else {
					comb = 0;
				}
			}
			if (cnt != -1) {
				row.push_back(i);
				peo.push_back(cnt);
			}
		}
		memset(f, 0, sizeof(f));
		for (int i = 0; i < row.size(); i++) {
			f[1][i][0] = peo[i];
		}
		for (int i = 0; i < row.size(); i++) {
			for (int j = 0; j < row.size(); j++) {
				f[2][i][j] = peo[i] + peo[j];
			}
		}
		for (int i = 3; i <= n; i++) {
			for (int j = 0; j < row.size(); j++) {
				for (int g = 0; g < row.size(); g++) {
					for (int h = 0; h < row.size(); h++) {
						// cout << j << " " << g << " " << h << endl;
						// cout << (row[j] & row[g] & row[h]) << endl;
						if (!(row[j] & row[g] & row[h])) {
							f[i][j][g] = max(f[i][j][g], f[i - 1][g][h]);
						}
						// cout << "======" << f[i][j][g] << "======" << endl;
					}
					if (f[i][j][g]) {
						f[i][j][g] += peo[j];
					}
					// cout << "!!!" << f[i][j][g] << endl;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < row.size(); i++) {
			for (int j = 0; j < row.size(); j++) {
				ans = max(ans, f[n][i][j]);
			}
		}
		cout << "Case #" << tt << ": " << ans << endl;
		// return 0;
	}
	return 0;
}