#include <stdio.h>

short lpierwsza(int n){
	if( n == 2 || n==3 || n == 5){ return 1;}
	if(n<2 || n%2 == 0 || n%3 == 0 || n%5 == 0){ return 0; }

	int k = 5;
	while(k*k<=n){
		k+=2;
		if(n%k == 0) return 0;
		k+=2;
		if(n%k == 0) return 0;
	}

	return 1;
}

short niemalejacy(int n){
	int tmp = n%10;
	n = n/10;
	while(n>0){
		int tmp2 = n%10;
		if(tmp2 > tmp) return 0;
		tmp = tmp2;
		n/=10;
	}
	return 1;
}

int main(){
	int n;
	scanf("%i", &n);
	int i = 2;
	while(i<=n){
		if(lpierwsza(i) == 1 && niemalejacy(i) == 1){
			printf("%i\n", i);
		}
		i++;
	}
	
	return 0;
}
