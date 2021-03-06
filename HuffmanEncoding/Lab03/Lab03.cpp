// Lab03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

class Tree {
	public:
		Tree(int w, char c);
		Tree(int w, Tree* t1, Tree* t2);
		~Tree();
		int getWeight() const;
		void printTree(vector<char> &bitString) const;
	private:
		Tree* left;
		Tree* right;
		int weight;
		char ch;
};

Tree::Tree(int w, char c) {
	weight = w;
	ch = c;
	left = NULL;
	right = NULL;
}

Tree::Tree(int w, Tree* t1, Tree* t2) {
	weight = w;
	if (t1->weight > t2->weight) {
		left = t1;
		right = t2;
	}
	else {
		left = t2;
		right = t1;
	}
	ch = NULL;
}

Tree::~Tree() {

}

int Tree::getWeight() const {
	return weight;
}

void Tree::printTree(vector<char> &bitString) const {

}

#ifndef NULL
#define NULL 0 
#endif

struct TreeWrapper {

	Tree* tree;

	TreeWrapper() {
		tree = NULL;
	}
	TreeWrapper(Tree* t) {
		tree = t;
	}

	bool operator<(const TreeWrapper &tw) const {
		return tree->getWeight() > tw.tree->getWeight();
	}
	
};



Tree* algo(priority_queue<TreeWrapper, vector<TreeWrapper>, TreeWrapper> p) {
	while (p.size() > 1) {
		Tree* t1t = p.top().tree;
		p.pop();
		Tree* t2t = p.top().tree;
		p.pop();

		Tree* t = new Tree((t1t->getWeight() + t2t->getWeight()), t1t, t2t);
		p.push(TreeWrapper(t));
	}

	return p.top().tree;
}

int main()
{
	cout << "Started" << endl;

	priority_queue<TreeWrapper, std::vector<TreeWrapper>, TreeWrapper> q;

	cout << "Queue is made" << endl;

	q.push(TreeWrapper(new Tree(4, 'a')));
	q.push(TreeWrapper(new Tree(3, 'b')));
	q.push(TreeWrapper(new Tree(1, 'c')));

	cout << "In Queue" << endl;

	Tree* returned(algo(q));

	cout << "Algo Run" << endl;

	//vector<char> bitString;
	//returned->printTree(bitString);

	system("pause");
	return 0;
}
