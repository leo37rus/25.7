#include"Chat.h"

using namespace std;
int main()
{
	cout << "\033[31m\n";
	cout << "                                                      .$$$' $.                .$ '$$$\n";
	cout << "                                                      $$$. .$$                $$. .$$$.\n";
	cout << "                                                      $$$$$$$$                 $$$$$$$$\n";
	cout << "           $$                                         '$$$$$$      $     $      $$$$$$'\n";
	cout << "           $$                                           '$$$$   .$$0$$$$$0$$$.   $$$$'\n";
	cout << "           $$                 $$                          '$$..$$$$$$$$$$$$$$$$..$$'\n";
	cout << "           $$                 $$                      .$$.  $$$$$$$$$$$$$$$$$$$$$$' .$$.\n";
	cout << "  ..$$$$.  $$$$$$$.   .$$$.  $$$$$                  .$$''$$.:$$$$$$$$$$$$$$$$$$$$: $$  $$\n";
	cout << " $$'    '$ $$'   '$$ '    $$  $$                    $'    :$$$$$$$$$$$$$$$$$$$$$$$$'    '$\n";
	cout << "$$:        $$     $$ .$$$$$$  $$                    $ .$$$'  '$$$$$$$$$$$$$$$$$$'  .$$$. $\n";
	cout << " $$.    .$ $$     $$ $   .$$  $$                     .$' '$$$$'$$$$$$$$$$$$$$$$'$$$$' '$\n";
	cout << "  '$$$$$$' $$     $$ '$$$$ $$ '$$$$   4.7           $:       .$'$$$$$$$$$$$$'$.       '$\n";
	cout << "                                                     '$     .$$$              '$$$.     $\n";
	cout << "                                                            $'                   '$\n\033[37m";
	string login, str;
	char choice_menu;
	Chat chat;

	Network netConnect;
	auto connectNet = netConnect.ClientOpen();
	cout << "CONNECTION:  " << connectNet << std::endl;
	if (connectNet == -1)
	{cout << "—бой сети!" << std::endl;exit(-1);}
	do
	{choice_menu = mainMenu();
		if (incorrectInputMenu(choice_menu))
		{str = choice_menu;netConnect.sendMessage(connectNet, str);}

		if (choice_menu == '1')
		{login = chat.signUp(connectNet);
			if (login != "error"){chat.messageWriteRead(connectNet, login);}}
		if (choice_menu == '2')
		{auto loginIn = chat.entrance(connectNet);
			if (loginIn != "error")
			{chat.messageWriteRead(connectNet, loginIn);}}
	} while (choice_menu != '3');
	netConnect.connectClose(connectNet);
	return 0;
}


