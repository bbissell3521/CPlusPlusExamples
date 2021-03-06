// Data Structures Lab 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;



struct person {
	int id;
	vector<person*> adv;
};

map<int, person> graph;

person* getPerson(int id) {
	if (graph.count(id) == 0) {
		graph[id] = { id, {} };
	}

	return &graph[id];
}

void createGraph(const vector<pair<int, vector<int>>> graph) {

	for (auto const &p : graph) {
		person* pers = getPerson(p.first);

		for (int edge : p.second) {
			pers->adv.push_back(getPerson(edge));
		}
	}
}

//Give this function the graph you want searched, and the id of the node you want the friends of.
vector<person*> search(map<int, person> g, int id) {
	
	vector<person*> ret;

	person* temp = getPerson(id);

	pair<person*, int> ptemp(temp, 0);

	queue<pair<person*, int>> myQueue;
	myQueue.push(ptemp);

	bool *visited = new bool[g.size()];
	for (int i = 0; i < g.size(); i++) {
		visited[i] = false;
	}

	auto it = find_if(g.begin(), g.end(), [id](const pair<int, person> &g) {
		return g.second.id == id; });
	int index = distance(g.begin(), it);
	visited[index] = true;
	
	while (!myQueue.empty()) {

		temp = myQueue.front().first;
		if (myQueue.front().second % 2 == 0 && myQueue.front().second != 0) {
			cout << temp->id << " is friend of the node" << endl;
			ret.push_back(temp);
		}
		int adv = myQueue.front().second + 1;
		id = myQueue.front().first->id;
		
		myQueue.pop();
		
		
			for (int i(0); i < temp->adv.size(); i++) {
				int newId = temp->adv[i]->id;
				auto it = find_if(g.begin(), g.end(), [newId](const pair<int, person> &g) {
					return g.second.id == newId; });
				index = distance(g.begin(), it);
				if (!visited[index]) {
					visited[index] = true;
					myQueue.push(make_pair(temp->adv[i], adv));
				}				
			}
		
		
		
	}
	return ret;
}

int main()
{
	createGraph({
		{0, {1,2}},
		{1, {2}},
		{2, {0,3}},
		{3, {3}}
		});


	/*for (auto const &f : graph) {
		cout << f.second.id;
		cout << "edges: ";
		for (auto i : f.second.adv) {
			cout << i->id << endl;
		}
	}
	*/
	search(graph, 2);

	system("pause");
	return 0;
}




