#include <stdio.h>
#include <stdlib.h>

#define ui unsigned int

short wiel(ui A, ui a){// czy A jest wieloktornością a
    if(A == 0) return 0;
    int b=A/a;
    if(b*a == A){ return 1;}
    return 0;
}


int main(){

    int N,M;
    scanf("%d %d", &N, &M);

    ui zakres = 1;
    int cnt = 0;
    for(ui i = 1; i<(1<<N); i++){
        if(wiel(i, M) == 0){
            zakres = 1;
            ui l = 0;
            while(zakres < (1<<N)){
                l = (zakres|i);
                if(wiel(l, M)==1){
                    cnt+=1;
                    break;
                }
                l = ((~zakres)&i);
                if(wiel(l, M) == 1){
                    cnt += 1;
                    break;
                }
                zakres <<= 1;
            }
        }
    }    
    printf("%d\n", cnt);

    return 0;
}