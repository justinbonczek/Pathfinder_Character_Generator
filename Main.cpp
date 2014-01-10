#include "Character.h"
#include <iostream>
#include <sstream>
#include <fstream>

//Clears party.txt for a new party
void ClearParty();

int main()
{
	ClearParty();
	std::cout << "Welcome to the character generator. Type done to quit." << std::endl;
	std::string choice;

	while(true)
	{
		std::cout << "Random generation? y/n ";
		std::cin >> choice;
		std::cin.ignore();

		if(choice != "y" && choice != "n")
		{
			std::cout << "Invalid input please try again.";
			continue;
		}
		else
			break;
	}

	bool running = true;
	while(running)
	{
		if(choice == "y")
		{
			std::string name;
			std::cout << "Character name? ";
			std::getline(std::cin, name);
			
			if(name == "done" || name == "Done" || name == "DONE")
				break;
			else if(name == "party")
			{
				std::cout << "'party' is an invalid character name";
				continue;
			}

			Character character(name.c_str());
			character.Print();
			character.Export();
			std::cout << std::endl;
		}
		else if(choice == "n")
		{
			std::string name;
			std::cout << "Character name? ";
			std::getline(std::cin, name);

			if(name == "done" || name == "Done" || name == "DONE")
				break;
			else if(name == "party")
			{
				std::cout << "'party' is an invalid character name";
				continue;
			}

			std::string race;
			std::cout << "Character race? ";
			std::getline(std::cin, race);
			Race myRace;

			if(race == "Dwarf" || race == "dwarf")
			{
				myRace = Dwarf;
			}
			else if(race == "Elf" || race == "elf")
			{
				myRace = Elf;
			}
			else if(race == "Gnome" || race == "gnome")
			{
				myRace = Gnome;
			}
			else if(race == "Half-Elf" || race == "Half-elf" || race ==  "half-elf" ||
				race == "Half Elf" || race == "Half elf" || race == "half elf" || 
				race == "Halfelf" || race == "halfelf")
			{
				myRace = HalfElf;
			}
			else if(race == "Half-Orc" || race == "Half-orc" || race ==  "half-orc" ||
				race == "Half Orc" || race == "Half orc" || race == "half orc" ||
				race == "Halforc" || race == "halforc")
			{
				myRace = HalfOrc;
			}
			else if(race == "Halfling" || race == "halfling")
			{
				myRace = Halfling;
			}
			else if(race == "Human" || race == "human")
			{
				myRace = Human;
			}
			else
			{
				std::cout << "Invalid race" << std::endl;
				continue;
			}

			std::string characterClass;
			std::cout << "Character class? ";
			std::getline(std::cin, characterClass);
			Class myClass;

			if(characterClass == "Barbarian" || characterClass == "barbarian")
				myClass = Barbarian;
			else if(characterClass == "Bard" || characterClass == "bard")
				myClass = Bard;
			else if(characterClass == "Cleric" || characterClass == "cleric")
				myClass = Cleric;
			else if(characterClass == "Druid" || characterClass == "druid")
				myClass = Druid;
			else if(characterClass == "Fighter" || characterClass == "fighter")
				myClass = Fighter;
			else if(characterClass == "Monk" || characterClass == "monk")
				myClass = Monk;
			else if(characterClass == "Paladin" || characterClass == "paladin")
				myClass = Paladin;
			else if(characterClass == "Ranger" || characterClass == "ranger")
				myClass = Ranger;
			else if(characterClass == "Rogue" || characterClass == "rogue")
				myClass = Rogue;
			else if(characterClass == "Sorcerer" || characterClass == "sorcerer")
				myClass = Sorcerer;
			else if(characterClass == "Wizard" || characterClass == "wizard")
				myClass = Wizard;
			else
			{
				std::cout << "Invalid class" << std::endl;
				continue;
			}
			std::cout << std::endl;

			Character character(name.c_str(), myRace, myClass);
			
			if(myRace == Human || myRace == HalfElf || myRace == HalfOrc)
			{
				do
				{
				
					std::string score;
					std::cout << "+2 to which Ability Score? ";
					std::getline(std::cin, score);

					if(score == "Strength" || score == "strength" || score == "Str" || 
						score == "str")
					{
						character.IncreaseScore(character.Strength(), 2);
						break;
					}
					else if(score == "Dexterity" || score == "dexterity" || score == "Dex" || 
						score == "dex")
					{
						character.IncreaseScore(character.Dexterity(), 2);
						break;
					}
					else if(score == "Constitution" || score == "constitution" || score == "Con" || 
						score == "con")
					{
						character.IncreaseScore(character.Constitution(), 2);
						break;
					}
					else if(score == "Intelligence" || score == "intelligence" || score == "Int" || 
						score == "int")
					{
						character.IncreaseScore(character.Intelligence(), 2);
						break;
					}
					else if(score == "Wisdom" || score == "wisdom" || score == "Wis" || 
						score == "wis")
					{
						character.IncreaseScore(character.Wisdom(), 2);
						break;
					}
					else if(score == "Charisma" || score == "charisma" || score == "Cha" || 
						score == "cha")
					{
						character.IncreaseScore(character.Charisma(), 2);
						break;
					}
					else
					{
						std::cout << "Invalid stat try again." << std::endl;
						continue;
					}
				} while(true);
			}

			character.Print();
			character.Export();
			std::cout << std::endl;
		}
	}

	system("pause");
}

void ClearParty()
{
	std::ofstream party;
	party.open("party.txt");
	party.clear();
	party.close();
}