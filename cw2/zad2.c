#include <stdio.h>
#include <stdlib.h>

void increment(int* liczba, int len, int podst){
	liczba[len-1]++;
	int i = len-1;
	while(i>0){
		if(liczba[i] != 0 && liczba[i]%podst == 0){
			liczba[i-1]++;
			liczba[i] = 0;
		}
		i--;
	}
	if(liczba[0]%podst == 0){
		liczba[0] = 0;
	}
}

int dziesie(int* liczba, int len, int podst){

	int result = 0;
	int i = len-1;
	int tmp = 1;
	while(i>-1){
		result += tmp*liczba[i];
		tmp *= podst;
		i--;
	}
	return result;
}

int sumab(int* liczba, int len, int podst){
	int result = 0, i = len - 1, tmp = 1, j= len - 1;
	while(i>-1){
		j = len;
		tmp = 1;
		while(j){
			tmp *= liczba[i];	
			j--;
		}
		result += tmp;
		i--;
	}
	return result;
}

void showL(int * liczba, int len){
	
	char* digit = malloc(16 *  sizeof(char));
	int i = 0;
	
	while(i<10){
		digit[i] = '0'+i;
		i++;
	}
	digit[10] = 'A';
	digit[11] = 'B';
	digit[12] = 'C';
	digit[13] = 'D';
	digit[14] = 'E';
	digit[15] = 'F';

	i = 0;
	while(i<len){
		printf("%c", digit[liczba[i]]);
		i++;
	}
	free(digit);
}

int main(){
	
	int m,b;
	scanf("%i %i", &m, &b);
	int *liczba = malloc(m * sizeof(int));
	int i = 0;
	while(i<m){
		liczba[i] = 0;
		i++;
	}
	liczba[0] = 1;
	
	int counter = 0;
	while(liczba[0] != 0){
		/*showL(liczba, m);
		printf("%i %i\n", dziesie(liczba, m, b), sumab(liczba, m, b));
		printf("\n");*/
		if(dziesie(liczba, m, b) == sumab(liczba, m, b)){
			showL(liczba, m);		
			printf(" ");
			counter++;
		}
		increment(liczba, m, b);
	}
	
	if(counter == 0){
		printf("NO\n");
	}

	free(liczba);
	
	return 0;
}
