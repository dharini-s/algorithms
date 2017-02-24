#pragma once
#include<iostream>
#include<vector>
#include<utility>
#include<list>
#include "timer.h"

using namespace std;

struct vertex
{
	int val;
	float key;
};

class minHeap
{
private:
	int length;
	int heap_size;

public:
	float* Key;
	vertex *PQ;
	minHeap(int);
	int parent(int);
	int leftChild(int);
	int rightChild(int);
	void swap(vertex*, vertex*);
	void minHeapify(int);
	//void buildMinHeap(int);
	vertex extractMin();
	void insertKey(vertex*);
	int size();
	void decreaseKey(int, float);

};

class graph
{
	int numV;
	list<pair<int, float> > *adjlist;

public:
	graph(int);
	void addEdge(int, int, float);
	void prim(std::ifstream &, int);
};
