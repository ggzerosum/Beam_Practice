#include "includes.h"
#include "idol.h"

//������
idol::idol(int age, int size, const char* name, const char* words)
	:age(age), size(size)
{
	StrToDes(this->name, name);
	StrToDes(this->words, words);
}

//���� ������
idol::idol(const idol &ref)
	:age(ref.age), size(ref.size)
{
	StrToDes(this->name, ref.name);
	StrToDes(this->words, ref.words);
}

//�Ҹ���
idol::~idol()
{
	if (name != nullptr)
		delete[] name;

	if (words != nullptr)
		delete[] words;
}

void idol::StrToDes(char* &destination, const char* source)
{
	rsize_t size = strlen(source) + 1;
	destination = new char[size];
	strcpy_s(destination, size, source);
}

int idol::GetAge() const
{
	return age;
}

int idol::GetSize() const
{
	return size;
}

const char* idol::GetName() const
{
	return name;
}

const char* idol::GetWords() const
{
	return words;
}

void idol::DoHateSpeech(const idol &target)
{
	const char* NameOfTarget;
	NameOfTarget = target.GetName();

	cout << endl;
	cout << NameOfTarget;
	cout << "���迡��... " << endl;
	cout << "\"" << words << "\"" << endl;
	cout << endl;
}