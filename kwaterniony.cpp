#include <iostream>
#include <ostream>
/*
 Dzien dobry, 
 generalnie wkurwia mnie tutaj kilka rzeczy wiec sugeruje swoje poprawki w tym kodzie, Który uważam za wybitny ale za duzo jest tu napisane a ja mam autyzm i sie przestymulowywuje. 

 1. usunałem wszystkie get itd, ja nawet nie wiem jak to wczesniej działało bo nie rozumiem totalnie, ciaglłe odwoływanie sie do get i set jest mylące i nadprogramowe IMO. 
 2. dodałem skibidi() do pokazywania kwaternionu by nie dodawać operatora << bo po do skoro mozna fresh zrobić. ale rozumiem idee, 
 3. zrobiłem jednostkowy kwaternion `jednostkowy()`, by sprawdzić sobie czy działa, ale zostawie ci. 
 4.  wyciszylem float kwa_matrix().
 5. no i oczywiscie zmieniłem klase na pisaną dużą literą. 

A więc teraz klasa działa tak. 

a) 
const Kwaternion foo(1,2,3,4); 
// wewnatrz klasy uruchamia sie i ustawia wszystkie wartosci na podane
// a,b,c,d = 1,2,3,4 < - podstawia takie coś w miejsca poprzednich zer patrz.  referencja_1
// i to juz tyle, potem poprostu mozesz robić rzeczy, robienie tych get i set było boring. 
 */
class Kwaternion{
    private:
        float a, b, c, d;
    public:
      // I TERAZ MASZ JUZ KWATERION KTÓRY jak jest tworzony i dajesz mu jakies wartosci abcd 
      // to on je ma i nie trzeba sie bawic w settery i gettery. Szczerze mówiać ja nawet nie wiem jak uzywać set i get dlatego to zmieniam.
      Kwaternion(): a(0), b(0),c(0),d(0){};//ustawia defaultowe wartosci   referencja_1
  //zmienia defaultowe wartosci na te podane 
      Kwaternion(float a,float b,float c,float d): a(a), b(b), c(c), d(d){};

         // float kwa_matrix(); // wykomentowałem to bo narazie nie uzywane.

        //funkcja dodana do robienia poważnych rzeczy a nie get
        //get some bitches better a nie ciagle get get get/ 
  

      void skibidi() const {
        std::cout << a << " + " << b << "i + " << c << "j + " << d << "k" << std::endl;
      }
      //pa jakie fajne
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
        // zobacz ze wyzej zrobiłem operator kwaternionu juz jako friend   
        //friend kwaternion operator*(kwaternion & H1,kwaternion & H2);
        //friend kwaternion operator+(kwaternion & H1,kwaternion & H2);

};


int main() {
    Kwaternion h1(2.0, 4.0, 6.0, 7.0);
    Kwaternion h2(2.0, 7.0, 8.0, 9.0);
    //std::cout << h1 << "\n";
    //std::cout << h2 << "\n";
    Kwaternion h3 = h1*h2;
    //std::cout << h3 << "\n";
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
