/*
	BOJ 2613 - 숫자구슬
	Created by haejun on 2020/03/17
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int arr[302];

bool solution(int mid, vector<int>& ans) {
	ans.clear();
	int nowSize = 0;
	int nowSum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid) return false;
		else if (nowSum + arr[i] <= mid) {
			nowSize++;
			nowSum += arr[i];
		}
		else {
			ans.push_back(nowSize);
			nowSize = 1;
			nowSum = arr[i];
		}
	}
	ans.push_back(nowSize);
	return ans.size() <= m;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int left = 0, right = 30000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector <int> ans;
	//이분 탐색
	while (left < right) {
		//중간 값 찾기.
		int mid = (left + right) / 2;
		if (solution(mid, ans) < 1) left = mid + 1;
		else right = mid;
	}
	solution(left, ans);

	while (ans.size() < m) {
		//배열 중 가장 큰 값 찾기
		*max_element(ans.begin(), ans.end()) -= 1;
		ans.push_back(1);
	}


	cout << left << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}


	return 0;
}
