#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n, x;
	scanf("%d", &n);
	vector<int> a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	deque<int> q;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			q.push_back(a[i]);
		} else {
			q.push_front(a[i]);
		}
		// for (auto& e: q) {
		// 	cout << e << " ";
		// }
		// cout << endl;
	}
	while (q.size()) {
		printf("%d%c", q.front(), " \n"[q.size() == 1]);
		q.pop_front();
	}
	return 0;
}