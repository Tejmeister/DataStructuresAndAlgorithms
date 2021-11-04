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
	adj[end].push_back(start);
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

// BFS
bool checkForUGCycleBFS(int s, int V, vector<int>& visited, Graph g)
    {
        vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : g.adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }

// DFS
bool checkForUGCycleDFS(int node, int parent, vector<int>& vis, Graph g){
	vis[node] = 1;
	for(auto neighbour : g.adj[node]){
		if(!vis[neighbour]){
			if(checkForUGCycleDFS(neighbour, node, vis, g))
				return true;
		}
		else{
			if(neighbour != parent)
				return true;
		}
	}

	return false;
}

bool isUGCycleDFS(Graph g){
	int V = g.adj.size();

	vector<int> visited(V+1, 0);

	for(int i=0; i<V; i++){
		if(!visited[i]){
			if(checkForUGCycleDFS(i, -1, visited, g))
			    return true;
		}
	}
	
	return false;
}

bool isUGCycleBFS(Graph g){
	int V = g.adj.size();

	vector<int> visited(V+1, 0);

	for(int i=0; i<V; i++){
		if(!visited[i]){
			if(checkForUGCycleBFS(i, g.adj.size(), visited, g))
			    return true;
		}
	}
	
	return false;
}

int main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	//g.addEdge(1, 2);
	//g.addEdge(2, 0);
	g.addEdge(2, 3);
	
	cout<<isUGCycleBFS(g);
	return 0;
}
