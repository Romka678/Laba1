// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.MaxPower)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
  return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
  return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	if (BitField.GetBit(Elem) == 1)
		return 1;
	else
    return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
  return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return (BitField==s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
  return (BitField!=s.BitField);
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet Res(BitField & s.BitField);
	return Res;


	//if (MaxPower >= s.MaxPower) {
	//	TSet Res(MaxPower);
	//	Res.BitField = BitField | s.BitField;
	//	return Res;
	//}
	//else
	//{
	//	TSet Res(s.MaxPower);
	//	Res.BitField = BitField | s.BitField;
	//	return Res;
	//}
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet Res(*this);
	if (Res.BitField.GetBit(Elem) != 1)
		Res.BitField.SetBit(Elem);
  return Res;

}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet Temp(*this);
	if (Temp.BitField.GetBit(Elem) != 1)
		Temp.BitField.ClrBit(Elem);
  return Temp;

}

TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet Res(BitField & s.BitField);
	return Res;


//	if (MaxPower >= s.MaxPower) {
//	TSet Res(s.MaxPower);
//	Res.BitField = BitField & s.BitField;
//	return Res;
//}
//	else {
//		TSet Res(MaxPower);
//		Res.BitField = BitField & s.BitField;
//		return Res;
//	}

}

TSet TSet::operator~(void) // дополнение
{
	TSet Temp=*this;
	Temp.BitField = ~BitField;
  return Temp;

}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	istr >> s.MaxPower;
	istr >> s.BitField;
  return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	ostr << s.BitField;
  return ostr;
}
