#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 200

void silnia(int* tab, int n){
	for(int i = 0; i<TAB_SIZE; i++){
		tab[i] = 0;
	}
	
	tab[0] = 1;
	int c =0, r = 0;
	while(n){
		for(int i = 0; i<TAB_SIZE; i++){
			tab[i] *= n;
		}
		for(int i = 0; i<TAB_SIZE-1; i++){
			tab[i] += c;
			r = tab[i]%10000;
			c = tab[i]/10000;
			tab[i] = r;
		}
		n--;
	}
	
}
void write(int *tab){
	int s = 0;
	for(int i =TAB_SIZE-1; i>=0; i--){
		if(tab[i] != 0){
			s = i;
			break;
		}
	}
	printf("%d", tab[s]);
	for(int i = s-1; i>=0; i--){
		if(tab[i] < 10) printf("000");
		else if(tab[i] < 100) printf("00");
		else if(tab[i] < 1000) printf("0");
		printf("%d", tab[i]);		
	}
	printf("\n");
}

int main(){

	int* tab = malloc(TAB_SIZE*sizeof(int));
	int n;
	scanf("%d", &n);
	silnia(tab, n);
	write(tab);
	free(tab);
	return 0;
}
