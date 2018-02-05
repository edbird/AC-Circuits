#ifndef GRID_HPP
#define GRID_HPP

// Pure virtual class
// Can't have a "Grid"
// Can have "Parallel" or "Series" Grid
class GridControl //: public Base
{

    public:

    virtual
    void ~Grid() = 0;

    void AddComponent(const std::string& name, const Component& component);

    const Component& GetComponent(const std::string& name);

    Component& MutableComponent(const std::string& name);

    virtual
    std::complex<double> Impedance() const;


    void AddSeriesGrid()
    {
        if(_grid_depth == 0)
        {
            //_grid.push_back(new SeriesGrid);
            if(_grid.get() == nullptr)
            {
                _grid = new SeriesGrid();
            }
            else
            {
                throw;
            }
        }
        else
        {
            //_grid[Current()].AddSeriesGrid();
            //_grid[_grid_pos].AddSeriesGrid();
            _grid->AddSeriesGrid(_grid_depth - 1);
        }
    }

    void AddParellelGrid()
    {
        if(_grid_depth == 0)
        {
            //_grid.push_back(new ParallelGrid);
            if(_grid.get() == nullptr)
            {
                _grid = new ParallelGrid();
            }
            else
            {
                throw;
            }
        }
        else
        {
            //_grid[Current()].AddParallelGrid();
            //_grid[_grid_pos].AddParallelGrid();
            _grid->AddParallelGrid(_grid_depth - 1);
        }
    }
    

    void PushDepth()
    {
        ++ _grid_depth;
    }

    void PopDepth()
    {
        if(_grid_depth - 1 >= 0)
        {
            -- _grid_depth;
        }
    }
    
    //std::size_t Depth() const
    //{
    //    return _grid_depth;
    //}
    
    
    virtual
    void Next()
    {
        if(_grid_depth == 0)
        {
            //if(_grid_pos + 1 < _grid.size())
            //{
            //    ++ _grid_pos;
            //}
            throw;
        }
        else
        {
            //_grid[_grid_pos].Next();
            _grid->Next();
        }
    }

    virtual
    void Prev()
    {
        if(_grid_depth == 0)
        {
            //if(_grid_pos - 1 > 0)
            //{
            //    -- _grid_pos;
            //}
            throw;
        }
        else
        {
            //_grid[_grid_pos].Prev();
            _grid->Prev();
        }
    }
    
    //std::size_t Current() const
    //{
    //    return _grid_pos;
    //}

    protected:

    std::map<std::string, Component> _component;

    // vector of Series/Parallel grid objects
    std::unique_ptr<Grid> _grid;
    // Grid "level" or "depth"
    // Used to navigate sub-levels, to create more complex networks
    std::size_t _grid_depth;
    // Grid "position"
    // Used to navigate across a grid
    std::size_t _grid_pos;
};

void Grid::AddComponent(const std::string& name, const Component& component)
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



class Grid : public Base
{

    public:
    
    virtual
    ~Grid();

    virtual
    std::complex<double> Impedance(const double freq) const = 0;

    virtual
    void Next() = 0;
    
    virtual
    void Prev() = 0;
    
    //std::vector<Component> _component;
    std::vector<Grid> _grid;
    std::size_t _grid_pos;

};

class SeriesGrid : public Grid
{

    public:

    std::complex Impedance(const double freq) const;


    virtual
    void Next()
    {
        if(_grid_depth == 0)
        {
            if(_grid_pos + 1 < _grid.size())
            {
                ++ _grid_pos;
            }
            else
            {
                throw;
            }
        }
        else
        {
            _grid[_grid_pos].Next();
        }
    }

    virtual
    void Prev()
    {
        if(_grid_depth == 0)
        {
            if(_grid_pos - 1 > 0)
            {
                -- _grid_pos;
            }
            else
            {
                throw;
            }
        }
        else
        {
            _grid[_grid_pos].Prev();
        }
    }

    //protected:

    //std::vector<Component> _component;
    //std::vector<Grid> _grid;
    //std::size_t _grid_pos;
    
};

std::complex<double> Grid::Impedance(const double freq) const
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

    std::complex<double> Impedance(const double freq) const;


    virtual
    void Next()
    {
        if(_grid_depth == 0)
        {
            if(_grid_pos + 1 < _grid.size())
            {
                ++ _grid_pos;
            }
            else
            {
                throw;
            }
        }
        else
        {
            _grid[_grid_pos].Next();
        }
    }

    virtual
    void Prev()
    {
        if(_grid_depth == 0)
        {
            if(_grid_pos - 1 > 0)
            {
                -- _grid_pos;
            }
            else
            {
                throw;
            }
        }
        else
        {
            _grid[_grid_pos].Prev();
        }
    }

    //protected:

    //std::vector<Component> _component;
    //std::vector<std::unique_ptr<Grid>> _grid;
    //std::size_t _grid_pos;
    
}

std::complex<double> Grid::Impedance(const double freq) const
{
    std::complex<double> ret(0.0, 0.0);
    std::vector<Component>::const_iterator it{_component.cbegin()};
    for(; it != _component.cend(); ++ it)
    {
        ret += 1.0 / it->Impedance();
    }
    return 1.0 / ret;
}

#endif