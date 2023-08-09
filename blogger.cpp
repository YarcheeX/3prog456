#include "blogger.h"

int blogger::blogger_count = 0;

blogger::blogger()
{
	name = "Noname";
	description = "";
	followers = 0;
	videos = nullptr;
	video_count = 0;
	photos = nullptr;
	photo_count = 0;
	stat_increm();
}

blogger::~blogger()
{
	if (video_count == 1) {
		delete videos[0];
		delete videos;
	}
	else {
		for (unsigned i = 0; i < video_count; i++)
			delete videos[i];
		delete[] videos;
	}

	if (photo_count == 1) {
		delete photos[0];
		delete photos;
	}
	else {
		for (unsigned i = 0; i < photo_count; i++)
			delete photos[i];
		delete[] photos;
	}
	stat_decrem();
}

void blogger::stat_increm()
{
	blogger_count++;
}

void blogger::stat_decrem()
{
	blogger_count--;
}
blogger::blogger(string name) :blogger()
{
	this->set_name(name);
}
blogger::blogger(string name, string descr) :blogger(name)
{
	this->set_description(descr);
}
blogger::blogger(const blogger& other)
{
	*this = other;
}
int blogger::getstat()
{
	return blogger_count;
}

const blogger& blogger::operator=(const blogger& other)
{
	name = other.name;
	description = other.description;

	followers = other.followers;

	if (video_count == 1) {
		delete videos[0];
		delete videos;
	}
	else {
		for (unsigned i = 0; i < video_count; i++)
			delete videos[i];
		delete[] videos;
	}

	video_count = other.video_count;
	if (video_count == 0) {
		videos = nullptr;
	}
	else {
		if (video_count == 1) {
			videos = new video * ();
			videos[0] = new video(*other.videos[0]);
		}
		else {
			videos = new video * [video_count];
			for (unsigned i = 0; i < video_count; i++)
			{
				videos[i] = new video(*other.videos[i]);
			}
		}
	}

	if (photo_count == 1) {
		delete photos[0];
		delete photos;
	}
	else {
		for (unsigned i = 0; i < photo_count; i++)
			delete photos[i];
		delete[] photos;
	}

	photo_count = other.photo_count;
	if (photo_count == 0) {
		photos = nullptr;
	}
	else {
		if (photo_count == 1) {
			photos = new photo * ();
			photos[0] = new photo(*other.photos[0]);
		}
		else {
			photos = new photo * [photo_count];
			for (unsigned i = 0; i < photo_count; i++)
			{
				photos[i] = new photo(*other.photos[i]);
			}
		}
	}

	return *this;
}
void blogger::add_video(const video& vid)
{
	video_count += 1;
	if (video_count == 1) {
		videos = new video * ();
		videos[0] = new video(vid);
	}
	else {
		video** temp = new video * [video_count];
		for (unsigned i = 0; i < video_count - 1; i++)
			temp[i] = videos[i];
		delete[] videos;

		videos = new video * [video_count];
		for (unsigned i = 0; i < video_count - 1; i++)
			videos[i] = temp[i];
		videos[video_count - 1] = new video(vid);

		delete[] temp;
	}
}
void blogger::add_photo(const photo& pho)
{
	photo_count += 1;
	if (photo_count == 1) {
		photos = new photo * ();
		photos[0] = new photo(pho);
	}
	else {
		photo** temp = new photo * [photo_count];
		for (unsigned i = 0; i < photo_count - 1; i++)
			temp[i] = photos[i];
		delete[] photos;

		photos = new photo * [photo_count];
		for (unsigned i = 0; i < photo_count - 1; i++)
			photos[i] = temp[i];
		photos[photo_count - 1] = new photo(pho);

		delete[] temp;
	}
}
void blogger::set_name(string name)
{
	this->name = name;
}
void blogger::set_description(string descr)
{
	this->description = descr;
}
void blogger::follow(unsigned followers)
{
	this->followers += followers;

}
void blogger::print_videos()
{
	printf("\n�����: ");
	if (video_count == 0)
	{
		printf("�����������.\n");
		return;
	}
	for (unsigned i = 0; i < video_count; i++)
	{
		printf("\n%d)", i);
		videos[i]->print_post();
	}
}
void blogger::print_photos()
{
	printf("\n����: ");
	if (photo_count == 0)
	{
		printf("�����������.\n");
		return;
	}
	for (unsigned i = 0; i < photo_count; i++)
	{
		printf("\n%d)", i);
		photos[i]->print_post();
	}
}
void blogger::print_all_posts()
{
	this->print_photos();
	this->print_videos();
}

void blogger::print_blogger()
{
	printf("\n�������� ��������: %s\n", name.c_str());
	printf("��������: %s\n", description.c_str());
	printf("����������: %u | ����: %u | �����: %u\n", followers, photo_count, video_count);
}

ostream& operator << (ostream& os, const blogger& b) {

	os << "�������� ��������: " << b.name << '\n';
	os << "��������: " << b.description << '\n';
	os << "����������: " << b.followers << " | ����: " << b.photo_count << " | �����: " << b.video_count << '\n';
	return os;
}

void blogger::input_blogger()
{
	printf("���� ��������:\n");

	printf("������ �������� ��������? (�� - 1, ��� - 2): ");
	int a;
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("������. �������� ���� �� ������������ ���������: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, name);
	}

	printf("������ ��������? (�� - 1, ��� - 2): ");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("������. �������� ���� �� ������������ ���������: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		getline(cin, description);
	}
}
