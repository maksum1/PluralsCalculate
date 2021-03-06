﻿#include "set.h"
#include<qdebug.h>

bool Set::inlude( int Element)
{
    for(int i =0;i<SizePlural;i++)
    {
        if(this->Plural[i]==Element)
        {
            return true;
        }
    }
    return false;
}

void Set::Add( int Element)
{
    if(!this->inlude(Element))
    {
        int NewSize = this->getSizePlural() + 1;
        int *Temp=new int[NewSize];//Тимчасовий масив (більший на 1)

        for(int i =0;i<this->getSizePlural();i++)
        {
            Temp[i]=this->Plural[i];//Присвоюєм значення з множини
        }

        Temp[this->getSizePlural()]=Element;//Присвоюєм передани елемент в кінецьь масиву

        if(this->getSizePlural())
        free(this->Plural);//звільняєм память


        this->setSizePlural(NewSize);//збільшуєм розмір множини на 1


        this->Plural=Temp;
        for (int i = 0 ; i< this->getSizePlural();i++)
            qDebug()<<Temp[i];


    }

}

void Set::Delete(int Element)
{
    if(this->inlude(Element))
    {
        int *Temp=new int[SizePlural-1];//Тимчасовий масив менший на 1
        int Position;//позиція елемента який будем видаляти

        for(int i =0 ; i<SizePlural;i++)
        {
            if(this->Plural[i]==Element)
                Position=i;//шукаєм елемент
        }
        for(int i =0 ; i<Position;i++)
        {
            Temp[i]=this->Plural[i];//присвоюєм усі крім нього
        }

        for(int i = Position;i < SizePlural - 1;i++)
        {
            Temp[i]=this->Plural[i+1];//присвоюєм усі крім нього/
        }

        if(this->getSizePlural())
        free(this->Plural);//видаляєм старий

        SizePlural--;//Розмір на 1 менше

        this->Plural = Temp;
    }


}

int Set::Max()
{
    return *std::max_element(this->Plural , this->Plural + this->getSizePlural());

}

int Set::Min()
{
    return *std::min_element( this->Plural , this->Plural+this->SizePlural);
}

int Set::At(int position) const
{
    return this->Plural[position];
}

Set& Set::operator =(const Set &obj)
{

    if(this->getSizePlural())
    free(this->Plural);

    this->setSizePlural(obj.getSizePlural());

    this->Plural=new int[this->getSizePlural()];

    for(int i = 0 ; i <this->getSizePlural();i++)
    {
        this->Plural[i]=obj.Plural[i];
    }

    return *this;



}

const Set Set::operator +(const Set &obj)
{
    Set Adding;
    for(int i = 0 ; i<this->getSizePlural();i++)
    {
        Adding.Add(Plural[i]);    //переприсвоюєм 1 множину
    }

    for(int i = 0; i < obj.getSizePlural();i++ )
    {
        if(!Adding.inlude(obj.At(i)))//якщо обєкта немає
        {
            Adding.Add(obj.At(i));
        }
    }


    return Adding;
}

const Set Set::operator -(const Set &obj)
{
    Set Minus;


    for(int i = 0 ; i<obj.getSizePlural();i++)
    {
        if(this->inlude(obj.At(i)))
        {
            Minus.Add(Plural[i]);
        }
    }


    return Minus;

}

const Set  Set::operator /(const Set &obj)
{
    Set Without;

    for(int i = 0 ; i < this->getSizePlural(); i++)
    {
        Without.Add( this->Plural[i] );
    }

    for(int i = 0 ;i<obj.getSizePlural();i++)
    {
        if(Without.inlude(obj.Plural[i]))
        {
            Without.Delete(obj.Plural[i]);
        }
    }
    return Without;

}

int Set::getSizePlural() const
{
    return SizePlural;
}

void Set::setSizePlural(int value)
{
    SizePlural = value;
}

