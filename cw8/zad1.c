#include <stdlib.h>
#include <stdio.h>

#define lli long long int

lli f(lli S, int cnt, int Dodo){
	printf("%lld\n", S);	

	if( S == 0){ return 0; }
	if( S <0 || cnt <= 0) { return -1; }

	lli l = 10;
	lli s = S;
	while(s){
		l = s%10;
		s = s/10;
	}
	//printf("%lld %d\n", l, cnt);
	if(Dodo <= 0 ){
			lli a = 0;
			lli zm = 0;
			lli tmp_s = S;
			lli tmp_cnt = cnt;
			while(tmp_cnt--){
				tmp_s -= a;
				a *= 10;
			}
			zm = f(tmp_s, cnt - 1, Dodo);
			if(zm != -1){
				while( a < zm ) { a *= 10; }
				return a+zm;
			}
		}
		Dodo -= 1;
	if(l == 1){
		printf("Pierwszy if: %d %d\n", l, cnt);
			lli a = 1;
			lli zm = 0;
			lli tmp_s = S;
			lli tmp_cnt = cnt;
			while(tmp_cnt--){
				tmp_s -= a;
				a *= 10;
			}
			zm = f(tmp_s, cnt - 1, Dodo);
			if(zm != -1){
				while( a < zm ) { a *= 10; }
				return a+zm;
			}
			a = 9;
			zm = 0;
			tmp_s = S;
			tmp_cnt = cnt-1;
			while(tmp_cnt--){
				tmp_s -= a;
				a *= 10;
			}
			zm = f(tmp_s, cnt - 2, Dodo);
			if(zm != -1){
				while( a < zm ) { a *= 10; }
				return a+zm;
			}
	}
	else{
			printf("Drugi if: %d %d\n", l, cnt);	
			lli a = l;
			lli zm = 0;
			lli tmp_s = S;
			lli tmp_cnt = cnt;
			while(tmp_cnt--){
				tmp_s -= a;
				a *= 10;
			}
			zm = f(tmp_s, cnt - 1, Dodo);
			if(zm != -1){
				while( a < zm ) { a *= 10; }
				return a+zm;
			}
			a = l-1;
			zm = 0;
			tmp_s = S;
			tmp_cnt = cnt;
			while(tmp_cnt--){
				tmp_s -= a;
				a *= 10;
			}
			zm = f(tmp_s, cnt - 1, Dodo);
			if(zm != -1){
				while( a < zm ) { a *= 10; }
				return a+zm;
			}
	}

	return -1;
}

lli first(lli S){

}

lli check(lli x){
	lli S = 0;

	while(x){
		S+=x;
		x /= 10;
	}
	return S;
}

int main(){
	
	lli S;
	scanf("%lld", &S);
	//for(int i = 1; i<=1000; i++){
	//S = i;
	int cnt =0;
	lli tmp = S;
	while(tmp){
		cnt++;
		tmp /= 10;
	}
	printf("%lld ", S);
	lli ans = f(S, cnt, 1)/10;
	//printf("%lld\n", ans);
	if(check(ans) == S){
		printf("%lld\n", ans);
	}
	else{
		printf("%d\n", -1);
	}
	//}
	

	return 0;
}
