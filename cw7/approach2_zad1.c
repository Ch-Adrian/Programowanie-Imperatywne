#include <stdlib.h>
#include <stdio.h>

#define ull unsigned long long int
ull tab[100001];
int fib[30];
void show(int liczba, int dl){
	char* tab= malloc((dl+1)*sizeof(char));
	int wsk = dl;
	tab[wsk--] = '\0';
	
	while(wsk!=-1){
		tab[wsk--] = '0'+(liczba&1);
		liczba>>=1;
	}
	wsk = 0;
	while(tab[wsk]!='\0'){
		printf("%c", tab[wsk++]);
	}
	printf("\n");

	free(tab);
}

int main(){

	int N, K;
	scanf("%d %d", &N, &K);
	fib[1]=1;
	fib[2]=1;
	for(int i = 3; i<30; i++){
		fib[i] = fib[i-1]+fib[i-2];
	}

	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 4;
	tab[4] = 5;
	ull f_sum = 4;
	int dl = 2;
	int kt = 5;
	int pocz = 0;
	for(int f = 4; f < 30; f++){
		f_sum += fib[f];
		dl+=1;
		pocz = 0;
		while(kt <= f_sum){
			tab[kt++] = (1<<dl)|tab[pocz++];
			if( kt ==100000){
				break;
			}
		}
		if( kt == 100000){ break; }
	}

	ull ans = tab[K-1];
	dl = 0;
	while(ans){ dl++; ans>>=1; }
	if(dl <= N){
		show(tab[K-1], N);
	}
	else{
		printf("-1\n");
	}
	

	return 0;
}
