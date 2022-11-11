#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if( a<b){ return b; }
	else return a;
}

int main(){

	int n;
	scanf("%d", &n);

	int t[n+2][n+2];
	for(int i = 0; i<n+2; i++){
		for(int j = 0; j<n+2; j++){
			t[i][j] = 0;
		}
	}
	for(int i = 1; i<n+1; i++){
		for(int j = 1; j<n+1; j++){
			scanf("%d", &t[i][j]);
		}
	}

	for(int i = 1; i<n+2; i++){
		for(int j = 1; j<n+2; j++){
			t[i][j] = t[i][j] + t[i-1][j] + t[i][j-1] - t[i-1][j-1];
		}
	}

	int maxi = 0;
	for(int i = 1; i<n+1; i++){
		for(int j = 1; j<n+1; j++){
			for(int k = i; k<n+1;k++){
				for(int l = j; l<n+1; l++){
					if(t[k][l] - t[k][j-1] - t[i-1][l] + t[i-1][j-1] == 0){
						maxi = max(maxi, (k-i+1)*(l-j+1));
					}
				}
			}
		}
	}
	printf("%d\n", maxi);
	return 0;
}
