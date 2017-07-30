/*
 * sum.c
 *
 *  Created on: 2017/07/30
 *      Author: seijiro
 */

int sum(int min, int max) {
	int num;
	num = (min + max) * (max - min + 1) / 2;
	return num;
}

