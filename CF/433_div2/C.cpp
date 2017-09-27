#include <bits/stdc++.h>

using namespace std;

int tf[300300];

int main() {
	freopen("1.in", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	set< pair<long long, int> > d;
	long long sum = 0, tot = 0;
	vector<int> air;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);

		tot += sum;
		sum += x;
		air.push_back(x);
		d.insert(make_pair(x, i));

		if (i >= k) {
			auto it = d.end();
			it--;
			tf[(*it).second] = i + 1;
			sum -= (*it).first;
			d.erase(it);
		}
	}
	for (int i = 0; i < k; i++) {
		tot += sum;
		auto it = d.end();
		it--;
		tf[(*it).second] = n + i + 1;
		sum -= (*it).first;
		d.erase(it);
	}
	printf("%lld\n", tot);
	for (int i = 0; i < n; i++) {
		printf("%d%c", tf[i], " \n"[i == n - 1]);
	}
	return 0;
}