#pragma once
#include"Bus.h"
#include"Car.h"

#define INIT_CAPACITY 10
#define RESIZE_FACTOR 2

class Garage {

	Vechicle** vechiles;
	size_t capacity;
	size_t count;
	size_t seriousness;

	void resize() {
		size_t newCapacity = capacity * RESIZE_FACTOR;
		Vechicle** newVechicle = new Vechicle * [newCapacity];
		for (size_t i = 0; i < count; i++) {
			newVechicle[i] = vechiles[i];
		}
		delete[] vechiles;
		vechiles = newVechicle;
		newVechicle = nullptr;
	}

	void copyFrom(const Garage& other) {

		capacity = other.capacity;
		count = other.count;
		allocate();
		for (size_t i = 0; i < count; i++) {
			vechiles[i] = other.vechiles[i];
		}
	}

	void free() {
		for (size_t i = 0; i < count; i++) {
			delete vechiles[i];
		}
		delete[] vechiles;
	}

	void allocate() {
		vechiles = new Vechicle * [capacity];
	}

public:

	Garage() :capacity(INIT_CAPACITY), count(0),seriousness(0) {
		allocate();
	}
	
	void addVechicle(const Vechicle& vechicle) {
		if (count >= capacity) {
			resize();
		}

		

		if (seriousness < 10) {

			if (vechicle.getProblemType() == SMALL) {
				seriousness += 1;
			}

			if (vechicle.getProblemType() == MIDDLE) {
				seriousness += 3;
			}
			
			if (vechicle.getProblemType() == HIGH) {
				seriousness += 5;
			}

			vechiles[count] = vechicle.clone();
			count++;
		}
		else {

			cout << "Garage to busy right now . Come again later." << endl;
			cout << "Seriousness now : " << seriousness << endl;
		}
	}

	void display() {
		for (size_t i = 0; i < count; i++) {
			vechiles[i]->print();
			cout << endl;
		}
	}

	void freeVechicle() {
		
		if (count >= 1) {
			seriousness -= vechiles[0]->getProblemType();
			cout << "Delete ,Now serioussnes: " << seriousness;
			delete vechiles[0];
			count--;

		}

		for (size_t i = 0; i < count; i++) {
			vechiles[i] = vechiles[i + 1];
		}
	}

	~Garage() {
		free();
	}

};