#include<iostream>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;
enum color { white, grey, black };
class Node
{
public: //see lab 10 usmy kiye han task ye wala run nhi ho raha
	color clr;
	int elem;
	int dist;
	Node* pred;
	vector<Node>adj;
	Node()
	{
		clr = white;
		elem = 0;
		dist = -1;
		pred = NULL;
	}
	Node(int k)
	{
		clr = white;
		elem = k;
		dist = -1;
		pred = NULL;
	}
	friend ostream& operator<<(ostream &out, Node &c);

	void show()
	{
		vector<Node>::iterator it;
		for (it = adj.begin(); it != adj.end(); ++it)
		{
			cout << *it;
		}
		cout << endl;

	}
	bool operator==(Node& n)
	{
		if (n.elem == this->elem && n.clr == this->clr&&n.dist == this->dist&&n.pred == this->pred)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Work(Node &k)
	{
		for (int i = 0; i < k.adj.size(); i++)
		{
			if (k.adj[i].clr == white)
			{
				k.adj[i].clr = grey;
				k.adj[i].dist = adj[i].dist + 1;
				k.adj[i].pred = &k;
			}
		}
	}
	void Enqueue(queue<Node> &q, Node& j)
	{
		for (int i = 0; i < adj.size(); i++)
		{
			q.push(adj[i]);
		}
	}
	void setc(color k)
	{
		clr = k;
	}
};
ostream& operator<<(ostream &out, Node &c)
{
	out << c.elem << " ";
	return out;
}
class Graph
{
private:
	Node* list;
	int size;
	int count;
public:
	int getsize()
	{
		return size;
	}
	Node getind(int i)
	{
		return list[i];
	}
	Graph(int k)
	{
		size = k;
		list = new Node[size];
		initialize();
	}
	void initialize()
	{
		for (int i = 0; i < size; i++)
		{
			list[i].elem = i;
		}
	}
	void Addvertex(int src, int dest)
	{
		Node k(dest);
		Node j(src);
		list[src].adj.push_back(k);
		list[dest].adj.push_back(j);

	}
	void Display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << list[i].elem << " ";
			list[i].show();
		}
	}
	Node getNode(Node &n)
	{
		if (Search(n))
		{
			for (int i = 0; i < size; i++)
			{

				if (list[i] == n)
				{
					return list[i];
				}
			}
		}
	}
	bool Search(Node &n)
	{
		bool k = false;
		for (int i = 0; i < size; i++)
		{
			if (list[i] == n)
			{
				k = true;
			}
		}
		return k;
	}
	int count_connection()
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			count += list[i].adj.size();
		}
		return count / 2;
	}
	//try


};

void BFS(Graph &g, Node &n)
{
	for (int i = 0; i < g.getsize(); i++)
	{
		Node temp = g.getind(i);
		temp.clr = white;
		temp.dist = -1;
		temp.pred = NULL;

		Node t2 = g.getind(i);
		t2.clr = grey;
		t2.dist = 0;
		t2.pred = NULL;
		queue<Node>q;
		q.push(t2);
		while (!q.empty())
		{
			Node t3 = q.front();
			q.pop();
			for (int j = 0; j< t3.adj.size(); j++)
			{
				if (t3.adj[j].clr == white)
				{
					t3.adj[j].setc(grey);
					t3.adj[j].dist = t3.dist + 1;
					t3.adj[j].pred = &t3;
					q.push(t3.adj[j]);
				}
			}
			t3.setc(black);
			t3.show();

		}
	}

}
int time;
void DFS_visit(Graph g, Node &t)
{
	time = time + 1;
	t.dist = time;
	t.clr = grey;
	cout << t.elem << " ";
	for (int j = 0; j!=t.adj.size(); j++)
	{
		if (t.adj[j].clr == white)
		{
			t.adj[j].pred = &t;
			cout << t.adj[j].elem << " ";
			DFS_visit(g, t.adj[j]);
			//cout << t.adj[j].elem << " ";

		}
	}
	t.clr = black;
	time = time + 1;
	t.dist = time;

}
void DFS(Graph&g,Node&n)
{
	for (int i = 0; i < g.getsize(); i++)
	{
		Node temp = g.getind(i);
		temp.clr = white;
		temp.pred = NULL;
	}
	time = 0;
	
	Node temp2 = n;

		if (temp2.clr == white)
		{
			cout << temp2.elem << "--->";
			DFS_visit(g, temp2);
		}

	
		



}

int main()
{
	Graph g(3);
	Node k(2);
	g.Addvertex(1, 2);
	g.Addvertex(2, 3);
	g.Addvertex(3, 4);
	g.Addvertex(4, 5);
	//DFS(g,k);

	//g.Display();
	//cout << "------------";
	//BFS(g, k);
	////------------TASK 2 -----------//
	//cout << "\nNumber of connected vertices: " << g.count_connection() << endl;
	return 0;
}