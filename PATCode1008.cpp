#include<iostream>
#include<list>
using namespace std;
const int MOVE_UP_TIME = 6;
const int MOVE_DOWN_TIME = 4;
const int STAY_TIME = 5;
int main() {

	// 1.  ‰»Î
	list<int>* floors = new list<int>;
	int num = 0;
	cin >> num;
	int temp;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		floors->push_back(temp);
	}

	// 2. º∆À„
	int result = 0;
	int nowFloor = 0;
	int sub = 0;
	result += num * STAY_TIME;
	list<int>::iterator iter = floors->begin();
	while (iter != floors->end()) {
		sub = *iter - nowFloor;
		if (sub > 0) result += MOVE_UP_TIME*sub;
		else	result += MOVE_DOWN_TIME*sub*(-1);
		nowFloor = *iter;
		iter++;
	}

	// 3.  ‰≥ˆ
	cout<< result;

	return 0;
}