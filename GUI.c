#include "Sudoku.h"
#include "GUI.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "graphics2.h"

/*You cannot change the name of these constants but you can change their definition*/
#define MARGIN 120
#define GRId_SIZE (MAX_X - 600)/BOARD_SIZE //original value is 400
#define STEP ((MAX_X)/(GRId_SIZE*(BOARD_SIZE)))
#define X_START_OFFSET MARGIN
#define X_END_OFFSET (GRId_SIZE + MARGIN)
#define Y_START_OFFSET MARGIN
#define Y_END_OFFSET (MARGIN+GRId_SIZE)
#define BORDER_OFFSET GRId_SIZE/20

void drawSections(){
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
		
	
		setlinestyle(SOLID_LINE, 0, GRId_SIZE / 10);
		setcolor(CYAN);
		
		for (int i = 0; i < GAME_SIZE; i++) {
			for (int j = 0; j < GAME_SIZE; j++) {
				rectangle(((i)*GRId_SIZE*GAME_SIZE) + X_START_OFFSET,
					((j)*GRId_SIZE*GAME_SIZE)+Y_START_OFFSET,
					((i+1)*GRId_SIZE*GAME_SIZE)+X_START_OFFSET,
					((j+1)*GRId_SIZE*GAME_SIZE)+Y_START_OFFSET);
			}
		}

		/*
		// Top first box
		rectangle(X_START_OFFSET,
			Y_START_OFFSET + GRId_SIZE * GAME_SIZE,
			X_END_OFFSET + GRId_SIZE * (GAME_SIZE-1),
			Y_END_OFFSET - GRId_SIZE); 
		
		// Top second box
		rectangle(X_START_OFFSET + GRId_SIZE * (GAME_SIZE*2),
			Y_START_OFFSET+GRId_SIZE * GAME_SIZE,
			X_END_OFFSET + GRId_SIZE * (GAME_SIZE - 1),
			Y_END_OFFSET - GRId_SIZE);
									
		// Top third box
		rectangle(X_START_OFFSET + GRId_SIZE * (GAME_SIZE*3),
			Y_START_OFFSET + GRId_SIZE *GAME_SIZE,
			X_END_OFFSET + GRId_SIZE * (GAME_SIZE - 1),
			Y_END_OFFSET - GRId_SIZE); 

		// Middle first box
		rectangle(X_START_OFFSET,
			Y_START_OFFSET + GRId_SIZE *(GAME_SIZE + 3),
			X_END_OFFSET + GRId_SIZE *(GAME_SIZE - 1),
			Y_END_OFFSET + GRId_SIZE*(GAME_SIZE - 1));

		//Middle second box
		rectangle(X_START_OFFSET + GRId_SIZE * (GAME_SIZE * 2),
			Y_START_OFFSET + GRId_SIZE *(GAME_SIZE + 3),
			X_END_OFFSET + GRId_SIZE *(GAME_SIZE - 1),
			Y_END_OFFSET + GRId_SIZE*(GAME_SIZE - 1));

		//Middle third box
		rectangle(X_START_OFFSET + GRId_SIZE * (GAME_SIZE * 3),
			Y_START_OFFSET + GRId_SIZE *(GAME_SIZE + 3),
			X_END_OFFSET + GRId_SIZE *(GAME_SIZE - 1),
			Y_END_OFFSET + GRId_SIZE*(GAME_SIZE - 1));

		//Bottom first box
		rectangle(X_START_OFFSET,
			Y_START_OFFSET + GRId_SIZE * (GAME_SIZE + 6),
			X_END_OFFSET + GRId_SIZE * (GAME_SIZE - 1),
			Y_END_OFFSET + GRId_SIZE * ((GAME_SIZE * 2) - 1));

		//Bottom second box
		rectangle(X_START_OFFSET + GRId_SIZE * (GAME_SIZE * 2),
			Y_START_OFFSET + GRId_SIZE * (GAME_SIZE + 6),
			X_END_OFFSET + GRId_SIZE * (GAME_SIZE - 1),
			Y_END_OFFSET + GRId_SIZE * ((GAME_SIZE * 2) - 1));

		//Bottom third box
		rectangle(X_START_OFFSET + GRId_SIZE * (GAME_SIZE * 3),
			Y_START_OFFSET + GRId_SIZE * (GAME_SIZE + 6),
			X_END_OFFSET + GRId_SIZE * (GAME_SIZE - 1),
			Y_END_OFFSET + GRId_SIZE * ((GAME_SIZE * 2) - 1));
			*/
}

int isClickOutOfBoard(){
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
	return FALSE;
}

int isClickInSelection(){
	/*You have to use this function in your implementation
	Please ENTER YOUR OWN SOURCE CODE*/
	return FALSE;
}

int getMouseX(){
	/*You can change this function*/
	int mc = mouseclickx();
	mc -= X_START_OFFSET;
	int gz = GRId_SIZE;
	mc = mc / gz;
	return mc;
}

int getMouseY(){
	/*You can change this function*/
	int mc = mouseclicky();
	mc -= Y_START_OFFSET;
	int gz = GRId_SIZE;
	mc = mc / gz;
	return mc;
}

void printAtBottom(char *text){
	/*You can change this function*/
	settextstyle(10, HORIZ_DIR, GRId_SIZE / 14);
	outtextxy(20, MAX_Y-100, text);
}

void initializeGraphics(){
	/*You can change this function*/
	int GraphDriver = 0, GraphMode = 0;
	initgraph(&GraphDriver, &GraphMode, "", MAX_X, MAX_Y); // Start Window
	cleardevice();
}

void drawHeader(){
	/*You can change this function*/
	setcolor(WHITE);
	settextstyle(10, HORIZ_DIR, 5);
	outtextxy(20, 20, "SuDOkU - ICT1002");
	settextstyle(10, HORIZ_DIR, 2);
	setcolor(RED);
	outtextxy(20, 70, "Copyright © SIT/ICT 2015 ");
}


void drawGridCell(int x, int y, int color){
	/*You can change this function*/
	setcolor(color);
	setlinestyle(SOLID_LINE, 0, GRId_SIZE / 20);
	setfillstyle(SOLID_FILL, color);

	bar(x*GRId_SIZE + X_START_OFFSET,
		y * GRId_SIZE + Y_START_OFFSET,
		x * GRId_SIZE + X_END_OFFSET,
		y * GRId_SIZE + Y_END_OFFSET);
	setcolor(WHITE);
	rectangle(x*GRId_SIZE + X_START_OFFSET,
		y * GRId_SIZE + Y_START_OFFSET,
		x * GRId_SIZE + X_END_OFFSET,
		y * GRId_SIZE + Y_END_OFFSET); //Outline
}

void setGridValue(int x, int y, int g){
	/*You can change this function*/
	int color;
	switch (g) {
	case EMPTY:	
		color = DARKGRAY;
		drawGridCell(x, y, color);
		break;
	case 0:
		drawGridCell(x, y, LIGHTGRAY);
		break;
	default:	
		color = BLACK;
		drawGridCell(x, y, color);
		settextstyle(10, HORIZ_DIR, GRId_SIZE /13);
		char value[10]="";
		_itoa(g, value, 10);
		outtextxy(x*GRId_SIZE + X_START_OFFSET+GRId_SIZE/5.5,
			y * GRId_SIZE + Y_START_OFFSET + GRId_SIZE / 5.5, value);
		break;
	}
	drawSections();

}