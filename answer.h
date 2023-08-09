#pragma once
#include "date.h"
#include <string.h>


class answer {

private:
	string author;
	string text;

public:
	date upload_date;
	answer();
	answer(date date);
	answer(date date, string text);
	answer(date date, string text, string author);
	answer(const answer& other);
	~answer();

	const answer& operator = (const answer& other);
	void set_author(string aouthor);
	void set_text(string text);
	void print_answer() const;
	void input_answer();

};