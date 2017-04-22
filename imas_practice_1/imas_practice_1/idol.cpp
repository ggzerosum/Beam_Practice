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

	if (destination[size -2] == '\n')
		destination[size-2] = '\0';
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

void idol::PrintText(const char* text)
{
	char chr;
	int len = strlen(text);

	for (int i = 0; i<len; i++)
	{
		chr = text[i];

		if (chr & 0x80)
		{
			printf("%.2s", text + i);
			i++;
		}
		else
		{
			if (chr != '\n')
				printf("%.1s", text + i);
		}

		switch (chr)
		{
		case ' ':
			Sleep(150);
			break;

		default:
			Sleep(70);
			break;
		}
	}
}

void idol::DoHateSpeech(const idol* target)
{
	if (target == nullptr)
	{
		cout << endl;
		PrintText("�� ������� �� ���� ���µ�.");
		return;
	}

	cout << endl;
	PrintText("��ȣ�� Ÿ���� ���ϰ� �ֽ��ϴ�!");
	Sleep(1000);
	cout << endl;
	PrintText(". . . . . . . . . .");
	cout << endl << endl;
	PrintText("��ȣ�� ");
	PrintText(target->GetName());
	PrintText("�� �Ĵٺ��ҽ��ϴ�!");
	
	Sleep(1000);

	cout << endl << endl;
	PrintText(target->GetName());

	if (target->GetAge() > age)
	{
		PrintText(" ����(?)");
		cout << endl;
	}
	else
	{
		cout << endl;
	}

	Sleep(1000);

	cout << "\"";
	PrintText(target->GetWords());
	cout << "\"" << endl;
	cout << endl;
}