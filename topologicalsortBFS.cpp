int graph[MAXN][MAXV];  
int indegree[MAXV]; 
int topologicalOrder[MAXV]; 
int V; 

int main(){
	// get input 
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			if (graph[j][i]) indegree[i]++;  
		}
	}
	queue<int> q; 
	for (int i = 1; i <= V; i++){
		if (indegree[i] == 0) q.push(i);  
	}
	int counter = 0, v; 
	while (!q.empty()){
		v = q.front(); q.pop();  
		topologicalOrder[v] = ++counter; 
		for (int i = 1; i <= V; i++){
			if (graph[v][i] && --indegree[i] == 0) q.push(i);  
		}
	}
	if (counter != n) printf("0\n");  
	else{
		vector< pair<int,int> > a; 
		for (int i = 1; i <= V; i++){
			a.push_back(make_pair(topologicalOrder[i],i));  
		}
		sort(a.begin(),a.end());  
		for (int i = 0; i < a.size(); i++){
			printf("%d\n",a[i].second);  
		}
	}
} 
