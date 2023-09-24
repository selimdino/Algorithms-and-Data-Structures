#include <iostream>
#include <vector>

template <typename Comparable>
const Comparable & findMax( const std::vector<Comparable> & a )
{
    int maxIndex = 0;

    for( int i = 1; i < a.size( ); ++i)
        if( a[ maxIndex ] < a[ i ])
            maxIndex = i;
    return a[ maxIndex ];
}

class Square
{
    public:
        explicit Square( double s = 0.0 ) : side{ s }
        { }

        double getSide() const
        { return side; } 
        double getArea() const
        { return side*side; }
        double getPerimeter() const
        { return 4 * side; }

        void print( std::ostream & out = std::cout ) const // if you not provide ostream object, will refer to cout by default
        { out << "(square" << getSide( ) << ")"; }
        bool operator< ( const Square & rhs ) const 
        { return getSide() < rhs.getSide(); }
    
    private:
        double side;
};

std::ostream & operator<< ( std::ostream & out, const Square & rhs )
{
    rhs.print( out );
    return out;
}

int main()
{
    std::vector<Square> v = { Square{ 3.0 }, Square{ 2.0 }, Square{ 2.5 } };
    std::cout << "Largest Square" << findMax( v ) << std::endl;

}

