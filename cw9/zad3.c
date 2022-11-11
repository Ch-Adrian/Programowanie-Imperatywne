#include <stdio.h>
#include <stdlib.h>

int main(){

    int N, G;
    scanf("%d %d", &N, &G);
    int *T = malloc(N* sizeof(int));
    int *sum = malloc(33*sizeof(int));
    for(int i =0; i<33; i++){
        sum[i] = 0;
    }

    for(int i = 0; i<N; i++){
        scanf("%d", &T[i]);        
        if((T[i]|G) != G){
                T[i] = 0;
        }
    }

    for(int i = 0; i<N; i++){
        int cnt = 0;
        while(T[i]){
            sum[cnt] += T[i]%2;
            T[i] >>= 1;
            cnt++;
        }
    }


    int mini = N+1;
    int cnt = 0;
    while(G){
        if(G%2){
            if(mini > sum[cnt]){
                mini = sum[cnt];
            }
        }
        cnt++;
        G>>=1;
    }

    printf("%d\n", mini);

    free(T);
    free(sum);

    return 0;
}