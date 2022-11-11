#include <stdio.h>
#include <stdlib.h>
#define DL 200
#define END 10000
#define LL unsigned long long

short koncowa(LL* arr, int len){
    for(int i =0; i<len-1; i++){
        if(arr[i]+arr[i+1]>1){
            return 0;
        }
    }
    return 1;
}

int main(){

    int n, pos, cnt;
    scanf("%d", &n);
    LL *arr = malloc((END+2*DL)*sizeof(LL));
    for(int i = 0; i<END+2*DL; i++){ arr[i] = 0; }
    for(int i = 0; i<n; i++){
        scanf("%d %d", &pos, &cnt);
        arr[pos+DL+1] = cnt;
    }
    /*for(int i = 0; i<150; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");*/
    int tower = 1;
    while(tower){
        tower = 0;
        for(int i = 3; i<END+2*DL-2; i++){
            if(arr[i] >= 3){
                arr[i-2] += arr[i]/3;
                arr[i+2] += arr[i]/3;
                if(arr[i-2]>=3) tower++;
                arr[i] = arr[i]%3;
            }
        }
    }
    
    /*for(int i = 0; i<150; i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");*/
    
    while(koncowa(arr, END+2*DL) == 0){
        int i;
        for(i = END+2*DL-2; i>0 && arr[i] == 0; i--);
        while(i>0){
            //printf("%d\n", i);
            if(arr[i] > 0 && arr[i+1] > 0){
                arr[i] -= 1;
                arr[i+1] -= 1;
                arr[i+2] += 1;
                i += 2;
            }
            else if(arr[i] == 2 && arr[i-1] > 0) i--;
            else if(arr[i] == 2 && arr[i+1] == 0){
                arr[i-1]++;
                arr[i-2]++;
                arr[i]--;
                arr[i-1]--;
                arr[i]--;
                arr[i+1]++;
                i+=1;
            }
            else if(arr[i] == 3){
                arr[i-2]++;
                arr[i+2]++;
                arr[i]-=3;
                i+=2;
            }
            else i--;
            /*for(int i = 10100; i<10150; i++){
        printf("%lld ", arr[i]);
            }
    printf("\n");*/
        }
    }


    /*for(int i = DL-10; i<150; i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");*/
    for(int i = 0; i<END+2*DL; i++){
        if(arr[i] == 1){
            printf("%d ", (-1)*DL+i-1);
        }
    }
    printf("\n");
    free(arr);

    return 0;
}