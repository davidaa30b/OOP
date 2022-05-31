#include"Garage.h"

int main() {
	Garage garage;
	Vechicle* vec1 = new Car(true,"Honda","Civic",2011,"String wheel goes left",MIDDLE);
	Vechicle* vec2 = new Bus(false, "Man", "Truncker", 2011, "BIG BAD", HIGH);
	Vechicle* vec3 = new Car(true, "Dodge", "Demon", 2020, "BIG BAD", HIGH);
	Vechicle* vec4 = new Car(false, "Porsche", "911", 2020, "BIG BAD", SMALL);
	
	garage.addVechicle(*vec1);
	garage.addVechicle(*vec2);
	garage.addVechicle(*vec3);
	cout << "before delete---------------" << endl;
	garage.display();
	garage.freeVechicle();
	garage.addVechicle(*vec3);
	cout << "after delete---------------" << endl;
	garage.display();


}