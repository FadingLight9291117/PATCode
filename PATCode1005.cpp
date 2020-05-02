#include<iostream>
#include<list>
int compute(int input[], int size) {
	int result = 0;
	for (int i = 0; i < size; i++) {
		result += input[i];
	}
	return result;
}

void printDig(int e) {
	switch (e) {
	case 0: printf("zero"); break;
	case 1: printf("one"); break;
	case 2: printf("two"); break;
	case 3: printf("three"); break;
	case 4: printf("four"); break;
	case 5: printf("five");  break;
	case 6: printf("six"); break;
	case 7: printf("seven"); break;
	case 8: printf("eight"); break;
	case 9: printf("nine"); break;
	default:printf("error"); break;
	}
}

void print(int e) {
	if (e == 0) {
		printDig(0);
	}
	int len = 0;
	int temp = e;
	while (1) {
		if (temp != 0) {
			len++;
		}
		else {
			break;
		}
		temp /= 10;
	}
	temp = 1;
	for (int i = 0; i < len; i++) {
		temp *= 10;
	}
	temp /= 10;
	int tempe;
	for (int i = 0; i < len; i++) {
		tempe = e / temp;
		e -= temp * tempe;
		printDig(tempe);
		temp /= 10;
		if (i != len - 1) {
			printf(" ");
		}
	}
}

int PATCode1005() {

	// 1. ÊäÈë
	int input[101] = { 0 };
	char c;
	int i = 0;
	while ((c = getchar()) != '\n') {
		input[i++] = c - '0';
	}

	// 2. ¼ÆËã
	int result = compute(input, i);
	// printf("result = %d \n", result);

	// 3. Êä³ö
	print(result);
	return 0;
}