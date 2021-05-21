#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#include <math.h>
#include "FiniteFieldElement.hpp"

namespace Field
{
    /*
        Elliptic Curve over a finite field of order P:
        y^2 mod P = x^3 + ax + b mod P

        Template parameter P is the order of the finite field Fp over which this curve is defined
    */
    template<int P>
    class   EllipticCurve
    {
    public:
        typedef FiniteFieldElement<P> ffe_t;

        class   Point  // a point, or group element, on the EC, consisting of two elements of the field Fp

        {
            friend  class   EllipticCurve<P>;
            typedef FiniteFieldElement<P> ffe_t;
            ffe_t  x_;
            ffe_t  y_;
            EllipticCurve* ec_;

            // adding two points on the curve
            void    add(ffe_t x1, ffe_t y1, ffe_t x2, ffe_t y2, ffe_t& xR, ffe_t& yR) const
            {
                // special cases involving the additive identity                     
                if (x1 == 0 && y1 == 0)
                {
                    xR = x2;
                    yR = y2;
                    return;
                }
                if (x2 == 0 && y2 == 0)
                {
                    xR = x1;
                    yR = y1;
                    return;
                }
                if (y1 == -y2)
                {
                    xR = yR = 0;
                    return;
                }

            }

            Point(int x, int y)
                : x_(x),
                y_(y),
                ec_(0)
            {}

            Point(int x, int y, EllipticCurve<P>& EllipticCurve)
                : x_(x),
                y_(y),
                ec_(&EllipticCurve)
            {}

            Point(const ffe_t& x, const ffe_t& y, EllipticCurve<P>& EllipticCurve)
                : x_(x),
                y_(y),
                ec_(&EllipticCurve)
            {}

        public:
            static  Point   ONE;

            Point(const Point& rhs)
            {
                x_ = rhs.x_;
                y_ = rhs.y_;
                ec_ = rhs.ec_;
            }

            Point& operator=(const Point& rhs)
            {
                x_ = rhs.x_;
                y_ = rhs.y_;
                ec_ = rhs.ec_;
                return *this;
            }
            // access x component as element of Fp
            ffe_t x() const { return x_; }
            // access y component as element of Fp
            ffe_t y() const { return y_; }
            // calculate the order of this point

            unsigned int Order(unsigned int maxPeriod = ~0) const
            {
                Point r = *this;
                unsigned int n = 0;
                while (r.x_ != 0 && r.y_ != 0)
                {
                    ++n;
                    r += *this;
                    if (n > maxPeriod) break;
                }
                return n;
            }

            // -
            Point   operator-()
            {
                return Point(x_, -y_);
            }
            // ==
            friend bool operator==(const Point& lhs, const Point& rhs)
            {
                return (lhs.ec_ == rhs.ec_) && (lhs.x_ == rhs.x_) && (lhs.y_ == rhs.y_);
            }
            // !=
            friend bool operator!=(const Point& lhs, const Point& rhs)
            {
                return (lhs.ec_ != rhs.ec_) || (lhs.x_ != rhs.x_) || (lhs.y_ != rhs.y_);
            }

        };

        // EllipticCurve implementation
        typedef EllipticCurve<P> this_t;

        // Initialize EC as y^2 = x^3 + ax + b
        EllipticCurve(int a, int b)
            : a_(a),
            b_(b),
            m_table_(),
            table_filled_(false)
        {
        }
        // Calculate all the points (group elements) for this EC
        void    CalculatePoints()
        {
            int x_val[P];
            int y_val[P];
            for (int n = 0; n < P; ++n)
            {
                int nsq = n * n;
                x_val[n] = ((n * nsq) + a_.i() * n + b_.i()) % P;
                y_val[n] = nsq % P;
            }

            for (int n = 0; n < P; ++n)
            {
                for (int m = 0; m < P; ++m)
                {
                    if (x_val[n] == y_val[m])
                    {
                        m_table_.push_back(Point(n, m, *this));
                    }
                }
            }

            table_filled_ = true;
        }
        // get a point (group element) on the curve 
        Point   operator[](int n)
        {
            if (!table_filled_)
            {
                CalculatePoints();
            }

            return m_table_[n];
        }
        // number of elements in this group
        size_t  Size() const { return m_table_.size(); }
        // the degree P of this EC
        int     Degree() const { return P; }
        // the parameter a (as an element of Fp)
        FiniteFieldElement<P>  a() const { return a_; }
        // the paramter b (as an element of Fp)
        FiniteFieldElement<P>  b() const { return b_; }

        // ostream handler: print this curve in readable form
        template<int T>
        friend ostream& operator <<(ostream& os, const EllipticCurve<T>& EllipticCurve);
        // print all the elements of the EC group
        ostream& PrintTable(ostream& os, int columns = 4);

    private:
        typedef std::vector<Point>  m_table_t;

        m_table_t                   m_table_;   // table of points
        FiniteFieldElement<P>       a_;         // parameter a of the EC equation
        FiniteFieldElement<P>       b_;         // parameter b of the EC equation
        bool    table_filled_;                  // true if the table has been calculated
    };

    template<int T>
    typename EllipticCurve<T>::Point EllipticCurve<T>::Point::ONE(0, 0);

    template<int T>
    ostream& operator <<(ostream& os, const EllipticCurve<T>& EllipticCurve)
    {
        os << "y^2 mod " << T << " = (x^3" << showpos;
        if (EllipticCurve.a_ != 0)
        {
            os << EllipticCurve.a_ << "x";
        }

        if (EllipticCurve.b_.i() != 0)
        {
            os << EllipticCurve.b_;
        }

        os << noshowpos << ") mod " << T;
        return os;
    }

    template<int P>
    ostream& EllipticCurve<P>::PrintTable(ostream& os, int columns)
    {
        if (table_filled_)
        {
            int col = 0;
            typename EllipticCurve<P>::m_table_t::iterator iter = m_table_.begin();
            for (; iter != m_table_.end(); ++iter)
            {
                os << "(" << (*iter).x_.i() << ", " << (*iter).y_.i() << ") ";
                if (++col > columns)
                {
                    os << "\n";
                    col = 0;
                }
            }
        }
        else
        {
            os << "EllipticCurve, F_" << P;
        }
        return os;
    }
}

using namespace Field;

int main(int argc, char* argv[])
{
    typedef EllipticCurve<16> ec_t;
    ec_t   myEllipticCurve(1, 1);

    myEllipticCurve.CalculatePoints();

    cout << endl
        << "Points on the curve (the group elements):"
        << endl;
    myEllipticCurve.PrintTable(cout, 5);
    cout << endl << endl
        << "The order of the group is " << myEllipticCurve.Size() + 1
        << endl << endl;

    system("pause");
    return 0;
}