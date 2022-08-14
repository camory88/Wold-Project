#include <Windows.h>
#include <string>
#include "People.h"
#include "tools.h"

person p = person();
void infoPage();

void inspectPage()
{
	system("cls");
	std::cout << "[ Shift ] back" << std::endl;

	for (int i = 0; i < p.people; ++i)
	{

		std::cout << "Name: " << p.PersonName[i].c_str() << "   Id: " << p.PersonId[i] << std::endl;
	}
	while (true)
	{
		if (getKeyDown(VK_SHIFT))
		{
			infoPage();
			Sleep(500);
		}
	}
}

void infoPage()
{
	system("cls");
	std::cout << "===== ADD =====\n" << std::endl;
	std::cout << "[ UP arrow ] ADD Person" << std::endl;

	std::cout << "\n===== INFO =====\n" << std::endl;
	std::cout << "People -> " << p.people << std::endl;

	std::cout << "\n[ Shift ] inspect all people" << std::endl;

	while (true)
	{
		name = "";
		if (getKeyDown(VK_UP))//add person
		{
			p.PersonId[p.people] = p.people;//set person id

			system("cls");
			std::cout << "typpe new name here: ";
			std::cin >> name;
			if (name.size() >= 11)//cheack if name > 10 caricters
			{
				MessageBoxA(0, 0, "Name to long!", 4);
				system("cls");
				std::cout << "typpe new name here: ";
				std::cin >> name;
			}

			p.PersonName[p.people] = name;//set name

			p.people += 1;
			Sleep(100);
			infoPage();
		}
		else if (getKeyDown(VK_SHIFT))
		{
			inspectPage();
			Sleep(500);
		}
	}
}

int main()
{
	infoPage();

	return 0;
}