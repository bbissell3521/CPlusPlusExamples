#include "pch.h"
#include "Graph.h"

using namespace std;

Graph::Graph()
{
	m_size = 0;
	graph = new vector<person>[m_size];
}

person Graph::addPerson() {
	int id = graph->size() + 1;
	person temp = { id, {} };
	this->graph->push_back(temp);
	return temp;
}

//adds a link between 2 nodes in the graph
void Graph::addAdversary(person *p1, person *p2) {
	p1->adv.push_back(*p2);
	p2->adv.push_back(*p1);
}


bool Graph::isFriend(person *head, person *target) {
	for (int i = 0; i < head->adv.size(); i++) {
		if (target->id == head->adv[i].id) {
			return true;
		}
	}
}
bool Graph::isAdversary(person *head, person *target) {

}

Graph::~Graph()
{
}
