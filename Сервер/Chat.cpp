#include "Chat.h"

Chat::Chat() = default;
Chat::~Chat() = default;
using namespace std;
void Chat::connectMySQL()
{_data.openData();_data.createDataTable();}

void Chat::disconnectMySQL()
{_data.closeData();}

string Chat::signUp(int connection)
{string name, login, password;
	Network netConnect;
	name = netConnect.reseiveMessage(connection);
	login = netConnect.reseiveMessage(connection);
	password = netConnect.reseiveMessage(connection);

	if (_data.insirtDataUser(name, login, password))
	{netConnect.sendMessage(connection, "Congratulations, you have successfully registered.");return login;}
	else
	{netConnect.sendMessage(connection, "error");return "error";}}

string Chat::entrance(int connection)
{Network netConnect;
	auto count = 0;
string login = netConnect.reseiveMessage(connection);
string password = netConnect.reseiveMessage(connection);

	if (_data.entranceDataUser(login, password)){netConnect.sendMessage(connection, "Login completed successfully..");return login;}
	else{netConnect.sendMessage(connection, "There is no such username/password. You may not be registered yet.");return "error";}}

void Chat::abonentList(int connection, const std::string &login_from)
{Network netConnect;
string str;
str = _data.readDataUsersLogin(login_from);
netConnect.sendMessage(connection, str);}

bool Chat::correctInputAbonent(int connection, const std::string &login_to)
{Network netConnect;
	if (_data.correctDataInputAbonent(login_to)){netConnect.sendMessage(connection, "true");return true;}
	else{netConnect.sendMessage(connection, "false");return false;}}

void Chat::messageInputAll(int connection, const std::string &login_from)
{Network netConnect;string text = netConnect.reseiveMessage(connection);
	_data.insertDataMessageAll(login_from, text);	}

void Chat::messageInputFromTo(int connection, const std::string &login_from)
{string text;
	string login_to;
	Network netConnect;

	abonentList(connection, login_from);
	login_to = netConnect.reseiveMessage(connection);
	if (login_to == "всем"){messageInputAll(connection, login_from);}
	else
	{if (correctInputAbonent(connection, login_to))
		{text = netConnect.reseiveMessage(connection);_data.insertDataMessage(login_from, login_to, text);}}}

void Chat::messageReadPersonal(int connection, const std::string &login_from)
{auto count = 0;
string str;
	Network netConnect;
	str = _data.readDataMessage(login_from);
	if (!str.empty()){netConnect.sendMessage(connection, str);}
	else{netConnect.sendMessage(connection, "error");}}

void Chat::messageReadAll(int connection)
{string str;
	Network netConnect;
	str = _data.readDataMessageAll();
	if (!str.empty())
	{netConnect.sendMessage(connection, str);}
	else
	{netConnect.sendMessage(connection, "error");}}

void Chat::messageWriteRead(int connection, const std::string &login_from)
{Network netConnect;
	const char *choice;
	string str;
	do
	{str = netConnect.reseiveMessage(connection);
		choice = str.c_str();
		switch (choice[0])
	   {case '1':messageReadAll(connection);break;
		case '2':messageReadPersonal(connection, login_from);break;
		case '3':messageInputFromTo(connection, login_from);break;
		case '4':break;
		default:break;}
	} while (choice[0] != '4');
}
