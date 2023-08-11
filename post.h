#pragma once
#include "comment.h"
#include "Time.h"


class post {  //базовый класс для photo и video
protected:
	string name;                 //название поста
	string description;          //описание поста
	unsigned int views;          //просмотры
	unsigned int likes;          //лайки
	unsigned int comments_count; //кол-во комментариев

public:
	date upload_date;                //дата выгрузки поста
	comment** comments = nullptr;	 //комментарии

	post();
	post(string name);
	post(string name, string descr);
	post(string name, string descr, date date);
	post(const post& other);
	~post();

	virtual void print_post() const;
	virtual void input_post();

	const post& operator=(const post& other);
	void set_name(string name); //сеттер названия
	void set_description(string descr); //сеттер описания
	void add_comment(const comment& comm); //добавить комментарий
	void watch(unsigned views); //просмотреть пост
	void like(unsigned a); //лайкнуть

	friend ostream& operator<<(ostream& os, const post& p);
};



class video : public post {

public:
	Time duration;
	video();//перегружает конструктор базового класса (в определении)
	video(string name);
	video(string name, string descr);
	video(string name, string descr, Time duration);
	video(string name, string descr, Time duration, date upload_date);
	video(const video& other); //конструктор копирования


	const video& operator = (const post& other); //перегрузка оператора = для базового класса
	const video& operator = (const video& other); //перегрузка оператора = для этого класса
	void set_duration(int hour, int min, int sec); //сеттер длительности
	void print_post() const; //перегруженный метод базового класса
	void input_post(); //перегруженный метод базового класса

	friend ostream& operator<<(ostream& os, const video& v);
};

class photo : public post {

public:
	photo();
	//перегружают конструкторы базового класса (в определении)
	photo(string name);
	photo(string name, string descr);
	photo(string name, string descr, date date);
	photo(const photo& other); //конструктор копирования

	const photo& operator = (const photo& other); //перегрузка оператора = для этого класса
	void print_post() const; //перегруженный метод базового класса
	void input_post(); //перегруженный метод базового класса

	friend ostream& operator<<(ostream& os, const photo& p);
};

