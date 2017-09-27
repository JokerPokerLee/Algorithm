#include <bits/stdc++.h>

#define N 300300

using namespace std;

vector< pair<int, int> > link[N];
int dep[N], edge[N], d[N], c[N];
int f[N][22];
bool vis[N], used[N];
map<int, int> pw;
vector<int> es;

void dfs(int u, int depth) {
	vis[u] = true;
	dep[u] = depth;
	for (int i = 0; i < link[u].size(); i++) {
		int v = link[u][i].first;
		if (!vis[v]) {
			f[v][0] = u;
			edge[v] = link[u][i].second;
			dfs(v, depth + 1);
		}
	}
}

int comAcc(int x, int y) {
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	int delta = dep[x] - dep[y];
	while (delta) {
		int t = pw[delta & -delta];
		x = f[x][t];
		delta -= delta & -delta;
	}
	if (x == y) {
		return x;
	}
	for (int t = 20; t >= 0; t--) {
		if (f[x][t] && f[x][t] != f[y][t]) {
			x = f[x][t];
			y = f[y][t];
		}
	}
	return f[x][0];
}

int solve(int u) {
	vis[u] = true;
	int res = c[u];
	for (int i = 0; i < link[u].size(); i++) {
		int v = link[u][i].first;
		if (!vis[v]) {
			int tmp = solve(v);
			if (tmp & 1) {
				es.push_back(edge[v]);
			}
			res += tmp;
		}
	}
	return res;
}

int main() {
	for (int t = 1, i = 0; i <= 20; t <<= 1, i++) {
		pw[t] = i;
	}
	freopen("1.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i + 1]);
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		link[x].push_back(make_pair(y, i));
		link[y].push_back(make_pair(x, i));
	}
	dfs(1, 1);
	for (int t = 0; true; t++) {
		bool updated = false;
		for (int i = 1; i <= n; i++) {
			int acc = f[i][t];
			if (acc && f[acc][t]) {
				f[i][t + 1] = f[acc][t];
				updated = true;
			}
		}
		if (!updated) {
			break;
		}
	}
	int l = 1;
	while (l <= n) {
		while (l <= n && d[l] < 1) {
			l++;
		}
		if (l > n) {
			break;
		}
		int r = l + 1;
		while (r <= n && d[r] < 1) {
			r++;
		}
		if (r > n) {
			for (int i = 1; i <= n; i++) {
				if (d[i] == -1) {
					r = i;
					break;
				}
			}
		}
		if (r > n) {
			cout << "-1" << endl;
			return 0;
		}
		int ff = comAcc(l, r);
		c[l]++, c[r]++, c[ff] -= 2;
		l = max(l, r) + 1;
	}
	memset(vis, 0, sizeof(vis));
	solve(1);
	printf("%d\n", es.size());
	sort(es.begin(), es.end());
	for (int i = 0; i < es.size(); i++) {
		printf("%d\n", es[i]);
	}
	return 0;
}