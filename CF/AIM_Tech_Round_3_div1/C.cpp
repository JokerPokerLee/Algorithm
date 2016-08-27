#include <bits/stdc++.h>

#define MP make_pair
#define EPS 1e-8
#define N 400400

using namespace std;

vector<int> link[N];
bool vis[N];
int n;

void dfs(int u, int pre) {
	son[u] = 1;
	fa[u] = pre;
	vis[u] = true;
	for (int i = 0; i < link[u].size(); i++) {
		int v = link[u][i];
		if (v != pre) {
			dfs(v, u);
			son[u] += son[v];
		}
	}
	if (son[u] > n / 2) {
		for (int i = 0; i < link[u].size(); i++) {
			int v = link[u][i];
			if (v != pre) {
				mnc[u]
			}
		}
	}
}

void solve(int u, int pre, int cut) {

}

int main() {
	freopen("1.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		link[x].push_back(y);
		link[y].push_back(x);
	}
	dfs(1, 0);
	solve(1, 0, 0);
	return 0;
}