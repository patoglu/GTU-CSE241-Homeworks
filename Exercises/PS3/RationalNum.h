/*
 * RationalNum.h
 */

#ifndef RATIONALNUM_H_
#define RATIONALNUM_H_

// n <-- numerator
//---
// d <-- denominator

class RationalNum {
public:
	RationalNum();
	RationalNum(int num, int denom);

	void setNumerator(int num);
	bool setDenominator(int denom);

	int getNumerator() const;
	int getDenominator() const;
	RationalNum add(const RationalNum& rn) const;
	RationalNum mult(const RationalNum& rn) const;
	double toDouble() const;

private:
	int mNumerator, mDenominator;
};

#endif /* RATIONALNUM_H_ */
