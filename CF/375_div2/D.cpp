#include <bits/stdc++.h>

using namespace std;

int a[55][55];
bool vis[55][55];
int n, m, k;

int fill(int x, int y) {
	int res = 1;
	vis[x][y] = true;
	if (x > 0 && !a[x - 1][y] && !vis[x - 1][y]) {
		res += fill(x - 1, y);
	}
	if (x <= n && !a[x + 1][y] && !vis[x + 1][y]) {
		res += fill(x + 1, y);
	}
	if (y > 0 && !a[x][y - 1] && !vis[x][y - 1]) {
		res += fill(x, y - 1);
	}
	if (y <= m && !a[x][y + 1] && !vis[x][y + 1]) {
		res += fill(x, y + 1);
	}
	return res;
}

int change(int x, int y) {
	a[x][y] = 1;
	if (x > 1 && !a[x - 1][y]) {
		change(x - 1, y);
	}
	if (x < n && !a[x + 1][y]) {
		change(x + 1, y);
	}
	if (y > 1 && !a[x][y - 1]) {
		change(x, y - 1);
	}
	if (y < m && !a[x][y + 1]) {
		change(x, y + 1);
	}
}

int main() {
	freopen("1.in", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '*') {
				a[i + 1][j + 1] = 1;
			}
		}
	}
	fill(0, 0);
	int cnt = 0;
	vector< pair<int , int> > area;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!a[i][j] && !vis[i][j]) {
				area.push_back(make_pair(fill(i, j), ((i - 1) * m) + (j - 1)));
				cnt++;
			}
		}
	}
	sort(area.begin(), area.end());
	cnt = cnt - k;
	int ans = 0;
	for (int i = 0; i < cnt; i++) {
		ans += area[i].first;
		change(area[i].second / m + 1, area[i].second % m + 1);
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j == m) {
				printf("\n");
			} else {
				if (a[i + 1][j + 1]) {
					printf("*");
				} else {
					printf(".");
				}
			}
		}
	}
	return 0;
}