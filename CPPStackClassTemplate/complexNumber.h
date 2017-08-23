#pragma once

#include<iostream>
#include <locale.h>
#include <iomanip>
#include <conio.h>
#include <exception>


using namespace std;

class Complex
{
	double realPart;
	double imagPart;
	static int count;

public:

	static const double M_PI; // �� 3.14159265358979323846
	Complex();//����������� �� ���������
	Complex(double real, double imaginary);//����������� � �����������
	Complex(Complex &obj);//����������� �����������
	~Complex();//����������

	static int getCount();//���������� ���-�� ����������� �����
	double modulus();//���������� ������ ������������ �����
	double argument();//���������� �������� ������������ �����
	double getReal();//���������� �������������� ����� ������������ �����
	double getImag();//���������� ������ ����� ������������ �����
	void changeReal(double newReal);//�������� �������� ����� �����
	void changeImag(double newImag);//�������� ������ ����� �����

	Complex operator + (Complex secondNumber);//���������� ��������
	Complex operator - (Complex secondNumber);//���������� ���������
	Complex operator * (Complex secondNumber);//���������� ���������
	Complex operator / (Complex secondNumber);//���������� �������
	Complex operator ++ ();//���������� ����������� ����������
	Complex operator ++ (int i);//���������� ������������ ����������
	Complex operator -- ();//���������� ����������� ����������
	Complex operator -- (int i);//���������� ������������ ����������
	Complex & operator = (Complex secondNumber);//���������� ������������
	friend ostream & operator << (ostream& os, const Complex & number); // ���������� ������ � �����
	friend istream & operator >> (istream& os, Complex & number); // ���������� ����� �� ������
};