
//
// Created by Maciej Ciura on 14.03.2020.
//
#include<iostream>
#include "Lista.h"

using namespace std;

Lista::Lista() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Lista::~Lista() {
    for (int i=0; i<size; i++)
    {
        ListEl *temp = head->next;
        delete head;
        head=temp;
    }
}

void Lista::pushFront(int value) {
    if(head == nullptr)
    {
        head = new ListEl();
        head->data = value;
        tail = head;
    }
    else
    {
        auto *newHead = new ListEl();
        newHead->data = value;
        newHead->next = head;
        newHead->prev = nullptr;
        head->prev = newHead;
        head = newHead;
    }
    size++;
}

void Lista::pushBack(int value) {
    if(head == nullptr)
    {
        head = new ListEl();
        tail = head;
    }
    else
    {
        auto *newTail = new ListEl;
        newTail->data = value;
        newTail->prev = tail;
        newTail->next = nullptr;
        tail->next = newTail;
        tail = newTail;

    }
    size++;
}

void Lista::popFront() {

    if (size > 1) {
        head->next->prev= nullptr;
        head = head->next;
    } else {
        head = nullptr;
        tail = nullptr;
    }
    size--;
}

void Lista::popBack() {
    if (size > 1) {
        tail->prev->next= nullptr;
        tail = tail-> prev;
    } else {
        head = nullptr;
        tail = nullptr;
    }
    size--;

}

void Lista::pushAny(int value, int pos) {

    if(pos < 0 || pos > size)
    {
        std::cout<<"Nie ma takiego indeksu!";
        return;
    }
    if(pos == 0)
    {
        this->pushFront(value);
        return;
    }
    if(pos == size)
    {
        this->pushBack(value);
        return;
    }

    ListEl *temp;

    if(pos < size /2)
    {
        temp = head;
        for(int i=0; i < pos; i++)
        {
            temp = temp->next;
        }
    } else
    {
        temp = tail;
        for(int i= 0 ; i < getSize() - pos - 1; i++)
        {
            temp = temp->prev;
        }
    }

    auto *newElem = new ListEl();
    newElem->next = temp;
    newElem->prev = temp->prev;
    newElem->data = value;
    temp->prev->next = newElem;
    temp->prev = newElem;

}

void Lista::popAny(int pos) {
    if(pos < 0 || pos >= size)
    {
        std::cout<<"Nie ma takiego indeksu!";
        return;
    }
    if(pos == 0)
    {
        this->popFront();
        return;
    }
    if(pos == size-1)
    {
        this->popBack();
        return;
    }
    ListEl * temp;

    if(pos < size /2)
    {
        temp = head;
        for(int i=0; i < pos; i++)
            temp = temp->next;
    } else
    {
        temp = tail;
        for(int i=0; i < getSize() - pos - 1; i++)
            temp = temp->prev;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    size--;
}

int Lista::getSize()
{
    return this->size;
}

int Lista::checkIfPresent(int value) {
    //JeĹĽeli lista jest pusta, zwrĂłÄ‡ false z automatu
    if (size == 0) {
        return -1;

    }
    ListEl *newHead;
    //Przypisa pierwszy element jako aktualny
    newHead = head;

    //Przeszukaj listÄ™ pod kÄ…tem wartoĹ›ci
    for (int i = 0; i < size; i++) {
        if (newHead->data == value) {
            return i;
        }

        newHead = newHead->next;
    }

    //JeĹĽeli wartoĹ›Ä‡ nie wystÄ…piĹ‚a w ĹĽadnej iteracji listy zwrĂłÄ‡ false
    return -1;
}

void Lista::print() {
//Ustaw jako akutualny element pierwszy element listy

    cout << "Aktualny stan listy:" << endl;
    ListEl *newHead = head;

    if (size == 0)
        cout << "Lista nie zawiera zadnego elementu." << endl;

    for (int i = 0; i < size; i++) {

        cout << "{" << newHead->data << "} ";

        //Przypisz kolejny element listy jako aktualny
        newHead = newHead->next;

    }
}





