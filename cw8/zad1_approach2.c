#include <stdio.h>
#include <stdlib.h>
#define lli long long int

lli f(lli x){
	lli sum = 0;
	while(x){
		sum+=x;
		x/=10;
	}
	return sum;
}

lli first(lli l){
	
	lli beg=1, end = l, mid;
	while(beg<=end){
		mid = beg + (end-beg)/2;
		lli zm = f(mid);
	//	printf("%lld %lld\n", zm, mid);
		if(zm == l){
			return mid;
		}
		else if(zm < l){
			beg = mid+1;
		}
		else{ end = mid-1; }
	}
	return -1;
}

int main(){
	
	lli l;
	scanf("%lld", &l);
	printf("%lld\n", first(l));
	return 0;
}
