#include "includes.h"
#include "factory.h"

factory* factory::isCreated = nullptr;

factory::factory()
	:SizeOfList(0)
{}

factory::~factory()
{
	isCreated = nullptr;
}

void factory::CreateIdolList(void)
{
	//시호의 독설이 담긴 텍스트 파일을 연결.
	FILE* TextFile;
	fopen_s(&TextFile, "Shiho's hate speech.txt", "r");

	//이제 TextFile라는 녀석을 가지고 실제 내용을 읽어들이기.
	char name[32] = { '\0' };
	char words[102] = { '\0' };
	int age, size;

	for (int i = 0; i < 50; i++)
	{
		if (fgets(name, 32, TextFile) == NULL)
			return;
		
		//이름, 사이즈, 할 말 입력
		fscanf_s(TextFile, "%d %d ", &age, &size);
		fgets(words, 102, TextFile);

		//아이돌 생성 및 목록에 저장
		ListOfIdols[i] = new idol(age, size, name, words);

		//빈 공간을 위해서
		fgets(name, 32, TextFile);

		SizeOfList++;
	}

	fclose(TextFile);
}

idol* factory::SearchIdol(void)
{
	char name[32] = { '\0' };
	cout << "시호가 대화할 상대: ";
	fgets(name, 32, stdin);

	if (name[strlen(name) - 1] == '\n')
		name[strlen(name) - 1] = '\0';

	for (int i = 0; i < SizeOfList; i++)
	{
		int check = strcmp(name, ListOfIdols[i]->GetName());

		if (!check)
		{
			return ListOfIdols[i];
		}
	}

	return nullptr;
}

idol* factory::SearchIdol(int index)
{
	return ListOfIdols[index];
}

factory* factory::itSelf(void)
{
	if(isCreated == nullptr)
	{
		isCreated = new factory;
	}

	return isCreated;
}