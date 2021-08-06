#pragma once
#include <iostream>
using namespace std;

class A {
protected:
	double x, y, time;
public:
	A(double time=0, double x=0, double y=0);
	~A() = default;
	A(const A&) = default;
	A(A&&) = default;
	A& operator=(const A&) = default;
	A& operator=(A&&) = default;

	double getX() const noexcept;
	bool setX(double x) noexcept;
	double getY() const noexcept;
	bool setY(double y) noexcept;
	double getTime() const noexcept;
	bool setTime(double time) noexcept;

	virtual void whoAmI() const noexcept;
	void deserialize() const noexcept;
};

class B :public A {
protected:
	double z;
public:
	B(double time = 0, double x = 0, double y = 0, double z = 0);

	double getZ() const noexcept;
	bool setZ(double z) noexcept;

	void whoAmI() const noexcept override;
	void deserialize() const noexcept;
};

class C : public A {
protected:
	double velocity;
public:
	C(double time = 0, double x = 0, double y = 0, double velocity = 0);

	double getVelocity() const noexcept;
	bool setVelocity(double v) noexcept;

	void whoAmI() const noexcept override;
	void deserialize() const noexcept;
};

class D : public C {
protected:
	double z;
public:
	D(double time = 0, double x = 0, double y = 0, double z = 0, double velocity = 0);

	double getZ() const noexcept;
	bool setZ(double z) noexcept;

	void whoAmI() const noexcept override;
	void deserialize() const noexcept;
};