#include <iostream>
using namespace std;
class MyString
{
private:
	//��������� �� ���, ��� �������, ������� �� �������� � ��� ������ 
	char* str{};
	int len{};
public:
	//��������� ��� ���������� 
MyString() 
	{
		str = nullptr;
		len = 0;
	}
// ��������� � �����������, ��� �������� ������� ����� ���������� ������, ������� ����� �������  
MyString(const char * str) {
		
		len = strlen(str);
		//�������� ������ ��� ����� ���� ��� ������ ������ 
		this->str = new char[len+1];
		for (int i = 0; i < len; i++)
		{
			this->str[i] = str[i]; //�������� �� ������ ������� � ������
		}
		this->str[len] = '\0'; // ������ ����������� 
		// ���� ����� - ������ ������ 
	}
~MyString()
	{
		delete[] this->str; // ������� ����� ������ ������� ������ 
	}
//����������� �����������, ����� ��� ����� ����� ������� ������, �� � ������ ������� ������ 
MyString(const MyString &other) //const ������ �� ������ ������
{
	
	int len = strlen(other.str);
	this->str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[len] = '\0';
	
}
MyString& operator = (const MyString &other) //const ������ �� ������ ������
{
	if(this->str!=nullptr)
	{
		delete[] str; // ���� �� ���� 
	}
	len = strlen(other.str);
	this->str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[len] = '\0'; 
	return *this;
}
//����������� ������ ������� (����� ��� ������ str+str2)
MyString operator+(const MyString& other)
{
	MyString newStr;
	int thisLen = strlen(this->str);
	int otherLen = strlen(other.str);
	newStr.len = thisLen + otherLen;
	// �������� �����
	newStr.str = new char[thisLen + otherLen + 1];
	//new mass �� ������� ���������� ��� ����� �������
	int i = 0;
	for (; i < thisLen; i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < otherLen; i++, j++)
	{
		newStr.str[i] = other.str[j];
	}
	// ����� ��������� ������
	newStr.str[thisLen + otherLen] = '\0';
	return newStr;
}
//������� ������
void printf_s()
	{
	cout << str;
	}
int Lenght()
{
	return len;
}
};
int main() 
{
	MyString str("Hello_");
	MyString str2("World");
	MyString result;
	result = str + str2;
	cout << "Length: " << str.Lenght() << endl;
	cout << "Length: " << str2.Lenght() << endl;
	cout << "Length: " << result.Lenght() << endl;
	result.printf_s();
	cout << endl << endl;
	return 0;
}