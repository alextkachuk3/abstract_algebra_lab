namespace Field
{
    // helper functions
    namespace   detail
    {
        // g = a*u + b*v
        int EGCD(int a, int b, int& u, int& v)
        {
            u = 1;
            v = 0;
            int g = a;
            int u1 = 0;
            int v1 = 1;
            int g1 = b;
            while (g1 != 0)
            {
                int q = g / g1; // Integer divide 
                int t1 = u - q * u1;
                int t2 = v - q * v1;
                int t3 = g - q * g1;
                u = u1; v = v1; g = g1;
                u1 = t1; v1 = t2; g1 = t3;
            }

            return g;
        }

        int InvMod(int x, int n) // Solve linear congruence equation x * z == 1 (mod n) for z 
        {
            //n = Abs(n); 
            x = x % n; // % is the remainder function, 0 <= x % n < |n| 
            int u, v, g, z;
            g = EGCD(x, n, u, v);
            if (g != 1)
            {
                // x and n have to be relative prime for there to exist an x^-1 mod n
                z = 0;
            }
            else
            {
                z = u % n;
            }
            return z;
        }
    }

    /*
        An element in a  field FP
        Adapted for the specific behaviour of the "mod" function where (-n) mod m returns a negative number

        The template argument P is the order of the field
    */
    template<int P>
    class   FiniteFieldElement
    {
        int     i_;

        void    assign(int i)
        {
            i_ = i;
            if (i < 0)
            {
                // ensure (-i) mod p correct behaviour
                // the (i%P) term is to ensure that i is in the correct range before normalizing
                i_ = (i % P) + 2 * P;
            }

            i_ %= P;
        }

    public:
        // ctor
        FiniteFieldElement()
            : i_(0)
        {}
        // ctor
        explicit FiniteFieldElement(int i)
        {
            assign(i);
        }
        // copy ctor
        FiniteFieldElement(const FiniteFieldElement<P>& rhs)
            : i_(rhs.i_)
        {
        }

        // access "raw" integer
        int i() const { return i_; }
        // negate
        FiniteFieldElement  operator-() const
        {
            return FiniteFieldElement(-i_);
        }
        // assign from integer
        FiniteFieldElement& operator=(int i)
        {
            assign(i);
            return *this;
        }
        // assign from field element
        FiniteFieldElement<P>& operator=(const FiniteFieldElement<P>& rhs)
        {
            i_ = rhs.i_;
            return *this;
        }
        // *=
        FiniteFieldElement<P>& operator*=(const FiniteFieldElement<P>& rhs)
        {
            i_ = (i_ * rhs.i_) % P;
            return *this;
        }
        // ==
        friend bool    operator==(const FiniteFieldElement<P>& lhs, const FiniteFieldElement<P>& rhs)
        {
            return (lhs.i_ == rhs.i_);
        }
        // == int
        friend bool    operator==(const FiniteFieldElement<P>& lhs, int rhs)
        {
            return (lhs.i_ == rhs);
        }
        // !=
        friend bool    operator!=(const FiniteFieldElement<P>& lhs, int rhs)
        {
            return (lhs.i_ != rhs);
        }

        // ostream handler
        template<int T>
        friend  ostream& operator<<(ostream& os, const FiniteFieldElement<T>& g)
        {
            return os << g.i_;
        }
    };
}



