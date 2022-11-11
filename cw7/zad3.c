#include <stdlib.h>
#include <stdio.h>

#define lli long long int

int main(){

	int n, k, l;
	scanf("%d %d %d", &n, &k, &l);
	lli** T = malloc(n*sizeof(lli*));
	for(int i = 0; i<n; i++){
		T[i] = malloc(n*sizeof(lli));
		for(int j = 0; j<n; j++){
			scanf("%lld ", &T[i][j]);
		}
	}
	
	short** P = malloc(k*sizeof(short*));
	for(int i = 0; i<k; i++){
		P[i] = malloc(l*sizeof(short));
		for(int j = 0; j<l; j++){
			scanf("%hd ", &P[i][j]);
		}
	}

	lli max_sum = 0;
	lli sum = 0;
	for(int i = 0; i<n-k; i++){
		for(int j = 0; j<n-l; j++){
			sum = 0;
			for(int m = i; m<i+k; m++){
				for(int n = j; n<j+l; n++){
					if(P[m-i][n-j] == 1){
						sum += T[m][n];
					}
				}
			}
			if(max_sum < sum){ max_sum = sum; }
		}
	}
	
	printf("%lld\n", max_sum);
	
	for(int i = 0; i<k; i++){
		free(P[i]);
	}
	free(P);

	for(int i = 0; i<n; i++){
		free(T[i]);
	}
	free(T);

	return 0;
}
