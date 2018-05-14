#ifndef SET_H
#define SET_H
#include<qdebug.h>
#include<QVector>

class Set
{

public:
    Set(Set &obj)
    {
        SizePlural=obj.getSizePlural();
        if(this->getSizePlural())
        free(this->Plural);
        this->Plural=new int [obj.getSizePlural()];
        for(int i = 0 ;i<obj.getSizePlural();i++)
        {
            this->Plural[i]=obj.Plural[i];
        }

    }
    Set()
    {
     SizePlural=0;

    }
    Set(size_t Size)
    {
        Plural = new int[Size] ;
        SizePlural=Size;
    }
    ~Set()
    {
        if(this->getSizePlural())
        free (Plural);
    }

    bool inlude(int Element);
    void Add(int Element);
    void Delete(int Element);
    int Max();
    int Min();
    int At(int position) const;

Set &operator =(Set const &obj);
const Set operator +(const Set &obj);
const Set operator -(const Set &obj);
const Set operator / (const Set &obj);



    int getSizePlural() const ;

    void setSizePlural(int value);
    int *Plural;
private:

    int SizePlural;
};

#endif // SET_H
