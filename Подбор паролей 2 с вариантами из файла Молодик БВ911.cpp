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
	unsigned count = 0; //������� ��������� ������� �������

	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//�������� ��������� ������ ��� ������ (�� ����� ������� ������)
	cout << " ������� ������ : ";
	string secretword;                   //������ ��� ����� ������ � ��� ������� ������
	int a;                               //����������� ���������� �������� � ������
	do
	{
		getline(cin, secretword);        //���� ������
		a = secretword.size();           //����������� ���������� �������� � ������
		if (a != 4 && a != 5 && a != 6 && a != 7 && a != 8)
		{
			cout << " �� ����� " << a << " ������a(��). ������� �� 4 �� 8 ��������. ����������� ��� ���: ";
		}


	} while (a != 4 && a != 5 && a != 6 && a != 7 && a != 8);
	string new_password;
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//��������� � ������ �������� ������� �� �����
	ifstream password_file("8-more-passwords.txt");
	string beta;                        //���� ��������� ����123456789
	string str;                         //�������� ������
	if (password_file.is_open())        //�������� �� �������� �����
	{
		cout << " ���� ������" << endl;
		while (!password_file.eof())    //���������� ����� �� �������
		{
			//str = "";
			getline(password_file, str);
			//cout << str;
			beta = beta + str;
		}
	}
	else cout << " ���� �� ������" << endl;
	password_file.close();              //��������� ����
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	ofstream fout("myfile.txt");        //��������� ���� ��� ������ ���������� ���������
	if (!fout.is_open()) cout << " ���� �� ��������" << endl;
	int pos;
	pos = beta.find(secretword);         //������� ������ ��������� ������ � ������ ��������� �� �����
	if (pos == (-1))
	{
		cout << " ������ � ����� �� ������" << endl;
		fout << " ������ � ����� �� ������" << endl;
	}
	else
	{
		new_password = beta.substr(pos, a); //��������� ��������� ������ �� ������ ��������������� ���������
		cout << " ������ ������ � ����� : " << new_password << endl;
		fout << " ������ ������ � ����� : " << new_password << endl;
		return 0;
	}
	fout.close();
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//���������� ������ � ���������� � ���������
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
	//������������ ����� ����������� �� ������ ���������
	int t = (end - start) / CLOCKS_PER_SEC;
	int hour, minut, sec;
	//cout << " start: " << start << endl;
	//cout << " end: " << end << endl;
	ofstream fout1("myfile.txt", ios::app); //��������� ���� ��� ������ ���������� ���������
	if (!fout1.is_open()) cout << " ���� �� ��������" << endl;
	if (t < 60)
	{
		cout << " ����������� ����� �� ������ ������: " << t << " c" << endl;
		fout1 << " ����������� ����� �� ������ ������: " << t << " c" << endl;
	}
	else if (t < 3600)
	{
		 minut = t / 60;
		 sec = t % 60;
		cout << " ����������� ����� �� ������ ������: " <<minut << " ��� "<<sec<<" c" << endl;
		fout1 << " ����������� ����� �� ������ ������: " <<minut << " ��� "<<sec<<" c" << endl;
	}
	else
	{
		hour = t / 3600;
		int a = t % 3600;
		minut = a / 60;
		sec = a % 60;
		cout << " ����������� ����� �� ������ ������: " << hour<<" � "<<minut<<" ���"<<sec << " c" << endl;
		fout1 << " ����������� ����� �� ������ ������: " << hour<<" � "<<minut<<" ���"<<sec << " c" << endl;
	}
	cout << " ����������� ����� �� ������ ������ (���������): " << t << " c" << endl;
	fout1<< " ����������� ����� �� ������ ������ (���������): " << t << " c" << endl;
	fout1.close();
	return 0;
}
