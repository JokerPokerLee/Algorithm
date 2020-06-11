#include <bits/stdc++.h>

using namespace std;

int n, m;

int dfs(int p, vector<int> &vis, vector<int> &path) {
	if (path.size() == n * m) {
		return 1;
	}
	int x = p / m;
	int y = p % m;
	for (int np = 0; np < n * m; np++) {
		if (vis[np]) continue;
		int nx = np / m;
		int ny = np % m;
		if (nx == x || ny == y || nx + ny == x + y || nx - ny == x - y) {
			continue;
		}
		vis[np] = 1;
		path.push_back(np);
		if (dfs(np, vis, path)) return 1;
		vis[np] = 0;
		path.pop_back();
	}
	return 0;
}

bool baoli(vector<int> &path) {
	vector<int> vis(n * m, 0);
	for (int i = 0; i < n * m; i++) {
		path.push_back(i);
		vis[i] = 1;
		if (dfs(i, vis, path)) {
			return true;
		}
		vis[i] = 0;
		path.pop_back();
	}
	return false;
}

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		cin >> n >> m;
		cout << "Case #" << tt << ": ";
		bool flip = false;
		if (n > m) {
			swap(n, m);
			flip = true;
		}
		if (n == 1) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		vector<int> path;
		if (m <= 5) {
			if (baoli(path)) {
				cout << "POSSIBLE" << endl;
				for (int i = 0; i < path.size(); i++) {
					int x = path[i] / m + 1;
					int y = path[i] % m + 1;
					if (flip) {
						cout << y << " " << x << endl;
					} else {
						cout << x << " " << y << endl;
					}
				}
			} else {
				cout << "IMPOSSIBLE" << endl;
			}
			continue;
		}
		int rem = n, base = 0;
		while (rem > 3 || rem == 2) {
			for (int i = 2; i < m; i++) {
				path.push_back(m + i + base);
				path.push_back(i - 2 + base);
			}
			path.push_back(m + base);
			path.push_back(m - 2);
			path.push_back(m + base + 1);
			path.push_back(m - 1);
			base += 2 * m;
			rem -= 2;
		}
		if (rem) {
			for (int i = 2; i < m; i++) {
				path.push_back(i - 2 + base);
				path.push_back(m + i + base);
				path.push_back(2 * m + i - 2 + base);
			}
			path.push_back(m - 2 + base);
			path.push_back(m + base);
			path.push_back(m * 3 - 2 + base);
			path.push_back(m - 1 + base);
			path.push_back(m + 1 + base);
			path.push_back(m * 3 - 1 + base);
		}
		cout << "POSSIBLE" << endl;
		for (int i = 0; i < path.size(); i++) {
			int x = path[i] / m + 1;
			int y = path[i] % m + 1;
			if (flip) {
				cout << y << " " << x << endl;
			} else {
				cout << x << " " << y << endl;
			}
		}
	}
	return 0;
}