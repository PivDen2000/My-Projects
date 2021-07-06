#pragma once
#include <iostream>
using namespace std;

class A {
private:
	double x, y, time;
public:
	A(double time=0, double x=0, double y=0);
	~A() = default;
	A(const A&) = default;
	A(A&&) = default;
	A& operator=(const A&) = default;
	A& operator=(A&&) = default;

	double getX() const;
	bool setX(double x);
	double getY() const;
	bool setY(double y);
	double getTime() const;
	bool setTime(double time);

	virtual void whoAmI() const;
	virtual void deserialize() const;
};

class B :public A {
private:
	double z;
public:
	B(double time = 0, double x = 0, double y = 0, double z = 0);

	double getZ() const;
	bool setZ(double z);

	void whoAmI() const override;
	void deserialize() const override;
};

class C : public A {
private:
	double velocity;

public:
	C(double time = 0, double x = 0, double y = 0, double velocity = 0);

	double getVelocity() const;
	bool setVelocity(double v);

	void whoAmI() const override;
	void deserialize() const override;
};

class D : public C {
private:
	double z;
public:
	D(double time = 0, double x = 0, double y = 0, double z = 0, double velocity = 0);

	double getZ() const;
	bool setZ(double z);

	void whoAmI() const override;
	void deserialize() const override;
};