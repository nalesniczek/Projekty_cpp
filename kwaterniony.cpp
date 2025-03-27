#include <iostream>
#include <ostream>
#include <complex>

class Kwaternion{
    private:
        float a, b, c, d;
    public:
        Kwaternion(): a(0), b(0), c(0),d(0){};
        Kwaternion(float a,float b,float c,float d): a(a), b(b), c(c), d(d){};
        
        void print_in_form_Matrix_4x4();
        void print_in_form_Matrix_2x2();


        friend Kwaternion operator*(Kwaternion & H1,Kwaternion & H2);
        friend Kwaternion operator+(Kwaternion & H1,Kwaternion & H2);

        friend std::ostream& operator<<(std::ostream& wyjscie, const Kwaternion& z);

};

void Kwaternion::print_in_form_Matrix_4x4(){
    std::cout 
    << a << " " << -b << " " << -c << " " << -d << "\n"
    << b << " " << a << " " << -d << " " << c << "\n"
    << c << " " << d << " " << a << " " << -b << "\n"
    << d << " " << -c << " " << b << " " << a << "\n";
        
}

//dodawanie kwaterionów
Kwaternion operator+(Kwaternion & H1, Kwaternion & H2){
    Kwaternion HD(H1.a+H2.a, H1.b+H2.b, H1.c+H2.c, H1.c+H2.c);
    return HD;
}

//mnożenie kwaterionów
Kwaternion operator*(Kwaternion & H1, Kwaternion & H2){
    return Kwaternion(
    H1.a * H2.a - H1.b * H2.b - H1.c * H2.c - H1.d * H2.d, //wspol a
    H1.a * H2.b + H1.b * H2.a + H1.c * H2.d - H1.d * H2.c, //wspol b
    H1.a * H2.c + H1.c * H2.a + H1.d * H2.b - H1.b * H2.d, //wspol c
    H1.a * H2.d + H1.d * H2.a + H1.b * H2.c - H1.c * H2.b);//wspol d

}

std::ostream & operator<< (std::ostream &wyjscie, const Kwaternion & z){
    return wyjscie <<  z.a << " + " <<  z.b << "i + " <<  z.c << "j + " <<  z.d << "k"<<"\n";
}

int main() {
    Kwaternion h1(2.0, 4.0, 6.0, 7.0);
    Kwaternion h2(2.0, 7.0, 8.0, 9.0);
    std::cout << h1 << "\n";
    std::cout << h2 << "\n";
    Kwaternion h3 = h1*h2;
    std::cout << h3 << "\n";
    h3.print_in_form_Matrix_4x4();

    return 0;

}