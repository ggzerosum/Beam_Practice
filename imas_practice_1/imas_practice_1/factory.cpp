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
	//��ȣ�� ������ ��� �ؽ�Ʈ ������ ����.
	FILE* TextFile;
	fopen_s(&TextFile, "Shiho's hate speech.txt", "r");

	//���� TextFile��� �༮�� ������ ���� ������ �о���̱�.
	char name[32] = { '\0' };
	char words[102] = { '\0' };
	int age, size;

	for (int i = 0; i < 50; i++)
	{
		if (fgets(name, 32, TextFile) == NULL)
			return;
		
		//�̸�, ������, �� �� �Է�
		fscanf_s(TextFile, "%d %d ", &age, &size);
		fgets(words, 102, TextFile);

		//���̵� ���� �� ��Ͽ� ����
		ListOfIdols[i] = new idol(age, size, name, words);

		//�� ������ ���ؼ�
		fgets(name, 32, TextFile);

		SizeOfList++;
	}

	fclose(TextFile);
}

idol* factory::SearchIdol(void)
{
	char name[32] = { '\0' };
	cout << "��ȣ�� ��ȭ�� ���: ";
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