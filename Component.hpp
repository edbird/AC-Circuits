#ifndef COMPONENT_HPP
#define COMPONENT_HPP


#include <cmath>
#include <complex>


class Grid
{

    public:

    virtual
    void ~Grid();

    void AddComponent(const std::string& name, const Component& component);

    const Component& GetComponent(const std::string& name);

    Component& MutableComponent(const std::string& name);

    virtual
    std::complex<double> CalcImpedance() const;



    protected:

    std::map<std::string, Component> _component;

};

void AddComponent(const std::string& name, const Component& component)
{
    // TODO: correct method?
    _component.insert(name, component);
}

const Component& Grid::GetComponent(const std::string& name)
{
    // TODO
    if(_component.find())
    {

    }
}

Component& Grid::MutableComponent(const std::string& name)
{
    // TODO
}



class SeriesGrid : public Grid
{

    public:

    std::complex CalcImpedance() const;



    //protected:

    //std::vector<Component> _component;

};

std::complex<double> Grid::CalcImpedance() const
{
    std::complex<double> ret(0.0, 0.0);
    std::vector<Component>::const_iterator it{_component.cbegin()};
    for(; it != _component.cend(); ++ it)
    {
        ret += it->Impedance();
    }
    return ret;
}


class ParallelGrid : public Grid
{

    public:

    std::complex<double> CalcImpedance() const;



    //protected:

    //std::vector<Component> _component;

}

std::complex<double> Grid::CalcImpedance() const
{
    std::complex<double> ret(0.0, 0.0);
    std::vector<Component>::const_iterator it{_component.cbegin()};
    for(; it != _component.cend(); ++ it)
    {
        ret += 1.0 / it->Impedance();
    }
    return 1.0 / ret;
}


class Component
{

    public:

    Component()
    {

    }

    virtual
    ~Component();

    virtual
    std::complex<double> Impedance() const;


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
