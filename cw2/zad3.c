#include <stdio.h>
#include <stdlib.h>

#define p(A, B, C) printf("%c:%i %i", A, B, C)

int check_podz(int* wsk, int pos, int sumB){
	int dwa = 1, i = pos+1;
	printf("%c", 'a');
	while(i){
		dwa *= 2;
		i--;
	}
	dwa--;
	p('c', dwa, 0);
	i = 0;
	while(i < dwa){
		int t = i;
		int masa = 0;
		int idx = pos;
		while(t){
			if(t%2 == 1){
				masa += wsk[idx--];
			}
			t = t>>1;
		}

		if(masa + sumB == 0){
			return 1;
		}

	}
	return 0;
}

int podzb(int* tab, int len, int w){
	int dwa = 1, i = len;
	while(i){
		dwa *= 2;
		i--;
		printf("%i\n", dwa);
	}
	dwa-=1;
	printf("%i\n", dwa);

	int masa = 0;
	int* wsk = (int*)malloc((len+1) * sizeof(int));
	int pos = 0;
	i = 0;
	while(i < dwa){
		printf("%i\n", i);
		int t = i;
		masa = 0;
		int idx = len-1;
		while(t != 0){
			if(t%2 == 1){
				masa += tab[idx--];
			}
			else{
				wsk[pos++] = tab[idx--];
			}
			t = t>>1;
			printf("t:%i\n", t);
		}
		printf("dizla");
		if(check_podz(wsk, pos, w - masa) == 1){
			printf("YES\n");
			return 1;
		}

		i++;
	}

	free(wsk);
	return 0;
}

int main(){
	
	int n, w;
	scanf("%i %i", &n, &w);
	int* tab = (int*)malloc(n * sizeof(int));
	int i = 0;
	while(i< n){
		scanf("%i", &tab[i]);
		i++;
	}

	if(!podzb(tab, n, w)){ printf("NO\n"); }

	free(tab);
	
	return 0;
}
