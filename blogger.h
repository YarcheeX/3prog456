#pragma once
#include "post.h"


class blogger {

private:
	string name;               //название канала
	string description;        //описание канала
	unsigned int followers;    //подписчики
	unsigned int video_count;  //кол-во видео
	unsigned int photo_count;  //видео канала
	static int blogger_count;  //счетчик кол-ва объектов blogger
	static void stat_increm();  //увеличивает счетчик на 1
	static void stat_decrem();  //уменьшает счетчик на 1

public:

	video** videos;            //видео канала
	photo** photos;            //фото канала
	blogger();
	blogger(string name);
	blogger(string name, string descr);
	blogger(const blogger& other); //конструктор копирования
	~blogger();

	static int getstat();
	const blogger& operator = (const blogger& other); //перегрузка оператора = для этого класса
	void add_video(const video& vid);  //добавить фото
	void add_photo(const photo& pho);  //добавить видео
	void set_name(string name);         //сеттер названия канала
	void set_description(string descr); //сеттер описания канала
	void follow(unsigned followers);   //подписаться
	void print_videos();               //вывести все видео
	void print_photos();               //вывести все фото
	void print_all_posts();            //вывести все посты
	void print_blogger();
	void input_blogger();

	friend ostream& operator << (ostream& os, const blogger& b);
};