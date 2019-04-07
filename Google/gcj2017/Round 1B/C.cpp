#include <bits/stdc++.h>

using namespace std;

double ti[1010];
double dist[1010][1010];

int main() {
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// freopen("A-large.in", "r", stdin);
	// freopen("A-large.out", "w", stdout);
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-small-attempt0.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		int n, q;
		scanf("%d %d", &n, &q);
		vector<int> v, d;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			d.push_back(x);
			v.push_back(y);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%lf", &dist[i][j]);
			}
		}
		scanf("%*d%*d");
		for (int i = 0; i < n; i++) {
			ti[i] = 1e10;
		}
		ti[0] = 0;
		for (int i = 0; i < n; i++) {
			double len = 0;
			for (int j = i + 1; j < n; j++) {
				if (dist[j - 1][j] == -1) {
					break;
				}
				len += dist[j - 1][j];
				double t = 1.0 * len / v[i];
				ti[j] = min(ti[j], ti[i] + t);
			}
		}
		printf("%.10f\n", ti[n - 1]);
	}
	return 0;
}