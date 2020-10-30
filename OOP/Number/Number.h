class Number
{
private:
    double data;

public:
    Number(double = 1.1);
    ~Number();
    operator int();
    operator double();
};