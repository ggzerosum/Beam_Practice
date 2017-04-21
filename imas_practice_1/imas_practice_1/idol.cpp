#include "includes.h"
#include "idol.h"

//생성자
idol::idol(int age, int size, const char* name, const char* words)
	:age(age), size(size)
{
	StrToDes(this->name, name);
	StrToDes(this->words, words);
}

//복사 생성자
idol::idol(const idol &ref)
	:age(ref.age), size(ref.size)
{
	StrToDes(this->name, ref.name);
	StrToDes(this->words, ref.words);
}

//소멸자
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
		PrintText("그 사람에게 할 말은 없는데.");
		return;
	}

	cout << endl;
	PrintText("시호가 타겟을 정하고 있습니다!");
	Sleep(1000);
	cout << endl;
	PrintText(". . . . . . . . . .");
	cout << endl << endl;
	PrintText("시호가 ");
	PrintText(target->GetName());
	PrintText("를 쳐다보았습니다!");
	
	Sleep(1000);

	cout << endl << endl;
	PrintText(target->GetName());

	if (target->GetAge() > age)
	{
		PrintText(" 선배(?)");
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