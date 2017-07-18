#include <iostream>
#include "grid.h"
#include "window.h"
#include "graphicsdisplay.h"
using namespace std;

Grid::Grid() {}

Grid::~Grid() {
	delete gd;
}

void Grid::clearGrid() { 
	for (int r = 0; r < gridSize; ++r) {
		theGrid[r].clear();
	}
	theGrid.clear();
}

bool Grid::isWon() const {
	for (int r = 0; r < gridSize; ++r) {
		for (int c = 0; c < gridSize; ++c) {
			if (theGrid[r][c].getState()) return false; // if there exsist an on grid, return false
		}
	}
	return true;
}

void Grid::init(int n, Xwindow* win) {
	clearGrid();
	gridSize = n;
	gd = new GraphicsDisplay(gridSize,win); // initialize the graph display
	for (int r = 0; r < gridSize; ++r) { // add cells to the grid
		vector<Cell> temp;
		for (int c = 0; c < gridSize; ++c) {
			Cell tempCell;
			tempCell.setCoords(r, c);
			temp.push_back(tempCell);
		}
		theGrid.push_back(temp);
	}
	for (int r = 0; r < gridSize; ++r) { // add observers
		for (int c = 0; c < gridSize; ++c) {
			if (r > 0) { // top neighbour
				theGrid[r][c].attach(&theGrid[r - 1][c]);
			}
			if (r < gridSize-1) { // bottom neighbour
				theGrid[r][c].attach(&theGrid[r + 1][c]);
			}
			if (c > 0) { // left neighbour
				theGrid[r][c].attach(&theGrid[r][c - 1]);
			}
			if (c < gridSize - 1) { // right neighbour
				theGrid[r][c].attach(&theGrid[r][c + 1]);
			}	
			theGrid[r][c].attach(&theGrid[r][c]); // add itself
			theGrid[r][c].attach(gd); // add graph display
		}
	}
}

void Grid::turnOn(int r, int c) {
	theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
	theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly); // notify neighbours & graph
}

