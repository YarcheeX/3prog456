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
	printf("�����: %s | ", author.c_str());
	upload_date.print_date();
	printf("�����: %s\n", text.c_str());
}


void answer::input_answer()
{
	printf("���� ����������.\n");
	upload_date.input_date();

	int a = 0;
	printf("������ ������? (�� - 1, ��� - 2):");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("������. �������� ���� �� ������������ ���������: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, author);
	}

	a = 0;

	printf("������ �����? (�� - 1, ��� - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("������. �������� ���� �� ������������ ���������: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, text);
	}

	
}

ostream& operator<<(ostream& os, const answer& a)
{
	os << "�����: " << a.author << "| ";
	os << a.upload_date;
	os << "�����: " << a.text << '\n';
	return os;
}