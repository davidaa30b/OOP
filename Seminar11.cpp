#include<iostream>

enum Type {
	Diesel,
	Petrol
};
class Car {
protected:
	char* model;
	int height;
	int width;
	int length;
	int weight;

	void copyFrom(const Car& other) {
		setModel(other.model);
		setHeight(other.height);
		setWidth(other.width);
		setLength(other.length);
		setWeight(other.weight);
	}
public:
	char* getModel() {
		return model;
	}

	int getHeight() {
		return height;
	}

	int getWidth() {
		return width;
	}

	int getLength() {
		return length;
	}

	int getWeight() {
		return weight;
	}

	void setModel(const char* model) {
		delete[] this->model;
		this->model = new char[strlen(model) + 1];

		strcpy(this->model, model);
		
	}

	void setHeight(int height) {
		this->height = height;
	}

	void setWidth(int width) {
		this->width = width;
	}

	void setLength(int length) {
		this->length = length;
	}

	void setWeight(int weight) {
		this->weight = weight;
	}

	Car():height(0), width(0), length(0), weight(0){
		setModel("");
	}
	

	Car(const char* model,int height,int width, int length, int weight):model(nullptr) {
		setModel(model);
		setHeight(height);
		setWidth(width);
		setLength(length);
		setWeight(weight);
	}

	Car (const Car& other) {
		copyFrom(other);
	}

	Car& operator=(const Car& other){
		if (this != &other) {
			delete[] model;
			copyFrom(other);
		}
	return *this;
	}

	~Car() {
		delete[] model;
	}

};

class ElectricCar :public Car {
private:
	int battery_power;
public:
	int getBatteryPower(){
		return battery_power;
	}
	void setBatteryPower(int battery_power) {
		this->battery_power = battery_power;
	}

	ElectricCar() :Car() {
		setBatteryPower(0);
	};

	ElectricCar(const char* model, int height, int width, int length, int weight,int battery_power) :Car(model, height, width, length, weight)  {
		setBatteryPower(battery_power);
	};

	

};

class FuelCar:public Car {
private:
	Type type;
	int horsepower;
public:
	Type getType(Type type) {
		return type;
	}
	void setType(Type type) {
		this->type = type;
	}

	int getHorsePower() {
		return horsepower;
	}

	void setHorsePower(int horsepower) {
		this->horsepower = horsepower;
	}

	FuelCar() :Car() {
		setHorsePower(0);
		setType(Diesel);
	};

	FuelCar(const char* model, int height, int width, int length, int weight, int horsepower,Type type) :Car(model, height, width, length, weight) {
		setHorsePower(horsepower);
		setType(type);
	};

	

	
};

int main() {


	return 0;
}
