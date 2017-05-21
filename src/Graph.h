/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include "Reservation.h"
#include <algorithm>
#include <unistd.h>

using namespace std;

template <class N, class R> class Edge;
template <class N, class R> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template <class N, class R>
class Vertex {
	N info;
	vector<Edge<N,R>  > adj;
	bool visited;
	bool processing;
	int indegree;
	int dist;
	double heuristic;
	int num_cli;
public:

	Vertex(N in);
	friend class Graph<N,R>;

	void addEdge(Vertex<N,R> *dest,R road, double w);
	bool removeEdgeTo(Vertex<N,R> *d);

	N getInfo() const;
	void setInfo(N info);

	void addCli();

	int getNumCli() const;

	int getDist() const;
	int getIndegree() const;

	vector<Edge<N,R>  > getAdj() const;

	Vertex* path;
};

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template <class N, class R>
class Edge {
	Vertex<N,R> * dest;
	R road;
	double weight;
public:
	Edge(Vertex<N,R> *d, R road, double w);
	void setRoad(R road);
	R getRoad() const;
	friend class Graph<N,R>;
	friend class Vertex<N,R>;
};

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template <class N, class R>
class Graph {
	vector<Vertex<N,R>*> vertexSet;
	void dfs(Vertex<N,R> *v, vector<N> &res) const;


	int numCycles;
	void dfsVisit(Vertex<N,R> *v);
	void dfsVisit();
	void getPathTo(Vertex<N,R> *origin, list<N,R> &res);

public:
	bool addVertex(const N &in);
	bool addEdge(const N &sourc, const N &dest,R road, double w);
	bool removeVertex(const N &in);
	bool removeEdge(const N &sourc, const N &dest);
	vector<N> dfs() const;
	vector<N> bfs(Vertex<N,R> *v) const;
	int maxNewChildren(Vertex<N,R> *v, N &inf) const;
	vector<Vertex<N,R> * > getVertexSet() const;
	int getNumVertex() const;

	Vertex<N,R>* getVertex(const N &v) const;
	Vertex<N,R>* getVertex(const int node_id) const;
	Vertex<N,R>* getVertex(const string destination) const;
	void resetIndegrees();
	vector<Vertex<N,R>*> getSources() const;
	int getNumCycles();
	vector<N> topologicalOrder();
	vector<N> getPath(const N &origin, const N &dest);
	void unweightedShortestPath(const N &v);
	bool isDAG();
	void dijkstraShortestPath(const N &initial);
	void aStarPath(const N &initial, const N &final);
	int calcHeuristic(vector<Reservation> reservations);
};

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template <class N, class R>
struct vertex_greater_than {
    bool operator()(Vertex<N,R> * a, Vertex<N,R> * b) const {
        return a->getDist() > b->getDist();
    }
};

template <class N, class R>
bool Vertex<N,R>::removeEdgeTo(Vertex<N,R> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<N,R> >::iterator it= adj.begin();
	typename vector<Edge<N,R> >::iterator ite= adj.end();
	while (it!=ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}

template <class N, class R>
Vertex<N,R>::Vertex(N in): info(in), visited(false), processing(false), indegree(0), dist(0), num_cli(0){
	path = NULL;
}

template <class N, class R>
void Vertex<N,R>::addEdge(Vertex<N,R> *dest,R road, double w) {
	Edge<N,R> edgeD(dest,road,w);
	adj.push_back(edgeD);
}

template <class N, class R>
N Vertex<N,R>::getInfo() const {
	return this->info;
}

template <class N, class R>
int Vertex<N,R>::getDist() const {
	return this->dist;
}

template <class N, class R>
void Vertex<N,R>::setInfo(N info) {
	this->info = info;
}

template <class N, class R>
int Vertex<N,R>::getIndegree() const {
	return this->indegree;
}

template <class N, class R>
vector<Edge<N,R>  > Vertex<N,R>:: getAdj() const{
	return this->adj;
}

template <class N, class R>
void Vertex<N,R>:: addCli(){
	this->num_cli++;
}

template <class N, class R>
int Vertex<N,R>:: getNumCli() const{
	return this->num_cli;
}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template <class N, class R>
Edge<N,R>::Edge(Vertex<N,R> *d, R road, double w): dest(d), weight(w), road(road){}

template <class N, class R>
void Edge<N,R>::setRoad(R road){this->road = road;}
template <class N, class R>
R Edge<N,R>::getRoad() const{return road;}

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template <class N, class R>
int Graph<N,R>::getNumVertex() const {
	return vertexSet.size();
}

template <class N, class R>
vector<Vertex<N,R> * > Graph<N,R>::getVertexSet() const {
	return vertexSet;
}

template <class N, class R>
int Graph<N,R>::getNumCycles() {
	numCycles = 0;
	dfsVisit();
	return this->numCycles;
}

template <class N, class R>
bool Graph<N,R>::isDAG() {
	return (getNumCycles() == 0);
}

template <class N, class R>
bool Graph<N,R>::addVertex(const N &in) {
	typename vector<Vertex<N,R>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<N,R>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++)
		if ((*it)->info == in) return false;
	Vertex<N,R> *v1 = new Vertex<N,R>(in);
	vertexSet.push_back(v1);
	return true;
}

