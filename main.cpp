#include <iostream>
#include "PQueue.h"
// ! !!!! la supraincarcarea operatorului << se aplica functia delete_queue care elimina elementele din coada
int main() {
    PQueue a, p, d,e;

//"Introduceti n elemnte  elemente pentru prima coada ,prima data prioritatea apoi valoarea pentru fiecare element: "
    for (int i = 0; i < 3; i++)
        cin >> a;

//"Introduceti elementele pentru a doua coada: "
    for (int i = 0; i < 3; i++)
       cin >> p;




//fuziunea cozii a si p
    d=a+p;
    int j=d.nr_elemente();
    e=d;//copie dupa afisare se pierd valorile din d
    for (int i = 0; i < j; i++)
        cout << d << endl;
d=e;
      d=d-e;
cout<<endl<<endl;
      j=d.nr_elemente();
e=d;
//prima coada dupa scaderea prioritatii cu 1
     for (int i = 0; i <j; i++)
           cout << d << endl;

       cout << endl;


//prioritatea creste cu 1 la toate elementele din coada
    ++e;
    d=e;
    cout << endl;
     j=d.nr_elemente();
    for (int i = 0; i < j; i++)
        cout << d << endl;
d=e;
    cout << endl << d.priority_max()<<" "<< d.val_max();

    //extrageam elementul cu prioritatea cea mai mare din coada
    d.delete_queue();

    cout << endl << d.priority_max() << " "<< d.val_max();




    return 0;
}