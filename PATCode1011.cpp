#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
// ��ȷ
int PATCode1011() {
	// 1. ����
	double a[3], b[3], c[3];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> c[i];
	}

	// 2. ����
	int max1 = 0, max2 = 0, max3 = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] > a[max1]) {
			max1 = i;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (b[i] > b[max2]) {
			max2 = i;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (c[i] > c[max3]) {
			max3 = i;
		}
	}
	double profit;
	profit = (a[max1] * b[max2] * c[max3] * 0.65 - 1) * 2;

	map<int, char> m;
	m[0] = 'W';
	m[1] = 'T';
	m[2] = 'L';

	// 3. ���
	cout << m[max1] << " " << m[max2] << " " << m[max3] << " ";
	printf("%.2lf", profit);

	return 0;
}