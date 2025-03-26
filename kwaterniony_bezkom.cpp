#include <iostream>
#include <ostream>
class Kwaternion{
    private:
        float a, b, c, d;
    public:
    Kwaternion(): a(0), b(0),c(0),d(0){};
    Kwaternion(float a,float b,float c,float d): a(a), b(b), c(c), d(d){};
      void skibidi() const {
        std::cout << a << " + " << b << "i + " << c << "j + " << d << "k" << std::endl;
      }
            static Kwaternion jednostkowy(){
        return Kwaternion(1, 0, 0, 0);
      }
      friend Kwaternion operator+(const Kwaternion& H1, const Kwaternion& H2) {
        return Kwaternion(
            H1.a + H2.a,
            H1.b + H2.b,
            H1.c + H2.c,
            H1.d + H2.d
        );
    }

    friend Kwaternion operator*(const Kwaternion& H1, const Kwaternion& H2) {
        return Kwaternion(
            H1.a * H2.a - H1.b * H2.b - H1.c * H2.c - H1.d * H2.d,
            H1.a * H2.b + H1.b * H2.a + H1.c * H2.d - H1.d * H2.c,
            H1.a * H2.c + H1.c * H2.a + H1.d * H2.b - H1.b * H2.d,
            H1.a * H2.d + H1.d * H2.a + H1.b * H2.c - H1.c * H2.b
        );
    }
};


int main() {
    Kwaternion h1(2.0, 4.0, 6.0, 7.0);
    Kwaternion h2(2.0, 7.0, 8.0, 9.0);
    Kwaternion h3 = h1*h2;
    h1.skibidi(); 
    h2.skibidi();
    std::cout<<"Wynik mnozenia: ";
    h3.skibidi();
    Kwaternion defaultowy = Kwaternion::jednostkowy();  
    std::cout<<"Jednostkowy: ";
    defaultowy.skibidi();
    std::cout << "Mam dosc windowsa";
    return 0;
}
