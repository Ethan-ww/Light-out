#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) { 
	observers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
	if (t == SubscriptionType::SwitchOnly) {
		for (unsigned int i = 0; i < observers.size(); ++i) {
			observers[i]->notify(*this);
		}
	}
	else {
		for (unsigned int i = 0; i < observers.size(); ++i) {
			if(observers[i]->subType()==SubscriptionType::All) observers[i]->notify(*this); // update graph display
		}
	}
}


