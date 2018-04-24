
vector<int> getPartialMatch(string &s){
	int m = s.size(); 
	vector<int> pi(m,0); 
	int begin = 1, matched = 0; 
	while (begin+matched < m){
		if (s[begin+matched] == s[matched]){
			++matched;  
			pi[begin+matched-1] = matched; 
		}else{
			if (matched == 0) ++begin; 
			else{
				begin += matched-pi[matched-1];  
				matched = pi[matched-1]; 
			}
		}
	}
	return pi;  
}

vector<int> kmp(string &H,string &N){
	int n = H.size(),m = N.size(); 
	vector<int> ret; 
	vector<int> pi = getPartialMatch(N); 
	int begin = 0, matched = 0; 
	while (begin <= n-m){
		if (matched < m && H[begin+matched] == N[matched]){
			++matched; 
			if (matched == m) ret.push_back(begin);  
		}else{
			if (matched == 0) ++begin; 
			else{
				begin += matched-pi[matched-1]; 
				matched = pi[matched-1]; 
			}
		}
	}
	return ret;
}
