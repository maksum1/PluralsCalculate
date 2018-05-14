#include "set.h"
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
        int *Temp=new int[SizePlural+1];//Тимчасовий масив (більший на 1)

        for(int i =0;i<SizePlural;i++)
        {
            Temp[i]=this->Plural[i];//Присвоюєм значення з множини
        }

        Temp[SizePlural]=Element;//Присвоюєм передани елемент в кінецьь масиву

        free(this->Plural);//звільняєм память

        SizePlural++;//збільшуєм розмір множини на 1

        this->Plural=new int[SizePlural]; // виділяєм нову память

        for(int i =0 ;i<SizePlural;i++)
        {
            this->Plural[i]=Temp[i];//переприсвоюєм
        }

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

        for(int i = Position+1;i < SizePlural;i++)
        {
            Temp[i]=this->Plural[i];//присвоюєм усі крім нього/
        }

        free(this->Plural);//видаляєм старий

        SizePlural--;//Розмір на 1 менше

        this->Plural = new int[SizePlural];//нову память на 1 менше

        for(int i =0 ; i<SizePlural;i++)
        {
            this->Plural[i]=Temp[i];//переприсвоюєм
        }
    }


}

int Set::Max()
{
    return std::max_element(this->Plural,this->Plural+this->SizePlural);

}

int Set::Min()
{
    return std::min_element(this->Plural,this->Plural+this->SizePlural);
}

Set &Set::operator =(const Set &obj)
{
    this->setSizePlural(obj.getSizePlural());

    free(this->Plural);

    this->Plural=new int[this->getSizePlural()];

    for(int i = 0 ; i <this->getSizePlural();i++)
    {
        this->Plural[i]=obj.Plural[i];
    }

    return *this;



}

Set Set::operator +(const Set &obj) const
{
    Set Adding(this->getSizePlural());
    int NewSize=this->getSizePlural();//Розмір нової множини

    for(int i = 0 ; i<this->SizePlural;i++)
    {
        Adding.Plural[i]=this->Plural[i];    //переприсвоюєм 1 множину
    }

    for(int i = this->SizePlural; i < obj.getSizePlural();i++ )
    {
        if(!Adding.inlude(obj.Plural[i]))//якщо обєкта немає
        {
           Adding.Add(obj.Plural[i]);
        }
    }


    return Adding;
}

Set Set::operator -(const Set &obj) const
{
    Set Minus(*this);

    int index;

    for(int i = 0 ; i<obj.getSizePlural();i++)
    {
        if(Minus.inlude(obj->Plural[i]))
        {
            Minus.Plural[index]=obj.Plural[i];
            index++;
        }
    }

    Set Result (index);
    for(int i = 0 ; i<index;i++)
    {
        Result.Plural=Minus.Plural[i];
    }
    return Result;

}

Set Set::operator /(const Set &obj) const
{
    Set Without(obj);

    for(int i = 0 ; i<Without.getSizePlural();i++)
    {
        Without.Plural[i]=this->Plural[i;]
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

