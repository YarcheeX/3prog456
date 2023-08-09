#include "post.h"

post::post() {
	name = "";
	description = "";
	views = 0;
	likes = 0;
	comments = nullptr;
	comments_count = 0;
}

post::post(string name) : post()
{
	this->name = name;
}

post::post(string name, string descr) : post(name)
{
	description = descr;
}

post::post(string name, string descr, date date) : post(name, descr)
{
	this->upload_date = date;
}

post::post(const post& other)
{
	*this = other;
}

post::~post()
{
	if (comments_count == 1) {
		delete comments[0];
		delete comments;
	}
	else {
		for (unsigned i = 0; i < comments_count; i++)
			delete comments[i];
		delete[] comments;
	}
}

void post::set_name(string name)
{
	this->name = name;
}

void post::set_description(string descr)
{
	description = descr;
}

const post& post::operator=(const post& other)
{
	name = other.name;
	description = other.description;

	views = other.views;
	likes = other.likes;
	upload_date = other.upload_date;

	if (comments_count == 1) {
		delete comments[0];
		delete comments;
	}
	else {
		for (unsigned i = 0; i < comments_count; i++)
			delete comments[i];
		delete[] comments;
	}

	comments_count = other.comments_count;
	if (comments_count == 0) {
		this->comments = nullptr;
	}
	else {
		if (comments_count == 1) {
			comments = new comment * ();
			comments[0] = new comment(*other.comments[0]);
		}
		else {
			comments = new comment * [comments_count];
			for (unsigned i = 0; i < comments_count; i++)
			{
				comments[i] = new comment(*other.comments[i]);
			}
		}
	}

	return *this;
}

void post::input_post()
{
	printf("\nВвод текстового поста.");
	printf("Ввести заголовок поста? (Да - 1, нет - 2):");
	int a = 0;
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, name);
	}

	a = 0;

	printf("Ввести описание? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, description);
	}
}

void post::add_comment(const comment& comm)
{
	comments_count += 1;
	if (comments == nullptr) {
		comments = new comment * ();
		comments[0] = new comment(comm);
	}
	else {
		comment** temp = new comment * [comments_count];
		for (unsigned i = 0; i < comments_count - 1; i++)
			temp[i] = comments[i];
		delete[] comments;

		comments = new comment * [comments_count];
		for (unsigned i = 0; i < comments_count - 1; i++)
			comments[i] = temp[i];
		comments[comments_count - 1] = new comment(comm);

		delete[] temp;
	}
}


void post::watch(unsigned views)
{
	this->views += views;
	this->print_post();
	printf("Описание: %s\nКомментарии:\n", description.c_str());
	if (comments_count == 0) printf("Отсутствуют\n");
	for (unsigned i = 0; i < comments_count; i++) {
		printf("%d)", i);
		comments[i]->print_comment();
	}
}

void post::like(unsigned a) {

	this->likes += a;
}

void post::print_post() const
{
	printf("Заголовок: %s\n", name.c_str());
	printf("Просмотры: %u | Лайки: %u | Комментарии: %u\n", views, likes, comments_count);
	upload_date.print_date();
}

video::video() {

	duration = { 0,0,0 };
}

video::video(string name) : post(name) {

	duration = { 0,0,0 };
}

video::video(string name, string descr) : post(name, descr) {

	duration = { 0,0,0 };
}

video::video(string name, string descr, Time duration) : post(name, descr) {

	this->duration = duration;
}

video::video(string name, string descr, Time duration, date upload_date) : post(name, descr, upload_date) {

	this->duration = duration;
}

video::video(const video& other):video()
{

	*this = other;
}


void video::print_post() const
{
	printf("Название: %s\n", name.c_str());
	printf("Длительность: %d:%d:%d\n", duration.get_hour(), duration.get_min(), duration.get_sec());
	printf("Просмотры: %u | Лайки: %u | Комментарии: %u\n", views, likes, comments_count);
	upload_date.print_date();
}

void video::input_post()
{
	printf("\nВвод видео.\n");
	upload_date.input_date();

	printf("Ввести название видео? (Да - 1, нет - 2):");
	int a;
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, name);
	}

	printf("Ввести описание? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, description);
	}

	printf("Ввести длительность видео? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1) {
		int min, sec, hour;
		printf("Введите часы: ");
		while (scanf_s("%d", &hour) != 0) {
			printf("Ошибка. Введите часы: ");
		}
		while (getchar() != '\n');
		printf("Введите минуты:");
		while (scanf_s("%d", &min) != 0) {
			printf("Ошибка. Введите минуты: ");
		}
		while (getchar() != '\n');

		printf("Введите секунды:");
		while (scanf_s("%d", &sec) != 0) {
			printf("Ошибка. Введите секунды: ");
		}
		while (getchar() != '\n');

		this->set_duration(hour, min, sec);
	}
}

const video& video::operator=(const post& other)
{
	post::operator=(other);
	duration = { 0,0,0 };
	return *this;
}

const video& video::operator=(const video& other)
{
	post::operator=(other);
	duration = other.duration;
	return *this;
}

void video::set_duration(int hour, int min, int sec)
{
	duration.set_time(hour, min, sec);
}

photo::photo() : post() {}
photo::photo(string name) : post(name) {}
photo::photo(string name, string descr) : post(name, descr) {}
photo::photo(string name, string descr, date date) : post(name, descr, date) {}
photo::photo(const photo& other):post()
{
	*this = other;
}


const photo& photo::operator=(const photo& other)
{
	post::operator=(other);
	return *this;
}

void photo::print_post() const
{
	printf("Название: %s\n", name.c_str());
	printf("Просмотры: %u | Лайки: %u | Комментарии: %u\n", views, likes, comments_count);
	upload_date.print_date();
}

void photo::input_post()
{
	printf("\nВвод фото.\n");
	upload_date.input_date();

	printf("Ввести название фото? (Да - 1, нет - 2):");
	int a;
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, name);
	}

	a = 0;

	printf("Ввести описание? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, description);
	}

}
