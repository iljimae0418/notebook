// finding values of euler phi function : https://en.wikipedia.org/wiki/Euler%27s_totient_function
int phi[MAXN];  
void eulerPhi(int n){
	phi[1] = 1;  
	for (int i = 2; i <= n; i++){
		if (!phi[i]){
			for (int j = i; j <= n; j += i){
				if (!phi[j]){
					phi[j] = j;   
				}
				phi[j] = phi[j]/i*(i-1);  
			}
		}
	}
}
