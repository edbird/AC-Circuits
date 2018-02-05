#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

class Circuit
{

    public:

    Circuit();

    ~Circuit();


    protected:


    // pointer to either a Series or Parellel grid type
    std::unique_ptr<Grid> _grid;

};

#endif