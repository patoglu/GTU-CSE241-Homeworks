#include <iostream>

using namespace std;

class Complex
{
public:
	Complex();
	explicit Complex(double realPart);
	Complex(double realPart, double imaginaryPart);
	void setReal(double theRealPart);
	void setImaginary(double theImaginaryPart);
	double getReal() const;
	double getImaginary() const;
	const Complex operator +(const Complex& secondComplex) const;
	//const Complex operator +(const Complex& firstComplex, const Complex& secondComplex);
	const Complex operator -(const Complex& secondComplex) const;
	bool operator ==(const Complex& secondComplex) const;
	const Complex operator -() const;
	const Complex operator *(const Complex& secondComplex) const;
	friend ostream& operator <<(ostream& output, const Complex& aComplex);
	friend istream& operator >>(istream& input, Complex& aComplex);
	//istream& operator >>(istream& input, Complex& aComplex)
private:
	double imaginary;
	double real;
};

Complex::Complex():imaginary(0), real(0)
{/*initially left emty;)*/}

Complex::Complex(double realPart):imaginary(0), real(realPart)
{}

Complex::Complex(double realPart, double imaginaryPart):imaginary(imaginaryPart), real(realPart)
{}

void Complex::setReal(double theRealPart)
{
	real = theRealPart;
}

void Complex::setImaginary(double theImaginaryPart)
{
	imaginary = theImaginaryPart;
}

double Complex::getReal() const
{
	return real;
}

double Complex::getImaginary() const
{
	return imaginary;
}

const Complex Complex::operator+(const Complex& secondComplex) const
{
	double realSum;
	double imaginarySum;

	realSum = real + secondComplex.real;
	imaginarySum = imaginary + secondComplex.imaginary;

	return Complex(realSum, imaginarySum);
}

const Complex Complex::operator-(const Complex& secondComplex) const
{
	double realSub;
	double imaginarySub;

	realSub = real -  secondComplex.real;
	imaginarySub = imaginary - secondComplex.imaginary;

	return Complex(realSub, imaginarySub);
}

bool Complex::operator ==(const Complex& secondComplex) const
{
	return ((real == secondComplex.real) && (imaginary == secondComplex.imaginary));
}

const Complex Complex::operator*(const Complex& secondComplex) const
{
	double realMult;
	double imaginaryMult;

	realMult = real * secondComplex.real - imaginary*secondComplex.imaginary;
	imaginaryMult = real * secondComplex.imaginary + imaginary * secondComplex.real;

	return Complex(realMult, imaginaryMult);
}

const Complex Complex::operator-()const
{
	return Complex(-real,-imaginary);
}

ostream& operator <<(ostream& output, const Complex& aComplex)
{
	output << aComplex.real;
	output << "+";
	output << aComplex.imaginary;
	output << "*i";

	return output;
}
istream& operator >>(istream& input, Complex& aComplex)
{
	double realPart;
	double imaginaryPart;

	input >> realPart;
	input >> imaginaryPart;

	//aComplex.setReal(realPart);
	//aComplex.setImaginary(imaginaryPart);

	aComplex.real = realPart;
	aComplex.imaginary = imaginaryPart;

	return input;
}

int main()
{
	Complex myComplex(2,3);
	Complex yourComplex(5,6);

	cout << myComplex << endl;

	cout << yourComplex << endl;


	cout << "myComplex + yourComplex is = " << myComplex + yourComplex << endl;

	cout << "myComplex * yourComplex is = " << -(myComplex * yourComplex) << endl;

	Complex thirdComplex;

	cout << "Default: " << thirdComplex << endl;

	//cin >> thirdComplex;

	//cout << thirdComplex << endl;
	Complex ultraComplex = myComplex + 10;
	cout << ultraComplex << endl;

	return 0;
}