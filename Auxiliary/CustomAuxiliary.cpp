/*
 * Auxiliary.c
 *
 *  Created on: Mar 26, 2025
 *      Author: lex
 */

#include "CustomAuxiliary.h"

	int maxi(int x, int y) { return x < y ? y : x; };
	int mini(int x, int y) { return x < y ? x : y; };
	int boundi(int minValue, int x, int maxValue) { return mini(maxi(minValue, x), maxValue); };
