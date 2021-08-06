#include "classes.h"

A::A(double time, double x, double y) : x(x), y(y), time(time) {}

double A::getX() const noexcept
{
    return x;
}

bool A::setX(double x) noexcept
{
    return this->x = x;
}

double A::getY() const noexcept
{
    return y;
}

bool A::setY(double y) noexcept
{
    return this->y = y;
}

double A::getTime() const noexcept
{
    return time;
}

bool A::setTime(double time) noexcept
{
    return this->time = time;
}

void A::whoAmI() const noexcept
{
    cout << "I am class A" << endl;
}

void A::deserialize() const noexcept
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}

B::B(double time, double x, double y, double z) : A::A(time, x, y), z(z) {}

double B::getZ() const noexcept
{
    return z;
}

bool B::setZ(double z) noexcept
{
    return this->z = z;
}

void B::whoAmI() const noexcept
{
    cout << "I am class B" << endl;
}

void B::deserialize() const noexcept
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My z: " << this->getZ() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}

C::C(double time, double x, double y, double velocity) : A::A(time, x, y), velocity(velocity) {}

double C::getVelocity() const noexcept
{
    return velocity;
}

bool C::setVelocity(double velocity) noexcept
{
    return this->velocity = velocity;
}

void C::whoAmI() const noexcept
{
    cout << "I am class C" << endl;
}

void C::deserialize() const noexcept
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My velocity: " << this->getVelocity() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}

D::D(double time, double x, double y, double z, double velocity) : C::C(time, x, y, velocity), z(z) {}

double D::getZ() const noexcept
{
    return z;
}

bool D::setZ(double z) noexcept
{
    return this->z = z;
}

void D::whoAmI() const noexcept
{
    cout << "I am class D" << endl;
}

void D::deserialize() const noexcept
{
    this->whoAmI();
    cout << "My x: " << this->getX() << endl;
    cout << "My y: " << this->getY() << endl;
    cout << "My z: " << this->getZ() << endl;
    cout << "My velocity: " << this->getVelocity() << endl;
    cout << "My time: " << this->getTime() << endl;
    cout << "*****************" << endl;
}