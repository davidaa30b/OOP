#pragma once
#pragma once
#include"Vechicle.h"

class Bus :virtual public Vechicle {
private:
	bool hasPassengers;
public:

	bool getHasPassengers()const {
		return hasPassengers;
	}

	void setHasPassengers(bool personal) {
		this->hasPassengers = personal;
	}

	Bus() :hasPassengers(true), Vechicle() {}

	Bus(bool personal, const string brand, const string model, int year, const string problem, ProblemType problemType) :
		Vechicle(brand, model, year, problem, problemType) {
		setHasPassengers(personal);
	}

	void print()const override {
		Vechicle::print();
		cout << "Has Passengers " << hasPassengers << endl;
	}

	Vechicle* clone()const override {
		return new Bus(*this);
	}

};