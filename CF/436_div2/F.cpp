#include <bits/stdc++.h>

#define N 3030

using namespace std;

struct Que{
	int s, t, k, i, res;
	Que(int s, int t, int k, int i) : s(s), t(t), k(k), i(i) {}
};

vector<int> link[N], rlink[N];
map<int, int> mul;
vector<Que> que;
int st[N][15];
bool vis[N];
int dep[N];
int n, m, q;

bool cmpt(Que q1, Que q2) {
	return q1.t < q2.t;
}

bool cmpi(Que q1, Que q2) {
	return q1.i < q2.i;
}

void clean() {
	for (int i = 0; i <= n; i++) {
		dep[i] = -1;
	}
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
	}
	for (int i = 0; i <= n; i++) {
		for (int t = 0; t < 15; t++) {
			st[i][t] = 0;
		}
	}
}

void dfs(int u) {
	for (int i = 0; i < link[u].size(); i++) {
		int v = link[u][i];
		bool f = st[v][0] == 0;
		if (st[v][0] == 0 || st[v][0] > u) {
			st[v][0] = u;
		}
		if (f) {
			dfs(v);
		}
	}
}

void depth(int u, int d) {
	dep[u] = d;
	for (int i = 0; i < link[u].size(); i++) {
		int v = link[u][i];
		if (st[v][0] == u && dep[v] == -1) {
			depth(v, d + 1);
		}
	}
}

void buildst() {
	for (int i = 1; i <= n; i++) {
		if (dep[i] == -1) {
			st[i][0] = 0;
		}
	}
	for (int t = 1; t < 15; t++) {
		bool updated = false;
		for (int i = 1; i <= n; i++) {
			int acc = st[i][t - 1];
			if (acc && st[acc][t - 1]) {
				st[i][t] = st[acc][t - 1];
				updated = true;
			}
		}
		if (!updated) {
			break;
		}
	}
}

int search(int u, int k) {
	if (k > dep[u] + 1) {
		return -1;
	}
	k--;
	while (k) {
		int del = k & -k;
		u = st[u][mul[del]];
		k -= del;
	}
	return u;
}

int main() {
	freopen("1.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		link[y].push_back(x);
	}
	while (q--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		que.push_back(Que(x, y, z, que.size()));
	}
	sort(que.begin(), que.end(), cmpt);
	int root = 0;
	for (int t = 0; t < 20; t++) {
		mul[1 << t] = t;
	}
	for (int i = 0; i < que.size(); i++) {
		// printf("%d %d %d %d\n", que[i].s, que[i].t, que[i].k, que[i].i);
		if (que[i].t != root) {
			clean();
			dfs(que[i].t);
			// for (int j = 1; j <= n; j++) {
			// 	printf("%d%c", st[j][0], " \n"[j == n]);
			// }
			// printf("depth\n");
			depth(que[i].t, 0);
			// for (int j = 1; j <= n; j++) {
			// 	printf("%d%c", dep[j], " \n"[j == n]);
			// }
			buildst();
			root = que[i].t;
		}
		que[i].res = search(que[i].s, que[i].k);
	}
	sort(que.begin(), que.end(), cmpi);
	for (int i = 0; i < que.size(); i++) {
		printf("%d\n", que[i].res);
	}
	return 0;
}