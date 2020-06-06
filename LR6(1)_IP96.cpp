#include <iostream>

using namespace std;

class Cmaster {
public:
    Cmaster() { x = 0; };
    ~Cmaster() {};
    float x;
    virtual float count(float numb)=0;
};

class Ctangents : public Cmaster {
public:
    float count(float numb);
    
private:
    float Barr[21];
    void fillBArr();
    int factorial(int numb);
};

void Ctangents::fillBArr() {
    Barr[0] = 1.0;
    for (int i = 3; i < 20; i = i + 2) {
        if (i % 2 != 0) { Barr[i] = 0; }
    }
    Barr[1] = -0.5;
    Barr[2] = 0.166667;
    Barr[4] = -0.033333;
    Barr[6] = 0.0238095;
    Barr[8] = -0,0333333;
    Barr[10] = 0,075757;
    Barr[12] = -0.253113;
    Barr[14] = 1.166666666;
    Barr[16] = -7.092156862;
    Barr[18] = 54.97117794;
    Barr[20] = -529.1242424;
}

int Ctangents::factorial(int numb) {
    int sum = 1;
    for (int i = 2; i < numb; i++) {
        sum = sum * i;
    }
    return sum;
}

float Ctangents::count(float numb) {
    fillBArr();
    this->x = numb;
    float tan = x;
    for (int i = 2; i < 3; i++) {
       float formul = (Barr[2 * i] * pow(-4, i) * (1 - pow(4, i)) * pow(x, ((2 * i) - 1)))/ factorial(2*i);
        tan = tan + formul;
    }
    return tan;
}

class Carctangents : public Cmaster {
public:
     float  count(float numb);
};

float Carctangents::count(float numb) {
    this->x = numb;
   float arctg = x;
    for (int i = 1; i < 9; i++) {
        int n = 2 * i + 1;
        arctg = arctg + ((pow(-1, i) * pow(x, n)) / n);
    }
  return arctg;
}

int main()
{
    float numb = 1;
    while (numb >= 1 || numb <= -1) {
        printf("%s\n", "Write x data: ");
        cin >> numb;
    }
    
    Cmaster* res;
    res = new Carctangents;
    float n = res->count(numb);
    printf("%s\n", "Arctg is: ");
    cout << n << endl;

    res = new Ctangents;
    n = res->count(numb);
    printf("%s\n", "tang is: ");
    cout << n << endl;
}


