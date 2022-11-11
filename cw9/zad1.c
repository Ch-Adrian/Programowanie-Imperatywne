#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sor(char *t, int size){

    for(int i = 1; i<size; i++){
        int j= i-1;
        char ele = t[i];
        while( j>=0 && t[j] > ele){
            t[j+1] = t[j];
            j--;
        }
        t[j+1] = ele;
    }

}

short lpierwsza(int a){
    if( a == 2 || a == 3 || a == 5) return 1;
    if( a%2== 0 || a%3 == 0 || a%5 == 0) return 0;

    int k = 5;
    while(k*k <=a){
        k += 2;
        if(a%k == 0) return 0;
        k+= 4;
        if(a%k == 0) return 0;
    }
    return 1;
}

char* comp(char* t1, char* t2, int size){
    for(int i = 0; i<size; i++)
    {
        if(t1[i] < t2[i]){
            return t1;
        }
        else if(t1[i] > t2[i]){
            return t2;
        }
    }
    return t1;
}

int main(){

    char * str = malloc(51*sizeof(char));
    char * strMini = malloc(51*sizeof(char));
    char * strNext = malloc(51*sizeof(char));
    char * tmpMini = strMini;
    char * tmpNext = strNext;
    scanf("%s", str);
    int n= strlen(str);
    
    char mini = 'z';
    for(int i = 0; i<n;i++){
        if( mini >= str[i]){
            mini = str[i];
        }
    }

    for(int i = 0; i<n; i++){
        strMini[i] = 'z';
        strNext[i] = '\0';
    }
    strMini[n] = '\0';//vaservea
    strNext[n] = '\0';
    //printf("%d", n);
    for(int o = 0; o < n; o++){
        if(str[o] == mini){
            for(int p = 2; p<n; p++){
                strNext[0] = str[o];
                int idx = 1;
                if(lpierwsza(p) == 1){
                    int next = o+p;
                    //printf("%c: %d, %d\n", str[o], o, next);
                    while(idx<n){
                        strNext[idx] = str[next%n];
                        next += p;
                        idx++;
                    }
                    //printf("%s\n", strNext);
                    char *tmp = comp(strMini, strNext, n);
                    for(int ii = 0; ii<n; ii++){
                        strMini[ii] = tmp[ii];
                    }
                }
            }
        }
    }

    printf("%s\n", strMini);

    free(str);
    free(tmpMini);
    free(tmpNext);

    return 0;
}