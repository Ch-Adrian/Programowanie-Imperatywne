#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HUNDRED 100
#define LL long long

struct liczba{
    LL * l;
    int dl;
    short ujemna;
};

void divU(struct liczba* licz){
    struct liczba tmp;
    tmp.l = malloc(31*sizeof(LL));
    for(int i = 0; i<31; i++){
        tmp.l[i] = 0;
    }
    tmp.dl = 0;
    tmp.ujemna = 0;
    //printf("%d\n", licz->dl);
    for(int i = licz->dl-1; i>0; i--){
        if(licz->l[i]%2 == 1){
            tmp.l[i-1] += 5; 
        }
        tmp.l[i] += licz->l[i]/2;
    }
    if(licz->l[0]%2 == 1){
        tmp.l[0] += (licz->l[0]+1)/2;
    }
    else{
        tmp.l[0] += licz->l[0]/2;
    }

    for(int i= 0; i<licz->dl-1; i++){
        if(tmp.l[i]/10 != 0){
            tmp.l[i+1] += tmp.l[i]/10;
        }
        tmp.l[i] = tmp.l[i]%10;
    }

    if(tmp.l[licz->dl-1] == 0){
        tmp.l[licz->dl-1] = -1;
        tmp.dl = licz->dl-1;
    }
    else{
        tmp.l[licz->dl] = -1;
        tmp.dl = licz->dl;
    }

    LL* tmpL = licz->l;
    licz->l = tmp.l;
    licz->dl = tmp.dl;
    licz->ujemna = tmp.ujemna;
    free(tmpL);        

}

void divP(struct liczba* licz){
    struct liczba tmp;
    tmp.l = malloc(31*sizeof(LL));
    for(int i =0 ; i<31; i++){
        tmp.l[i] = 0;
    }

    tmp.dl = 0;
    tmp.ujemna = 1;
    for(int i = licz->dl-1; i>0; i--){
        if(licz->l[i]%2 == 1){
            tmp.l[i-1] += 5;
        }
        tmp.l[i] += licz->l[i]/2;
    }
    if(licz->l[0]%2 == 1){
        tmp.l[0] += (licz->l[0]-1)/2;
    }
    else{
        tmp.l[0] += licz->l[0]/2;
    }

    for(int i =0 ; i<licz->dl; i++){
        if(tmp.l[i]%10!= 0){
            tmp.l[i+1] += tmp.l[i]/10;
        }
        tmp.l[i] = tmp.l[i]%10;
    }

    if(tmp.l[licz->dl-1] == 0){
        tmp.l[licz->dl-1] = -1;
        tmp.dl = licz->dl-1;
    }
    else{
        tmp.l[licz->dl] = -1;
        tmp.dl = licz->dl;
    }

    LL* tmpL = licz->l;
    licz->l = tmp.l;
    licz->dl = tmp.dl;
    licz->ujemna = 1;
    free(tmpL);
}

int mod(struct liczba* licz){
    if(licz->dl!= 0){
        return licz->l[0]%2;
    }
    else return 0;
}

short zero(struct liczba* licz){
    for(int i = 0; i<licz->dl; i++){
        if(licz->l[i] > 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int ile = 0;
    scanf("%d", &ile);
    while(ile--){
    char *n = malloc(31*sizeof(char));
    short *tab = malloc(100*sizeof(short));
    struct liczba L;
    struct liczba LU;
    L.l = malloc(31*sizeof(LL));
    LU.l = malloc(31*sizeof(LL));
    scanf("%s", n);
    L.dl = strlen(n);
    L.ujemna = 0;
    LU.dl = strlen(n);
    LU.ujemna = 0;

    if(n[0] == '-'){
        for(int i = 0;i<L.dl-1;i++){
            L.l[i] = (n[L.dl-1-i] - '0');
        }
        L.dl--;
        L.l[L.dl] = -1;
        L.ujemna = 1;
        LU.ujemna = 0;
    }
    else{
        for(int i = 0; i<L.dl; i++){
            L.l[i] = (n[L.dl - 1 - i] - '0');
        }
        L.l[L.dl] = -1;
        LU.ujemna = 1;
    }

    for(int i= 0; i<L.dl; i++){
        LU.l[i] = L.l[i];
    }
    LU.dl = L.dl;

    for(int i = 0; i<31; i++){
        //printf("%lld", L.l[i]);
    }
    //printf("\n");
    //printf("%d\n", L.dl);
    //printf("%d\n", L.ujemna);

    for(int i = 0; i<HUNDRED; i++){
        tab[i] = 0;
    }

    for(int i =0 ;i<HUNDRED; i++){
        tab[i] = mod(&L);
        if(L.ujemna == 1) divU(&L);
        else divP(&L);
    }
    if(zero(&L)){
        for(int i =HUNDRED-1; i>=0; i--){
            if(tab[i] == 1){
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    else{
        printf("NIE\n");
    }

    for(int i = HUNDRED-1; i>=0; i--){
        tab[i] = 0;
    }

    for(int i =0 ;i<HUNDRED; i++){
        tab[i] = mod(&LU);
        if(LU.ujemna == 1) divU(&LU);
        else divP(&LU);
    }
    if(zero(&LU)){
        for(int i =HUNDRED-1; i>=0; i--){
            if(tab[i] == 1){
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    else{
        printf("NIE\n");
    }


    free(n);
    free(tab);
    free(L.l);
    }
    return 0;
}