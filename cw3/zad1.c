#include <stdio.h>
#include <stdlib.h>

int parent(int idx){ return idx/2; }
int left(int idx){ return idx*2; }
int right(int idx){ return idx*2 + 1; }

void heapify(int* heap, int last_idx, int size){
    int maxi = last_idx;
    if(left(last_idx) <= size && heap[maxi] < heap[left(last_idx)]) maxi = left(last_idx);
    if(right(last_idx) <= size && heap[maxi] < heap[right(last_idx)]) maxi = right(last_idx);

    if(maxi != last_idx){
        int tmp = heap[maxi];
        heap[maxi] = heap[last_idx];
        heap[last_idx] = tmp;
        heapify(heap, maxi, size);
    }
}

void sort(int* heap, int size){
    for(int i = parent(size); i>0; i--){
        heapify(heap, i, size);
    }    
}

int main(){
    int n,k;
    scanf("%d %d", &n, &k);

    int* heap = malloc((n+2)*sizeof(int));

    for(int i = 1; i<=n; i++){
        scanf("%d", &heap[i]);
    }
    sort(heap, n);
    
    while(k--){
        heap[1] = heap[1]/2;
        heapify(heap, 1,n);
    }
    
    long long int sum = 0;
    for(int i = 1; i<=n; i++){
        sum += heap[i];
    }
    printf("%ld\n", sum);
    free(heap);

    return 0;
}