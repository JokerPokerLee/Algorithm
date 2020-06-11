#include <bits/stdc++.h>

using namespace std;

int getfa(int x, vector<int> &fa) {
	return x == fa[x] ? x : fa[x] = getfa(fa[x], fa);
}

int main() {
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		int n, m, x, y;
		scanf("%d %d", &n, &m);
		vector<int> fa(n);
		for (int i = 0; i < n; i++) {
			fa[i] = i;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			fa[getfa(y - 1, fa)] = getfa(x - 1, fa);
		}
		set<int> fs;
		for (int i = 0; i < n; i++) {
			fs.insert(getfa(i, fa));
		}
		// cout << fs.size() << endl;
		printf("Case #%d: %d\n", tt, n - 1 + (int)fs.size() - 1);
	}
	return 0;
}