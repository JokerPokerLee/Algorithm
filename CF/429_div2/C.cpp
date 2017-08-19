#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> a;
	vector< pair<int, int> > b;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		b.push_back(make_pair(x, i));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int* ans = new int[n];
	for (int i = 0; i < n; i++) {
		ans[b[i].second] = a[n - 1 - i];
	}
	for (int i = 0; i < n; i++) {
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
	return 0;
}