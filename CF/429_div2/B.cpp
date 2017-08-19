#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<long long> a;
	bool odd = false;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
		if (x & 1) {
			odd = true;
		}
		sum += 1LL * x;
	}
	if (sum & 1 || odd) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
	return 0;
}