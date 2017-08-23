#include "complexNumber.h"

int Complex::count = 0;
const double Complex::M_PI = 3.14159265358979323846;

Complex::Complex()
{
	realPart = 1.1;
	imagPart = 1.1;
	count++;
	//	cout << "����������� �� ��������� " << endl;
	//	cout << "������ " << realPart << "+" << imagPart << "i" << endl;
}

Complex::Complex(double real, double imaginary) :realPart(real), imagPart(imaginary)//����������� � �����������
{
	count++;
	//	cout << "����������� �� ������� ������������� " << endl;
	//	cout << "������ " << realPart << "+" << imagPart << "i" << endl;
}

Complex::Complex(Complex & obj)//����������� �����������
{
	count++;
	this->realPart = obj.realPart;
	this->imagPart = obj.imagPart;
	//		cout << "����������� ����������� " << endl;
}

Complex::~Complex()// ����������
{
	count--;
	//	cout << "����������" << endl;
	//	cout << "��������� ������ " << realPart << "+" << imagPart << "i" << endl;
}



int Complex::getCount()
{
	return count;
}

double Complex::modulus()//���������� ������ ������������ �����
{
	return sqrt((realPart*realPart) + (imagPart*imagPart));
}

double Complex::argument()//���������� �������� ������������ �����
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
		throw exception("��� ������������ ����� 0.0+0.0i �������� �� ���������.");
	}
	return arg;
}

double Complex::getReal()//���������� �������������� ����� ������������ �����
{
	return realPart;
}

double Complex::getImag() //���������� ������ ����� ������������ �����
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
	//	cout << "�������� + " << endl;
	return tempNumber;
}

Complex Complex::operator-(Complex secondNumber)
{
	Complex tempNumber(this->realPart - secondNumber.realPart, imagPart - secondNumber.imagPart);
	//	cout << "�������� - " << endl;
	return tempNumber;
}

Complex Complex::operator*(Complex secondNumber)
{
	Complex tempNumber;
	tempNumber.realPart = realPart * secondNumber.realPart - imagPart * secondNumber.imagPart;
	tempNumber.imagPart = realPart * secondNumber.imagPart + imagPart * secondNumber.realPart;
	//	cout << "�������� * " << endl;
	return tempNumber;
}

Complex Complex::operator/(Complex secondNumber)
{
	Complex tempNumber;
	tempNumber.realPart = (realPart * secondNumber.realPart + imagPart * secondNumber.imagPart) / (secondNumber.realPart*secondNumber.realPart + secondNumber.imagPart*secondNumber.imagPart);
	tempNumber.imagPart = (secondNumber.realPart*imagPart - realPart*secondNumber.imagPart) / (secondNumber.realPart*secondNumber.realPart + secondNumber.imagPart*secondNumber.imagPart);
	//	cout << "�������� / " << endl;
	return tempNumber;
}

Complex Complex::operator++()
{
	Complex tempNumber;
	tempNumber.realPart = ++realPart;
	tempNumber.imagPart = ++imagPart;
	//	cout << "�������� ++a " << endl;
	return tempNumber;
}

Complex Complex::operator++(int i)
{
	Complex tempNumber(realPart, imagPart);
	realPart++;
	imagPart++;
	//	cout << "�������� a++ " << endl;
	return tempNumber;
}

Complex Complex::operator--()
{
	Complex tempNumber;
	tempNumber.realPart = --realPart;
	tempNumber.imagPart = --imagPart;
	//	cout << "�������� --a " << endl;
	return tempNumber;
}

Complex Complex::operator--(int i)
{
	Complex tempNumber(realPart, imagPart);
	realPart--;
	imagPart--;
	//	cout << "�������� a-- " << endl;
	return tempNumber;
}

Complex & Complex::operator=(Complex secondNumber)
{
	realPart = secondNumber.realPart;
	imagPart = secondNumber.imagPart;
	//	cout << "�������� = " << endl;
	return *this;
}


ostream & operator<<(ostream & os, const Complex & number)
{
	os << number.realPart << " + " << number.imagPart << "i";
	//	os<< setw(7) << number.realPart << " + " << setw(5) << number.imagPart << "i";
	//	cout << endl<<"��� �������� �������� << " << endl;
	return os;
}

istream & operator >> (istream & os, Complex & number)
{
	os >> number.realPart;

	if (!cin.good())
	{
		throw exception("������� �� ������ �������� (�� �������������� �����)");
	}
	os >> number.imagPart;
	if (!cin.good())
	{
		throw exception("������� �� ������ �������� (�� �������������� �����)");
	}
	//	cout << endl << "��� �������� �������� >> " << endl;
	return os;

}
