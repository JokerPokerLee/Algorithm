#include <bits/stdc++.h>

using namespace std;

struct Node {
	int lv, rv;
	Node* ln;
	Node* rn;
};

int getfa(int x, int* f) {
	return f[x] == x ? x : f[x] = getfa(f[x], f);
}

void dfs(Node* node) {
	// cout << node -> lv << ", " << node -> rv << endl;
	if (node -> lv == -1) {
		dfs(node -> ln);
	} else {
		printf("%d ", node -> lv);
	}
	if (node -> rv == -1) {
		dfs(node -> rn);
	} else {
		printf("%d ", node -> rv);
	}
	delete node;
}

int main() {
	freopen("1.in", "r", stdin);
	int n, x, y;
	scanf("%d", &n);
	int* f = new int[n + 1];
	Node** node = new Node*[n + 1];
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		node[i] = NULL;
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		int fx = getfa(x, f);
		int fy = getfa(y, f);
		// cout << fx << " " << fy << endl;
		Node* newNode = new Node;
		if (node[fx] != NULL) {
			newNode -> lv = -1;
			newNode -> ln = node[fx];
		} else {
			newNode -> lv = x;
		}
		if (node[fy] != NULL) {
			newNode -> rv = -1;
			newNode -> rn = node[fy];
		} else {
			newNode -> rv = y;
		}
		node[fy] = newNode;
		f[fx] = fy;
	}
	// return 0;
	f[1] = getfa(1, f);
	Node* root = node[f[1]];
	dfs(root);
	cout << endl;
	delete f;
	delete node;
	return 0;
}