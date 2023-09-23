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
        
        int read() const   
            { return *storedValue; }
        void write( int x )
            { *storedValue = x; }
            
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