#include <bits/stdc++.h>

#define N 100100
#define INF 1000000007

#define mp make_pair

using namespace std;

vector< pair<int , int> > link[N];
bool f[N];

int main() {
	freopen("1.in", "r", stdin);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int u, v, l;
		scanf("%d %d %d", &u, &v, &l);
		link[u].push_back(mp(v, l));
		link[v].push_back(mp(u, l));
	}
	vector<int> a;
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
		f[x] = true;
	}
	int ans = INF;
	for (int i = 0; i < a.size(); i++) {
		int u = a[i];
		for (int j = 0; j < link[u].size(); j++) {
			int v = link[u][j].first;
			int l = link[u][j].second;
			if (!f[v]) {
				ans = min(ans, l);
			}
		}
	}
	if (ans == INF) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}