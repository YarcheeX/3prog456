#pragma once
#include "date.h"
#include "answer.h"
#include <string.h>
//#include <stdlib.h>


class comment {

private:
	string author;                //����� �����������
	string text;                  //��� ������ �����������
	unsigned int answers_count;   //���������� ������� �� �����������
public:
	date upload_date;             //���� �������� �����������
	answer** answers = nullptr;   //������ �� ����������

	comment();
	comment(date date);
	comment(date date, string text);
	comment(date date, string text, string author);
	comment(const comment& other); //����������� �����������
	~comment();

	const comment& operator = (const comment& other); //���������� ��������� =
	void add_answer(const answer& ans); //����� ���������� ������ � �����������
	void set_author(string author); //������ ������ �����������
	void set_text(string text); //������ ������ �����������
	void print_comment() const; //����������� �����������
	void watch_comment() const; //���������� ����������� (� ��������)
	void input_comment(); //������ �����������

};