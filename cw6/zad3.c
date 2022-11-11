#include <stdio.h>
#include <stdlib.h>

int cnt2(int** tab, int* tab_wsk,int n, int m){
	int *t_wsk = malloc((n+1)*sizeof(int));
	for(int i = 0; i<=n; i++){
		t_wsk[i] = 0;
	}
	int **t = malloc((n+1)*sizeof(*t));
	for(int i = 0; i<=n; i++){
		t[i] = malloc((n+2)*sizeof(int));
		for(int j = 0; j<n+2; j++){
			t[i][j] = '\0';
		}
	}

	for(int i = 1; i<=n; i++){
	for(int j = i+1; j<=n; j++){
		char exist = 0;
		for(int k = 0; k<tab_wsk[i]; k++){
			if(tab[i][k] == j){
				exist = 1;
				break;
			}
		}
		if(exist == 0){
			t[i][t_wsk[i]++] = j;
			t[j][t_wsk[j]++] = i;
		}
	}
	}
	int counter = 0;
	for(int i = 1; i<=n; i++){
		//printf("%d ", i);
		for(int j = 0; j<t_wsk[i]; j++){
			//printf("%d ", t[i][j]);
			for(int k =0; k<t_wsk[t[i][j]]; k++){
				//printf("%d ", t[t[i][j]][k]);
				for(int l = 0; l<t_wsk[t[t[i][j]][k]]; l++){
					//printf("%d\n", t[t[t[i][j]][k]][l]);
					if(t[t[t[i][j]][k]][l] == i){
						//printf("%d %d %d\n", i, t[i][j], t[t[i][j]][k]);
						counter++;
					}
				}
			}
		}
	}
	

	for(int i =0 ; i<=n; i++){
		free(t[i]);
	}
	free(t);
	free(t_wsk);

	return counter;
}

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	int *t_wsk = malloc((n+1)*sizeof(int));
	for(int i = 0; i<=n; i++){
		t_wsk[i] = 0;
	}
	int **t = malloc((n+1)*sizeof(*t));
	for(int i = 0; i<=n; i++){
		t[i] = malloc((n+2)*sizeof(int));
		for(int j = 0; j<n+2; j++){
			t[i][j] = '\0';
		}
	}

	int a, b;
	for(int i = 0; i<m; i++){
		scanf("%d %d", &a, &b);
		t[a][t_wsk[a]++] = b;
		t[b][t_wsk[b]++] = a;
	}
	int counter = 0;
	for(int i = 1; i<=n; i++){
		//printf("%d ", i);
		for(int j = 0; j<t_wsk[i]; j++){
			//printf("%d ", t[i][j]);
			for(int k =0; k<t_wsk[t[i][j]]; k++){
				//printf("%d ", t[t[i][j]][k]);
				for(int l = 0; l<t_wsk[t[t[i][j]][k]]; l++){
					//printf("%d\n", t[t[t[i][j]][k]][l]);
					if(t[t[t[i][j]][k]][l] == i){
						//printf("%d %d %d\n", i, t[i][j], t[t[i][j]][k]);
						counter++;
					}
				}
			}
		}
	}

	printf("%d\n", (counter+cnt2(t, t_wsk, n, m))/6);


	for(int i =0 ; i<=n; i++){
		free(t[i]);
	}
	free(t);
	free(t_wsk);

	return 0;
}	
