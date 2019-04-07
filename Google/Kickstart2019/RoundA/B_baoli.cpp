#include <bits/stdc++.h>

#define MP make_pair
#define PII pair<int, int>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
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
		if (office.size() == r * c) {
			printf("Case #%d: %d\n", tt, 0);
			continue;
		}
		int ans = 250000, x, y;
		for (int ii = 0; ii < r; ii++) {
			for (int jj = 0; jj < c; jj++) {
				if (grid[ii][jj] == '0') {
					office.push_back(MP(ii, jj));
					for (int g = 0; g < r; g++) {
						for (int h = 0; h < c; h++) {
							vis[g][h] = 0;
						}
					}
					queue<PII> q;
					for (int i = 0; i < office.size(); i++) {
						q.push(office[i]);
						vis[office[i].first][office[i].second] = 1;
					}
					int d = 0;
					while (q.size()) {
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
						if (q.size()) d++;
					}
					ans = min(ans, d);
					office.pop_back();
				}
			}
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}