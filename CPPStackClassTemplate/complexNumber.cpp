#include "complexNumber.h"

int Complex::count = 0;
const double Complex::M_PI = 3.14159265358979323846;

Complex::Complex()
{
	realPart = 1.1;
	imagPart = 1.1;
	count++;
	//	cout << "Конструктор по умолчанию " << endl;
	//	cout << "Объект " << realPart << "+" << imagPart << "i" << endl;
}

Complex::Complex(double real, double imaginary) :realPart(real), imagPart(imaginary)//конструктор с параметрами
{
	count++;
	//	cout << "Конструктор со списком инициализации " << endl;
	//	cout << "Объект " << realPart << "+" << imagPart << "i" << endl;
}

Complex::Complex(Complex & obj)//конструктор копирования
{
	count++;
	this->realPart = obj.realPart;
	this->imagPart = obj.imagPart;
	//		cout << "Конструктор КОПИРОВАНИЯ " << endl;
}

Complex::~Complex()// деструктор
{
	count--;
	//	cout << "Деструктор" << endl;
	//	cout << "Удаляется объект " << realPart << "+" << imagPart << "i" << endl;
}



int Complex::getCount()
{
	return count;
}

double Complex::modulus()//возвращает модуль комплексного числа
{
	return sqrt((realPart*realPart) + (imagPart*imagPart));
}

double Complex::argument()//возвращает аргумент комплексного числа
{
	double arg = 0.0;
	if (realPart > 0)
	{
		arg = atan(imagPart / realPart);
	}
	if (realPart < 0 && imagPart >= 0)
	{
		arg = atan(imagPart / realPart) + M_PI;
	}
	if (realPart < 0 && imagPart < 0)
	{
		arg = atan(imagPart / realPart) - M_PI;
	}
	if (realPart == 0 && imagPart > 0)
	{
		arg = M_PI / 2;
	}
	if (realPart == 0 && imagPart < 0)
	{
		arg = -(M_PI / 2);
	}
	if (realPart == 0 && imagPart == 0)
	{
		throw exception("Для комплексного числа 0.0+0.0i аргумент не определен.");
	}
	return arg;
}

double Complex::getReal()//возвращает действительную часть комплексного числа
{
	return realPart;
}

double Complex::getImag() //возвращает мнимую часть комплексного числа
{
	return imagPart;
}

void Complex::changeReal(double newReal)
{
	realPart = newReal;
}

void Complex::changeImag(double newImag)
{
	imagPart = newImag;
}

Complex Complex::operator+(Complex secondNumber)
{
	Complex tempNumber(this->realPart + secondNumber.realPart, imagPart + secondNumber.imagPart);
	//	cout << "перегруз + " << endl;
	return tempNumber;
}

Complex Complex::operator-(Complex secondNumber)
{
	Complex tempNumber(this->realPart - secondNumber.realPart, imagPart - secondNumber.imagPart);
	//	cout << "перегруз - " << endl;
	return tempNumber;
}

Complex Complex::operator*(Complex secondNumber)
{
	Complex tempNumber;
	tempNumber.realPart = realPart * secondNumber.realPart - imagPart * secondNumber.imagPart;
	tempNumber.imagPart = realPart * secondNumber.imagPart + imagPart * secondNumber.realPart;
	//	cout << "перегруз * " << endl;
	return tempNumber;
}

Complex Complex::operator/(Complex secondNumber)
{
	Complex tempNumber;
	tempNumber.realPart = (realPart * secondNumber.realPart + imagPart * secondNumber.imagPart) / (secondNumber.realPart*secondNumber.realPart + secondNumber.imagPart*secondNumber.imagPart);
	tempNumber.imagPart = (secondNumber.realPart*imagPart - realPart*secondNumber.imagPart) / (secondNumber.realPart*secondNumber.realPart + secondNumber.imagPart*secondNumber.imagPart);
	//	cout << "перегруз / " << endl;
	return tempNumber;
}

Complex Complex::operator++()
{
	Complex tempNumber;
	tempNumber.realPart = ++realPart;
	tempNumber.imagPart = ++imagPart;
	//	cout << "перегруз ++a " << endl;
	return tempNumber;
}

Complex Complex::operator++(int i)
{
	Complex tempNumber(realPart, imagPart);
	realPart++;
	imagPart++;
	//	cout << "перегруз a++ " << endl;
	return tempNumber;
}

Complex Complex::operator--()
{
	Complex tempNumber;
	tempNumber.realPart = --realPart;
	tempNumber.imagPart = --imagPart;
	//	cout << "перегруз --a " << endl;
	return tempNumber;
}

Complex Complex::operator--(int i)
{
	Complex tempNumber(realPart, imagPart);
	realPart--;
	imagPart--;
	//	cout << "перегруз a-- " << endl;
	return tempNumber;
}

Complex & Complex::operator=(Complex secondNumber)
{
	realPart = secondNumber.realPart;
	imagPart = secondNumber.imagPart;
	//	cout << "перегруз = " << endl;
	return *this;
}


ostream & operator<<(ostream & os, const Complex & number)
{
	os << number.realPart << " + " << number.imagPart << "i";
	//	os<< setw(7) << number.realPart << " + " << setw(5) << number.imagPart << "i";
	//	cout << endl<<"был перегруз перегруз << " << endl;
	return os;
}

istream & operator >> (istream & os, Complex & number)
{
	os >> number.realPart;

	if (!cin.good())
	{
		throw exception("Введено не верное значение (не действительное число)");
	}
	os >> number.imagPart;
	if (!cin.good())
	{
		throw exception("Введено не верное значение (не действительное число)");
	}
	//	cout << endl << "был перегруз перегруз >> " << endl;
	return os;

}
