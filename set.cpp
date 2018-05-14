#include "set.h"
#include<qdebug.h>


Set Set::operator +(const Set &obj)const
{
    int *Add= new int[this->SizePlural + obj.SizePlural];

    int k = 0;
    int index = 0;

    for (int i = 0; i < this->getSizePlural(); ++i)
        Add[i] = this->Plural[i];


    for(ont i = 0 ;i<this->getSizePlural();i++)
    {
        if(Find(obj,this->OutPut(i)));



    }


    Set Temp(this->SizePlural + index);
    for(int i =0 ; i< Temp.SizePlural;i++)
    {
        Temp.Plural[i]=Add[i];
    }

    return Temp;
}

Set Set::operator -(const Set &obj) const
{
    int Peretun[this->getSizePlural()+obj.getSizePlural()];
    int k = 0;
    for (int i = 0; i< this->getSizePlural(); ++i)
      for (int j = 0; j < obj.getSizePlural(); ++j)
      {
        if (this->Plural[i] == obj.Plural[j])
        {
            Peretun[k]=this->Plural[i];
          ++k;
          break;
        }
      }
    Set Temp(k);

    for(int i =0 ; i<k;i++)
    {
        Temp.Plural[i]=Peretun[i];
    }

    return Temp;
}

Set Set::operator /(const Set &obj) const
{

    int k = 0;
    int index = 0;
    int Difference[this->getSizePlural()+obj.getSizePlural()];
    for (int i = 0; i < this->getSizePlural(); ++i)
    {
      for (int j = 0; j < obj.getSizePlural(); ++j)
      {
        if (this->Plural[i] == obj.Plural[j]) ++k;
      }
      if (k == 0)
      {
        Difference[index] = this->Plural[i];
        ++index;
      }
      k = 0;
    }

    for (int i = 0; i < obj.getSizePlural(); ++i)
    {
      for (int j = 0; j < obj.getSizePlural(); ++j)
      {
        if (obj.Plural[i] == this->Plural[j]) ++k;
      }
      if (k == 0)
      {
        Difference[index] = obj.Plural[i];
        ++index;
      }
      k = 0;
    }
Set Temp(index);
for(int i= 0 ; i <index ; i++)
{
    Temp.Plural[i]=Difference[i];
}


return Temp;

}



Set& Set::operator =(const Set &obj)
{

    this->Plural=new int[obj.SizePlural];
    for(int i = 0 ; i<obj.SizePlural;i++)
    {
        this->Plural[i]=obj.Plural[i];
    }
    this->SizePlural=obj.SizePlural;

    return *this;

}



void Set::Read( int index,int number)
{
    this->Plural[index]=number;
}

bool Set::InludeElement( int element)
{

    for(int i =0 ; i < this->SizePlural;i++)
    {
        if(element == this->Plural[i])
        {
            return true;
        }
    }
    return false;
}

int Set::Power()
{
    return this->SizePlural;
}

int Set::MaxElement()
{
    int res = *std::max_element(this->Plural, this->Plural+this->SizePlural);
    return res;
}

int Set::MinElement()
{
    int res = *std::min_element(this->Plural, this->Plural+this->SizePlural);
    return res;
}

Set Set::DeleteElement(int position)
{

    int Without[this->getSizePlural()];

    for(int i =0 ; i<position;i++)
    {
        Without[i]=this->Plural[i];
    }


    for(int i = position+1 ; i < this->SizePlural ; i++)
    {

        Without[i-1]=this->Plural[i];

    }

    int Size = this->getSizePlural()-1;

    Set Temp(Size);

    for(int i = 0 ; i < Temp.getSizePlural();i++)
    {
        Temp.Plural[i] = Without[i];
    }



    return Temp;


}

int Set::getSizePlural() const
{
    return SizePlural;
}

int Set::OutPut(int index)
{
    return this->Plural[index];
}

bool Set::Find(const Set &Arr, int Element)
{
    for(int i =0 ; i < Arr.getSizePlural();i++)
    {
        if (Arr.OutPut(i)==Element)
        {
            return true;
        }


    }
  return false;
}
