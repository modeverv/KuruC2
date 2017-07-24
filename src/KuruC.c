/*
 ============================================================================
 Name        : KuruC.c
 Author      : norainu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void get_data();
void check_array();
void pri(int);
void print_array(int[]);

int main(void) {
	int a = 0b1111;
	printf("%d", a);
	printf("aaaa");
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//get_data();
	check_array();
	return EXIT_SUCCESS;
}
void get_data() {
	double data;
	printf("input data:");
	scanf("%lf", &data);
	printf("%f", data);
}

void check_array() {
	int ar[] = { 1, 2, 3 };
	pri(ar[0]);
	pri(ar[1]);
	pri(ar[2]);
	int i;
	for (i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		printf("ar[%d] is %d\n", i, ar[i]);
	}
	//配列のコピー
	int ar2[] = { 3, 4, 5 };
	memcpy(ar2, ar, sizeof(ar));
	print_array(ar2);
	for (i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		printf("ar-[%d] is %d\n", i, ar[i]);
	}
}

void print_array(int ar[]) {
	int i;
	// 全要素を回せないねー
	// ポインタとかいるのでしょうかね。
	for (i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		printf("ar2[%d] is %d\n", i, ar[i]);
	}
}

void pri(int i) {
	printf("%d\n", i);
}
