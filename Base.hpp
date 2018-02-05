#ifndef BASE_HPP
#define BASE_HPP

class Base
{

    public:

    virtual
    void ~Base() = 0;

    virtual
    std::complex<double> Impedance() const = 0;

};

#endif