/*
 * Makefile tutorial:
 *
 * Reduce the time taken by the edit-compile-debug cycle.
 *
 * If a target is included as a command-line argument, that target is updated. If no com-
 * mand-line targets are given, then the first target in the file is used, called the default
 * goal.
 *
 *Rule:
 *target: prereq 1 prereq 2
	commands
 *
 *
 */

#include <iostream>

#include "RationalNum.h"

using namespace std;

int main() {
	RationalNum rn_a, rn_b, rn_c;

	rn_a.setNumerator(3);
	rn_a.setDenominator(5);

	rn_b.setNumerator(-7);
	rn_b.setDenominator(8);

	rn_c = rn_a.add(rn_b);
	cout << "a + b = " << rn_c.getNumerator() << "/"  << rn_c.getDenominator() << endl;

	rn_c = rn_a.mult(rn_b);
	cout << "a * b = " << rn_c.getNumerator() << "/"  << rn_c.getDenominator() << endl;

	return 0;
}
