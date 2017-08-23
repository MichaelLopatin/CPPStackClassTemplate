#include "complexNumber.h"
#include "stackTemplate.h"
#include <typeinfo>

enum Menu
{
	exitMenu = 48,
	putComplexNumberIntoStack,
	getComplexNumberFromStack,
	showStack,
	showTopOfStack,
	showParametrsOfStack
};

int random(int i);//псевдорандом
void clearBufAndErr(); // чистит поток
void showMenu(); //показывает пункты меню
void menu();//работа в меню
void enterMaxSizeOfStack(int &maxSizeOfStack);//запрашивает размер стека


void main()
{
	setlocale(LC_ALL, "Russian");
	menu();
}


int random(int i)
{
	srand(i);
	return(rand());
}

void showMenu()
{
	cout << "  1 - Добавить комплексное число в стек" << endl;
	cout << "  2 - Изъять число из стека" << endl;
	cout << "  3 - Вывести содержимое стека на экран" << endl;
	cout << "  4 - Вывести вершину стека на экран" << endl;
	cout << "  5 - Вывести параметры стека на экран" << endl;
	cout << "  0 - Выход из программы" << endl;
}

void clearBufAndErr()
{
	cin.clear();
	cin.sync();
	cin.ignore(100, '\n');
}


void enterMaxSizeOfStack(int & maxSizeOfStack)
{
	bool endCycle = true;
	while (endCycle)
	{
		cout << "Введите максимальное количество элементов стека:" << endl;
		try
		{
			cin >> maxSizeOfStack;
			if (!cin.good() || (maxSizeOfStack <= 0))
			{
				throw exception("Введено не верное значение (необходимо натуральное число).");
			}
			else
			{
				clearBufAndErr();
				endCycle = false;
			}
		}
		catch (exception str)
		{
			cout << str.what() << endl;
			clearBufAndErr();
		}
	}
}

void menu()
{
	char key;//код нажатой клавиши
	bool quit = true;//завершение работы в меню
	int maxSizeOfStack = 0; // размер стека
	int intForRand = 5; // базовая переменная для псевдорандома

	enterMaxSizeOfStack(maxSizeOfStack);
	RealStack <Complex> firstStack(maxSizeOfStack);

	showMenu();
	cout << "_______________________________" << endl;
	do
	{
		if (_kbhit())
		{
			key = _getch();
			switch (key)
			{
			case exitMenu:
			{
				quit = false;
				return;
				break;
			}

			case putComplexNumberIntoStack:
			{
				Complex *tempPtrComplexNumber;
				double realTemp, imagTemp;
				realTemp = double(random(intForRand + 1) % 100) + double(((random(intForRand + 1) / 10 + random(intForRand + 1) % 10) % 100)) / 100;
				imagTemp = double(random(intForRand*intForRand) % 100) + double(((random(intForRand*intForRand) / 10 + random(intForRand*intForRand) % 10) % 100)) / 100;

				tempPtrComplexNumber = new Complex(realTemp, imagTemp);

				firstStack.putVal(*tempPtrComplexNumber);
				//if ((firstStack.quantityOfStackElements()) < firstStack.returnMaxSizeOfStack())
				//{
				//	cout << "Добавлено число  " << firstStack.returnElementOfStackByIndex(firstStack.quantityOfStackElements() - 1) << endl;
				//}

				intForRand++;
				delete tempPtrComplexNumber;
				break;
			}
			case getComplexNumberFromStack:
			{
				//cout << "Изято число  " << firstStack.getVal() << endl;
				firstStack.getVal();
				break;
			}
			case showStack:
			{
				cout << "index" << " Комплексное число" << endl;
				if (firstStack.quantityOfStackElements() > 0)
				{
					for (int i = firstStack.quantityOfStackElements(); i > 0; i--)
					{

						cout << i << "   " << firstStack.returnElementOfStackByIndex(i - 1) << endl;
					}
				}
				else
				{
					cout << "Стек пустой" << endl;
				}
				break;
			}
			case showTopOfStack:
			{
				if (firstStack.quantityOfStackElements() > 0)
				{
					cout << "Вершина стека:  ";
					cout << firstStack.returnElementOfStackByIndex(firstStack.quantityOfStackElements() - 1) << endl;
				}
				else
				{
					cout << "Стек пустой" << endl;
				}

				break;
			}
			case showParametrsOfStack:
			{
				cout << "Параметры стека:" << endl;
				cout << "Максимальный размер стека:   " << firstStack.returnMaxSizeOfStack() << endl;
				cout << "Количество заполненных элементов в стеке:  " << firstStack.quantityOfStackElements() << endl;
				if (firstStack.quantityOfStackElements() > 0)
				{
					cout << "Вершина стека:  ";
					cout << firstStack.returnElementOfStackByIndex(firstStack.quantityOfStackElements() - 1) << endl;

				}
				cout << "Тип данных элементов стека:  " << typeid(firstStack.returnElementOfStackByIndex(0)).name() << endl;

				break;
			}

			default:cout << "Выбран некорректный пункт меню, будьте внимательны" << endl;
				break;
			}
			cout << "_______________________________" << endl;
			showMenu();
			cout << "_______________________________" << endl;
		}
	} while (quit);
}

