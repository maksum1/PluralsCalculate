#ifndef SET_H
#define SET_H
#include"mainwindow.h"
#include<qdebug.h>
class Set
{

public:
    Set()
    {
        qDebug()<<"sadasd";
    }
    Set(size_t Size)
    {
        Plural = new int[Size] ;
        SizePlural=Size;
    }
    ~Set()
    {
        delete[] Plural;
    }

     Set& operator = (const Set &obj);
     Set operator +(const Set &obj)const;
     Set operator -(const Set &obj)const;
     Set operator / (const Set &obj)const;



    void Read(int index, int number);
    bool InludeElement(int element);

    int Power();
    bool HaveElement;
    int MaxElement();
    int MinElement();
    Set DeleteElement(int position);
    int getSizePlural() const;
    int OutPut(int index);
    bool Find(const Set &Arr, int Element );
private:
    int *Plural;
    int SizePlural;

};

#endif // SET_H
