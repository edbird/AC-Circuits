#if COMPONENTS_HPP
#define COMPONENTS_HPP

class Resistor : public Component
{

    public:

    Resistor(const double resistance);

}

class Capacitor : public Component
{
    
    public:

    Capacitor(const double capacitance);

}

class Inductor : public Component
{

    public:

    Inductor(const double inductance);

}

class RealCapacitor : public Component
{

    public:

    RealCapacitor(const double capacitance, const double resistance);

}

class RealInductor : public Component
{

    public:

    RealInductor(const double inductance, const double resistance, const double capacitance);

}

#endif
