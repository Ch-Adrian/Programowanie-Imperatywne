#include <stdio.h>

int main(){
	int n, m, counter = 0;
	scanf("%i %i", &n, &m);
	long long int tab[100];
	if(n%2==1) n++; 
	
	long long int pot = 2;
	while(((pot-1)*(pot/2)) <= m){
		if(((pot-1)*(pot/2))<n) {
			pot *= 2;
			continue;
		}
		int pierwsza = 1;
		long long int i = 2; 
		while(i<pot-1){
			if((pot-1)%i == 0) {
			pierwsza = 0;
			break;
			}
			i++;
		}
		if(pierwsza == 1){
			tab[counter] = (pot-1)*(pot/2);
			counter++;
		}
		pot *= 2;
	}

	printf("%i\n", counter);
	int i = 0;
	while(i<counter){
		printf("%lli ", tab[i]); 
		i++;
	}
	

	return 0;
}
