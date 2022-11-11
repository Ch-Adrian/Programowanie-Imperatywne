#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n;
	scanf("%d", &n);

	int t[n][n];

	int cnt = 1;
	for( int i = 0; i<n/2+1; i++){
		
		for(int j = i; j<n-i; j++){
			t[j][i] = cnt++;
		}

		for(int j = i+1; j<n-i; j++){
			t[n-1-i][j] = cnt++;
		}

		for(int j = n-i-2; j>i-1; j--){
			t[j][n-i-1] = cnt++;
		}

		for(int j = n-2-i; j>i; j--){
			t[i][j] = cnt++;
		}
	}
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			printf("%d ",t[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
