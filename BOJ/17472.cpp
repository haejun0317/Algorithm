/*
	BOJ 17472 - 다리 만들기2
	Created by haejun on 2020/02/22
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<algorithm>
using namespace std;
const int MAX = 12;

int n, m;
int arr[MAX][MAX];
int map[MAX][MAX];
bool check[MAX][MAX];

// 구조체, 구조체 큐 생성
struct coor {
	int y;
	int x;
	int num;
};
queue <coor> q;

// 다리 조사할 때 다시 조사할 큐 생성
queue <coor> bq;

// 그룹 번호 지정
int gNum = 1;

// 외곽 벗어나는지 inside check
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 다리 연결할 vector 생성
// a -> b 까지 길이 c;
struct bridge {
	int a;
	int b;
	int c;
};
vector <bridge> v;

bool cmp(const bridge & a, const bridge & b) {
	if (a.c < b.c) return true;
	else return false;
}


// MST를 위한 변수
int p[102];

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int num = q.front().num;
		q.pop();
		
		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && check[ny][nx] == 0 && arr[ny][nx] == 1) {
				check[ny][nx] = 1;
				map[ny][nx] = num;
				q.push({ ny,nx,num });
				bq.push({ ny,nx,num });
			}
		}
	}
}

int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	p[a] = b;
}
bool sp(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 1. input
	memset(check, 0, sizeof(check));
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];

	// 2. 섬 번호 메기기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && check[i][j] == 0) {
				check[i][j] = 1;
				map[i][j] = gNum;
				q.push({ i,j,gNum });
				bq.push({ i,j,gNum });
				bfs();
				gNum++;
			}
		}
	}

	// 3. 섬에서 다른 섬 갈 수 있는지 확인하고,
	// vector에 (섬1 , 섬2 , 거리) 로 넣기
	memset(check, 0, sizeof(check));
	while (!bq.empty()) {
		int y = bq.front().y;
		int x = bq.front().x;
		int num = bq.front().num;
		bq.pop();

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			int s = 1;
			int cnt = 1;
			while (true) {
				ny = y + dy[i] * s;
				nx = x + dx[i] * s;
				if (!inside(ny, nx)) break;
				if (map[ny][nx] == num) break;
				if (map[ny][nx] != 0 && map[ny][nx] != num) {
					if (cnt - 1 >= 2) v.push_back({ num, map[ny][nx], cnt - 1 });
					break;
				}
				s++;
				cnt++;
			}
		}
	}


	// 4. Union Find, MST 사용
	for (int i = 1; i < 102; i++) p[i] = i;

	sort(v.begin(), v.end(), cmp);

	
	// 5. BFS로 한 정점에서 모든 정점으로 갈 수 있는지,
	int ans = 0;
	vector <int> c[7];
	bool check2[102] = { 0, };
	queue <int> lq;
	int m = 0;
	for (int i = 0; i < v.size(); i++) {
		if (sp(v[i].a, v[i].b) == false) {
			Union(v[i].a, v[i].b);
			ans += v[i].c;
			c[v[i].a].push_back(v[i].b);
			c[v[i].b].push_back(v[i].a);
			if (m == 0) m = v[i].a;
		}
	}

	lq.push(m);
	while (!lq.empty()) {
		int num = lq.front();
		lq.pop();
		check2[num] = true;
		for (int i = 0; i < c[num].size(); i++) {
			if (check2[c[num][i]] == false) {
				check2[c[num][i]] = true;
				lq.push(c[num][i]);
			}
		}
	}

	

	bool flag = false;
	for (int i = 1; i < gNum; i++) {
		//cout << check2[i] << " ";
		if (check2[i] == false) flag = true;
	}

	if (flag == false) cout << ans << "\n";
	else cout << -1 << "\n";



	return 0;
}