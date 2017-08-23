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

	static const double M_PI; // Пи 3.14159265358979323846
	Complex();//конструктор по умолчанию
	Complex(double real, double imaginary);//конструктор с параметрами
	Complex(Complex &obj);//конструктор копирования
	~Complex();//деструктор

	static int getCount();//возвращает кол-во комплексных чисел
	double modulus();//возвращает модуль комплексного числа
	double argument();//возвращает аргумент комплексного числа
	double getReal();//возвращает действительную часть комплексного числа
	double getImag();//возвращает мнимую часть комплексного числа
	void changeReal(double newReal);//изменяет реальную часть числа
	void changeImag(double newImag);//изменяет мнимую часть числа

	Complex operator + (Complex secondNumber);//перегрузка сложения
	Complex operator - (Complex secondNumber);//перегрузка вычитания
	Complex operator * (Complex secondNumber);//перегрузка умножения
	Complex operator / (Complex secondNumber);//перегрузка деления
	Complex operator ++ ();//перегрузка префиксного инкремента
	Complex operator ++ (int i);//перегрузка постфиксного инкремента
	Complex operator -- ();//перегрузка префиксного декремента
	Complex operator -- (int i);//перегрузка постфиксного декремента
	Complex & operator = (Complex secondNumber);//перегрузка присваивания
	friend ostream & operator << (ostream& os, const Complex & number); // перегрузка вывода в поток
	friend istream & operator >> (istream& os, Complex & number); // перегрузка ввода из потока
};