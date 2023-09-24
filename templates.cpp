#include <string>
#include <iostream>
/**
 * A class simulating a memory cell
*/

template <typename Object>
class MemoryCell
{
    public:
        explicit MemoryCell( const Object & initialValue = Object{ }) // default parameter is Object with its zero-parameter constructor
            : storedValue{ initialValue }{ }
        const Object & read() const
            { return storedValue; }
        void write( const Object & x )
            { storedValue = x;}    
        
    private:
        Object storedValue;
};

int main(){
    MemoryCell<int> cell_0;
    MemoryCell<std::string> cell{ "hello" };

    cell_0.write( 37 );
    cell.write( cell.read() + " world ");
    std::cout << cell_0.read() << std::endl << cell.read() << std::endl; 
    
    return 0;
}
