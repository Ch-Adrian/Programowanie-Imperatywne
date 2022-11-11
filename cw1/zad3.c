#include <stdio.h>

int main(){
	
	long long int n;
	scanf("%lli", &n);

	long long int a = 0, b = 1, c;
	while(a*b<=n){
		if(a*b == n){
			printf("YES");
			return 0;
		}
		c = b;
		b = a+b;
		a = c;
	}
	printf("NO");
	return 0;
}