template <class N, class R>
bool Graph<N,R>::removeVertex(const N &in) {
	typename vector<Vertex<N,R>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<N,R>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++) {
		if ((*it)->info == in) {
			Vertex<N,R> * v= *it;
			vertexSet.erase(it);
			typename vector<Vertex<N,R>*>::iterator it1= vertexSet.begin();
			typename vector<Vertex<N,R>*>::iterator it1e= vertexSet.end();
			for (; it1!=it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}

			typename vector<Edge<N,R> >::iterator itAdj= v->adj.begin();
			typename vector<Edge<N,R> >::iterator itAdje= v->adj.end();
			for (; itAdj!=itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template <class N, class R>
bool Graph<N,R>::addEdge(const N &sourc, const N &dest,R road, double w) {
	typename vector<Vertex<N,R>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<N,R>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<N,R> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2) return false;
	vD->indegree++;
	vS->addEdge(vD,road,w);

	return true;
}

template <class N, class R>
bool Graph<N,R>::removeEdge(const N &sourc, const N &dest) {
	typename vector<Vertex<N,R>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<N,R>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<N,R> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2)
		return false;

	vD->indegree--;

	return vS->removeEdgeTo(vD);
}

template <class N, class R>
vector<N> Graph<N,R>::dfs() const {
	typename vector<Vertex<N,R>*>::const_iterator it= vertexSet.begin();
	typename vector<Vertex<N,R>*>::const_iterator ite= vertexSet.end();
	for (; it !=ite; it++)
		(*it)->visited=false;
	vector<N> res;
	it=vertexSet.begin();
	for (; it !=ite; it++)
	    if ( (*it)->visited==false )
	    	dfs(*it,res);
	return res;
}

template <class N, class R>
void Graph<N,R>::dfs(Vertex<N,R> *v,vector<N> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<N,R> >::iterator it= (v->adj).begin();
	typename vector<Edge<N,R> >::iterator ite= (v->adj).end();
	for (; it !=ite; it++)
	    if ( it->dest->visited == false ){
	    	dfs(it->dest, res);
	    }
}

template <class N, class R>
vector<N> Graph<N,R>::bfs(Vertex<N,R> *v) const {
	vector<N> res;
	queue<Vertex<N,R> *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex<N,R> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename vector<Edge<N,R> >::iterator it=v1->adj.begin();
		typename vector<Edge<N,R> >::iterator ite=v1->adj.end();
		for (; it!=ite; it++) {
			Vertex<N,R> *d = it->dest;
			if (d->visited==false) {
				d->visited=true;
				q.push(d);
			}
		}
	}
	return res;
}

template <class N, class R>
int Graph<N,R>::maxNewChildren(Vertex<N,R> *v, N &inf) const {
	vector<N> res;
	queue<Vertex<N,R> *> q;
	queue<int> level;
	int maxChildren=0;
	inf =v->info;
	q.push(v);
	level.push(0);
	v->visited = true;
	while (!q.empty()) {
		Vertex<N,R> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		int l=level.front();
		level.pop(); l++;
		int nChildren=0;
		typename vector<Edge<N,R> >::iterator it=v1->adj.begin();
		typename vector<Edge<N,R> >::iterator ite=v1->adj.end();
		for (; it!=ite; it++) {
			Vertex<N,R> *d = it->dest;
			if (d->visited==false) {
				d->visited=true;
				q.push(d);
				level.push(l);
				nChildren++;
			}
		}
		if (nChildren>maxChildren) {
			maxChildren=nChildren;
			inf = v1->info;
		}
	}
	return maxChildren;
}

