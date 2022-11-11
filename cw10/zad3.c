#include <stdio.h>
#include <stdlib.h>

struct bramka{
    int wej1;
    int wej2;
    short val;
};

void wyjscie(struct bramka* B, short* W, int num){
    if(B[num].val == -1){
        int val1 = 0, val2 = 0;
        if(B[num].wej1 < 0){
            val1 = W[(-1)*B[num].wej1];
        }
        else{
            if(B[B[num].wej1].val == -1){
                wyjscie(B, W, B[num].wej1);
            }
            val1 = B[B[num].wej1].val;
        }
        if(B[num].wej2 < 0){
            val2 = W[(-1)*B[num].wej2];
        }
        else{
            if(B[B[num].wej2].val == -1){
                wyjscie(B, W, B[num].wej2);
            }
            val2 = B[B[num].wej2].val;
        }
        B[num].val = (val1+val2)%2;
    }
}

int convertDec(char* arr, int n){
    int liczba = 0;
    int cnt =1;
    for(int i = n-1; i>=0; i--){
        if(arr[i] == '1'){
            liczba += cnt;
        }
        cnt<<=1;
    }
    return liczba;
}

int main(){

    int n,m,e, a,b;
    scanf("%d %d %d", &n,&m,&e);
    struct bramka* Bramki = malloc((m+1)*sizeof(struct bramka));
    short* Wejscia = malloc((n+1)*sizeof(short));

    for(int i= 0; i<m; i++){
        scanf("%d %d", &a, &b);
        Bramki[i+1].wej1 = a;
        Bramki[i+1].wej2 = b;
        Bramki[i+1].val = -1;
    }

    short* Values = malloc((n+1)*sizeof(short));

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=n; j++){
            Wejscia[j] = 0;
        }
        Wejscia[i] = 1;
        for(int j = 0; j<=m; j++){
            Bramki[j].val = -1;
        }
        wyjscie(Bramki, Wejscia, e);
        Values[i] = Bramki[e].val;
    }

    /*for(int i =1 ;i<=n; i++){
        printf("%d: %d\n", i, Values[i]);
    }*/

    char* beg = malloc((n+1)*sizeof(char));
    char* end = malloc((n+1)*sizeof(char));
    scanf("%s", beg);
    scanf("%s", end);
    int result = 0;
    int numBeg = convertDec(beg, n);
    int numEnd = convertDec(end, n);

    while(numBeg <= numEnd){
        int tmp = numBeg;
        for(int i = n; i>0; i--){
            Wejscia[i] = (tmp&1);
            tmp>>=1;
        }
        int miniResult = ((Values[1]*Wejscia[1])+(Values[2]*Wejscia[2]))%2;
        for(int i = 3; i<=n; i++){
            miniResult = (miniResult+Values[i]*Wejscia[i])%2;
        }
        result += miniResult;
        numBeg++;
    }

    printf("%d\n", result);
    free(beg);
    free(end);
    free(Bramki);
    free(Wejscia);
    free(Values);       
    return 0;
}