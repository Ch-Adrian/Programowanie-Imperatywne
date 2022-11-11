#include <stdio.h>
#include <stdlib.h>

int letter['Z' - 'A' + 1];

char* rek(int num, char *t, int wsk){
	if(num == 0){
		return t;
	}
	if(num < 1000){
	if(num < 900){
		if(num < 500){
			if(num<400){
				if(num < 100){
					if(num < 90){
						if(num < 50){
							if(num < 40){
								if(num < 10){
									if(num < 9){
										if(num<5){
											if(num < 4){
												if(num < 1){
													return t;
												}
												else{
													num -= 1;
													t[wsk++] = 'I';
													return rek(num, t, wsk);
												}
											}
											else{
												num -= 4;
												t[wsk++] = 'I';
												t[wsk++] = 'V';
												return rek(num, t, wsk);
											}
										}
										else{
											num -= 5;
											t[wsk++] = 'V';
											return rek(num, t, wsk);
										}
									}
									else{
										num -= 9;
										t[wsk++] = 'I';
										t[wsk++] = 'X';
										return rek(num, t, wsk);
									}
								}
								else{
									num -= 10;
									t[wsk++] = 'X';
									return rek(num, t, wsk);
								}
							}
							else{
								num -= 40;
								t[wsk++] = 'X';
								t[wsk++] = 'L';
								return rek(num, t, wsk);
							}
						}
						else{
							num -= 50;
							t[wsk++] = 'L';
							return rek(num, t, wsk);
						}
					}
					else{
						num -= 90;
						t[wsk++] = 'X';
						t[wsk++] = 'C';
						return rek(num, t, wsk);
					}
				}
				else{
					num-=100;
					t[wsk++] = 'C';
					return rek(num, t, wsk);
				}
			}
			else{
				num -= 400;
				t[wsk++] = 'C';
				t[wsk++] = 'D';
				return rek(num, t, wsk);
			}
		}
		else{
			num -= 500;
			t[wsk++] = 'D';
			return rek(num, t, wsk);
		}
	}
	else{
		num -= 900;
		t[wsk++] = 'C';
		t[wsk++] = 'M';
		return rek(num, t, wsk);
	}
	}
	else{
		num -= 1000;
		t[wsk++] = 'M';
		return rek(num, t, wsk);
	}
}

int main(){

	letter['C' - 'A'] = 100;
	letter['I' - 'A'] = 1;
	letter['V' - 'A'] = 5;
	letter['X' - 'A'] = 10;
	letter['L' - 'A'] = 50;
	letter['D' - 'A'] = 500;
	letter['M' - 'A'] = 1000;
	char stack[2][20];
	int cnt_s[2];
	cnt_s[0] = 0;
	cnt_s[1] = 0;
	char c='a';
	int s = 0;
	int num1=0, num2 = 0;

	scanf("%c", &c);
	while(c != '\n'){
		if(c == ' '){
			s = 1;
			scanf("%c", &c);
			continue;
		}
		stack[s][cnt_s[s]++]=c;	
		scanf("%c", &c);
	}
	/*
	for(int i = 0; i<cnt_s[0]; i++){
		printf("%c ", stack[0][i]);
	}
	printf("\n");
	for(int j = 0; j<cnt_s[1]; j++){
		printf("%c ", stack[1][j]);
	}
	printf("\n");
	*/
	int stack2[cnt_s[0]];
	int stack3[cnt_s[1]];
	for(int i = 0; i<cnt_s[0]; i++){
		stack2[i] = 0;
	}
	for(int i = 0; i<cnt_s[1]; i++){
		stack3[i] = 0;
	}
	stack2[0] = letter[stack[0][0] - 'A'];
	for(int i = 1; i<cnt_s[0]; i++){
		if(stack2[i-1]<letter[stack[0][i]-'A']){
			stack2[i] = letter[stack[0][i]-'A'] - stack2[i-1];
			stack2[i-1] = 0;
		}
		else{
			stack2[i] = letter[stack[0][i]-'A'];
		}
	}
	for(int i =0 ;i <cnt_s[0]; i++){ num1 += stack2[i]; }

	stack3[0] = letter[stack[1][0] - 'A'];
	for(int i = 1; i<cnt_s[1]; i++){
		if(stack3[i-1] < letter[stack[1][i] - 'A']){
			stack3[i] = letter[stack[1][i]-'A'] - stack3[i-1];
			stack3[i-1] = 0;
		}
		else{
			stack3[i] = letter[stack[1][i]-'A'];
		}
	}
	for(int i =0 ; i<cnt_s[1]; i++){ num2 += stack3[i]; }

	char *t = malloc(100*sizeof(char));
	for(int i = 0;i <100; i++){
		t[i] = '\0';
	}
	t = rek(num1+num2, t, 0);
	int i = 0;
	while(i< 100 && t[i] != '\0'){
		printf("%c", t[i++]);
	}
	printf("\n");
	free(t);
	return 0;
}
