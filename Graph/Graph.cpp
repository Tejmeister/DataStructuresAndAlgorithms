#include <bits/stdc++.h>

using namespace std;

class Graph {
	public:
	int V;
	unordered_map<int, vector<int>> adj;
	
	Graph(int V);
	void addEdge(int start, int end);
	vector<int> DFS(int startVertex);
	vector<int> BFS(int startVertex);
	void DFS(int startVertex, vector<int> &visited, vector<int>& result);
};

Graph::Graph(int V){
    this->V = V;
}

void Graph::addEdge(int start, int end){
	adj[start].push_back(end);
	// uncomment for undirected graph
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

bool checkForDGCycleDFS(int node, vector<int>& dfsVis, vector<int>& vis, Graph g){
	vis[node] = 1;
	dfsVis[node] = 1;
	for(auto neighbour : g.adj[node]){
		if(!vis[neighbour]){
			if(checkForDGCycleDFS(neighbour, dfsVis, vis, g))
				return true;
		}
		else{
			if(dfsVis[neighbour])
				return true;
		}
	}
	dfsVis[node] = 0;

	return false;
}

bool isDGCycleDFS(Graph g){
    int V = g.adj.size();

	vector<int> visited(V, 0);
	vector<int> dfsVisited(V, 0);

	for(int i=0; i<V; i++){
		if(!visited[i]){
			if(checkForDGCycleDFS(i, dfsVisited, visited, g))
			    return true;
		}
	}
	
	return false;
}

// Using Kahn's algorithm of topological sort
bool isDGCycleBFS(int V, Graph g){
    
    // Queue for BFS
    queue<int> q;
    
    // indegree for Kahn's algorithm
    vector<int> indegree(V, 0);
    
    for(int i=0; i <V; i++){
        for(auto node: g.adj[i]){
            indegree[node]++;
        }
    }
    
    // put nodes with indegree = 0 in queue
    for(int i=0; i<V; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    // init count
    // if final count is equal to total nodes then there is no cycle 
    
    int count = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        count++;
        
        for(auto neighbour: g.adj[node]){
            if(--indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if(count == V)
        return false;
        
    return true;
}

void topologicalSortUtil(int node, stack<int> &s, vector<int>& vis, Graph g){
	vis[node] = 1;

	for(int neighbor: g.adj[node]){
		if(!vis[neighbor]){
			topologicalSortUtil(neighbor, s, vis, g);
		}
	}
	s.push(node);
}

vector<int> topologicalSortDFS(Graph g){
	int V = g.adj.size();
	vector<int> visited(V, 0);
	stack<int> s;

	for(int i=0; i<V; i++){
		if(!visited[i]){
			topologicalSortUtil(i, s, visited, g);
		}
	}

	vector<int> result;

	while(!s.empty()){
		result.push_back(s.top());
		s.pop();
	}

	return result;
}

vector<int> topologicalSortBFS(Graph g){
	int V = g.V;
	cout<<V;
	vector<int> indegree(V, 0);
	for(int i=0; i<V; i++){
		for(auto neighbor: g.adj[i])
			indegree[neighbor]++;
	}

	queue<int> q;

	for(int i=0; i<V; i++){
		if(indegree[i] == 0)
			q.push(i);
	}

	vector<int> result;

	while(!q.empty()){
		int current = q.front();
		q.pop();

		result.push_back(current);

		for(auto neighbor: g.adj[current]){
			if(--indegree[neighbor] == 0)
				q.push(neighbor);
		}
	}

	return result;
}

bool isBipartiteBFSUtil(int node, vector<int>& color, Graph g){
    queue<int> q;
    q.push(node);
    
    color[node] = 1;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int neighbor: g.adj[curr]){
            if(color[neighbor] == -1){
                color[neighbor] = 1 - color[curr];
                q.push(neighbor);
            }
            else if(color[neighbor] == color[curr]){
                return false;
            }
        }
    }
    
    return true;
}

bool isBipartiteBFS(Graph g){
    int V = g.V;
    vector<int> color(V, -1);
    
    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if(!isBipartiteBFSUtil(i, color, g))
                return false;
        }
    }
    return true;
}

int main()
{
    
	Graph g(9);   
    // Biparatite eg.
    /*    
        8 7 
        0 1 
        1 2 
        2 3 
        3 4 
        4 6 
        6 7 
        1 7
        4 5 
    */

    g.addEdge(8, 7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 6);
    g.addEdge(6, 7);
    g.addEdge(1, 7);
    g.addEdge(4, 5);
	
    cout<<isBipartiteBFS(g);	
	
	// Non-Biparatite eg.
    /*    
        8 7 
        0 1 
        1 2 
        2 3 
        3 4 
        4 6 
        6 7 
        1 7
        4 5 
    */
    Graph nbg(7);
    
    nbg.addEdge(7, 7);
    nbg.addEdge(0, 1);
    nbg.addEdge(1, 2);
    nbg.addEdge(2, 3);
    nbg.addEdge(3, 4);
    nbg.addEdge(4, 6);
    nbg.addEdge(6, 1);
    nbg.addEdge(4, 5);
	
    cout<<isBipartiteBFS(nbg);
	
	return 0;
}
