#include"Func.h"
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

char mainMenu()
{
	char choice;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << " (1) �����������" << std::endl;
	std::cout << " (2) ����" << std::endl;
	std::cout << " (3) ����� �� ���������" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	std::cout << "����� -  ";
	std::cin >> choice;
	std::cin.ignore(1, '\n');
	return choice;
}

char menuMessage()
{
	std::cout << "******************************" << std::endl;
	std::cout << " *1* �������� ��������� �� ������ ����." << std::endl;
	std::cout << " *2* �������� ������ ���������." << std::endl;
	std::cout << " *3* �������� ���������." << std::endl;
	std::cout << " *4* ����� �� ������� ������." << std::endl;
	std::cout << "******************************" << std::endl;

	std::cout << " ����� -  ";
	char choice;
	std::cin >> choice;
	std::cin.ignore(100, '\n');
	return choice;
}

std::string inputName()
{
	std::string str;
	std::cout << "��� - ";
	std::cin >> str;
	return str;
}

std::string inputLogin()
{
	std::string str;
	std::cout << "����� - ";
	std::cin >> str;
	return str;
}

std::string inputPass()
{
	std::string str;
	std::cout << "������ - ";
	std::cin >> str;
	return str;
}

std::string inputTo()
{
	std::string str;
	std::cout << std::endl;
	std::cout << "���� - ";
	/*std::cin.ignore();
	std::getline(std::cin, str);*/
	std::cin >> str;
	return str;
}

std::string massageText()
{
	std::string text;
	std::cout << ">>  ";
	std::cin.ignore();
	std::getline(std::cin, text);

	return text;
}

void incorrectInputMenuMessage()
{
	std::cout << "������������ ����. ���������� ��� ���." << std::endl;

}

bool incorrectInputMenu(char choice_menu)
{
	if (choice_menu < 49 || choice_menu > 52)
	{
		std::cout << std::endl;
		std::cout << "������������ ����. ���������� ��� ���." << std::endl;
		return false;
	}
	return true;
}

/*void noMessages()
{
	std::cout << "��� ��� ������ ��������� ���." << std::endl;
}*/

