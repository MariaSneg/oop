#include "Date.h"
#include "Date.h"

CDate::CDate(unsigned day, Month month, unsigned year)
{
    m_timestamp = DateToTimestamp(day, month, year);
}

CDate::CDate(unsigned timestamp)
    : m_timestamp(timestamp)
{
}

CDate::CDate()
    : m_timestamp(0)
{
}

unsigned CDate::GetDay() const
{
    return m_timestamp - DateToTimestamp(1, GetMonth(), GetYear()) + 1;
}

Month CDate::GetMonth() const
{
    int sumMonth[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    int days = m_timestamp - DateToTimestamp(1, Month::JANUARY, GetYear());
    if ((GetYear() % 4 == 0 && GetYear() % 100 != 0) || GetYear() % 400 == 0)
    {
        days--;
    }
    int month = days / 30;

    if (sumMonth[month] > days && month < 2)
    {
        return Month(days / 30 + 1);
    }
    return Month(days /30);
}

unsigned CDate::GetYear() const
{
    int years = m_timestamp / 365;
    int leapYears = 0;
    if (years > 2)
    {
        leapYears = (years - 2) / 4;
    }
    return 1970 + (m_timestamp - leapYears)/365;
}

WeekDay CDate::GetWeekDay() const
{
    return WeekDay((m_timestamp + static_cast<unsigned>(WeekDay::THURSDAY)) % 7);
}

unsigned CDate::GetTimestamp() const
{
    return m_timestamp;
}

unsigned CDate::DateToTimestamp(unsigned day, Month month, unsigned year) const
{
    unsigned timestamp = 0;
    int leapYears = 0;
    if (year > 1972)
    {
        leapYears = (year + 2 - 1970) / 4 - (year + 2 - 1970) / 100 + (year + 2 - 1970) / 400;
    }
    
    timestamp = (year - 1970) * 365 + leapYears;

    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && (static_cast<int>(month) > 2))
    {
        timestamp++;
    }

    int months[12] = { 31,28,31,30,31,30, 31,31,30,31,30,31 };
    for (int i = 0; i < static_cast<int>(month) - 1; i++)
    {
        timestamp += months[i];
    }

    timestamp += day - 1;
    return timestamp;
}

CDate& CDate::operator++()
{
	if (GetYear() == 9999 && GetMonth() == Month::DECEMBER && GetDay() == 31)
	{
		throw std::out_of_range("Date exceeded max date value");
	}
	++m_timestamp;
	return *this;
}

CDate& CDate::operator--()
{
	if (GetYear() == 1970 && GetMonth() == Month::JANUARY && GetDay() == 1)
	{
		throw std::out_of_range("Date bellow min date value");
	}
	--m_timestamp;
	return *this;
}

CDate CDate::operator+(unsigned value) const
{
	CDate date(m_timestamp + value);
	return date;
}

CDate operator+(unsigned value, const CDate& date)
{
	return date + value;
}

CDate CDate::operator-(unsigned value) const
{
	if (value > m_timestamp)
	{
		throw std::out_of_range("Date bellow min date value");
	}
	return CDate(m_timestamp - value);
}

unsigned CDate::operator-(const CDate& date) const
{
	return m_timestamp - date.m_timestamp;
}

CDate& CDate::operator+=(unsigned value)
{
	if (m_timestamp + value > DateToTimestamp(31, Month::DECEMBER, 9999))
	{
		throw std::out_of_range("Date exceeded max date value");
	}

	m_timestamp += value;
	return *this;
}

CDate& CDate::operator-=(unsigned value)
{
	if (value > m_timestamp)
	{
		throw std::out_of_range("Date bellow min date value");
	}
	m_timestamp -= value;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const CDate& date)
{
	out << std::setfill('0') << std::setw(2) << date.GetDay() << "."
		<< std::setfill('0') << std::setw(2) << static_cast<unsigned>(date.GetMonth()) << "."
		<< date.GetYear();
	return out;
}

std::istream& operator>>(std::istream& in, CDate& date)
{
	unsigned day, month, year;
	char ch1, ch2;
	in >> day >> ch1 >> month >> ch2 >> year;
	if (day > 31 || ch1 != '.' || month > 12 || ch2 != '.' || year > 9999 || year < 1970)
	{
		throw std::invalid_argument("Format must be dd.mm.yyyy, day <= 31, month <= 12, year 1970 - 9999");
	}
	date = CDate(day, static_cast<Month>(month), year);
	return in;
}

bool CDate::operator!=(const CDate& date) const
{
	if (GetDay() != date.GetDay())
	{
		return true;
	}
	if (GetMonth() != date.GetMonth())
	{
		return true;
	}
	if (GetYear() != date.GetYear())
	{
		return true;
	}

	return false;
}

bool CDate::operator==(const CDate& date) const
{
	return !(*this != date);
}

bool CDate::operator<(const CDate& date) const
{
	if (GetYear() < date.GetYear())
	{
		return true;
	}
	if (GetMonth() < date.GetMonth())
	{
		return true;
	}
	if (GetDay() < date.GetDay())
	{
		return true;
	}
	return false;
}

bool CDate::operator>(const CDate& date) const
{
	if (*this == date)
	{
		return false;
	}

	return !(*this < date);
}

bool CDate::operator<=(const CDate& date) const
{
	return ((*this == date) || (*this < date));
}

bool CDate::operator>=(const CDate& date) const
{
	return ((*this == date) || (*this > date));
}

