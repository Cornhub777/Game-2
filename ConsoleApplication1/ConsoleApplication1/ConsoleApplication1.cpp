#include <stdio.h>  
#include <Windows.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <time.h>
int main() {
	//настр 
	const int startingMoney = 500;
	const int  turnCost = 50;
	const int doubleBonus = 60;
	const int tripleBonus = 100;

	//логика
	int Money = startingMoney;
	int bonus = 0;
	char panel0 = 'X';
	char panel1 = 'X';
	char panel2 = 'X';
	srand(time(0));
	//цикл
	do {
		//рендер
		system("cls");
		printf("\n\n");
		printf("\t ######## \n");
		printf("\t# Yerbol #\n");
		printf("\t###########\n");
		printf("\t#         #\n");
		printf("\t#  %c %c %c  #\n", panel0, panel1, panel2);
		printf("\t#         #\n");
		printf("\t###########\n");
		printf("\n");
		if (bonus > 0) {
			printf("\t  +%i$\n", (bonus - turnCost));
		}
		else
		{
			printf("\n");
		}
		printf("\n");
		printf("\tMoney: %i$\n", Money);


		//пауза
		_getch();
		//главная логика 
		Money = Money - turnCost;
		panel0 = 3 + (rand() % 4);
		panel1 = 3 + (rand() % 4);
		panel2 = 3 + (rand() % 4);
		//if   

		if ((panel0 == panel1) && (panel0 == panel2))
		{
			bonus = tripleBonus;
		}
		else
		{
			if ((panel0 == panel1) || (panel1 == panel2) || (panel0 == panel2)) {
				bonus = doubleBonus;
			}
			else {
				bonus = 0;
			}
		}
		Money = Money + bonus;
	} while (Money >= turnCost);
	return 0;
}