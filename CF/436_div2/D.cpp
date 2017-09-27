#include <bits/stdc++.h>

#define N 200200

using namespace std;

int cnt[N];
bool used[N];

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
		cnt[x]++;
	}
	set<int> num;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			num.insert(i);
		}
	}
	cout << num.size() << endl;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] > 1) {
			if (used[a[i]]) {
				a[i] = *num.begin();
				num.erase(num.begin());
			} else {
				if (a[i] < *num.begin()) {
					used[a[i]] = true;
				} else {
					cnt[a[i]]--;
					a[i] = *num.begin();
					num.erase(num.begin());
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d%c", a[i], " \n"[i == n - 1]);
	}
	return 0;
}