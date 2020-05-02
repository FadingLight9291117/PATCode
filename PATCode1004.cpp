#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<map>
#include<stdio.h>
using namespace std;
class Node {
public:
	int id;
	int level;
	int parentId;
	list<int> *nodeList;
	Node(int id, int level);
	void setParentId(int parentId) {
		this->parentId = parentId;
	}
};
Node::Node(int id, int level) {
	this->id = id;
	this->level = level;
	this->parentId = 0;
	nodeList = new list<int>;
}
class NodeManager {
private:
	static int len;
	static int maxLevel;
	static Node* nodes[101];
	static int rootId;
public:
	static void init(int len);
	static void setChild(int parentId, int id);
	static void setRoot();
	static int getRoot();
	static void setLevel(int rooId);
	static void print();
};
int NodeManager::len = 0;
int NodeManager::maxLevel = 0;
Node* NodeManager::nodes[101] = { nullptr };
int NodeManager::rootId = 0;
void NodeManager::setRoot() {
	for (int i = 1; i <= 100; i++) {
		if (nodes[i]->parentId == 0) {
			rootId = i;
			nodes[rootId]->level = 1;
			break;
		}
	}
}
int NodeManager::getRoot() {
	return rootId;
}
void NodeManager::init(int len) {
	NodeManager::len = len;
	for (int i = 1; i <= len; i++) {
		nodes[i] = new Node(i, 0);
	}
	NodeManager::maxLevel = 0;
}

void NodeManager::setChild(int parentId, int id) {
	Node* node = nodes[id];
	Node* parentNode = nodes[parentId];
	parentNode->nodeList->push_back(id);
}

void NodeManager::setLevel(int id) {
	int level = nodes[id]->level;
	if (level > maxLevel) {
		maxLevel = level;
	}
	if (nodes[id]->nodeList->size() != 0) {
		list<int>::iterator iter = nodes[id]->nodeList->begin();
		while (iter != nodes[id]->nodeList->end()) {
			nodes[*iter]->level = level + 1;
			setLevel(*iter);
			iter++;
		}
	}
}


void NodeManager::print() {
	int a[101] = { 0 };
	
	for (int i = 1; i <= len; i++) {
		if (nodes[i]->nodeList->size() == 0) {
			a[nodes[i]->level]++;
		}
	}
	
	for (int i = 1; i <= maxLevel; i++) {
		if (i != maxLevel) {
			cout << a[i] << " ";
		}
		else {
			cout << a[i];
		}
	}
}

int PATCode1004() {
	// 1. ÊäÈë
	int nodeNum, nonLeafnode;
	cin >> nodeNum;
	cin >> nonLeafnode;
	NodeManager::init(nodeNum);
	for (int i = 0; i < nonLeafnode; i++) {
		int parentId;
		int childNum;
		cin >> parentId;
		cin >> childNum;
		for (int j = 0; j < childNum; j++) {
			int childNodeId;
			cin >> childNodeId;
			NodeManager::setChild(parentId, childNodeId);
		}
	}
	// 2. ¼ÆËã
	NodeManager::setRoot();
	NodeManager::setLevel(NodeManager::getRoot());
	// 3. Êä³ö
	NodeManager::print();

	return 0;
}