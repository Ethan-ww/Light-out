#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
	Info temp = {r, c, isOn};
	return temp;
}

void Cell::setOn() {
	isOn = true;
	this->notifyObservers(SubscriptionType::All); // notify the graph display
}

void Cell::toggle() {
	isOn = !isOn;
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &) {
	toggle();
	this->notifyObservers(SubscriptionType::All); // notify the graph display
}

SubscriptionType Cell::subType() const {
	return SubscriptionType::SwitchOnly;
}

