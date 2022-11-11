#include <stdio.h>
#include <stdlib.h>

short prime(long long int x){
    if(x == 2 || x == 3 || x == 5) return 1;
    if(x<2 || x%2 == 0 || x%3 == 0 || x%5==0) return 0;

    long long int k = 5;
    while(k*k<=x){
        k+=2;
        if(x%k==0) return 0;
        k+=4;
        if(x%k==0) return 0;
    }
    return 1;
}

short jednokw(int x){
    int tmp = x, tmp_sum = 0;
    while(x != 1 && x != 4){
        tmp = x;
        tmp_sum = 0;
        while(tmp>0){
            tmp_sum += (tmp%10)*(tmp%10);
            tmp = tmp/10;
        }
        x = tmp_sum;
    }
    if( x == 1) return 1;
    else return 0;
}

int main(){

    int l,u,k, cnt = 0;
    scanf("%d %d %d", &l, &u, &k);

    for(int i = l; i<=u; i++){
        if(prime(i) == 1 && jednokw(i)){
            cnt++;
            if(cnt == k){
                printf("%d\n", i);
                return 0;
            }
        }
    }
    printf("%d\n", -1);

    return 0;
}