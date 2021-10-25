#include <bits/stdc++.h>

using namespace std;

class Graph {
	public:
	
	unordered_map<int, vector<int>> adj;
	
	void addEdge(int start, int end);
	vector<int> DFS(int startVertex);
	vector<int> BFS(int startVertex);
	void DFS(int startVertex, vector<int> &visited, vector<int>& result);
};

void Graph::addEdge(int start, int end){
	adj[start].push_back(end);
}

void Graph::DFS(int v, vector<int> &visited, vector<int> &result)
{
	visited[v] = 1;
	result.push_back(v);
  
	// Recur for all the vertices adjacent
	// to this vertex
	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i, visited, result);
}

vector<int> Graph::DFS(int startVertex){
	stack<int> s;
	vector<int> visited(adj.size(), 0);
	
	vector<int> result;
	
	s.push(startVertex);
	visited[startVertex] = 1;
	
	while(!s.empty()){
		int current = s.top();
		s.pop();
		result.push_back(current);
		for(int neighbor : adj[current]){
			if(!visited[neighbor]){
				visited[neighbor] = 1;
				s.push(neighbor);
			}
		}
	}
	
	return result;
}

vector<int> Graph :: BFS(int startVertex){
	vector<int> visited(adj.size(), 0);
	vector<int> result;
	queue<int> q;
	
	q.push(startVertex);
	visited[startVertex] = 1;
	
	while(!q.empty()){
		int current = q.front();
		q.pop();
		
		result.push_back(current);
		
		for(int neighbor: adj[current]){
			if(!visited[neighbor]){
				visited[neighbor] = 1;
				q.push(neighbor);
			}
		}
	}
	
	return result;
}

void printVector(vector<int> v){
	cout<<"[";
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<",";
	}
	cout<<"]"<<endl;
}

int main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	vector<int> v = g.DFS(2);
	printVector(v);

	vector<int> r;	

	vector<int> visited(g.adj.size(), 0);
	g.DFS(2, visited, r);
	printVector(r);
	
	v = g.BFS(2);
	printVector(v);

	// For traversing all the disconnected components start DFS/BFS from all the unvisited nodes
	return 0;
}
