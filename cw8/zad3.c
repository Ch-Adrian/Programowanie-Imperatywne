#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(char* tab){
	for(int i = 0; i<50; i++){
		printf("%c", tab[i]);
	}
	printf("\n");
}

int main(){

	char* str = malloc(51*sizeof(char));

	scanf("%s", str);
	int len = strlen(str);
	int k = 0;
	if(len == 1){
		printf("%s\n", str);
		return 0;
	}
	char tmp = 0;
	for(int i = 1; i<len;i++){
		int j = i-1;
		//printf("Wejscie: ");
		//show(str);
		while(j>=0 && str[j]<str[i]){
			str[j] = 0;
			j--;
		}
		//printf("Wyjscie: ");
		tmp = str[i];
		str[i] = 0;
		str[j+1] = tmp;
		k = j+2;
		//show(str);
	}
	str[k] = '\0';
	printf("%s\n", str);

	free(str);

	return 0;
}
