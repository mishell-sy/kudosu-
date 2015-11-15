#include "Sudoku.h"
#include "GUI.h"
#include <time.h>
#include <stdlib.h>

int board[BOARD_SIZE][BOARD_SIZE] = { EMPTY };
int mouseX = -1, mouseY = -1;
int numOfRevealedBoxes;


int randNumGenerator()
{
	int randNum;
	time_t t; /* time*/

	/* Intializes random number generator */
	srand((unsigned)time(&t));

	randNum = rand() % (BOARD_SIZE);//it is random from 0 to (BOARD_SIZE*BOARD_SIZE). so we +1 at the random value when it is to display


	return randNum;
}

void initializeNumOnBoard() {//based on user's level.
							 //get the rowNum and columnNum first
							 //use checkSection() first to see if the cell's number is displayed before
							 //if it is, then random again, else ,  just remain. (use dowhile loop)
							 //numOfRevealedBoxes = get from user input from
	int i, rowNum = 0, columnNum = 0;
	for (i = 0; i < numOfRevealedBoxes; i++) {
		do {
			//getting a random row first
			rowNum = randNumGenerator();
			//getting a random column first
			columnNum = randNumGenerator();
		} while (checkSection(rowNum, columnNum, 0));

		board[rowNum][columnNum] = (randNumGenerator() + 1);
		setGridValue(rowNum, columnNum, (randNumGenerator() + 1));//printing values


	}
}

int checkSection(int x, int y, int value){
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
	x = (x / GAME_SIZE) * GAME_SIZE;
	y = (y / GAME_SIZE) * GAME_SIZE;
	int row, col;
	for (row = 0; row<GAME_SIZE; row++)
		for (col = 0; col<GAME_SIZE; col++)
			if (board[x + row][y + col] == value);
				return FALSE;

	return TRUE;
}

int checkRow(int x, int y, int value){
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
	int col;
	for (col = 0; col <9; col++)
		if (board[x][col] == value)
			return FALSE;

	return TRUE;
}

int checkColumn(int x, int y, int value){
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
	int row;
	for (row = 0; row < BOARD_SIZE; row++)
		if (board[row][y] == value)
			return FALSE;
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
	int selection = 0;
	if (mouseup()){
		if (!isClickOutOfBoard()){
			mouseX = getMouseX();
			mouseY = getMouseY();
			setGridValue(mouseX, mouseY, 0);
			return;
		}
		selection = getSelection();
		if (checkSection(mouseX, mouseY, selection)) {
			if (checkRow(mouseX, mouseY, selection)) {
				if (checkColumn(mouseX, mouseY, selection)) {
					setGridValue(mouseX, mouseY, selection);
					return;
				}
				else
					printAtBottom("Column conflict");
			}
			else
				printAtBottom("Row conflict");
		}
		else
			printAtBottom("Section conflict");
	}
}

void main()
{
	initializeGraphics();
	cleardevice();
	clearmouse();
	initializeGame();
	//setGridValue(0, 0, 9);
	/*You can change code from this point*/
	while (TRUE){
		startGame();
	}
	getch();
}




