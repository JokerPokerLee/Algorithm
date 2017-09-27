#include <bits/stdc++.h>

#define PII pair<int, int>
#define MP make_pair

const double PI = acos(-1.0);

using namespace std;

bool cmp1(PII a, PII b) {
	if (a.first > b.first) return true;
	if (a.first < b.first) return false;
	return a.second > b.second;
}

bool cmp2(PII a, PII b) {
	return 1LL * a.first * a.second > 1LL * b.first * b.second;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	// freopen("A-large.in", "r", stdin);
	// freopen("A-large.out", "w", stdout);
	int ttt;
	scanf("%d", &ttt);
	for (int tt = 1; tt <= ttt; tt++) {
		printf("Case #%d: ", tt);
		int n, k;
		scanf("%d %d", &n, &k);
		vector<PII> pc;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			pc.push_back(MP(x, y));
		}
		sort(pc.begin(), pc.end(), cmp1);
		double ans = 0.0;
		for (int i = 0; i < n - k + 1; i++) {
			sort(pc.begin() + i + 1, pc.end(), cmp2);
			double tmp = PI * pc[i].first * pc[i].first;
			for (int j = 0; j < k; j++) {
				tmp += 2.0 * PI * pc[i + j].first *  pc[i + j].second;
			}
			ans = max(ans, tmp);
			// cout << ans << endl;
			sort(pc.begin() + i + 1, pc.end(), cmp1);
		}
		printf("%.8f\n", ans);
	}
	return 0;
}