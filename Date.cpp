#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
private:

	// int month_[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
	// int day_ [13] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year;
	int month;
	int day;

public:
	 Date(int _year=1980,int _month=1,int _day=1):year(_year),month(_month),day(_day)
    {
        if(_year <= 0) year = 1980;
        if(_month <= 0) month = 1;
        if(_day <= 0) day = 1;
    }

    ~Date(){;};

      friend ostream & operator << (ostream & out,const Date & d1)
    {
        cout<<d1.year<<"/"<<d1.month<<"/"<<d1.day;
    }
    friend istream & operator >> (istream & in , Date & els)
    {
        return in >> els.year >> els.month >> els.day;
    }

	int Getdays(int month,int year){
		int month_[13] = {31,28,31,30,31,30,31,31,30,31,30,31};
		int day = month_[month];
		if(month == 2 && Isleap(year)){
			day += 1;
		}
		return day;
	}

	bool Islegal(int month = 1,int day = 1,int yaer = 1980){
		printf("1\n");
		this -> year = year;
		this -> month = month;
		this -> day = day;
		if(month <= 12 && month > 0){
			if(day <= Getdays(month,year)&& day > 0){
				return true;
			}
			else
				cout << "非法日期" << endl;
		}
		else
			cout << "非法日期" << endl;
	}

	bool Isleap(int year){
		if(year % 400 == 0 ||( year % 4 == 0 && year % 400 != 0))
			return true;
		else
			return false;
	}

	Date operator = (const Date & C){
		this -> year = C.year;
		this -> month = C.month;
		this -> day = C.day;
		return *this;
	}

	bool operator == (Date & C){
		return ( !(*this > C) && !(*this < C));
	}

	Date operator + (int n){
		Date temp(*this);
		temp.day += n;
		while(temp.day > Getdays(temp.month,temp.year)){
			temp.day -= Getdays(temp.month,temp.year);
			temp.month += 1;
			if(temp.month > 12){
				temp.year += 1;
				temp.month = 1;
			}
		}
		return temp;
	}

	Date operator - (Date & C){
		Date t1 = (*this >= C ) ? *this : C,
			 t2 = (*this <= C ) ? *this : C;
		int day_s = 0;
		while(!(t1 == (t2 + day_s))){
			day_s++;
		}
		return day_s;
	}

	bool operator != (Date & C){
		return !(*this == C);
	}

	bool operator <(Date & C){
		if(year != C.year){
			return year < C.year;
		}
		if(month != C.month){
			return month < C.month;
		}
		else
			return day < C.day;
	}

	bool operator >= (Date & C){
		return !(*this < C);
	}

	bool operator >(const Date & C) const{
		if(year != C.year){
			return year > C.year;
		}
		if(month != C.month){
			return month > C.month;
		}
		else
			return day > C.day;
	}

	bool operator <= (Date & C){
		return !(*this > C);
	}

	const int getyear() const{
		return year;
	}

	const int getmonth()const{
		return month;
	}

	const int getday() const{
		return day;
	}
};


int main(int argc, char const *argv[])
{
	Date d1(2000,4,22), d2(2018,11,26), d3, d4;
	cin >> d3 >> d4;
    cout << d1 << endl << d2 << endl << d3 << endl << d4 << endl;
    cout << (d3 + 100) << endl;
	return 0;
}