#include <stdio.h>
#include <stdlib.h>

#define lli long long int

int main(){
	int n,k;
	scanf("%d %d", &n,&k);
	int N = n;
	n = 3*n;
	lli** T = malloc(n*sizeof(lli*));
	for(int i = 0; i<n; i++){
		T[i] = malloc(n*sizeof(lli));
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			scanf("%lld", &T[i][j]);
			T[i+N][j] = T[i][j];
			T[i+2*N][j] = T[i][j];
			T[i][j+N] = T[i][j];
			T[i+N][j+N] = T[i][j];
			T[i+2*N][j+N] = T[i][j];
			T[i][j+2*N] = T[i][j];
			T[i+N][j+2*N] = T[i][j];
			T[i+2*N][j+2*N] = T[i][j];
			}
	}

	// horizontally
	lli max_sum = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<2*N; j++){
			lli sum = 0;
			for(int l = 0; l<k; l++){
				sum+= T[i][l+j];
			}
			if(max_sum < sum){
				max_sum = sum;
			}
		}
	}
	// vertically
	for(int i = 0; i<n; i++){
		for(int j = 0; j<2*N; j++){
			lli sum = 0;
			for(int l = 0; l<k; l++){
				sum += T[j+l][i];
			}
			if(max_sum<sum){ max_sum = sum; }
		}
	}
	
	for(int i = 0; i<N; i++){
		lli sum = 0;
		int j = 0;
		int l = 0;
		while( j < N ){
			sum = 0;
			l = 0;
			while(l<k){
				sum += T[j+l][i+j+l];
				l++;
			}
			if(max_sum<sum){ max_sum = sum; }
			j++;
		}
	}
	
	for(int i = n-1; i>= 2*N; i--){
		lli sum = 0;
		int l = 0;
		int j = 0;
		while(j<N){
			sum  = 0;
			l = 0;
			while(l<k){
				sum += T[j+l][i-j-l];
				l++;
			}
			j++;
			if(max_sum<sum){ max_sum = sum; }
		}
	}
	
	/*
	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			D[n-1-i][j] = T[j-i][i];
		}
	}
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<n-1-i; j++){
			D[i][j] = T[j+1+i][n-1-i];
		}
	}
	*/
	
	
	/*for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			printf("%lld ", T[i][j]);
		}
		printf("\n");
	}*/
	
	
	printf("%lld\n", max_sum);
	for(int i = 0; i<n; i++){
		free(T[i]);
	}
	free(T);
	return 0;
}
