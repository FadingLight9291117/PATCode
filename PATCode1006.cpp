#include<iostream>
#include<string>
#include<list>
using namespace std;
class Persion {
private:
	string id;
	string inTime;
	string outTime;
public:
	Persion(string id, string inTime, string outTime) {
		this->id = id;
		this->inTime = inTime;
		this->outTime = outTime;
	}
	string getId() {
		return id;
	}
	string getInTime() {
		return inTime;
	}
	string getOutTime() {
		return outTime;
	}
	static Persion* compareInTime(Persion* p1, Persion* p2) {
		if (p1->getInTime() <= p2->getOutTime()) {
			return p1;
		}
		else {
			return p2;
		}
	}
	static Persion* compareOutTime(Persion* p1, Persion* p2) {
		if (p1->getOutTime() >= p2->getOutTime()) {
			return p1;
		}
		else {
			return p2;
		}
	}
};

int PATHCode1006() {
	// 1.  ‰»Î
	int n;
	cin >> n;
	string id, in, out;
	list<Persion*> pList;
	for (int i = 0; i < n; i++) {
		cin >> id;
		cin >> in;
		cin >> out;
		pList.push_back(new Persion(id, in, out));
	}

	// 2. º∆À„
	Persion* first;
	Persion* last;
	list<Persion*>::iterator it = pList.begin();
	first = *it;
	last = *it;
	while (it != pList.end()) {
		first = Persion::compareInTime(first, *it);
		last = Persion::compareOutTime(last, *it);
		it++;
	}

	// 3.  ‰≥ˆ
	string strFirst;
	string strLast;
	strFirst = first->getId();
	strLast = last->getId();
	cout << strFirst << " " << strLast;

	return 0;
}