#include "Sudoku.h"
#include "GUI.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>//for random num i think

int board[BOARD_SIZE][BOARD_SIZE] = { EMPTY };
int mouseX = -1, mouseY = -1;
int numOfRevealedBoxes;

int randNumGenerator()
{
	int randNum;
	time_t t;

	/* Intializes random number generator */
	srand((unsigned)time(&t));
	
	randNum=rand() % (BOARD_SIZE);//it is random from 0 to (BOARD_SIZE*BOARD_SIZE). so we +1 at the random value when it is to display
	

	return randNum;
}

void initializeNumOnBoard() {//based on user's level.
	//get the rowNum and columnNum first
	//use checkSection() first to see if the cell's number is displayed before
	//if it is, then random again, else ,  just remain. (use dowhile loop)
	//numOfRevealedBoxes = get from user input from
	int i, rowNum = 0, columnNum = 0;
	for (i = 0; i < numOfRevealedBoxes;i++) {
	do {
		//getting a random row first
		rowNum = randNumGenerator();
		//getting a random column first
		columnNum = randNumGenerator();
	} while (checkSection(rowNum, columnNum, 0));
	
	board[rowNum][columnNum] = (randNumGenerator()+1);
	setGridValue(rowNum, columnNum, (randNumGenerator() + 1));//printing values


	}
}

int checkSection(int x, int y, int value) {
	int i, rowNum = 0, columnNum = 0;
	//This function checks if value has already existed in the same section with cell (x,y).
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
	if (board[rowNum][columnNum] == !NULL) 
		return TRUE;
}



int checkRow(int x, int y, int value) {
	//This function checks if value has already existed in row x
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
	int cellValue;
	cellValue = board[x][y];

	int i;

	for (i = 0; i <BOARD_SIZE; i++)
	{
		if (i == x)//ignore it's own row
		{
			continue;
		}
		
		//if their value == cellValue;
		printAtBottom("Row conflicts");
	}


	
	return TRUE;
}

int checkColumn(int x, int y, int value) {
	//This function checks if valuehas already existed in column y.
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/


	//same as checkRow();
	printAtBottom("Column conflicts");
	return TRUE;
}

void initializeGame(){
	/*You have to use this function in your implementation
	You can add more code to this function*/
	
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			board[i][j] = EMPTY;
			setGridValue(i, j, EMPTY);
		}
	}
	j = BOARD_SIZE + 1;
	for (i = 1; i <= BOARD_SIZE; i++){
		setGridValue(i - 1, j, i);
	}
	initializeNumOnBoard();
	drawHeader();
	drawSections();


}

int getSelection(){
	/*You have to use this function in your implementation*/
	int selection = 0;
	if (isClickInSelection()){
		selection = getMouseX();
	}

	return selection;
}

void startGame(){
	/*You have to use this function in your implementation
	You can add more code to this function*/
	if (mouseup()){
		if (!isClickOutOfBoard()){
			mouseX = getMouseX();
			mouseY = getMouseY();
			setGridValue(mouseX, mouseY, 0);
			return;
		}
	}
}

/*
void menu()
{
int choice, valid = 0;
system("cls");
printf("\n--------SuDOkU MENU--------");
printf("\nChoose the level");
printf("\n1 : Easy");
printf("\n2 : Medium");
printf("\n3 : Hard");
printf("\n4 : Exit");
printf("\nEnter your choice:>");

scanf("%d", &choice);

switch (choice)
{
case 1:
numOfRevealedBoxes=(BOARD_SIZE*BOARD_SIZE)*0.4;

break;
case 2:
numOfRevealedBoxes=(BOARD_SIZE*BOARD_SIZE)*0.35;

break;
case 3:
numOfRevealedBoxes=(BOARD_SIZE*BOARD_SIZE)*0.3;

case 4:
exit(1);
default:
menu();
}
}
*/


void main()
{
	initializeGraphics();
	cleardevice();
	clearmouse();
	initializeGame();
	//setGridValue(0, 0, randNumGenerator()); //return memory add
	/*You can change code from this point*/
	while (TRUE){
		startGame();
	}
	getch();
}




