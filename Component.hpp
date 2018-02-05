#ifndef COMPONENT_HPP
#define COMPONENT_HPP


#include <cmath>
#include <complex>




class Component : public Base
{

    public:

    Component();

    virtual
    ~Component();


    protected:

    // TODO: const pointer?
    // Points to any components connected (in parallel)
    // in the direction "next"
    //std::vector<Component*> _next_component;

    // direction "previous"
    //std::vector<Component*> _prev_component;
    std::complex<double> _impedance;

};






#endif
