#pragma once
#include<iostream>
#include<list>
#include<vector>

struct person {
	int id;
	vector<person> adv;
};

class Graph
{
private:
	
	std::vector<person> *graph;
	int m_size;
	
public:
	Graph();
	person addPerson();
	void addAdversary(person *p1, person *p2);
	bool isFriend(person *head, person *target);
	bool isAdversary(person *head, person *target);
	~Graph();
};

