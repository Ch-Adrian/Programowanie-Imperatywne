#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int N;
	int arr[201][201];
	for(int i = 0; i<201; i++){
		for(int j = 0; j<201; j++){
			arr[i][j] = 0;
		}
	}

	scanf("%d", &N );
	int x1,y1,x2,y2;
	int minx, maxx, miny,maxy;
	for(int i = 0; i<N; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 += 100;
		x2 += 100;
		y1 += 100;
		y2 += 100;
		minx = x1 < x2 ? x1 : x2;
		miny = y1 < y2 ? y1 : y2;
		maxx = x1 < x2 ? x2 : x1;
		maxy = y1 < y2 ? y2 : y1;
		for(int j = minx; j < maxx; j++){
			for(int k = miny; k < maxy; k++){
				arr[j][k]++;
			}
		}		
	}
	int answer = 0;
	for(int i = 0; i<201; i++){
		for(int j = 0; j<201; j++){
			if(arr[i][j]%2==1){
				answer++;
			}	
		}
	}
	printf("%d\n", answer);

	return 0;
}
