#define _USE_MATH_DEFINES
#define DELTA_H 0.000001

#include <string>
#include <cmath>
#include <random>
#include <ctime>

#include <iostream>

class Curve3D {
protected:

	std::string type;

public:

	virtual double getx(double t) = 0;
	virtual double gety(double t) = 0;
	virtual double getz(double t) = 0;

	virtual double getdx(double t) {
		double h = DELTA_H;
		return((getx(t + h) - getx(t)) / h);
	}

	virtual double getdy(double t) {
		double h = DELTA_H;
		return((gety(t + h) - gety(t)) / h);
	}

	virtual double getdz(double t) {
		double h = DELTA_H;
		return((getz(t + h) - getz(t)) / h);
	}

	virtual std::string getType() {
		return(type);
	}
};

class Curve3DCircle : public Curve3D {
protected:

	double r;

public:

	Curve3DCircle() {
		r = 0;
		type = "circle";
	}

	Curve3DCircle(double _r) {
		r = _r;
		type = "circle";
	}

	void set(double _r) {
		r = _r;
	}

	double getx(double t) override {
		return(r * sin(t));
	}

	double gety(double t) override {
		return(r * cos(t));
	}

	double getz(double t) override {
		return(0.0);
	}

	double getR() {
		return(r);
	}

};

class Curve3DEllipse : public Curve3D {
protected:

	double a;
	double b;

public:

	Curve3DEllipse() {
		a = 0;
		b = 0;
		type = "ellipse";
	}

	Curve3DEllipse(double _a, double _b) {
		a = _a;
		b = _b;
		type = "ellipse";
	}

	double set(double _a, double _b) {
		a = _a;
		b = _b;
		type = "ellipse";
	}

	double getx(double t) override {
		return(a * sin(t));
	}

	double gety(double t) override {
		return(b * cos(t));
	}

	double getz(double t) override {
		return(0.0);
	}

};

class Curve3DHelix : public Curve3D {
protected:

	double r;
	double s;

public:

	Curve3DHelix() {
		r = 0;
		s = 0;
		type = "helix";
	}

	Curve3DHelix(double _r, double _s) {
		r = _r;
		s = _s;
		type = "helix";
	}

	double set(double _r, double _s) {
		r = _r;
		s = _s;
		type = "helix";
	}

	double getx(double t) override {
		return(r * sin(t));
	}

	double gety(double t) override {
		return(r * cos(t));
	}

	double getz(double t) override {
		return(s * t / (2 * M_PI));
	}

};