template <class N, class R>
Vertex<N,R>* Graph<N,R>::getVertex(const N &v) const {
	for(unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v) return vertexSet[i];
	return NULL;
}

template <class N, class R>
Vertex<N,R>* Graph<N,R>::getVertex(const int node_id) const{
	for(unsigned int i = 0; i < vertexSet.size(); i++){
		if(vertexSet[i]->getInfo().getNodeId() == node_id) return vertexSet[i];
	}
	return NULL;
}

template <class N, class R>
Vertex<N,R>* Graph<N,R>::getVertex(const string destination) const{
	for(unsigned int i = 0; i < vertexSet.size(); i++){
		if(vertexSet[i]->getInfo().getHotelName() == destination) return vertexSet[i];
	}
	return NULL;
}

template <class N, class R>
void Graph<N,R>::resetIndegrees() {
	//colocar todos os indegree em 0;
	for(unsigned int i = 0; i < vertexSet.size(); i++) vertexSet[i]->indegree = 0;

	//actualizar os indegree
	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		//percorrer o vector de Edges, e actualizar indegree
		for(unsigned int j = 0; j < vertexSet[i]->adj.size(); j++) {
			vertexSet[i]->adj[j].dest->indegree++;
		}
	}
}

template <class N, class R>
vector<Vertex<N,R>*> Graph<N,R>::getSources() const {
	vector< Vertex<N,R>* > buffer;
	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		if( vertexSet[i]->indegree == 0 ) buffer.push_back( vertexSet[i] );
	}
	return buffer;
}

template <class N, class R>
void Graph<N,R>::dfsVisit() {
	typename vector<Vertex<N,R>*>::const_iterator it= vertexSet.begin();
	typename vector<Vertex<N,R>*>::const_iterator ite= vertexSet.end();
	for (; it !=ite; it++)
		(*it)->visited=false;
	it=vertexSet.begin();
	for (; it !=ite; it++)
	    if ( (*it)->visited==false )
	    	dfsVisit(*it);
}

template <class N, class R>
void Graph<N,R>::dfsVisit(Vertex<N,R> *v) {
	v->processing = true;
	v->visited = true;
	typename vector<Edge<N,R> >::iterator it= (v->adj).begin();
	typename vector<Edge<N,R> >::iterator ite= (v->adj).end();
	for (; it !=ite; it++) {
		if ( it->dest->processing == true) numCycles++;
	    if ( it->dest->visited == false ){
	    	dfsVisit(it->dest);
	    }
	}
	v->processing = false;
}

template <class N, class R>
vector<N> Graph<N,R>::topologicalOrder() {
	//vector com o resultado da ordenacao
	vector<N> res;

	//verificar se é um DAG
	if( getNumCycles() > 0 ) {
		cout << "Ordenacao Impossivel!" << endl;
		return res;
	}

	//garantir que os "indegree" estao inicializados corretamente
	this->resetIndegrees();

	queue<Vertex<N,R>*> q;

	vector<Vertex<N,R>*> sources = getSources();
	while( !sources.empty() ) {
		q.push( sources.back() );
		sources.pop_back();
	}

	//processar fontes
	while( !q.empty() ) {
		Vertex<N,R>* v = q.front();
		q.pop();

		res.push_back(v->info);

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			v->adj[i].dest->indegree--;
			if( v->adj[i].dest->indegree == 0) q.push( v->adj[i].dest );
		}
	}

	//testar se o procedimento foi bem sucedido
	if ( res.size() != vertexSet.size() ) {
		while( !res.empty() ) res.pop_back();
	}

	//garantir que os "indegree" ficam atualizados ao final
	this->resetIndegrees();

	return res;
}

template <class N, class R>
vector<N> Graph<N,R>::getPath(const N &origin, const N &dest){

	list<N> buffer;
	Vertex<N,R>* v = getVertex(dest);

	//cout << v->info << " ";
	buffer.push_front(v->info);
	while ( v->path != NULL &&  v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if( v->path != NULL )
		buffer.push_front(v->path->info);


	vector<N> res;
	while( !buffer.empty() ) {
		res.push_back( buffer.front() );
		buffer.pop_front();
	}
	return res;
}

template <class N, class R>
void Graph<N,R>::unweightedShortestPath(const N &s) {

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
	}

	Vertex<N,R>* v = getVertex(s);
	v->dist = 0;
	queue< Vertex<N,R>* > q;
	q.push(v);

	while( !q.empty() ) {
		v = q.front(); q.pop();
		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<N,R>* w = v->adj[i].dest;
			if( w->dist == INT_INFINITY ) {
				w->dist = v->dist + 1;
				w->path = v;
				q.push(w);
			}
		}
	}
}

