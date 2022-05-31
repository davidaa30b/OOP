#pragma once
#include"Vechicle.h"

class Car:virtual public Vechicle {
private:
	bool personal;
public:
	
	bool getPersonal()const {
		return personal;
	}

	void setPersonal(bool personal) {
		this->personal = personal;
	}

	Car() :personal(true), Vechicle() {}

	Car(bool personal, const string brand, const string model, int year, const string problem, ProblemType problemType) :
		Vechicle(brand, model, year, problem, problemType) {
		setPersonal(personal);
	}

	void print()const override {
		Vechicle::print();
		cout << "Personal " << personal << endl;
	}

	Vechicle* clone()const override {
		return new Car(*this);
	}
};