#include "PasswordGenerator.h"
#include <ctime>
using namespace std;


string arr{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',\
'q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I',\
'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1',\
'2','3','4','5','6','7','8','9' };

//string arr{ 'a','b','c','d','e','f','g','h' };
void Print(string& str)
{
	for (auto i = str.begin(); i != str.end(); i++)
	{
		cout << *i;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	unsigned count = 0; //счетчик вариантов подбора паролей

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//создание секретной строки для пароля (по факту создаем пароль)
	cout << " Введите пароль : ";
	string secretword;                   //строка для ввода пароля и для подбора пароля
	int a;                               //определение количества символов в пароле
	do
	{
		getline(cin, secretword);        //ввод пароля
		a = secretword.size();           //определение количества символов в пароле
		if (a != 4 && a != 5 && a != 6 && a != 7 && a != 8)
		{
			cout << " Вы ввели " << a << " символa(ов). Введите от 4 до 8 символов. Попытайтесь ещё раз: ";
		}


	} while (a != 4 && a != 5 && a != 6 && a != 7 && a != 8);
	string new_password;
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//считываем в строку варианты паролей из файла
	ifstream password_file("8-more-passwords.txt");
	string beta;                        //сюда считываем файл123456789
	string str;                         //буферная строка
	if (password_file.is_open())        //проверка на открытие файла
	{
		cout << " Файл открыт" << endl;
		while (!password_file.eof())    //считывание файла по строчно
		{
			//str = "";
			getline(password_file, str);
			//cout << str;
			beta = beta + str;
		}
	}
	else cout << " файл не открыт" << endl;
	password_file.close();              //закрываем файл
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	ofstream fout("myfile.txt");        //открываем файл для записи результата программы
	if (!fout.is_open()) cout << " Файл не открылся" << endl;
	int pos;
	pos = beta.find(secretword);         //находим начало вхождения пароля в строке считанной из файла
	if (pos == (-1))
	{
		cout << " пароль в файле не найден" << endl;
		fout << " пароль в файле не найден" << endl;
	}
	else
	{
		new_password = beta.substr(pos, a); //извлекаем найденный пароль из строки сгенерированных вариантов
		cout << " пароль найден в файле : " << new_password << endl;
		fout << " пароль найден в файле : " << new_password << endl;
		return 0;
	}
	fout.close();
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//генерируем пароли и сравниваем с введенным
	unsigned start, end;
	switch (a)
	{
	case 4:
	{
		start = clock();
		Password_4_symbol(arr, secretword);
		end = clock();
		break;
	}
	case 5:
	{
		start = clock();
		Password_5_symbol(arr, secretword);
		end = clock();
		break;
	}
	case 6:
	{
		start = clock();
		Password_6_symbol(arr, secretword);
		end = clock();
		break;
	}
	case 7:
	{
		start = clock();
		Password_7_symbol(arr, secretword);
		end = clock();
		break;
	}
	case 8:
	{
		start = clock();
		Password_8_symbol(arr, secretword);
		end = clock();
		break;
	}
	default:
		break;
	}
	//рассчитываем время затраченное на работу программы
	int t = (end - start) / CLOCKS_PER_SEC;
	int hour, minut, sec;
	//cout << " start: " << start << endl;
	//cout << " end: " << end << endl;
	ofstream fout1("myfile.txt", ios::app); //открываем файл для записи результата программы
	if (!fout1.is_open()) cout << " Файл не открылся" << endl;
	if (t < 60)
	{
		cout << " Затраченное время на подбор пароля: " << t << " c" << endl;
		fout1 << " Затраченное время на подбор пароля: " << t << " c" << endl;
	}
	else if (t < 3600)
	{
		 minut = t / 60;
		 sec = t % 60;
		cout << " Затраченное время на подбор пароля: " <<minut << " мин "<<sec<<" c" << endl;
		fout1 << " Затраченное время на подбор пароля: " <<minut << " мин "<<sec<<" c" << endl;
	}
	else
	{
		hour = t / 3600;
		int a = t % 3600;
		minut = a / 60;
		sec = a % 60;
		cout << " Затраченное время на подбор пароля: " << hour<<" ч "<<minut<<" мин"<<sec << " c" << endl;
		fout1 << " Затраченное время на подбор пароля: " << hour<<" ч "<<minut<<" мин"<<sec << " c" << endl;
	}
	cout << " Затраченное время на подбор пароля (справочно): " << t << " c" << endl;
	fout1<< " Затраченное время на подбор пароля (справочно): " << t << " c" << endl;
	fout1.close();
	return 0;
}
