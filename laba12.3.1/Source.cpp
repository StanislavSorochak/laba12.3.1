#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link1,
		* link2;
	inform inf;
};

void Create(Spusok*& first, Spusok*& last, inform inf);
void COUT(Spusok*& T);
void Process(Spusok*& T, inform v1, inform v2, Spusok*& last);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		x = rand() % 6;
		Create(first, last, x);
	}

	Spusok* T = first;
	COUT(T);


	int v1, v2;
	/*
	ϳ��� ������� �������� ������ �� ��������� �������������� ���� V1
	�������� ����� ������� �� ��������� �������������� ���� V2.
	*/
	cout << "������ V1: ";	cin >> v1;
	cout << endl;
	cout << "������ V2: ";	cin >> v2;
	cout << endl << endl;

	T = first;
	Process(T, v1, v2, last);
	T = first;
	COUT(T);

	return 0;
}

void Create(Spusok*& first, Spusok*& last, inform inf)
{
	Spusok* tmp = new Spusok;

	tmp->inf = inf;
	tmp->link1 = NULL;
	tmp->link2 = NULL;
	if (first == NULL)
		first = tmp;
	else
	{
		last->link1 = tmp;
		tmp->link2 = last;
	}
	last = tmp;
}

void COUT(Spusok*& T)
{
	inform inf;

	cout << "���� ���������� ��� ����� ����������� �������: " << endl << endl;
	while (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
		T = T->link1;
	}
	cout << endl << endl;
}

void Process(Spusok*& T, inform v1, inform v2, Spusok*& last)
{
	while (T != NULL)
	{
		if (T->inf == v1)
		{
			Spusok* tmp = new Spusok;  // 1(��������� ������ ������)
			tmp->inf = v2;             // 2(��������� �������������� ��������(�������������� ����) ��������)
			tmp->link1 = T->link1;     // 3(����� ���� ��'����(������ ��������) ������������ �� ������ �������)
			if (T->link1 != NULL)
				T->link1->link2 = tmp; // ��� 4(���� "T->link1 != NULL" �� ������ ������� ����������� �� �������������)
			else
				last = tmp;            // ��� 4(������ �������� last(������� --- '����� �� ������� �������') ����������� �� ������������� �������)
			T->link1 = tmp;            // 5(����� ���� ��'����(������� ��������) ������������ �� ������������� �������)
			tmp->link2 = T;            // 6(����� ���� ��'����(������ ��������)  ������������ �� ������ �������  )
			T = T->link1->link1;       // ��� 7(���� "T->inf == v1" �� �������� 'T' ����������� �� �� ������� ������(������ �������), ������� ��� ���������� �������)
		}
		else
			T = T->link1;              // ��� 7(������ �������� 'T' ����������� �� ���� ������� ������(������ �������), ������� �� ���� ��������������� ��������)
	}
}
