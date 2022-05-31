#pragma once
#include<iostream>
#include<string>
using namespace std;
enum ProblemType {
	SMALL =1,
	MIDDLE =3,
	HIGH=5
};
class Vechicle {
	string brand;
	string model;
	int year;
	string problem;
protected:
	ProblemType problemType;

public:
	string getBrand()const {
		return brand;
	}

	string getModel()const {
		return model;
	}

	int getYear()const {
		return year;
	}

	string getProblem()const {
		return problem;
	}

	ProblemType getProblemType()const {
		return problemType;
	}

	void setBrand(const string brand) {
		this->brand = brand;
	}

	void setModel(const string model) {
		this->model= model;
	}

	void setYear(int year) {
		this->year = year;
	}

	void setProblem(const string problem) {
		this->problem = problem;
	}

	void setProblemType(ProblemType problemType) {
		this->problemType = problemType;
	}

	Vechicle() :brand(""), model(""), year(0), problem(""), problemType(SMALL) {}

	Vechicle(const string brand, const string model, int year, const string problem,ProblemType problemType) {
		setBrand(brand);
		setModel(model);
		setYear(year);
		setProblem(problem);
		setProblemType(problemType);
	}

	virtual void print()const = 0  {
		cout << "Brand : " << brand << " , Model : " << model << " , Year : " << year << " , Problem : " << problem << " , Problem Type " << problemType << endl;
	}

	virtual Vechicle* clone()const = 0;

	virtual ~Vechicle() = default;
};

