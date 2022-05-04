#include <iostream>
using namespace std;
class MyString
{
private:
	//указатель на чар, все символы, которые мы передали в наш объект 
	char* str{};
	int len{};
public:
	//конструкт без параметров 
MyString() 
	{
		str = nullptr;
		len = 0;
	}
// конструкт с параметрами, при создании объекта нужно переделать строку, которую бужем хранить  
MyString(const char * str) {
		
		len = strlen(str);
		//выделяем память для диман масс где храним строку 
		this->str = new char[len+1];
		for (int i = 0; i < len; i++)
		{
			this->str[i] = str[i]; //копируем из одного массива в другой
		}
		this->str[len] = '\0'; // строка закончилась 
		// есть класс - хранит строку 
	}
~MyString()
	{
		delete[] this->str; // очистка после выхода объекта класса 
	}
//конструктор копирования, нужен для точно копии объекта класса, но в другой области памяти 
MyString(const MyString &other) //const ссылка на объект класса
{
	
	int len = strlen(other.str);
	this->str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[len] = '\0';
	
}
MyString& operator = (const MyString &other) //const ссылка на объект класса
{
	if(this->str!=nullptr)
	{
		delete[] str; // если не ноль 
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
//возвращение нового объекта (клеим две строки str+str2)
MyString operator+(const MyString& other)
{
	MyString newStr;
	int thisLen = strlen(this->str);
	int otherLen = strlen(other.str);
	newStr.len = thisLen + otherLen;
	// выделяем место
	newStr.str = new char[thisLen + otherLen + 1];
	//new mass из которых складываем две новые строчки
	int i = 0;
	for (; i < thisLen; i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < otherLen; i++, j++)
	{
		newStr.str[i] = other.str[j];
	}
	// когда закрываем строку
	newStr.str[thisLen + otherLen] = '\0';
	return newStr;
}
//костыль вывода
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