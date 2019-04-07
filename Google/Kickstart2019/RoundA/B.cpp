#include <bits/stdc++.h>

#define MP make_pair
#define PII pair<int, int>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		int r, c;
		string line;
		cin >> r >> c;
		vector<string> grid;
		vector<PII> office;
		vector<vector<int>> vis(r);
		for (int i = 0; i < r; i++) {
			cin >> line;
			grid.push_back(line);
			for (int j = 0; j < c; j++) {
				if (line[j] == '1') {
					office.push_back(MP(i, j));
				}
			}
			vis[i] = vector<int>(c);
		}
		int le = 4, ri = 5, ti = 0, x, y;
		while (le <= ri) {
			int m = (le + ri) / 2;
			cout << m << endl;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					vis[i][j] = 0;
				}
			}
			queue<PII> q;
			for (int i = 0; i < office.size(); i++) {
				q.push(office[i]);
				vis[office[i].first][office[i].second] = 1;
			}
			for (int d = 0; q.size() && d < m; d++) {
				queue<PII> nq;
				while (q.size()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					if (x && !vis[x - 1][y]) {
						nq.push(MP(x - 1, y));
						vis[x - 1][y] = 1;
					}
					if (y && !vis[x][y - 1]) {
						nq.push(MP(x, y - 1));
						vis[x][y - 1] = 1;
					}
					if (x < r - 1 && !vis[x + 1][y]) {
						nq.push(MP(x + 1, y));
						vis[x + 1][y] = 1;
					}
					if (y < c - 1 && !vis[x][y + 1]) {
						nq.push(MP(x, y + 1));
						vis[x][y + 1] = 1;
					}
				}
				q = nq;
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						cout << vis[i][j];
					}
					cout << endl;
				}
				cout << "--- " << d << " ---" << endl;
			}
			int minSum = 500, maxSum = 0;
			int minSub = 500, maxSub = -500;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!vis[i][j]) {
						cout << i << " " << j << endl;
						minSum = min(minSum, i + j);
						maxSum = max(maxSum, i + j);
						minSub = min(minSub, i - j);
						maxSub = max(maxSub, i - j);
					}
				}
			}
			printf("%d %d %d %d\n", minSum, maxSum, minSub, maxSub);
			if (maxSum - minSum == 2 * m && maxSub - minSub == 2 * m) {
				if ((maxSum ^ maxSub) & 1) {
					le = m + 1;
				} else {
					ri = m - 1;
				}
			} else {
				if (maxSum - minSum <= 2 * m && maxSub - minSub <= 2 * m) {
					ri = m - 1;
				} else {
					le = m + 1;
				}
			}
		}
		printf("Case #%d: %d\n", tt, le);
	}
	return 0;
}