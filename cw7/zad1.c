#include <stdlib.h>
#include <stdio.h>

#define ull unsigned long long int

ull f_rek(ull liczba, int dl, int k){
	
	static int cnt = 1;
	if(liczba == 1) cnt = 1;
	//printf("l, cnt, k: %lld %d %d\n", liczba, cnt, k);
	if(k == 0) {
		return 0;
	}

	if(k == cnt){
		return liczba;
	}

	if((liczba&1)!= 0 || (liczba&2) != 0){
		if( ((1<<(dl-1))&liczba) != 0){
			return 0;
		}
		//printf("cnt: %d\n", cnt);
		cnt += 1;
		return f_rek(liczba<<1, dl, k);
	}
	else{
		cnt += 1;
		ull l = 0;
		l = f_rek(liczba|1, dl, k);
		if(l != 0){ return l; }
		cnt += 1;
		l = f_rek(liczba<<1, dl, k);
		if ( l != 0){ return l; }
		cnt += 1;
		l = f_rek((liczba|1)<<1, dl, k);
		return l;
	}

} 

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
	ull ans = f_rek(1, N, K-1);
	if(K==1){
		show(0, N);
	}
	else{
		if(ans == 0){
			printf("%d\n", -1);
		}
		else{
			show(ans, N);
		}
	}

		
	printf("%lld\n", f_rek(1, 63, 100000));
	for(int i = 0; i<13; i++){ 
		ull ans2 = f_rek(1,5, i);
		printf("%d: %lld\n", i, ans2);
		show(ans2, 5);
	}
	

	return 0;
}
