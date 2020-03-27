//
// Created by Maciej Ciura on 14.03.2020.
//

#ifndef SDIZO_LISTA_H
#define SDIZO_LISTA_H

struct ListEl{
    int data;
    ListEl *next, *prev;
};

class Lista{

public:

private:
    ListEl *head, *tail;
    int size;

public:
    Lista();
    ~Lista();
    void pushFront(int value);
    void pushBack(int value);
    void popFront();
    void popBack();
    void pushAny(int value, int pos);
    void popAny(int pos);
    int getSize();


    ListEl *operator [] (int el){
        ListEl *temp = head;
        if(el<size)
        {
            for(int i=0;i<el;i++)
            {
                temp = temp->next;
            }
        return temp;
        }
        else{
            std::cout<<"Nie ma takiego indeksu!"<<std::endl;
        }
    }


    bool checkIfPresent(int i);

    void print();
};

#endif //SDIZO_LISTA_H
