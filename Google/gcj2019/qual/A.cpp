#include <bits/stdc++.h>

using namespace std;

int main() {
	int ttt;
	cin >> ttt;
	for (int tt = 1; tt <= ttt; tt++) {
		string n, a = "", b = "";
		cin >> n;
		cout << "Case #" << tt << ": ";
		for (int i = 0; i < n.size(); i++) {
			if (n[i] == '4') {
				a += '2';
				b += '2';
			} else {
				if (a.size()) {
					a += '0';
				}
				b += n[i];
			}
		}
		cout << a << " " << b << endl;
	}
	return 0;
}