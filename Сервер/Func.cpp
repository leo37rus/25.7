#include"Func.h"
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;
#define MESSAEG_LENGHT 4048 
#define PORT 51051

char mainMenu()
{	char choice;
	cout << "             .$$$$$$$.             .$$$$$$$.           .$$$$$$$. " << endl;
	cout << "$$$..   ..$$$'       '$$$..   ..$$$'      '$$$..   ..$$$'     '$$$." << endl;
	cout << "  '$$$$$$$'             '$$$$$$$'            '$$$$$$$'           '$$$\033[37m" << endl << endl;
	cout << " (1 - Registration" << endl << " (2 - Entrance" << endl << " (3 - Exiting" << endl;
	cout << "             .$$$$$$$.             .$$$$$$$.           .$$$$$$$. " << endl;
	cout << "$$$..   ..$$$'       '$$$..   ..$$$'      '$$$..   ..$$$'     '$$$." << endl;
	cout << "  '$$$$$$$'             '$$$$$$$'            '$$$$$$$'           '$$$\033[37m" << endl << endl;
	cout << "Choice -  ";
	cin >> choice;cin.ignore(100, '\n');
	return choice;}

char menuMessage()
{	cout << "             .$$$$$$$.             .$$$$$$$.           .$$$$$$$. " << endl;
	cout << "$$$..   ..$$$'       '$$$..   ..$$$'      '$$$..   ..$$$'     '$$$." << endl;
	cout << "  '$$$$$$$'             '$$$$$$$'            '$$$$$$$'           '$$$\033[37m" << endl << endl;
	cout << " (1 - Get messages from a general chat" << endl << " (2 - Get private messages." << endl;
	cout << " (3 - To write a message." << endl << " (4 - Sign out of your account." << endl;
	cout << "             .$$$$$$$.             .$$$$$$$.           .$$$$$$$. " << endl;
	cout << "$$$..   ..$$$'       '$$$..   ..$$$'      '$$$..   ..$$$'     '$$$." << endl;
	cout << "  '$$$$$$$'             '$$$$$$$'            '$$$$$$$'           '$$$\033[37m" << endl << endl;
	cout << " Choice -  ";
	char choice;
	cin >> choice;cin.ignore(100, '\n');
	return choice;}

string inputName()
{string str; cout << "Name - ";
	cin >> str; return str;}

string inputLogin()
{string str; cout << "Login - ";
	cin >> str; return str;}

string inputPass()
{string str; cout << "Password - ";
	cin >> str; return str;}

string inputTo()
{string str;
	cout << endl << "To whom - ";
	cin >> str; return str;}

std::string inputTo()
{string str;
	cout << endl << "To whom - ";
	cin >> str;return str;}

std::string massageText()
{string text;
	cout << ">> ";
	cin.ignore();getline(cin, text);
	return text;}

void incorrectInputMenuMessage()
{cout << "Invalid input. Try again." << std::endl;}

void incorrectInputMenu(char choice_menu)
{if (choice_menu < 49 || choice_menu > 52){cout << endl << "Invalid input. Try again." << std::endl;}}

void noMessages(){cout << "There are no private messages for you. << std::endl;}

