#include <stdio.h>

unsigned long long int sumF2(int l){
	if(l == 0) return 0;
	unsigned long long int sum = (l+1)/2;
	return sum*sum + sumF2(l/2);
}

int main(){

	int l;
	scanf("%d", &l);
	printf("%lld\n", sumF2(l));
	
	return 0;
}
