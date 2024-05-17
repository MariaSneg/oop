#pragma once
#include <iostream>
enum class Month
{
    JANUARY = 1, FEBRUARY, MARCH, APRIL,
    MAY, JUNE, JULY, AUGUST, SEPTEMBER,
    OCTOBER, NOVEMBER, DECEMBER
};

enum class WeekDay
{
    SUNDAY = 0, MONDAY, TUESDAY, WEDNESDAY,
    THURSDAY, FRIDAY, SATURDAY
};

class CDate
{
public:
    CDate(unsigned day, Month month, unsigned year);
    explicit CDate(unsigned timestamp);
    CDate();
    unsigned GetDay()const;
    Month GetMonth()const;
    unsigned GetYear()const;
    WeekDay GetWeekDay()const;
    unsigned GetTimestamp()const;
    bool IsValid()const;
	CDate& operator++();
	CDate& operator--();
	CDate operator+(unsigned value) const;
	friend CDate operator+(unsigned value, const CDate& date);
	CDate operator-(unsigned value) const;
	unsigned operator-(const CDate& date) const;
	CDate& operator+=(unsigned value);
	CDate& operator-=(unsigned value);
	friend std::ostream& operator<<(std::ostream& out, const CDate& date);
	friend std::istream& operator>>(std::istream& in, CDate& date);
	bool operator!=(const CDate& date) const;
	bool operator==(const CDate& date) const;
	bool operator<(const CDate& date) const;
	bool operator>(const CDate& date) const;
	bool operator<=(const CDate& date) const;
	bool operator>=(const CDate& date) const;

private:
    unsigned m_timestamp;
	unsigned DateToTimestamp(unsigned day, Month month, unsigned year) const;
};