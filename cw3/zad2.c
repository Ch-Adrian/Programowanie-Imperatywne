#include <stdio.h>
#include <stdlib.h>

short find(int* t, int n,  int x, int k){
    for(int i =0; i<n; i++){
        if(t[i] != x && t[i]-k <= x && t[i]+k >= x){
            return 1;
        }
    }
    return 0;

}

int main(){

    int n,k;
    scanf("%d %d", &n, &k);

    int* t = malloc((n+1)*sizeof(int));

    for(int i = 0; i<n; i++){
        scanf("%d", &t[i]);
    }
    int cnt = 0;
    for(int i =0 ; i<n; i++){
        if(find(t, n, t[i], k) == 1) cnt++;
    }
    printf("%d\n", cnt);
    
    free(t);

    return 0;
}