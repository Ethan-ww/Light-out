#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit | ios::failbit | ios::badbit);
  string cmd;
  Grid g;
  Xwindow* win=new Xwindow(500,500);
  int moves = 0;
  int row=410;
	
  // You will need to make changes to this code.

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        g.init(n,win);
      }
      else if (cmd == "init") {
        int n, m;
        while (cin >> n >> m) {
          if (n == -1 && m == -1) break;
          g.turnOn(n, m);
        }
      }
      else if (cmd == "game") {
        cin >> moves;
        win->drawString(20,400,to_string(moves)+" moves left");
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle(r, c);
        --moves;
	      if(moves==1){ // single
          		win->drawString(20,row,to_string(moves)+" move left");
			
	      }else{
		        win->drawString(20,row,to_string(moves)+" moves left");
	      }
			row+=10;
        if (!g.isWon() && moves == 0) { 
          win->drawBigString(250,100,"Lost");
          break;
        }

        if (g.isWon() && moves >= 0) {
          win->drawBigString(250,100,"Won");
          break;
        }
        
      }
    }
    delete win;
  }
  catch (ios::failure &) {
  }
}

