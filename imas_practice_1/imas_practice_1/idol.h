#pragma once
class idol
{
public:
	idol(int age, int size, const char* name, const char* words);
	idol(const idol &ref);
	~idol();
private:
	int age;
	int size;
	char* name;
	char* words;
protected:
	void StrToDes(char* &destination, const char* source);
public:
	int GetAge() const;
	int GetSize() const;
	const char* GetName() const;
	const char* GetWords() const;

//���̵��� �ൿ(�ϸ� �޼��� Method)
	void DoHateSpeech(const idol &target);
};

