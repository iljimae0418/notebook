// finds all the prime numbers in the range [0,MAXN] by using the sieve of eratosthenes algorithm 
// Time complexity O(sqrt(n)loglog(n)) 
int isPrime[MAXN+1]; 
void sieve(){
  for (int i = 0; i <= MAXN; i++) iPrime[i] = 1;  
	isPrime[0] = isPrime[1] = 0;  
	for (int i = 2; i*i <= MAXN; i++){
		if (isPrime[i]){
			for (int j = i*i; j <= MAXN; j += i){
				isPrime[j] = 0;  
			}
		}
	}
}
