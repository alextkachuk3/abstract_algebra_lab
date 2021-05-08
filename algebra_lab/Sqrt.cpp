class Sqrt {
public:
    int power(int x, int y, int p)
    {
        int res = 1; 
        x = x % p; 
        

        while (y > 0)
        {

        
            if (y & 1)
                res = (res * x) % p;

            
            y = y >> 1; 
            x = (x * x) % p;
        }
        return res;
    }

    
     void squareRoot(int n, int p)
    {
        n = n % p;
        if (p % 4 != 3) {
            for (int x = 2; x < p; x++) {
                if ((x * x) % p == n) {
                    cout << "Square root is " << x;
                    return;
                }
            }
            cout << "Square root doesn't exist";
            return;
        }

        
        
        int x = this->power(n, (p + 1) / 4, p);
        if ((x * x) % p == n) {
            cout << "Square root is " << x;
            return;
        }

        x = p - x;
        if ((x * x) % p == n) {
            cout << "Square root is " << x;
            return;
        }

        cout << "Square root doesn't exist ";
    }
};