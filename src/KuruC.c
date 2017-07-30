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
#include <time.h>

// ソース分割
#include "mylib/sum.h"


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
void check_malloc();
void check_realloc();
void check_time();
// 関数ポインタ
void wa(int, int);
void sa(int, int);
void check_func_pointer();

int main(void) {
	//int a = 0b1111;
	//printf("%d", a);
	//printf("aaaa");
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//get_data();
	//check_array();
	//file_write();
	//my_file_read();
	//check_define();
	//check_enum();
	//check_malloc();
	//check_realloc();
	//printf("%d\n", sum(1, 10));
	//check_time();
	check_func_pointer();
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

void check_malloc() {
	int i;
	int *heap;
	// mallocが返すのはvoidポインタなのでキャストする
	heap = (int*) malloc(sizeof(int) * 10);
	if (heap == NULL) {
		exit(1);
	}
	for (i = 0; i < 10; i++) {
		heap[i] = i;
	}
	printf("%d\n", heap[5]);
	free(heap);
}

void check_realloc() {
	int i;
	int *heap;
	heap = (int*) malloc(sizeof(int) * 10);
	if (heap == NULL) {
		exit(1);
	}
	heap = (int*) realloc(heap, sizeof(int) * 10);
	if (heap == NULL) {
		exit(1);
	}
	for (i = 0; i < 20; i++) {
		heap[i] = i;
	}
	printf("%d\n", heap[19]);
	free(heap);
}

void check_time() {
	clock_t start, end;
	int i;
	start = clock();
	printf("%d\n", start);
	for (i = 0; i < 10; i++) {
		printf("%s\n", "a");
	}
	end = clock();
	printf("%d\n", end);
	printf("%d[ms]\n", end - start);
}

void check_func_pointer() {
	void (*keisan[2])(int, int);
	keisan[0] = wa;
	keisan[1] = sa;
	int i;
	for (i = 0; i < 2; i++) {
		keisan[i](100, 20);
	}
}

void wa(int a, int b) {
printf("%d\n", a + b);
}

void sa(int a, int b) {
printf("%d\n", a - b);
}
