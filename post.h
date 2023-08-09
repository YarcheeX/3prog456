#pragma once
#include "comment.h"
#include "Time.h"


class post {  //������� ����� ��� photo � video
protected:
	string name;                 //�������� �����
	string description;          //�������� �����
	unsigned int views;          //���������
	unsigned int likes;          //�����
	unsigned int comments_count; //���-�� ������������

public:
	date upload_date;                //���� �������� �����
	comment** comments = nullptr;	 //�����������

	post();
	post(string name);
	post(string name, string descr);
	post(string name, string descr, date date);
	post(const post& other);
	~post();

	virtual void print_post() const;
	virtual void input_post();

	const post& operator=(const post& other);
	void set_name(string name); //������ ��������
	void set_description(string descr); //������ ��������
	void add_comment(const comment& comm); //�������� �����������
	void watch(unsigned views); //����������� ����
	void like(unsigned a); //��������

};



class video : public post {

public:
	Time duration;
	video();//����������� ����������� �������� ������ (� �����������)
	video(string name);
	video(string name, string descr);
	video(string name, string descr, Time duration);
	video(string name, string descr, Time duration, date upload_date);
	video(const video& other); //����������� �����������


	const video& operator = (const post& other); //���������� ��������� = ��� �������� ������
	const video& operator = (const video& other); //���������� ��������� = ��� ����� ������
	void set_duration(int hour, int min, int sec); //������ ������������
	void print_post() const; //������������� ����� �������� ������
	void input_post(); //������������� ����� �������� ������

};

class photo : public post {

public:
	photo();
	//����������� ������������ �������� ������ (� �����������)
	photo(string name);
	photo(string name, string descr);
	photo(string name, string descr, date date);
	photo(const photo& other); //����������� �����������

	const photo& operator = (const photo& other); //���������� ��������� = ��� ����� ������
	void print_post() const; //������������� ����� �������� ������
	void input_post(); //������������� ����� �������� ������

};

