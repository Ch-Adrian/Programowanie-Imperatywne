#include <stdio.h>
#include <stdlib.h>

void showTab(int **tab, int n, int r){
	for(int i = 0; i<(n+2*r); i++){
		for(int j = 0; j<(n+2*r); j++){
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	int n, r;
	scanf("%d %d", &n, &r);
	r++;
	int** tab=malloc((n+2*r)*sizeof(int*));
	for(int i = 0; i<(n+2*r); i++){
		tab[i] = malloc((n+2*r)*sizeof(int));
	}
	
	for(int i = r; i<(n+r); i++){

		for(int j = r; j<(n+r); j++){
			scanf("%d", &tab[i][j]);
		}
	}

	//showTab(tab,n,r);

	

	for(int i = 1; i<(n+2*r); i++){
		for(int j = 1; j<(n+2*r); j++){
			tab[i][j] = tab[i][j] + tab[i-1][j] + tab[i][j-1] - tab[i-1][j-1];
		}
	}

	//showTab(tab,n,r);

	for(int i = r; i<(n+r); i++){
		for(int j = r; j<(n+r); j++){
			printf("%d ", tab[i+r-1][j+r-1] - tab[i+r-1][j-r] - tab[i-r][j+r-1] + tab[i-r][j-r]);
		}
		printf("\n");
	}

	
	for(int i = 0; i<(n+2*r); i++){
		free(tab[i]);
	}
	free(tab);
	
	return 0;
}
