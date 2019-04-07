#include <bits/stdc++.h>

using namespace std;

int fa[2020];

int getfa(int x) {
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

int dfs(int u, vector<int>& height, map<int, vector<int>>& links, vector<int>& vis) {
	if (!links.count(u)) {
		height[u] = 1;
		vis[u] = 1;
		return 0;
	}
	vis[u] = 1;
	int hei = 0;
	for (auto& v: links[u]) {
		if (!vis[v]) {
			dfs(v, height, links, vis);
		}
		if (!height[v]) {
			return -1;
		}
		hei = max(hei, height[v]);
	}
	height[u] = hei + 1;
	return 0;
}

int main() {
	freopen("1.in", "r", stdin);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n + m; i++) {
		fa[i] = i;
	}

	vector<string> rela;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		rela.push_back(str);
		int x = i + 1;
		for (int j = 0; j < m; j++) {
			int y = n + j + 1;
			int fx = getfa(x);
			int fy = getfa(y);
			if (str[j] == '=') {
				fa[fx] = fy;
			} else {
				if (fx == fy) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	vector<int> ind(n + m + 1, 0);
	map<int, vector<int>> links;
	for (int i = 0; i < n; i++) {
		int x = i + 1;
		for (int j = 0; j < m; j++) {
			int y = n + j + 1;
			int fx = getfa(x);
			int fy = getfa(y);
			if (rela[i][j] == '<') {
				if (!links.count(fy)) {
					links[fy] = vector<int>();
				}
				links[fy].push_back(fx);
				ind[fx]++;
			} else
			if (rela[i][j] == '>') {
				if (!links.count(fx)) {
					links[fx] = vector<int>();
				}
				links[fx].push_back(fy);
				ind[fy]++;
			}
		}
	}

	links[0] = vector<int>();
	for (int i = 1; i <= n + m; i++) {
		int fi = getfa(i);
		if (!ind[fi]) {
			links[0].push_back(fi);
			ind[fi]++;
		}
	}

	if (!links[0].size()) {
		cout << "No" << endl;
		return 0;
	}

	vector<int> height(n + m + 1);
	vector<int> vis(n + m + 1);
	if (dfs(0, height, links, vis)) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for (int i = 0; i < n; i++) {
		int fi = getfa(i + 1);
		printf("%d%c", height[fi], " \n"[i == n - 1]);
	}
	for (int i = 0; i < m; i++) {
		int fi = getfa(n + i + 1);
		printf("%d%c", height[fi], " \n"[i == m - 1]);
	}

	return 0;
}