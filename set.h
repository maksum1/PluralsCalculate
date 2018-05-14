#ifndef SET_H
#define SET_H
#include<qdebug.h>
#include<QVector>

class Set
{

public:
    Set(const Set &obj)
    {
        SizePlural=obj.getSizePlural();
        free(this->Plural);
        this->Plural=new int [obj.getSizePlural()];
        for(int i = 0 ;i<obj.getSizePlural();i++)
        {
            this->Plural[i]=obj.Plural[i];
        }

    }
    Set()
    {

        Plural=nullptr;
    }
    Set(size_t Size)
    {
        Plural = new int[Size] ;
        SizePlural=Size;
    }
    ~Set()
    {
        free (Plural);
    }

    bool inlude(int Element);
    void Add(int Element);
    void Delete(int Element);
    int Max();
    int Min();
    int At(int position);

    Set& operator = (const Set &obj);
    Set operator +(const Set &obj)const;
    Set operator -(const Set &obj)const;
    Set operator / (const Set &obj)const;



    int getSizePlural() const;

    void setSizePlural(int value);

private:
    int *Plural;
    int SizePlural;
};

#endif // SET_H
