#include <stdio.h>
#include <stdlib.h>

int rek(int* tab, int len, int w, int wsk, int sumA, int sumB){
	if(wsk == len && sumA == sumB+w){
			printf("YES\n");
			return 1;
	}
	else if(wsk<len){
		int a = rek(tab,len,w,wsk+1, sumA+tab[wsk], sumB);
		if(a== 1) return 1;
		a = rek(tab,len,w,wsk+1, sumA, sumB+tab[wsk]);
		if(a==1) return 1;
		a= rek(tab,len,w,wsk+1, sumA, sumB);
		if(a==1) return 1;
	}
	return 0;
}

int main(){
	
	int n, w, sum;
	sum = 0;
	scanf("%i %i", &n, &w);
	int* tab = (int*)malloc(n * sizeof(int));
	int i = 0;
	
	while(i< n){
		scanf("%i", &tab[i]);
		sum += tab[i];
		i++;
	}
	
	if(sum < w || !rek(tab, n, w,0,0,0)) printf("NO\n");

	free(tab);
	
	return 0;
}
