// Tarjan's SCC algorithm 
vector< vector<int> > adj; 
// the component number starts from 0.  
vector<int> sccId; 
vector<int> discovered;  
stack<int> st;  
int sccCounter,vertexCounter;  

// here를 루트로 하는 서브트리에서 역방향 간선이나 교차 간선을 
// 통해 갈 수 있는 정점 중 최소 발견 순서를 반환한다. 
// (이미 강한 연결 컴포넌트로 묶인 정점으로 연결된 교차 간선은 무시한다). 
int scc(int here){
	int ret = discovered[here] = vertexCounter++; 
	// we put here in stack. Every child of here goes after here in the stack. 
	st.push(here); 
	for (int i = 0; i < adj[here].size(); i++){
		int there = adj[here][i];  
		if (discovered[there] == -1){
			ret = min(ret,scc(there)); 
		}
		else if (sccId[there] == -1){
			ret = min(ret,discovered[there]); 
		}
	}
	if (ret == discovered[here]){
		while (true){
			int t = st.top(); 
			st.pop();  
			sccId[t] = sccCounter; 
			if (t == here) break; 
		}
		sccCounter++;  
	}
	return ret;  
}

vector<int> tarjanSCC(){
	sccId = discovered = vector<int>(adj.size(),-1);  
	sccCounter = vertexCounter = 0;  
	for (int i = 0; i < adj.size(); i++){
		if (discovered[i] == -1) scc(i); 
	}
	return sccId; 
}

