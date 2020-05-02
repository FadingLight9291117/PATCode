#include<iostream>
#include<string>
using namespace std;
int PATCode1006_2() {
	// 1. ÊäÈë
	int num;
	string ids[100];
	string inTime[100];
	string outTime[100];
	cin >> num;
	for(int i = 0; i < num; i++) {
		cin >> ids[i];
		cin >> inTime[i];
		cin >> outTime[i];
	}

	// 2. ¼ÆËã
	int firstIn = 0;
	int lastOut = 0;
	for (int i = 0; i < num; i++) {
		if (inTime[i] < inTime[firstIn]) {
			firstIn = i;
		}
		if (outTime[i] > outTime[lastOut]) {
			lastOut = i;
		}
	}

	// 3. Êä³ö
	cout << ids[firstIn] << " " << ids[lastOut];

	return 0;
}