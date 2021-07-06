#include "classes.h"

A::A(double time, double x, double y) : x(x), y(y), time(time) {}

double A::getX() const
{
    return x;
}

bool A::setX(double x)
{
    return this->x = x;
}

double A::getY() const
{
    return y;
}

bool A::setY(double y)
{
    return this->y = y;
}

double A::getTime() const
{
    return time;
}

bool A::setTime(double time)
{
    return this->time = time;
}

void A::whoAmI() const
{
    cout << "I am class A" << endl;
}

void A::deserialize() const
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}

B::B(double time, double x, double y, double z) : A::A(time, x, y), z(z) {}

double B::getZ() const
{
    return z;
}

bool B::setZ(double z)
{
    return this->z = z;
}

void B::whoAmI() const
{
    cout << "I am class B" << endl;
}

void B::deserialize() const
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My z: " << this->getZ() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}

C::C(double time, double x, double y, double velocity) : A::A(time, x, y), velocity(0) {}

double C::getVelocity() const
{
    return velocity;
}

bool C::setVelocity(double velocity)
{
    return this->velocity = velocity;
}

void C::whoAmI() const
{
    cout << "I am class C" << endl;
}

void C::deserialize() const
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My velocity: " << this->getVelocity() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}

D::D(double time, double x, double y, double z, double velocity) : C::C(time, x, y, velocity), z(z) {}

double D::getZ() const
{
    return z;
}

bool D::setZ(double z)
{
    return this->z = z;
}

void D::whoAmI() const
{
    cout << "I am class D" << endl;
}

void D::deserialize() const
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My z: " << this->getZ() << endl;
    cout << "My velocity: " << this->getVelocity() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}