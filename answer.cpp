#include "answer.h"

answer::answer()
{
	author = "Anonimous";
	text = "";
}

answer::answer(date date)
{
	upload_date = date;
}

answer::answer(date date, string text) : answer(date)
{
	this->text = text;
}

answer::answer(date date, string text, string author) : answer(date, text)
{
	this->author = author;
}

answer::answer(const answer& other)
{
	*this = other;
}

answer::~answer()
{
}

const answer& answer::operator=(const answer& other)
{
	author = other.author;

	text = other.text;

	upload_date = other.upload_date;

	return *this;
}

void answer::set_author(string author)
{
	this->author = author;
}

void answer::set_text(string text)
{
	this->text = text;
}

void answer::print_answer() const
{
	printf("Автор: %s | ", author.c_str());
	upload_date.print_date();
	printf("Текст: %s\n", text.c_str());
}


void answer::input_answer()
{
	printf("Ввод коментария.\n");
	upload_date.input_date();

	int a = 0;
	printf("Ввести автора? (Да - 1, нет - 2):");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, author);
	}

	a = 0;

	printf("Ввести текст? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, text);
	}

	
}

ostream& operator<<(ostream& os, const answer& a)
{
	os << "Автор: " << a.author << "| ";
	os << a.upload_date;
	os << "Текст: " << a.text << '\n';
	return os;
}