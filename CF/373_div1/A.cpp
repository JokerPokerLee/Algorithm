#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	int n, t;
	scanf("%d %d%*c", &n, &t);
	bool after = false;
	vector<int> a;
	string ans = "";
	for (int i = 0; i < n; i++) {
		char ch;
		scanf("%c", &ch);
		if (ch == '.') {
			after = true;
			a.push_back(-1);
			continue;
		}
		a.push_back(ch - '0');
		if (after) {
			if (a.back() >= 5) {
				break;
			}
		}
	}
	// for (int i = 0; i < a.size(); i++) {
	// 	if (a[i] == -1) {
	// 		printf(".");
	// 	} else {
	// 		printf("%d", a[i]);
	// 	}
	// }
	// printf("\n");
	// return 0;
	if (!after) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == -1) {
				printf(".");
			} else {
				printf("%d", a[i]);
			}
		}
		printf("\n");
		return 0;
	}
	while (t && a.back() >= 5) {
		a.pop_back();
		if (a.back() == -1) {
			a.pop_back();
			a[a.size() - 1]++;
			for (int j = a.size() - 1; j >= 0; j--) {
				if (a[j] > 9) {
					a[j] -= 10;
					if (j) {
						a[j - 1] += 1;
					} else {
						printf("1");
					}
				} else {
					break;
				}
			}
			break;
		} else {
			a[a.size() - 1]++;
		}
		t--;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == -1) {
			printf(".");
		} else {
			printf("%d", a[i]);
		}
	}
	printf("\n");
	return 0;
}