#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 2000000000

void merge(int** tab, int n){
	int* arr = malloc(n*n*sizeof(int));
	int size_arr = 0;
	int* wsk = malloc(n*sizeof(int));
	for(int i = 0; i<n; i++){ wsk[i] = 0; }
	int sum_wsk = 0;
	int mini_ele = MAX_INT;
	int mini_wsk = -1;

	while(sum_wsk < n*n){
		mini_ele = MAX_INT;
		mini_wsk = -1;
		for(int i = 0; i<n; i++){
			if(wsk[i] != n){
				if(mini_ele >= tab[i][wsk[i]]){
					mini_ele = tab[i][wsk[i]];
					mini_wsk = i;
				}
			}
		}

		if(size_arr>0){
			if(arr[size_arr-1] == mini_ele){
				wsk[mini_wsk]++;
				sum_wsk++;
			}
			else{
				arr[size_arr++] = mini_ele;
				sum_wsk++;
				wsk[mini_wsk]++;
			}
		}
		else{
			arr[size_arr] = mini_ele;
			wsk[mini_wsk]++;
			sum_wsk++;
			size_arr++;
		}
	
	}
	for(int i = 0; i<size_arr; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(wsk);
	free(arr);
}

int main(){
	
	int n;
	scanf("%d", &n);
	
	int** tab = malloc(n*sizeof(int*));
	for(int i = 0; i<n; i++){ tab[i] = malloc(n*sizeof(int)); }
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			scanf("%d", &tab[i][j]);
		}
	}
	
	merge(tab, n);

	for(int i = 0; i<n; i++){ free(tab[i]); }
	free(tab);
	
	return 0;
}
