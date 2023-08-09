#include "comment.h"

comment::comment()
{
	text = "Anonimous";
	author = "";
	answers_count = 0;
	answers = nullptr;
}

comment::comment(date date) :comment()
{
	this->upload_date = date;
}


comment::comment(date date, string text) : comment(date)
{
	this->text = text;
}

comment::comment(date date, string text, string author) : comment(date, text)
{
	this->author = author;
}

comment::comment(const comment& other)
{
	*this = other;
}

comment::~comment()
{
	if (answers_count == 1) {
		delete answers[0];
		delete answers;
	}
	else {
		for (unsigned i = 0; i < answers_count; i++)
			delete answers[i];
		delete[] answers;
	}
}

const comment& comment::operator=(const comment& other)
{
	author = other.author;

	text = other.text;

	upload_date = other.upload_date;

	if (answers_count == 1) {
		delete answers[0];
		delete answers;
	}
	else {
		for (unsigned i = 0; i < answers_count; i++)
			delete answers[i];
		delete[] answers;
	}

	this->answers_count = other.answers_count;

	if (answers_count == 0) {
		this->answers = nullptr;
	}
	else {
		if (answers_count == 1)
		{
			answers = new answer * ();
			answers[0] = new answer(*other.answers[0]);
		}
		else {
			answers = new answer * [answers_count];
			for (unsigned i = 0; i < answers_count; i++)
			{
				answers[i] = new answer(*other.answers[i]);
			}
		}
	}

	return *this;
}

void comment::add_answer(const answer& ans)
{
	answers_count += 1;
	if (answers == nullptr) {
		answers = new answer * ();
		answers[0] = new answer(ans);
	}
	else {

		answer** temp = new answer * [answers_count];
		for (unsigned i = 0; i < answers_count - 1; i++)
		{
			temp[i] = answers[i];
		}
		delete[] answers;

		answers = new answer * [answers_count];
		for (unsigned i = 0; i < answers_count - 1; i++)
			answers[i] = temp[i];
		answers[answers_count - 1] = new answer(ans);

		delete[] temp;
	}
}

void comment::set_author(string author)
{
	this->author = author;
}

void comment::set_text(string text)
{
	this->text = text;
}

void comment::print_comment() const
{
	printf("Автор: %s | ", author.c_str());
	upload_date.print_date();
	printf("Текст: %s\nОтветов: %u\n", text.c_str(), answers_count);
}

void comment::watch_comment() const {

	printf("Автор: %s | ", author.c_str());
	upload_date.print_date();
	printf("Текст: %s\nОтветы:\n", text.c_str());
	for (unsigned i = 0; i < answers_count; i++) {

		answers[i]->print_answer();
	}
}


void comment::input_comment()
{
	printf("Ввод даты коментария:\n");
	upload_date.input_date();
	printf("Ввести автора? (Да - 1, нет - 2):");
	int a = 0;

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
