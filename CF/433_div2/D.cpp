#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct Flight {
	int day, city;
	long long cost;
	Flight(int d, int ci, int c) : day(d), city(ci), cost(c) {}
};

long long cost[1000100];
long long tmp[100100];
int cnt[1000100];

bool cmp0(Flight f1, Flight f2) {
	return f1.day > f2.day;
}

bool cmp1(Flight f1, Flight f2) {
	return f1.day < f2.day;
}

int main() {
	freopen("1.in", "r", stdin);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<Flight> fli;
	int latest = 0;
	for (int i = 0; i < m; i++) {
		int d, s, t, c;
		scanf("%d %d %d %d", &d, &s, &t, &c);
		latest = max(latest, d);
		int city = s - t;
		fli.push_back(Flight(d, city, c));
	}
	sort(fli.begin(), fli.end(), cmp0);
	int now = 0;
	for (int ti = latest; ti > 0; ti--) {
		cost[ti] = cost[ti + 1];
		cnt[ti] = cnt[ti + 1];
		while (now < fli.size() && fli[now].day == ti) {
			// cout << fli[now].day << " " << fli[now].city << " " << fli[now].cost << endl;
			int city = fli[now].city;
			if (city < 0) {
				city = -city;
				cost[ti] -= tmp[city];
				if (tmp[city] == 0) {
					cnt[ti] += 1;
					tmp[city] = fli[now].cost;
				} else {
					tmp[city] = min(tmp[city], fli[now].cost);
				}
				cost[ti] += tmp[city];
			}
			now++;
		}
		// for (int i = 1; i <= n; i++) {
		// 	printf("%lld%c", tmp[i], " \n"[i == n]);
		// }
		// cout << "cost: " << cost[ti] << endl;
	}
	// for (int i = 1; i <= latest; i++) {
	// 	printf("%d%c", cnt[i], " \n"[i == latest]);
	// }
	sort(fli.begin(), fli.end(), cmp1);
	memset(tmp, 0, sizeof(tmp));
	now = 0;
	int arr = 0;
	long long sum = 0, ans = 0;
	for (int ti = 1; ti + k <= latest; ti++) {
		if (arr == n && cnt[ti + k] == n) {
			if (ans == 0) {
				ans = sum + cost[ti + k];
			} else {
				ans = min(ans, sum + cost[ti + k]);
			}
		}
		while (now < fli.size() && fli[now].day == ti) {
			// cout << fli[now].day << " " << fli[now].city << " " << fli[now].cost << endl;
			int city = fli[now].city;
			if (city > 0) {
				sum -= tmp[city];
				if (tmp[city] == 0) {
					arr += 1;
					tmp[city] = fli[now].cost;
				} else {
					tmp[city] = min(tmp[city], fli[now].cost);
				}
				sum += tmp[city];
			}
			now++;
		}
		// for (int i = 1; i <= n; i++) {
		// 	printf("%lld%c", tmp[i], " \n"[i == n]);
		// }
		// cout << "cost: " << sum << endl;
	}
	cout << (ans == 0 ? -1 : ans) << endl;
	return 0;
}