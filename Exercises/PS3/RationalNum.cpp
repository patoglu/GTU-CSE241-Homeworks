/*
 * RationalNum.cpp
 */

#include <iostream>

#include "RationalNum.h"

RationalNum::RationalNum(){
	mNumerator = 1;
	mDenominator = 1;
}

RationalNum::RationalNum(int num, int denom){
	mNumerator = num;
	mDenominator = denom;
}

void RationalNum::setNumerator(int numerator) {
	mNumerator = numerator;
}

bool RationalNum::setDenominator(int denominator) {
	if(denominator == 0)
		return false;

	mDenominator = denominator;
	return true;
}

int RationalNum::getNumerator() const{
	return mNumerator;
}

int RationalNum::getDenominator() const{
	return mDenominator;
}

RationalNum RationalNum::add(const RationalNum& rn) const{
	RationalNum resultRN;

	resultRN.mNumerator =  mNumerator * rn.mDenominator +
			mDenominator * rn.mNumerator;

	resultRN.mDenominator = mDenominator * rn.mDenominator;

	return resultRN;
}

RationalNum RationalNum::mult(const RationalNum& rn) const{
	RationalNum resultRN;

	resultRN.mNumerator = mNumerator * rn.mNumerator;
	resultRN.mDenominator =  mDenominator * rn.mDenominator;

	return resultRN;
}



double RationalNum::toDouble() const{
	return (double)mNumerator / mDenominator;
}
