#include <stdio.h>

int main(){
	int n;
	scanf("%i", &n);
	int tab[n];
	long long int sum = 0;
	int i = 0; 
	while(i<n){
		scanf("%i", &tab[i]);
		sum += tab[i];
		i++;
	}
	i = 0;
	long long int sum2 = 0;
	while(i<n){
		if(sum2 == sum - tab[i] - sum2){
			printf("%i\n", i);
		}
		sum2 += tab[i];
		i++;
	}

	return 0;
}
