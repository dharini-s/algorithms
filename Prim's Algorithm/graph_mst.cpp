#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<math.h>
#include<assert.h>
#include "graph.h"
#define INF 1e6

using namespace std;

typedef minHeap Q;

minHeap::minHeap(int size)
{
	length = size;
	heap_size = 0;
	PQ = new vertex[length];
	Key = new float[length];
	
}

int minHeap::size()
{	return heap_size;	}

int minHeap::leftChild(int i)
{	return ( (2 * i) + 1 ) ;	}

int minHeap::rightChild(int i)
{	return (2 * i + 2);	}

int minHeap::parent(int i)
{	return (i - 1) / 2;	}

void minHeap::swap(vertex *x, vertex *y)
{
	vertex temp = *x;
	*x = *y;
	*y = temp;
}

void minHeap::insertKey(vertex *V)
{
	if (heap_size >= length)
	{
		cout << "Heap overflow!\n";
		return;
	}
	++heap_size;
	int i = heap_size - 1;
	PQ[i] = *V;
	while (i >= 0 && PQ[parent(i)].key >PQ[i].key) 
	{
		vertex temp = PQ[parent(i)];
		PQ[parent(i)] = PQ[i];
		PQ[i] = temp;
		i = parent(i);
	}
}

void minHeap::minHeapify(int i)
{
	int least;
	int l = leftChild(i);
	int r = rightChild(i);
	least = i;
	if (l <= heap_size && PQ[l].key<PQ[i].key )
		least = l;
	if (r <= heap_size && PQ[r].key < PQ[least].key)
		least = r;
	if (least != i)
	{
		swap(&PQ[i], &PQ[least]);
		minHeapify(least);
	}
}
vertex minHeap::extractMin()
{
	vertex min;
	
	min = PQ[0];
	PQ[0] = PQ[heap_size - 1]; 
	heap_size -= 1;
	minHeapify(0);
	return min;
}

void minHeap::decreaseKey(int i, float w)
{
	if (w > PQ[i].key)
	{
		cout << "Error";
	}
	PQ[i].key = w;
	while (i > 0 && PQ[parent(i)].key > PQ[i].key)
	{
		vertex temp = PQ[parent(i)];
		PQ[parent(i)] = PQ[i];
		PQ[i] = temp;
		i = parent(i);
	}
	
}

graph::graph(int n)
{
	numV = n;
	adjlist = new list<pair<int, float> >[numV];
}

void graph::addEdge(int u, int v, float w)
{
	adjlist[u].push_back(make_pair(v, w));
	adjlist[v].push_back(make_pair(u, w));
}

void graph::prim(std::ifstream &iFile, int n)
{
	double sum = 0;
	int i = 0;
	int root = 0; 
	Q pq(n);
	for (int i = 0; i < n; i++)
	{
		vertex v;
		v.val = i;
		v.key = INF;
		pq.insertKey(&v);
	}
	vector<int> parent(n, -1);
	vector<bool> discover(n, false);

	pq.PQ[root].key = 0;
	

	while (i < n*n && !iFile.eof())
	{
		int v1, v2;
		float e;
		iFile >> v1 >> v2;
		iFile >> e;
		addEdge(v1, v2, e);
		i++; 

	}
	ofstream ofile;
	ofile.open("./TestOutput.txt");
	cout << "size = " << pq.size() << endl;


	stopwatch_init ();
  	struct stopwatch_t* timer = stopwatch_create (); assert (timer);

	stopwatch_start (timer);

	while (pq.size() != 0)
	{
		vertex u;
		int index;
		u = pq.extractMin();
		pq.Key[u.val] = u.key;
		discover[u.val] = true;
		list< pair<int, float> >::iterator iter;
		for (iter = adjlist[u.val].begin(); iter != adjlist[u.val].end(); iter++) 
		{
			int v = (*iter).first;
			float w = (*iter).second;
			for (int i = 0; i<n; i++)
			{
				if (pq.PQ[i].val == v)
				{
					index = i;
					break;
				}
				
			}
			if (discover[v] == false && pq.PQ[index].key > w)
			{
				pq.decreaseKey(index,w);
				parent[v] = u.val;
			}
		}
	}

	long double t_std = stopwatch_stop (timer);
	printf ("Execution time of Prim's algorithm: %Lg seconds ==> %Lg million keys per second\n\n", t_std, 1e-6 * n / t_std);

	stopwatch_destroy (timer);


	for (int k = 0; k < n; k++)
	{
		if (parent[k]!=-1)
		{
			
			ofile << parent[k] << "\t" << k << "\t" << pq.Key[k] << endl;
			sum += pq.Key[k];
		}
	}
	cout << "Sum of edges in MST = " << sum << endl;
	
	ofile.close();
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout<< "Please enter arguments in the correct format"<<endl;
	}
	int n;
	std::ifstream ifile;
	ifile.open(argv[1]);
	ifile >> n;
	graph G(n);
	G.prim(ifile, n);
	ifile.close();
	return 0;
}