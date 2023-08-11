#pragma once
#include "date.h"
#include "answer.h"
#include <string.h>
//#include <stdlib.h>


class comment {

private:
	string author;                //текст комментария
	string text;                  //имя автора комментария
	unsigned int answers_count;   //количество ответов на комментарий
public:
	date upload_date;             //дата загрузки комментария
	answer** answers = nullptr;   //ответы на коментарий

	comment();
	comment(date date);
	comment(date date, string text);
	comment(date date, string text, string author);
	comment(const comment& other); //конструктор копирования
	~comment();

	const comment& operator = (const comment& other); //перегрузка оператора =
	void add_answer(const answer& ans); //метод добавления ответа к комментарию
	void set_author(string author); //сеттер автора комментария
	void set_text(string text);//сеттер текста комментария
	void print_comment() const; //распечатать комментарий
	void watch_comment() const; //посмотреть комментарий (с ответами)
	void input_comment(); //ввести комментарий

	friend ostream& operator<<(ostream& os, const comment& c);
};