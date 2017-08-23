#pragma once

#include <iostream>
#include <locale.h>
#include <exception>



template <class TypeOfValue> //������ ������ "����"
class RealStack
{
	TypeOfValue *arrStack; // ��������� �� ������������ ������ ��������� �����
	int topIndex = -1; // ������ ������� �����
	int maxSizeOfStack; // ������������ ������ �����

public:
	RealStack(); // ����������� �� ���������
	RealStack(int maxSizeOfStack); // ����������� � �����������
	RealStack(RealStack & oldArrStack); // ����������� ����������� 

	~RealStack(); // ����������

	void putVal(TypeOfValue val); // "��������" ������� � ����
	TypeOfValue getVal(); // ������� ������� �� �����
	int quantityOfStackElements(); // ���������� ���������� �������� ��������� � �����
	int returnMaxSizeOfStack(); // ���������� ������������ ������ �����
	TypeOfValue returnElementOfStackByIndex(int index); // ������ ���������� ������� ����� �� �������
};

template<class TypeOfValue>
RealStack<TypeOfValue>::RealStack() : maxSizeOfStack(10)
{
	arrStack = new TypeOfValue[maxSizeOfStack];
}

template<class TypeOfValue>
RealStack<TypeOfValue>::RealStack(int maxSizeOfStack) :maxSizeOfStack(maxSizeOfStack)
{
	try
	{
		if (maxSizeOfStack <= 0)
		{
			throw exception("���� �� ������. ������ �������� �������� �������. (���������� ����������� �����).");
		}

	}
	catch (exception str)
	{
		cout << str.what() << endl;
	}
	if (maxSizeOfStack > 0)
	{
		arrStack = new TypeOfValue[maxSizeOfStack];
	}
}

template<class TypeOfValue> //����������� �����������
RealStack<TypeOfValue>::RealStack(RealStack & oldArrStack) :maxSizeOfStack(oldArrStack.maxSizeOfStack())
{
	arrStack = new TypeOfValue[maxSizeOfStack];
	//for (int i = 0; i < maxSizeOfStack; i++)
	//{
	//	arrStack[i] = NULL;
	//	cout << "����� ������������ �����������" << endl;
	//}
	for (int i = oldArrStack.quantityOfStackElements(); i > 0; i--)
	{
		arrStack[i] = oldArrStack.arrStack[i];
	}
}

template<class TypeOfValue>
RealStack<TypeOfValue>::~RealStack()
{
	delete[]arrStack;
	cout << "���������� �����" << endl;
}

template<class TypeOfValue>
void RealStack<TypeOfValue>::putVal(TypeOfValue val)
{
	//	cout << "put" << endl;
	if (topIndex + 1 < maxSizeOfStack)
	{
		topIndex++;
		arrStack[topIndex] = val;
	}
	else
	{
		try
		{
			throw exception("������� �� ��������. �������� ������ �����. ");
		}
		catch (exception str)
		{
			cout << str.what() << endl;
		}
	}

}

template<class TypeOfValue>
TypeOfValue RealStack<TypeOfValue>::getVal()
{
	//	cout << "get" << endl;
	if (topIndex >= 0)
	{
		TypeOfValue valTemp = arrStack[topIndex];
		//		arrStack[topIndex] = NULL;
		topIndex--;
		return valTemp;
	}
	try
	{
		if (topIndex <0)
		{
			throw exception("���������� ������ �������� - ���� ������. ");
		}

	}
	catch (exception str)
	{
		cout << str.what() << endl;
	}
}


template<class TypeOfValue>
inline int RealStack<TypeOfValue>::quantityOfStackElements()
{
	return (this->topIndex + 1);
}

template<class TypeOfValue>
inline int RealStack<TypeOfValue>::returnMaxSizeOfStack()
{
	return (this->maxSizeOfStack);
}

template<class TypeOfValue>
TypeOfValue RealStack<TypeOfValue>::returnElementOfStackByIndex(int index)
{
	return TypeOfValue(arrStack[index]);
}
