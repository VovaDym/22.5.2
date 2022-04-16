#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map <std::string, int> queue;
	std::string answer;

	while (true)
	{
		std::cout << "Enter last name or command \"Next\"" << std::endl;
		std::getline(std::cin, answer);

		system("cls");

		if (answer == "Next")
		{
			std::map <std::string, int>::iterator it = queue.begin();

			if (it != queue.end())
			{
				std::cout << "Calling: " << it->first << std::endl;
				if (it->second > 1)
				{
					--it->second;
				}
				else
				{
					queue.erase(it);
				}
			}
			else
			{
				std::cout << "Queue is empty" << std::endl;
			}
		}
		else
		{
			std::map <std::string, int>::iterator itf = queue.find(answer);
			if (itf == queue.end())
			{
				queue.insert(std::pair <std::string, int>(answer, 1));
			}
				
			else
			{
				++itf->second;
			}	
			std::cout << "Added " << answer << " on queue" << std::endl;
		}
	}
}
		