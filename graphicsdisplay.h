#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"

class GraphicsDisplay: public Observer{
	std::vector<std::vector<bool>> theDisplay;
	int gridSize;
	Xwindow* win;
public:
	GraphicsDisplay(int n, Xwindow* win);

	void notify(Subject &whoNotified) override;
	SubscriptionType subType() const override;

	~GraphicsDisplay();
};

#endif

