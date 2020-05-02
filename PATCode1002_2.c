#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 正确
int PATHCode_2() {
	// 1. 输入
	double a[2000] = { 0 }, b[2000] = { 0 };
	int k1, k2;
	scanf("%d", &k1);
	int e;
	double c;
	for (int i = 0; i < k1; i++) {
		scanf("%d %lf", &e, &c);
		a[e] = c;
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		scanf("%d %lf", &e, &c);
		b[e] = c;
	}
	// 2. 计算
	for (int i = 0; i < 2000; i++) {
		a[i] += b[i];
	}
	int count = 0;
	for (int i = 0; i < 2000; i++) {
		if (a[i] != 0)
			count++;
	}
	// 3.输出
	printf("%d", count);
	for (int i = 2000 -1 ; i >= 0; i--)
	{
		if (a[i] != 0) {
			printf(" %d %.1lf", i, a[i]);
		}
	}
	return 0;
}