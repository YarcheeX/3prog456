#pragma once
#include "post.h"


class blogger {

private:
	string name;               //�������� ������
	string description;        //�������� ������
	unsigned int followers;    //����������
	unsigned int video_count;  //���-�� �����
	unsigned int photo_count;  //����� ������
	static int blogger_count;  //������� ���-�� �������� blogger
	static void stat_increm();  //����������� ������� �� 1
	static void stat_decrem();  //��������� ������� �� 1

public:

	video** videos;            //����� ������
	photo** photos;            //���� ������
	blogger();
	blogger(string name);
	blogger(string name, string descr);
	blogger(const blogger& other); //����������� �����������
	~blogger();

	static int getstat();
	const blogger& operator = (const blogger& other); //���������� ��������� = ��� ����� ������
	void add_video(const video& vid);  //�������� ����
	void add_photo(const photo& pho);  //�������� �����
	void set_name(string name);         //������ �������� ������
	void set_description(string descr); //������ �������� ������
	void follow(unsigned followers);   //�����������
	void print_videos();               //������� ��� �����
	void print_photos();               //������� ��� ����
	void print_all_posts();            //������� ��� �����
	void print_blogger();
	void input_blogger();

	friend ostream& operator << (ostream& os, const blogger& b);
};