#pragma once
#include <iostream>
#include <locale.h>
#include <exception>



template <class TypeOfValue> //шаблон класса "стек"
class RealStack
{
	TypeOfValue *arrStack; // указатель на динамический массив элементов стека
	int topIndex = -1; // индекс вершины стека
	int maxSizeOfStack; // максимальный размер стека

public:
	RealStack(); // конструктор по умолчанию
	RealStack(int maxSizeOfStack); // конструктор с параметрами
	RealStack(RealStack & oldArrStack); // конструктор копировани¤ 

	~RealStack(); // деструктор

	void putVal(TypeOfValue val); // "положить" элемент в стек
	TypeOfValue getVal(); // извлечь элемент из стека
	int quantityOfStackElements(); // возвращает количество непустых элементов в стеке
	int returnMaxSizeOfStack(); // возвращает максимальный размер стека
	TypeOfValue returnElementOfStackByIndex(int index); // просто возвращает элемент стека по индексу
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
			throw exception("Стек не создан. «адано неверное значение размера. (Необходимо натуральное число).");
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

template<class TypeOfValue> //конструктор копировани¤
RealStack<TypeOfValue>::RealStack(RealStack & oldArrStack) :maxSizeOfStack(oldArrStack.maxSizeOfStack())
{
	arrStack = new TypeOfValue[maxSizeOfStack];
	//for (int i = 0; i < maxSizeOfStack; i++)
	//{
	//	arrStack[i] = NULL;
	//	cout << "конструктор копирования" << endl;
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
//	cout << "деструктор стека" << endl;
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
		/*	if (topIndex + 1 >= maxSizeOfStack)
			{*/
				throw exception("Элемент не добавлен. Превышен размер стека. ");
			//}

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
			throw exception("Невозможно изъять значение - стек пустой. ");
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