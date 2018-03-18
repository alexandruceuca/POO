//
// Created by Alex on 3/12/2018.
//

#include "PQueue.h"


PQueue::PQueue() {
    //constructor
    array = new Heap[1];
    queue_size = 0;
}

PQueue::PQueue(int queue_siez) {
    array = new Heap[queue_siez];
    queue_size = queue_siez;
}


PQueue::PQueue(const PQueue &q) {
    //copy constructor

    queue_size = q.queue_size;
    val_maxi = q.val_maxi;
    array = new Heap[queue_size];

    for (int i = 0; i < queue_size; i++) {
        array[i].priority = q.array[i].priority;
        array[i].val = q.array[i].val;
    }
}


PQueue::~PQueue() {
    //destructor
    delete[]array;
}

void PQueue::insert_queue(int priority, int val) {
//heap ul va fi construit in functie de prioritate,radacina va avea cea mai mare prioritate
// cum vectorul incepe de pe pozitia 0 ,tatal unui nod i este pe pozitia (i-1)/2
    //fiul stang al unui nod i este pe pozitia 2*i+1
    //fiul drept al unui nod i este pe pozitia 2*i+2

    Heap *tmp1;
    tmp1 = new Heap[queue_size + 1];

    for (int i = 0; i < queue_size; i++) {//realoc memorie pentru vecoturl cu o unitate in plus
        tmp1[i].priority = array[i].priority;
        tmp1[i].val = array[i].val;
    }

    delete[]array;
    array = tmp1;

    array[queue_size].priority = priority;
    array[queue_size].val = val;
    queue_size++;

    if (val_maxi < val)
        val_maxi = val;

    int i = queue_size -1;
    while (i != 0 && (array[(i - 1) / 2].priority < array[i].priority)) {//se reactualizeaza heap ul
        Heap tmp{};
        tmp = array[i];
        array[i] = array[(i - 1) / 2];
        array[(i - 1) / 2] = tmp;

        i = (i - 1) / 2;
    }
}


void PQueue::delete_queue() {

    //schimb radacina cu nodul cel mai din dreapta
    //

    if (queue_size == 1)// cand coada mai are un singur element
    {
        delete[]array;
        queue_size = 0;
        return;
    }

    Heap tmp{};
    tmp = array[0];
    val_maxi=0;
    array[0] = array[queue_size - 1];
    queue_size = queue_size - 1;

//left child 2*i+1
// right child 2*i+2
    int i = 0;


    while ((array[0].priority < array[2 * i + 1].priority) || (array[0].priority < array[2 * i + 2].priority)) {
        Heap tmp1{};
        //aleg fiul mai mare dintre cei doi
        if (array[2 * i + 1].priority >
            array[2 * i + 2].priority)  //daca fiul stang este mai mare de cat fiul drept il schimb cu radacina
        {
            tmp1 = array[0];
            array[0] = array[2 * i + 1];
            array[2 * i + 1] = tmp1;
            i = 2 * i + 1;

        } else {//daca fiul drept este mai mare
            tmp1 = array[0];
            array[0] = array[2 * i + 2];
            array[2 * i + 2] = tmp1;
            i = 2 * i + 2;


        }

    }


    Heap *tmp2;
    tmp2 = new Heap[queue_size];

    for (int i = 0; i < queue_size; i++) {//realoc memorie pentru vecoturl cu o unitate in minus
        tmp2[i].priority = array[i].priority;
        tmp2[i].val = array[i].val;
        if(val_maxi<array[i].val)
            val_maxi=array[i].val;//reactulizez valoarea maxima din coada
    }

    delete[]array;
    array = tmp2;


}


int PQueue::priority_max() {
//elementul cu prioritate maxima este chiar radacina
    return array[0].priority;
}

int PQueue::val_max() {

    return val_maxi;
}


int PQueue::nr_elemente() {
//numarul de elemente din coada este variabila queue_size deoarece cand se adauga un elemnt nou in lista variabila creste cu 1 si cand se elimina un element scade cu 1
    return queue_size;
}

PQueue &PQueue::operator++() {

    for (int i = 0; i <queue_size; i++)
        array[i].priority = array[i].priority + 1;
}

PQueue &PQueue:: operator+(const PQueue &que) {
    PQueue *tmp;
tmp=new PQueue;
    for (int i = 0; i < que.queue_size; i++)
        tmp->insert_queue(que.array[i].priority, que.array[i].val);

    for (int i = 0; i < this->queue_size; i++)
        tmp->insert_queue(this->array[i].priority,this->array[i].val);

    return *tmp;
}


PQueue &PQueue::operator-(const PQueue &q) {
//scad prioritatea elementelor din coada
PQueue *tmp;
    tmp=new PQueue;

    for(int i=0;i<queue_size;i++)
    {
        array[i].priority=array[i].priority-1;
        if(array[i].priority!=0)
            tmp->insert_queue(array[i].priority,array[i].val);
    }
  return *tmp;
}


PQueue &PQueue::operator=(const PQueue &q) {

    delete[]array;
    queue_size = q.queue_size;
    val_maxi = q.val_maxi;
    array = new Heap[queue_size];

    for (int i = 0; i < queue_size; i++) {
        array[i].priority = q.array[i].priority;
        array[i].val = q.array[i].val;
    }

    return *this;
}


ostream &operator<<(ostream &out, PQueue &q) {

    out << q.array[0].priority << " " << q.array[0].val;
    q.delete_queue();

    return out;

}


istream &operator>>(istream &in, PQueue &q) {
//citest prioritatea si valoare si le adaug in coada
    int priority, val;
    in >> priority >> val;
    q.insert_queue(priority, val);

    return in;
}