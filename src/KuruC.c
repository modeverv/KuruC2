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
#include <stdbool.h>


#define TAX 0.08
#define EXCISETAX 0.08
#define AUTHOR "日本語太郎"

typedef enum {
	ONE, TWO,
} Type;

void get_data();
void check_array();
void pri(int);
void print_array(int[]);
void file_write();
void my_file_read();
void check_define();
void check_enum();

int main(void) {
	//int a = 0b1111;
	//printf("%d", a);
	//printf("aaaa");
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//get_data();
	//check_array();
	//file_write();
	//my_file_read();
	check_define();
	check_enum();
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

void file_write() {
	FILE *file;
	file = fopen("test.txt", "w");
	fprintf(file, "Hello Test Text\n");
	fclose(file);
}

void my_file_read() {
	char a[128];
	FILE *file;
	file = fopen("test.txt", "r");
	// フォーマット指定しないとだめね～
	fscanf(file, "%s", &a);
	printf("%s", a);
}

void check_define() {
	double price = 100.0;
	price = price * (1 + TAX);
	printf("%f\n", TAX);
	printf("%f\n", EXCISETAX);
	printf("%f\n", price);
	printf("%s\n", AUTHOR);
}

void check_enum() {
	Type e = ONE;
	printf("%d\n", e);
}
