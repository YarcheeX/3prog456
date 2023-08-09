#include "date.h"

date::date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

date::date(int day, int month, int year)
{
	this->set_date(day, month, year);
}

void date::set_date(unsigned day, unsigned month, unsigned year)
{
	(day < 32) ? this->day = day : this->day = 0;
	(month < 13) ? this->month = month : this->month = 0;
	(year > 2005 && year < 2024) ? this->year = year : this->year = 0;
}


void date::get_date(int* day, int* month, int* year)
{
	*day = this->day;
	*month = this->month;
	*year = this->year;
}

void date::print_date() const
{
	printf("Дата: %u.%u.%u\n", day, month, year);
}

ostream& operator<<(ostream& os, const date& d)
{
	os << "Дата: " << setfill('0') << setw(2) << d.day;
	os << '.' << setfill('0') << setw(2) << d.month;
	os << '.' << setfill('0') << setw(2) << d.year << endl;
	return os;
}

void date::input_date()
{
	unsigned day, month, year;

	printf("\nВвод даты:\n");

	printf("День: ");
	while (scanf_s("%u", &day) != 1)
	{
		while (getchar() != '\n');
		printf("Ошибка, введите день: ");
	}
	while (getchar() != '\n');

	printf("Месяц (число): ");
	while (scanf_s("%u", &month) != 1)
	{
		while (getchar() != '\n');
		printf("Ошибка, введите месяц (числом): ");
	}
	while (getchar() != '\n');

	printf("Год: ");
	while (scanf_s("%u", &year) != 1)
	{
		while (getchar() != '\n');
		printf("Ошибка, введите год: ");
	}
	while (getchar() != '\n');

	this->set_date(day, month, year);
}

date& date::operator++()
{
	day++;
	if (month == 2 && day == 28) {
		day = 1;
		month++;
	}
	if ((month < 8 && month > 0)) {
		if ((month % 2 == 0 && day == 31) || (month % 2 != 0 && day == 32))
		{
			day = 1;
			month++;
		}
	}
	if ((month < 13 && month > 7)) {
		if ((month % 2 == 0 && day == 32) || (month % 2 != 0 && day == 31))
		{
			day = 1;
			if (month == 12) {
				month = 1;
				year++;
			}
			else month++;
		}
	}
	return *this;
}

date date::operator++(int)
{
	date retdate(*this);
	day++;
	if (month == 2 && day == 28) {
		day = 1;
		month++;
	}
	if ((month < 8 && month > 0)) {
		if ((month % 2 == 0 && day == 31) || (month % 2 != 0 && day == 32))
		{
			day = 1;
			month++;
		}
	}
	if ((month < 13 && month > 7)) {
		if ((month % 2 == 0 && day == 32) || (month % 2 != 0 && day == 31))
		{
			day = 1;
			if (month == 12) {
				month = 1;
				year++;
			}
			else month++;
		}
	}
	return retdate;
}
