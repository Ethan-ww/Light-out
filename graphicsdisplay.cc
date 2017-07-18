#include <iostream>
#include <utility>
#include "graphicsdisplay.h"
#include "cell.h"
#include "info.h"
#include "window.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int n, Xwindow* win) : gridSize(n), win(win){
	vector<bool> row(n, false);
	for (int c = 0; c < n; ++c) {
		theDisplay.push_back(row);
	}
}

void GraphicsDisplay::notify(Subject &whoNotified) {
	Info in = whoNotified.getInfo();
	theDisplay[in.row][in.col]=in.state;
	for(int r=0;r<gridSize;++r){
		for(int c=0;c<gridSize;++c){
			if(theDisplay[r][c]){
				win->fillRectangle(r*20, c*20, 20, 20, Xwindow::White);  // draw the graph
			}else{
				win->fillRectangle(r*20, c*20, 20, 20, Xwindow::Black);
			}
		}
	}
}

GraphicsDisplay::~GraphicsDisplay() {}

SubscriptionType GraphicsDisplay::subType() const {
	return SubscriptionType::All;
}

