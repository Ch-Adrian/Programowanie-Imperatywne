#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n, s;
	scanf("%d %d", &n, &s);
	int t[n][n];
	int answer[n][2];
	int cnt = 0;

	for(int i =0 ;i<n; i++){
		for(int j = 0; j<n;j++){
			scanf("%d", &t[i][j]);
		}
	}

	for(int K = 3; K<=n; K+=2){
		int mid = K/2;
		for(int i = mid; i<=n-mid-1; i++){
			for(int j = mid; j<=n-mid-1; j++){
				int sum_zew = 0;
				int sum_wew = 0;
				for(int k = i-mid; k<K+i-mid; k++){
					for(int l = j-mid; l<K+j-mid; l++){
						sum_zew += t[k][l];
					}
				}
				
				for(int k = i-mid+1; k<K+i-mid-1; k++){
					for(int l = j-mid+1; l < K+j-mid-1; l++){
						sum_wew += t[k][l];
					}
				}

				if(sum_zew - sum_wew == s){
					answer[cnt][0] = i;
					answer[cnt++][1] = j;
				}

			}	
		}
	}

	printf("%d\n", cnt);
	for(int i = 0; i<cnt; i++){
		printf("%d %d\n", answer[i][0], answer[i][1]);
	}
	
	return 0;
}
