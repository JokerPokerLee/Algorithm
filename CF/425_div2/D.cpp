#include <bits/stdc++.h>

#define N 100100

using namespace std;

struct Node{
	int depth;
	int acc[22];
	vector<int> son;
};

map<int, int> pw;
Node node[N];
bool vis[N];

void dfs(int now, int depth) {
	vis[now] = true;
	node[now].depth = depth;
	for (int i = 0; i < node[now].son.size(); i++) {
		if (!vis[node[now].son[i]]) {
			dfs(node[now].son[i], depth + 1);
		}
	}
}

int comAcc(int x, int y) {
	if (node[x].depth < node[y].depth) {
		swap(x, y);
	}
	int delta = node[x].depth - node[y].depth;
	while (delta) {
		int t = pw[delta & -delta];
		x = node[x].acc[t];
		delta -= delta & -delta;
	}
	if (x == y) {
		return x;
	}
	for (int t = 20; t >= 0; t--) {
		if (node[x].acc[t] && node[x].acc[t] != node[y].acc[t]) {
			x = node[x].acc[t];
			y = node[y].acc[t];
		}
	}
	return node[x].acc[0];
}

int solve(int x, int y, int z) {
	// printf("solve: %d %d %d\n", x, y, z);
	int fx = comAcc(x, z);
	int fy = comAcc(y, z);
	int res = 0;
	res += min(node[z].depth - node[fx].depth, node[z].depth - node[fy].depth);
	// cout << res << endl;
	if (fx == fy) {
		int fxy = comAcc(x, y);
		res += node[fxy].depth - node[fx].depth;
	}
	// cout << res << endl;
	return res;
}

int main() {
	for (int t = 1, i = 0; i <= 20; t <<= 1, i++) {
		pw[t] = i;
	}
	freopen("1.in", "r", stdin);
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		node[i].acc[0] = p;
		node[p].son.push_back(i);
	}
	for (int t = 0; true; t++) {
		bool updated = false;
		for (int i = 1; i <= n; i++) {
			int acc = node[i].acc[t];
			if (acc && node[acc].acc[t]) {
				node[i].acc[t + 1] = node[acc].acc[t];
				updated = true;
			}
		}
		if (!updated) {
			break;
		}
	}
	dfs(1, 1);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d: %d\n", i, node[i].depth);
	// 	for (int j = 0; j < node[i].son.size(); j++) {
	// 		printf("%d%c", node[i].son[j], " \n"[j == node[i].son.size() - 1]);
	// 	}
	// 	for (int j = 0; j < 10; j++) {
	// 		printf("%d%c", node[i].acc[j], " \n"[j == 9]);
	// 	}
	// }
	while (q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int ans = 0;
		ans = max(ans, solve(a, b, c));
		ans = max(ans, solve(b, c, a));
		ans = max(ans, solve(c, a, b));
		printf("%d\n", ans + 1);
	}
	return 0;
}