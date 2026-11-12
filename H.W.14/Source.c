#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <float.h>

double* full_elements(double* ptr_array, int size);
void put_elements(double* ptr_array, int size);
double min_element(double* ptr_array, int size, int k);

int main(void) {
	setlocale(LC_CTYPE, "RUS");

	double array[100];
	int size, k;
	double min_el;

	printf("Введите размер массива (до 100): ");
	scanf("%d", &size);
	printf("\n");

	printf("Введите число k: ");
	scanf("%d", &k);
	printf("\n");

	full_elements(array, size);
	put_elements(array, size);

	min_el = min_element(array, size, k);

	if (min_el == DBL_MAX) printf("Ничего не найдено\n");
	else printf("%f", min_el);

	return 0;
}

double* full_elements(double* ptr_array, int size) {
	
	for (int i = 0; i < size; i++) {
		printf("Введите %d элемент массива: ", i + 1);
		scanf("%lf", (ptr_array + i));
		printf("\n");
	}

	return ptr_array;
}

void put_elements(double* ptr_array, int size) {

	for (int i = 0; i < size; i++) printf("%d элемент массива: %f\n", i + 1, *(ptr_array + i));
	
}

double min_element(double* ptr_array, int size, int k) {

	double min_el = DBL_MAX;
	
	for (int i = 0; i < size; i++) {

		if ((i + 1) % k == 0) {

			if (*(ptr_array + i) < min_el) min_el = *(ptr_array + i);

		}
	}

	return min_el;
}