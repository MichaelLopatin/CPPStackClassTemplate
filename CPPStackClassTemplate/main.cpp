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

int random(int i);//������������
void clearBufAndErr(); // ������ �����
void showMenu(); //���������� ������ ����
void menu();//������ � ����
void enterMaxSizeOfStack(int &maxSizeOfStack);//����������� ������ �����


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
	cout << "  1 - �������� ����������� ����� � ����" << endl;
	cout << "  2 - ������ ����� �� �����" << endl;
	cout << "  3 - ������� ���������� ����� �� �����" << endl;
	cout << "  4 - ������� ������� ����� �� �����" << endl;
	cout << "  5 - ������� ��������� ����� �� �����" << endl;
	cout << "  0 - ����� �� ���������" << endl;
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
		cout << "������� ������������ ���������� ��������� �����:" << endl;
		try
		{
			cin >> maxSizeOfStack;
			if (!cin.good() || (maxSizeOfStack <= 0))
			{
				throw exception("������� �� ������ �������� (���������� ����������� �����).");
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
	char key;//��� ������� �������
	bool quit = true;//���������� ������ � ����
	int maxSizeOfStack = 0; // ������ �����
	int intForRand = 5; // ������� ���������� ��� �������������

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
				//	cout << "��������� �����  " << firstStack.returnElementOfStackByIndex(firstStack.quantityOfStackElements() - 1) << endl;
				//}

				intForRand++;
				delete tempPtrComplexNumber;
				break;
			}
			case getComplexNumberFromStack:
			{
				//cout << "����� �����  " << firstStack.getVal() << endl;
				firstStack.getVal();
				break;
			}
			case showStack:
			{
				cout << "index" << " ����������� �����" << endl;
				if (firstStack.quantityOfStackElements() > 0)
				{
					for (int i = firstStack.quantityOfStackElements(); i > 0; i--)
					{

						cout << i << "   " << firstStack.returnElementOfStackByIndex(i - 1) << endl;
					}
				}
				else
				{
					cout << "���� ������" << endl;
				}
				break;
			}
			case showTopOfStack:
			{
				if (firstStack.quantityOfStackElements() > 0)
				{
					cout << "������� �����:  ";
					cout << firstStack.returnElementOfStackByIndex(firstStack.quantityOfStackElements() - 1) << endl;
				}
				else
				{
					cout << "���� ������" << endl;
				}

				break;
			}
			case showParametrsOfStack:
			{
				cout << "��������� �����:" << endl;
				cout << "������������ ������ �����:   " << firstStack.returnMaxSizeOfStack() << endl;
				cout << "���������� ����������� ��������� � �����:  " << firstStack.quantityOfStackElements() << endl;
				if (firstStack.quantityOfStackElements() > 0)
				{
					cout << "������� �����:  ";
					cout << firstStack.returnElementOfStackByIndex(firstStack.quantityOfStackElements() - 1) << endl;

				}
				cout << "��� ������ ��������� �����:  " << typeid(firstStack.returnElementOfStackByIndex(0)).name() << endl;

				break;
			}

			default:cout << "������ ������������ ����� ����, ������ �����������" << endl;
				break;
			}
			cout << "_______________________________" << endl;
			showMenu();
			cout << "_______________________________" << endl;
		}
	} while (quit);
}

