/*
	BOJ 11758 - CCW
	Created by haejun on 2020/03/02
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

struct Point {
	int x;
	int y;
};
Point point[3];

int ccw(Point a, Point b, Point c) {
	double p1 = (b.x - a.x) * (c.y - a.y);
	double p2 = (c.x - a.x) * (b.y - a.y);
	if (p1 > p2) return 1;
	if (p1 < p2) return -1;
	return 0;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> point[i].x >> point[i].y;
	}

	cout << ccw(point[0], point[1], point[2]);


	return 0;
}