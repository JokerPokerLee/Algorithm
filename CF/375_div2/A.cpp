#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> a;
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	cout << a.back() - a[0] << endl;
	return 0;
}