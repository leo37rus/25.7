#include"Chat.h"
using namespace std;

Chat::Chat() = default;
Chat::~Chat() = default;

string Chat::signUp(int connect)
{
	string name, login, password;

	Network netConnect;
	name = inputName();
	netConnect.sendMessage(connect, name);
	login = inputLogin();
	netConnect.sendMessage(connect, login);
	password = inputPass();
	netConnect.sendMessage(connect, password);
	string str = netConnect.reseiveMessage(connect);
	if (strncmp("error", str.c_str(), 5) == 0)
	{cout << "This username/login/password has already been registered.\n Please try again. "<<endl; return "error";}
	else
	{cout << str << endl;return login;}}

string Chat::entrance(int connect)
{	string login, password;
	Network netConnect;
	login = inputLogin();
	netConnect.sendMessage(connect, login);
	password = inputPass();
	netConnect.sendMessage(connect, password);
	string str = netConnect.reseiveMessage(connect);
	if (strncmp("Entrance", str.c_str(), 4) == 0){cout << str << endl;return login;}
	else{cout << str << std::endl;return "error";}}

void Chat::abonentList(int connection, const std::string& login_from)
{	Network netConnect;
	cout << "Subscribers: all /";
	string str = netConnect.reseiveMessage(connection);
	cout << str << '\n';}

bool Chat::correctInputAbonent(int connection, const std::string& login_to)
{	Network netConnect;
	string str = netConnect.reseiveMessage(connection);
	if (strncmp("true", str.c_str(), 4) == 0){return true;}
	return false;}

void Chat::messageInputAll(int connect)
{	string text = massageText();
	Network netConnect;
	netConnect.sendMessage(connect, text);}

void Chat::messageInputFromTo(int connect, const std::string& login_from) {
	string text,login_to;
	Network netConnect;

	abonentList(connect, login_from);
	login_to = inputTo();
	netConnect.sendMessage(connect, login_to);
	if (login_to == "everyone"){messageInputAll(connect);}
	else{if (correctInputAbonent(connect, login_to))
		{text = massageText();netConnect.sendMessage(connect, text);}
		else
		{incorrectInputMenuMessage();}}
}

void Chat::messageReadPersonal(int connect, const std::string& login_from)
{	Network netConnect;
	string str1 = netConnect.reseiveMessage(connect);
	if (strncmp("error", str1.c_str(), 2) == 0){cout << "There are no private messages." << endl;return;}
	cout << "Private messages : " << endl << str1 << std::endl;}

void Chat::messageReadAll(int connect)
{	Network netConnect;
	string str1 = netConnect.reseiveMessage(connect);

	if (strncmp("error", str1.c_str(), 2) == 0){cout << "There are no messages from the general chat. " << std::endl;return;}
	cout << "General chat messages:     " << endl << str1 << std::endl;}

void Chat::messageWriteRead(int connect, const std::string& login_from)
{	Network netConnect;
	string str;
	char choice;
	do
	{	choice = menuMessage();
		str = choice;
		netConnect.sendMessage(connect, str);
		switch (choice)
	   {case '1':messageReadAll(connect);break;
		case '2':messageReadPersonal(connect, login_from);break;
		case '3':messageInputFromTo(connect, login_from);break;
		case '4':break;
		default:incorrectInputMenuMessage();break;}
	} while (choice != '4');
}