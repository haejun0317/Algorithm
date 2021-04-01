#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int start, v, e;

struct node {
	int end;
	int val;
};

vector <node> arr[20002];
int d[20002] = { 0, };

void dij(int s) {
	d[s] = 0;
	priority_queue <pair<int, int>> q;
	q.push({ 0, s });
	while (!q.empty()) {
		int node = q.top().second;
		int cost = -q.top().first;
		q.pop();

		for (int i = 0; i < arr[node].size(); i++) {
			int newVal = arr[node][i].val + d[node];
			int beforeVal = d[arr[node][i].end];

			if (newVal < beforeVal) {
				d[arr[node][i].end] = newVal;
				q.push({ -newVal, arr[node][i].end });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> start;
	int from, to, val;
	for (int i = 0; i < e; i++) {
		cin >> from >> to >> val;
		arr[from].push_back({ to, val });
	}

	for (int i = 1; i <= v; i++) d[i] = 987987987;

	dij(start);

	for (int i = 1; i <= v; i++) {
		if (d[i] != 987987987) cout << d[i] << "\n";
		else cout << "INF\n";
	}



	return 0;
}