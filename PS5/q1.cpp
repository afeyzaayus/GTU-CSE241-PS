#include <iostream>

class Polynomial{
    private:
        double *coef;
        int size;
    public:
        Polynomial();
        Polynomial(const Polynomial &);
        Polynomial(double coefficient[], int size);
        ~Polynomial();

        double &operator[](int degree);
        const double &operator[](int degree) const;
        const Polynomial &operator=(const Polynomial &rhs);
        int mySize();

        friend double evaluate(const Polynomial &ploy, double arg);
        friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);
        friend Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs);
        friend Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);
};


int Polynomial::mySize(){
    return size;
}

Polynomial::Polynomial() : coef(0), size(0){}

const Polynomial &Polynomial::operator=(const Polynomial &rhs){
    if (rhs.coef == coef)
        return rhs;
    else{
        delete[] coef;
        coef = new double[rhs.size];
        for (int i = 0; i < rhs.size; i++)
            coef[i] = rhs.coef[i];
        size = rhs.size;
    }
    return rhs;
}

Polynomial::Polynomial(const Polynomial &rhs) : size(rhs.size){
    coef = new double[rhs.size];
    for (int i = 0; i < rhs.size; i++)
        coef[i] = rhs.coef[i];
}

Polynomial::Polynomial(double coefficient[], int newSize) : size(newSize){
    coef = new double[size];
    for (int i = 0; i < size; i++)
        coef[i] = coefficient[i];
}

Polynomial::~Polynomial(){
    delete[] coef;
}

const double &Polynomial::operator[](int degree) const{
    return coef[degree];
}

double &Polynomial::operator[](int degree){
    return coef[degree];
}

double max(double lhs, double rhs){
    return (lhs > rhs) ? lhs : rhs;
}

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs){
    const int sumSize = max(lhs.size, rhs.size);
    double *sumCoefs = new double[sumSize];

    for (int i = 0; i < sumSize; i++)
        sumCoefs[i] = lhs.coef[i] + rhs.coef[i];

    Polynomial p(sumCoefs, sumSize);
    delete[] sumCoefs;
    return p;
}

Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs){
    int sumSize = max(lhs.size, rhs.size);
    double *sumCoefs = new double[sumSize];

    for (int i = 0; i < sumSize; i++)
        sumCoefs[i] = lhs.coef[i] - rhs.coef[i];

    Polynomial p(sumCoefs, sumSize);
    delete[] sumCoefs;
    return p;
}

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs){
    int prodSize = lhs.size + rhs.size;
    double *prodCoefs = new double[prodSize];

    for (int i = 0; i < prodSize; i++)
        prodCoefs[i] = 0;

    for (int i = 0; i < lhs.size; i++)
        for (int j = 0; j < rhs.size; j++)
            prodCoefs[i + j] += lhs[i] * rhs[j];

    return Polynomial(prodCoefs, prodSize);
}

double evaluate(const Polynomial& poly, double arg){
    double value = 0;
    for(int i = poly.size - 1; i>=0; i--)
        value = poly[i] + arg * value;
    return value;
}


int main()
{
    Polynomial empty;
    double one[] = {1};
    Polynomial One(one, 1);
    double quad[] = {3, 2, 1};
    double cubic[] = {1, 2, 0, 3};
    Polynomial q(quad, 3);
    Polynomial c(cubic, 4);
    Polynomial p = q;
    Polynomial r;
    r = q;
    r = c;

    std::cout << "Polynomial q " << std::endl;
        for (int i = 0; i < 3; i++)
            std::cout << "term with degree " << i << " has coefficient " << q[i] << std::endl;
    std::cout << "Polynomial c " << std::endl;
        for (int i = 0; i < 4; i++)
            std::cout << "term with degree " << i << " has coefficient " << c[i] << std::endl;
    std::cout << "value of q(2) is " << evaluate(q, 2) << std::endl;
    std::cout << "value of p(2) is " << evaluate(p, 2) << std::endl;
    std::cout << "value of r(2) is " << evaluate(r, 2) << std::endl;
    std::cout << "value of c(2) is " << evaluate(c, 2) << std::endl;

    r = q + c;
    std::cout << "value of (q + c)(2) is " << evaluate(r, 2) << std::endl;

    r = q - c;
    std::cout << "value of (q - c)(2) is " << evaluate(r, 2) << std::endl;

    r = q * c;
    std::cout << "size of q*c is " << r.mySize() << std::endl;
    std::cout << "Polynomial r (= q*c) " << std::endl;

    for (int i = 0; i < r.mySize(); i++)
        std::cout << "term with degree " << i << " has coefficient " << r[i] << std::endl;

    std::cout << "value of (q * c)(2) is " << evaluate(r, 2) << std::endl;
    return 0;
}