template<class N, class R>
void Graph<N,R>::dijkstraShortestPath(const N &s) {
	int counter = 0;

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Vertex<N,R>* v = getVertex(s);
	v->dist = 0;

	vector< Vertex<N,R>* > pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {
		usleep(10);
		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		//cout << "processing node " << v->getInfo().getNodeId() << endl;

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<N,R>* w = v->adj[i].dest;

			if(v->dist + v->adj[i].weight < w->dist ) {
				//cout << "processing node " << w->getInfo().getNodeId() << endl;

				w->dist = v->dist + v->adj[i].weight;
				w->path = v;

				//se já estiver na lista, apenas a actualiza
				if(!w->processing)
				{
					counter++;
					//cout << "o no com id= " << w->getInfo().getNodeId() << "foi colocado na pq" << endl;
					w->processing = true;
					pq.push_back(w);
				}

				make_heap (pq.begin(),pq.end(),vertex_greater_than<N,R>());
			}
		}
	}
	//cout << "processados: " << counter << endl;
}

template<class N, class R>
void Graph<N,R>::aStarPath(const N &initial, const N &final) {
	int counter = 0;

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Vertex<N,R>* f = getVertex(final);

	Vertex<N,R>* v = getVertex(initial);
	v->dist = 0;

	vector< Vertex<N,R>* > pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {
		usleep(10);
		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		//cout << "processing node " << v->getInfo().getNodeId() << endl;

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<N,R>* w = v->adj[i].dest;

			if(v->dist + v->adj[i].weight + v->heuristic < w->dist) {
				//cout << "processing node " << w->getInfo().getNodeId() << endl;

				//cout << "heuristic= " << v->heuristic << endl << "cost= " << v->dist + v->adj[i].weight << endl;

				w->dist = v->dist + v->adj[i].weight + v->heuristic;
				w->path = v;

				//se já estiver na lista, apenas a actualiza
				if(!w->processing)
				{
					counter++;
					w->processing = true;
					pq.push_back(w);

					if(w == f){
						//cout << "processados: " << counter << endl;
						make_heap (pq.begin(),pq.end(),vertex_greater_than<N,R>());
						return;
					}
				}

				make_heap(pq.begin(),pq.end(),vertex_greater_than<N,R>());
			}
		}
	}
	//cout << "processados: " << counter << endl;
}

template<class N, class R>
int Graph<N,R>::calcHeuristic(const vector<Reservation> reservations) {
	vector<string> dest;

	Vertex<N,R>* v = getVertex(1);
	v->dist = 0;

	Vertex<N,R>* f = v;

	int final_id;

	v->heuristic = 0;
	for(int j = 0; j < reservations.size(); j++){
		dest.push_back(reservations[j].getDestination());
	}

	for(unsigned int i = 0; i < vertexSet.size(); i++){
		Vertex<N,R>* temp = vertexSet.at(i);
		int d1x = abs(v->getInfo().getPointDegree().getX() - temp->getInfo().getPointDegree().getX());
		int d1y = abs(v->getInfo().getPointDegree().getY() - temp->getInfo().getPointDegree().getY());
		int heur = sqrt(d1x*d1x + d1y*d1y);
		if(heur > f->heuristic && find(dest.begin(), dest.end(), temp->getInfo().getHotelName()) != dest.end()){
			f= temp;
			final_id = temp->getInfo().getNodeId();
		}
	}

	f= getVertex(final_id);

	for(unsigned int k = 0; k < vertexSet.size(); k++){
		Vertex<N,R>* current = vertexSet.at(k);
		for(unsigned int a = 0; a < current->adj.size(); a++) {
			Vertex<N,R>* dest = current->adj[a].dest;
			dest->heuristic = current->adj[a].weight + (current->adj[a].weight / (dest->getNumCli() + 1));
		}
	}

	//cout << "final node " << final_id << endl;
	return final_id;
}

#endif /* GRAPH_H_ */
