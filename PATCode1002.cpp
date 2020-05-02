#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<list>
using namespace std;

// 正确

int PATCode2() {
	int nums1, nums2;
	map<int, double> map1, map2, mapResult;
	int e;
	double c;
	// 获取输入
	cin >> nums1;
	for (int i = 0; i < nums1; i++) {
		cin >> e;
		cin >> c;
		map1[e] = c;
	}
	cin >> nums2;
	for (int i = 0; i < nums2; i++) {
		cin >> e;
		cin >> c;
		map2[e] = c;
	}
	// 计算
	map<int, double>::iterator iter2 = map2.begin();
	int first;
	double second;
	while (iter2 != map2.end()) {
		first = iter2->first;
		second = iter2->second;
		if (map1.find(first) != map1.end()) {
			map1[first] += second;
			if (map1[first] == 0) {
				map1.erase(first);
			}
		}
		else {
			map1[first] = second;
		}
		iter2++;
	}
	// 输出
	list<int> listE;
	cout << map1.size();
	map<int, double>::iterator iter1 = map1.begin();
	while (iter1 != map1.end()) {
		listE.push_front(iter1->first);
		iter1++;
	}
	list<int>::iterator iter3 = listE.begin();
	while (iter3 != listE.end()) {
		cout << " " << *iter3 << " ";
		printf("%.1f", map1[*iter3]);
		iter3++;
	}
	return 0;
}