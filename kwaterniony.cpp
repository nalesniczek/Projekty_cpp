#include <iostream>
#include <ostream>

class kwaternion{
    private:
        float a, b, c, d;
    public:
        kwaternion();
        kwaternion(float,float,float,float);
        float kwa_matrix();

        float get_a();
        float get_b();
        float get_c();
        float get_d();

        void set_a(float);
        void set_b(float);
        void set_c(float);
        void set_d(float);

        friend kwaternion operator*(kwaternion & H1,kwaternion & H2);
        friend kwaternion operator+(kwaternion & H1,kwaternion & H2);


};

kwaternion::kwaternion(float x,float y,float z,float t){
    a = x;
    b = y;
    c = z;
    d = t;
}

kwaternion::kwaternion(){
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}

float kwaternion::get_a(){
    return a;
}

float kwaternion::get_b(){
    return b;
}

float kwaternion::get_c(){
    return c;
}

float kwaternion::get_d(){
    return d;
}

void kwaternion::set_a(float x){
    a = x;
}

void kwaternion::set_b(float x){
    b = x;
}

void kwaternion::set_c(float x){
    c = x;
}

void kwaternion::set_d(float x){
    d = x;
}


//dodawanie kwaterionów
kwaternion operator+(kwaternion & H1, kwaternion & H2){
    kwaternion HD(H1.a+H2.a, H1.b+H2.b, H1.c+H2.c, H1.c+H2.c);
    return HD;
}

//mnożenie kwaterionów
kwaternion operator*(kwaternion & H1, kwaternion & H2){
    kwaternion HD;
    HD.set_a(H1.a * H2.a - H1.b * H2.b - H1.c * H2.c - H1.d * H2.d);
    HD.set_b(H1.a * H2.b + H1.b * H2.a + H1.c * H2.d - H1.d * H2.c);
    HD.set_c(H1.a * H2.c + H1.c * H2.a + H1.d * H2.b - H1.b * H2.d);
    HD.set_d(H1.a * H2.d + H1.d * H2.a + H1.b * H2.c - H1.c * H2.b);
    return HD;
}

std::ostream & operator<< (std::ostream &wyjscie, kwaternion z){
    return wyjscie <<  z.get_a() << " + " <<  z.get_b() << "i + " <<  z.get_c() << "j + " <<  z.get_d() << "k"<<"\n";
}

int main() {
    kwaternion h1(2.0, 4.0, 6.0, 7.0);
    kwaternion h2(2.0, 7.0, 8.0, 9.0);
    std::cout << h1 << "\n";
    std::cout << h2 << "\n";
    kwaternion h3 = h1*h2;
    std::cout << h3 << "\n";


    std::cout << "Mam dosc windowsa";
    return 0;

}