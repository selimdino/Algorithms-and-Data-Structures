#include <vector>
#include <iostream>
#include <string>

//Swapping larger copies come with significant cost, there is no need for copies
//Instead we do moves instead of copies
//We can do moving if values on right-hand side are rvalues, and if vector<string> supports moving, but x, y and tmp are lvalues
//std::move convers a lvalue into rvalue, it makes a value subject to be moved

/*
// Swapping with TypeCast
void swap( vector<string> & x, vector<string> & y){
    vector<string> tmp = static_cast<vector<string>> &&>( x );
    x = static_cast<vector<string>> &&>( y );
    y = static_cast<vector<string>> &&>( tmp );
}
*/
// Swapping by Three Copies

void swap( std::vector<std::string> & x, std::vector<std::string> & y){
    std::vector<std::string> tmp = std::move( x );
    x = std::move( y );
    y = std::move( tmp );
}

class IntCell{
    public:
        explicit IntCell(int  initialValue = 0)
            { storedValue = new int { initialValue }; }
        
        ~IntCell( )
        { delete storedValue; }                                                 // Destructor
        
        IntCell( const IntCell & rhs) // takes another IntCell object as a input, the const ensures that 'rhs' is not modified inside the copy constructor
        { storedValue = new int{ *rhs.storedValue };}                           // Copy constructor

        IntCell( IntCell && rhs ) : storedValue{ rhs.storedValue }              // Move constructor
            { rhs.storedValue = nullptr; }
        
        IntCell & operator= ( const IntCell & rhs )                             // Copy assignment
        {
            if ( this != &rhs )    // avoid self-assignment
                *storedValue = *rhs.storedValue; // performing a deep copy
            return *this;
        }

        IntCell & operator= ( IntCell && rhs )                                 // Move assignment
        {
            std::swap(storedValue, rhs.storedValue);
            return *this;
        }


        int read() const   
            { return *storedValue; }
        void write( int x )
            { *storedValue = x; }
        
        // If swap is implemented using basic copy algorithm, the copy-and-swap idiom would not work, because there would be non-terminating recursion
        IntCell & operator= (const IntCell & rhs)
        {
            IntCell copy = rhs; // Places a copy of rhs into copy using the copy constructor
            std::swap( *this, copy ); // Copy is swapped into *this, placing the old contents into copy
            return *this;
        }
            
    private:
        int *storedValue;
};

int f()
{
    IntCell a{ 2 };
    IntCell b = a;
    IntCell c;

    c = b;
    a.write( 4 );
    std::cout << a.read( ) << std::endl << b.read( ) << std::endl << c.read( ) << std::endl;
    return 0;
}

int main() {
    f();
}