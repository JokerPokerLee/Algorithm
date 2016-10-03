#include <bits/stdc++.h>

using namespace std;

vector< pair<int , int> > p;
int cnt[2020], cml[2020];
int pos[2020];
bool ch[2020];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int div = n / m;
	int rem = n % m;
	rem = m - rem;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
		if (x <= m) {
			cnt[x]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		p.push_back(make_pair(cnt[i], i));
	}
	for (int i = 0; i < m; i++) {
		pos[p[i].second] = i;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > m) {
			ch[i] = true;
		} else
		if (cml[a[i]] < div + ((pos[a[i]] > m) ? 1 : 0)) {
			cml[a[i]]++;
		} else {
			ch[i] = true;
		}
	}
	int now = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ch[i]) {
			while (now <= m && cml[now] == div + ((pos[now] > m) ? 1 : 0)) now++;
			if (now <= m) {
				a[i] = now;
				cml[now]++;
				ans++;
			}
		}
	}
	printf("%d %d\n", div, ans);
	for (int i = 0; i < n; i++) {
		printf("%d%c", a[i], " \n"[i == n - 1]);
	}
	return 0;
}