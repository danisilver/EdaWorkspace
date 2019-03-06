/*
 * main.c
 *
 *  Created on: 23 dic. 2018
 *      Author: daniel
 */

#include <stdio.h>

int factorial(int n) {
	int r;

	if (n == 0)
		r = 1;
	else
		r = n * factorial(n - 1);
	return r;
}

int prod(int a, int b) {
	int r;

	if (b == 0) {
		r = 0;
	} else if (b == 1) {
		r = a;
	} else if (b % 2 == 0) {
		r = prod(2 * a, b / 2);
	} else {
		r = prod(2 * a, b / 2) + a;
	}
	return r;
}

int main(int argc, char *argv[]) {
	int resultado = factorial(3);
	printf("resultado:%d", resultado);
	return 0;
}
