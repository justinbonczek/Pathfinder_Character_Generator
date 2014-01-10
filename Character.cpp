#include "Character.h"
#include <lua.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

const ushort BARBARIAN_HIT_DICE = 12;
const ushort BARD_HIT_DICE = 8;
const ushort CLERIC_HIT_DICE = 8;
const ushort DRUID_HIT_DICE = 8;
const ushort FIGHTER_HIT_DICE = 10;
const ushort MONK_HIT_DICE = 8;
const ushort PALADIN_HIT_DICE = 10;
const ushort RANGER_HIT_DICE = 10;
const ushort ROGUE_HIT_DICE = 8;
const ushort SORCERER_HIT_DICE = 6;
const ushort WIZARD_HIT_DICE = 6;

Character::Character()	 :
	m_Name("Default Name"),
	m_Level(1),
	m_Health(0)
{
	//Initialize values
	m_Strength = 0;
	m_Dexterity = 0;
	m_Constitution = 0;
	m_Intelligence = 0;
	m_Wisdom = 0;
	m_Charisma = 0;
	m_ArmorClass = 0;
	m_Fortitude = 0;
	m_Reflex = 0;
	m_Will = 0;
	m_CombatManeuverDefense = 0;
	m_ArmorValue = 0;
	m_BaseAttackBonus = 0;
	m_CombatManeuverBonus = 0;
	m_Size = Medium;

	GenerateRaceAndClass();
	do
	{
		GenerateAbilityScores();
	}
	while(ConvertToMod(m_Strength) + ConvertToMod(m_Dexterity) + 
		ConvertToMod(m_Constitution) + ConvertToMod(m_Intelligence) + 
		ConvertToMod(m_Wisdom) + ConvertToMod(m_Charisma) < 0 &&
		ConvertToMod(m_Strength) + ConvertToMod(m_Dexterity) + 
		ConvertToMod(m_Constitution) + ConvertToMod(m_Intelligence) + 
		ConvertToMod(m_Wisdom) + ConvertToMod(m_Charisma) > 7);
	MakeAdjustments();
}

Character::Character(const char* name) :
	m_Name(name),
	m_Level(1),
	m_Health(0)
{
	//Initialize values
	m_Strength = 0;
	m_Dexterity = 0;
	m_Constitution = 0;
	m_Intelligence = 0;
	m_Wisdom = 0;
	m_Charisma = 0;
	m_ArmorClass = 0;
	m_Fortitude = 0;
	m_Reflex = 0;
	m_Will = 0;
	m_CombatManeuverDefense = 0;
	m_ArmorValue = 0;
	m_BaseAttackBonus = 0;
	m_CombatManeuverBonus = 0;
	m_Size = Medium;

	GenerateRaceAndClass();
	do
	{
		GenerateAbilityScores();
	}
	while(ConvertToMod(m_Strength) + ConvertToMod(m_Dexterity) + 
		ConvertToMod(m_Constitution) + ConvertToMod(m_Intelligence) + 
		ConvertToMod(m_Wisdom) + ConvertToMod(m_Charisma) < 1 && 
		ConvertToMod(m_Strength) + ConvertToMod(m_Dexterity) + 
		ConvertToMod(m_Constitution) + ConvertToMod(m_Intelligence) + 
		ConvertToMod(m_Wisdom) + ConvertToMod(m_Charisma) > 7 );
	MakeAdjustments();
}

Character::Character(const char* name, Race race, Class characterClass) :
	m_Name(name),
	m_Level(1),
	m_Health(0),
	m_Race(race),
	m_Class(characterClass)
{
	//Initialize values
	m_Strength = 0;
	m_Dexterity = 0;
	m_Constitution = 0;
	m_Intelligence = 0;
	m_Wisdom = 0;
	m_Charisma = 0;
	m_ArmorClass = 0;
	m_Fortitude = 0;
	m_Reflex = 0;
	m_Will = 0;
	m_CombatManeuverDefense = 0;
	m_ArmorValue = 0;
	m_BaseAttackBonus = 0;
	m_CombatManeuverBonus = 0;
	m_Size = Medium;

	do
	{
		GenerateAbilityScores();
	}
	while(ConvertToMod(m_Strength) + ConvertToMod(m_Dexterity) + 
		ConvertToMod(m_Constitution) + ConvertToMod(m_Intelligence) + 
		ConvertToMod(m_Wisdom) + ConvertToMod(m_Charisma) < 1 && 
		ConvertToMod(m_Strength) + ConvertToMod(m_Dexterity) + 
		ConvertToMod(m_Constitution) + ConvertToMod(m_Intelligence) + 
		ConvertToMod(m_Wisdom) + ConvertToMod(m_Charisma) > 7 );
	MakeAdjustments();
}

Character::~Character()
{
	
}

std::string Character::Name() { return m_Name; }
ushort* Character::Strength() { return &m_Strength; }
ushort* Character::Dexterity() { return &m_Dexterity; }
ushort* Character::Constitution() { return &m_Constitution; }
ushort* Character::Intelligence() { return &m_Intelligence; }
ushort* Character::Wisdom() { return &m_Wisdom; }
ushort* Character::Charisma() { return &m_Charisma; }

void Character::Print()
{
	char* pRace = "";
	char* pClass = "";

	//Determines the race based on the value
	switch(m_Race)
	{
	case Dwarf:
		pRace = "Dwarf";
		break;
	case Elf:
		pRace = "Elf";
		break;
	case Gnome:
		pRace = "Gnome";
		break;
	case HalfElf:
		pRace = "Half-Elf";
		break;
	case HalfOrc:
		pRace = "Half-Orc";
		break;
	case Halfling:
		pRace = "Halfling";
		break;
	case Human:
		pRace = "Human";
		break;
	default:
		pRace = "Invalid Race";
		break;
	}
	
	//Determines the class based on the value
	switch(m_Class)
	{
	case Barbarian:
		pClass = "Barbarian";
		break;
	case Bard:
		pClass = "Bard";
		break;
	case Cleric:
		pClass = "Cleric";
		break;
	case Druid:
		pClass = "Druid";
		break;
	case Fighter:
		pClass = "Fighter";
		break;
	case Monk:
		pClass = "Monk";
		break;
	case Paladin:
		pClass = "Paladin";
		break;
	case Ranger:
		pClass = "Ranger";
		break;
	case Rogue:
		pClass = "Rogue";
		break;
	case Sorcerer:
		pClass = "Sorcerer";
		break;
	case Wizard:
		pClass = "Wizard";
		break;
	default:
		pClass = "Invalid Class";
		break;
	}

	std::cout << "Name: " << m_Name << std::endl;	
	std::cout << "Race: " << pRace << std::endl;	
	std::cout << "Class: " << pClass << std::endl;
	std::cout << "Level: " << m_Level << std::endl;
	std::cout << "Speed: " << m_Speed << std::endl;
	std::cout << "Health: " << m_Health << std::endl;
	std::cout << "Strength: " << m_Strength << std::endl;
	std::cout << "Dexterity: " << m_Dexterity << std::endl;
	std::cout << "Constitution: " << m_Constitution << std::endl;
	std::cout << "Intelligence: " << m_Intelligence << std::endl;
	std::cout << "Wisdom: " << m_Wisdom << std::endl;
	std::cout << "Charisma: " << m_Charisma << std::endl;
	std::cout << "Armor Class: " << m_ArmorClass << std::endl;
	std::cout << "Fortitude: " << m_Fortitude << std::endl;
	std::cout << "Reflex: " << m_Reflex << std::endl;
	std::cout << "Will: " << m_Will << std::endl;
	std::cout << "Base Attack Bonus: " << m_BaseAttackBonus << std::endl;
	std::cout << "Combat Maneuver Bonus: " << m_CombatManeuverBonus << std::endl;
	std::cout << "Combat Maneuver Defense: " << m_CombatManeuverDefense << std::endl;
	std::cout << std::endl;
}

void Character::Export()
{
	char* pRace = "";
	char* pClass = "";

	//Determines the race based on the value
	switch(m_Race)
	{
	case Dwarf:
		pRace = "Dwarf";
		break;
	case Elf:
		pRace = "Elf";
		break;
	case Gnome:
		pRace = "Gnome";
		break;
	case HalfElf:
		pRace = "Half-Elf";
		break;
	case HalfOrc:
		pRace = "Half-Orc";
		break;
	case Halfling:
		pRace = "Halfling";
		break;
	case Human:
		pRace = "Human";
		break;
	default:
		pRace = "Invalid Race";
		break;
	}
	
	//Determines the class based on the value
	switch(m_Class)
	{
	case Barbarian:
		pClass = "Barbarian";
		break;
	case Bard:
		pClass = "Bard";
		break;
	case Cleric:
		pClass = "Cleric";
		break;
	case Druid:
		pClass = "Druid";
		break;
	case Fighter:
		pClass = "Fighter";
		break;
	case Monk:
		pClass = "Monk";
		break;
	case Paladin:
		pClass = "Paladin";
		break;
	case Ranger:
		pClass = "Ranger";
		break;
	case Rogue:
		pClass = "Rogue";
		break;
	case Sorcerer:
		pClass = "Sorcerer";
		break;
	case Wizard:
		pClass = "Wizard";
		break;
	default:
		pClass = "Invalid Class";
		break;
	}

	//Open data stream and clear it just in case
	std::ofstream data;
	data.open("Characters\\" + m_Name + ".txt");
	data.clear();

	//Write to file
	data << "Name: " << m_Name << std::endl;	
	data << "Race: " << pRace << std::endl;	
	data << "Class: " << pClass << std::endl;
	data << "Level: " << m_Level << std::endl;
	data << "Speed: " << m_Speed << std::endl;
	data << "Health: " << m_Health << std::endl; 
	data << "Strength: " << m_Strength << std::endl;
	data << "Dexterity: " << m_Dexterity << std::endl;
	data << "Constitution: " << m_Constitution << std::endl;
	data << "Intelligence: " << m_Intelligence << std::endl;
	data << "Wisdom: " << m_Wisdom << std::endl;
	data << "Charisma: " << m_Charisma << std::endl;
	data << "Armor Class: " << m_ArmorClass << std::endl;
	data << "Fortitude: " << m_Fortitude << std::endl;
	data << "Reflex: " << m_Reflex << std::endl;
	data << "Will: " << m_Will << std::endl;
	data << "Base Attack Bonus: " << m_BaseAttackBonus << std::endl;
	data << "Combat Maneuver Bonus: " << m_CombatManeuverBonus << std::endl;
	data << "Combat Maneuver Defense: " << m_CombatManeuverDefense << std::endl;
	data << std::endl;

	//Close data stream
	data.close();

	AddToParty();
}

void Character::AddToParty()
{
	char* pRace = "";
	char* pClass = "";

	//Determines the race based on the value
	switch(m_Race)
	{
	case Dwarf:
		pRace = "Dwarf";
		break;
	case Elf:
		pRace = "Elf";
		break;
	case Gnome:
		pRace = "Gnome";
		break;
	case HalfElf:
		pRace = "Half-Elf";
		break;
	case HalfOrc:
		pRace = "Half-Orc";
		break;
	case Halfling:
		pRace = "Halfling";
		break;
	case Human:
		pRace = "Human";
		break;
	default:
		pRace = "Invalid Race";
		break;
	}
	
	//Determines the class based on the value
	switch(m_Class)
	{
	case Barbarian:
		pClass = "Barbarian";
		break;
	case Bard:
		pClass = "Bard";
		break;
	case Cleric:
		pClass = "Cleric";
		break;
	case Druid:
		pClass = "Druid";
		break;
	case Fighter:
		pClass = "Fighter";
		break;
	case Monk:
		pClass = "Monk";
		break;
	case Paladin:
		pClass = "Paladin";
		break;
	case Ranger:
		pClass = "Ranger";
		break;
	case Rogue:
		pClass = "Rogue";
		break;
	case Sorcerer:
		pClass = "Sorcerer";
		break;
	case Wizard:
		pClass = "Wizard";
		break;
	default:
		pClass = "Invalid Class";
		break;
	}

	std::ofstream data;
	data.open("party.txt", std::ios::app);
	
	data << "Name: " << m_Name << std::endl;	
	data << "Race: " << pRace << std::endl;	
	data << "Class: " << pClass << std::endl;
	data << "Level: " << m_Level << std::endl;
	data << "Speed: " << m_Speed << std::endl;
	data << "Health: " << m_Health << std::endl;
	data << "Strength: " << m_Strength << std::endl;
	data << "Dexterity: " << m_Dexterity << std::endl;
	data << "Constitution: " << m_Constitution << std::endl;
	data << "Intelligence: " << m_Intelligence << std::endl;
	data << "Wisdom: " << m_Wisdom << std::endl;
	data << "Charisma: " << m_Charisma << std::endl; 
	data << "Armor Class: " << m_ArmorClass << std::endl;
	data << "Fortitude: " << m_Fortitude << std::endl;
	data << "Reflex: " << m_Reflex << std::endl;
	data << "Will: " << m_Will << std::endl;
	data << "Base Attack Bonus: " << m_BaseAttackBonus << std::endl;
	data << "Combat Maneuver Bonus: " << m_CombatManeuverBonus << std::endl;
	data << "Combat Maneuver Defense: " << m_CombatManeuverDefense << std::endl;
	data << std::endl;

	data.close();
}

void Character::GenerateAbilityScores()
{
	//Open new lua state
	lua_State* pState = lua_open();
	luaL_openlibs(pState);

	//Get the file and funtion name
	luaL_dofile(pState, "character_generation.lua");
	lua_getglobal(pState, "GenerateAbilityScores");

	//Call the function
	lua_call(pState, 0, 6);

	//Set the ability scores equal to the generated numbers
	switch(m_Class)
	{
	case Barbarian:
		m_Strength = (int) lua_tointeger(pState, -6);
		m_Dexterity = (int) lua_tointeger(pState, -5);
		m_Constitution = (int) lua_tointeger(pState, -4);
		m_Intelligence = (int) lua_tointeger(pState, -3);
		m_Wisdom = (int) lua_tointeger(pState, -2);
		m_Charisma = (int) lua_tointeger(pState, -1);
		break;
	case Bard:
		m_Charisma = (int) lua_tointeger(pState, -6);
		m_Dexterity = (int) lua_tointeger(pState, -5);
		m_Intelligence = (int) lua_tointeger(pState, -4);
		m_Strength = (int) lua_tointeger(pState, -3);
		m_Constitution = (int) lua_tointeger(pState, -2);
		m_Wisdom = (int) lua_tointeger(pState, -1);
		break;
	case Cleric:
		m_Constitution = (int) lua_tointeger(pState, -6);
		m_Wisdom = (int) lua_tointeger(pState, -5);
		m_Charisma = (int) lua_tointeger(pState, -4);
		m_Strength = (int) lua_tointeger(pState, -3);
		m_Intelligence = (int) lua_tointeger(pState, -2);
		m_Dexterity = (int) lua_tointeger(pState, -1);
		break;
	case Druid:
		m_Wisdom = (int) lua_tointeger(pState, -6);
		m_Dexterity = (int) lua_tointeger(pState, -5);
		m_Constitution = (int) lua_tointeger(pState, -4);
		m_Intelligence = (int) lua_tointeger(pState, -3);
		m_Charisma = (int) lua_tointeger(pState, -2);
		m_Strength = (int) lua_tointeger(pState, -1);
		break;
	case Fighter:
		m_Dexterity = (int) lua_tointeger(pState, -6);
		m_Strength = (int) lua_tointeger(pState, -5);
		m_Wisdom = (int) lua_tointeger(pState, -4);
		m_Constitution = (int) lua_tointeger(pState, -3);
		m_Charisma = (int) lua_tointeger(pState, -2);
		m_Intelligence = (int) lua_tointeger(pState, -1);
		break;
	case Monk:
		m_Strength = (int) lua_tointeger(pState, -6);
		m_Wisdom = (int) lua_tointeger(pState, -5);
		m_Dexterity = (int) lua_tointeger(pState, -4);
		m_Constitution = (int) lua_tointeger(pState, -3);
		m_Intelligence = (int) lua_tointeger(pState, -2);
		m_Charisma = (int) lua_tointeger(pState, -1);
		break;
	case Paladin:
		m_Strength = (int) lua_tointeger(pState, -6);
		m_Charisma = (int) lua_tointeger(pState, -5);
		m_Constitution = (int) lua_tointeger(pState, -4);
		m_Dexterity = (int) lua_tointeger(pState, -3);
		m_Wisdom = (int) lua_tointeger(pState, -2);
		m_Intelligence = (int) lua_tointeger(pState, -1);
		break;
	case Ranger:
		m_Dexterity = (int) lua_tointeger(pState, -6);
		m_Strength = (int) lua_tointeger(pState, -5);
		m_Wisdom = (int) lua_tointeger(pState, -4);
		m_Constitution = (int) lua_tointeger(pState, -3);
		m_Intelligence = (int) lua_tointeger(pState, -2);
		m_Charisma = (int) lua_tointeger(pState, -1);
		break;
	case Rogue:
		m_Dexterity = (int) lua_tointeger(pState, -6);
		m_Constitution = (int) lua_tointeger(pState, -5);
		m_Wisdom = (int) lua_tointeger(pState, -4);
		m_Strength = (int) lua_tointeger(pState, -3);
		m_Intelligence = (int) lua_tointeger(pState, -2);
		m_Charisma = (int) lua_tointeger(pState, -1);
		break;
	case Sorcerer:
		m_Charisma = (int) lua_tointeger(pState, -6);
		m_Constitution = (int) lua_tointeger(pState, -5);
		m_Dexterity = (int) lua_tointeger(pState, -4);
		m_Intelligence = (int) lua_tointeger(pState, -3);
		m_Wisdom = (int) lua_tointeger(pState, -2);
		m_Strength = (int) lua_tointeger(pState, -1);
		break;
	case Wizard:
		m_Intelligence = (int) lua_tointeger(pState, -6);
		m_Dexterity = (int) lua_tointeger(pState, -5);
		m_Constitution = (int) lua_tointeger(pState, -4);
		m_Charisma = (int) lua_tointeger(pState, -3);
		m_Wisdom = (int) lua_tointeger(pState, -2);
		m_Strength = (int) lua_tointeger(pState, -1);
		m_Intelligence++;
		m_Dexterity++;
		m_Constitution++;
		m_Charisma--;
		m_Wisdom--;
		m_Strength--;
		break;
	}
	//Delete the numbers from the lua stack
	lua_pop(pState, 6);

	//Close the lua state
	lua_close(pState);
}

void Character::GenerateRaceAndClass()
{
	Race races[] = {Dwarf, Elf, Gnome, HalfElf, Halfling, HalfOrc, Human};

	Class classes[] = {Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, 
		Ranger, Rogue, Sorcerer, Wizard};

	//Open new lua state
	lua_State* pState = lua_open();
	luaL_openlibs(pState);

	//Get the file and function name
	luaL_dofile(pState, "character_generation.lua");
	lua_getglobal(pState, "GenerateRaceAndClass");

	//Call the function
	lua_call(pState, 0, 2);

	//Set the race and class
	m_Race = races[(int) lua_tointeger(pState, -2)];
	m_Class = classes[(int) lua_tointeger(pState, -1)];

	//Clean up
	lua_pop(pState, 2);
	lua_close(pState);
}

void Character::MakeAdjustments()
{
	ushort sizemod = 0;
	//Race-based Adjustments
	switch (m_Race)
	{
	case Dwarf:
		m_Constitution += 2;
		m_Wisdom += 2;
		m_Charisma -= 2;
		m_Speed = 20;
		break;
	case Elf:
		m_Dexterity += 2;
		m_Intelligence += 2;
		m_Constitution -= 2;
		m_Speed = 30;
		break;
	case Gnome:
		m_Constitution += 2;
		m_Charisma += 2;
		m_Strength -= 2;
		m_Speed = 20;
		m_Size = Small;
		break;
	case HalfElf:
		*RandomScore() += 2;
		m_Speed = 30;
		break;
	case HalfOrc:
		*RandomScore() += 2;
		m_Speed = 30;
		break;
	case Halfling:
		m_Dexterity += 2;
		m_Charisma += 2;
		m_Strength -= 2;
		m_Speed = 20;
		m_Fortitude += 1;
		m_Reflex += 1;
		m_Will += 1;
		m_Size = Small;
		break;
	case Human:
		*RandomScore() += 2;
		m_Speed = 30;
		break;
	}

	//Class-based Adjustments
	switch(m_Class)
	{
	case Barbarian:
		m_Speed += 10;
		m_Health = BARBARIAN_HIT_DICE + ConvertToMod(m_Constitution);
		m_Fortitude += 2;
		m_BaseAttackBonus += 1;
		m_ArmorValue = 2;
		break;
	case Bard:
		m_Health = BARD_HIT_DICE + ConvertToMod(m_Constitution);
		m_Reflex += 2;
		m_Will += 2;
		m_ArmorValue = 3;
		break;
	case Cleric:
		m_Health = CLERIC_HIT_DICE + ConvertToMod(m_Constitution);
		m_Fortitude += 2;
		m_Will += 2;
		m_ArmorValue = 4;
		break;
	case Druid:
		m_Health = DRUID_HIT_DICE + ConvertToMod(m_Constitution);
		m_Fortitude += 2;
		m_Will += 2;
		m_ArmorValue = 2;
		break;
	case Fighter:
		m_Health = FIGHTER_HIT_DICE + ConvertToMod(m_Constitution);
		m_Fortitude += 2;
		m_BaseAttackBonus += 1;
		m_ArmorValue = 4;
		break;
	case Monk:
		m_Health = MONK_HIT_DICE + ConvertToMod(m_Constitution);
		m_Fortitude += 2;
		m_Reflex += 2;
		m_Will += 2;
		m_ArmorValue = 2;
		m_ArmorClass += ConvertToMod(m_Wisdom);
		m_CombatManeuverDefense += ConvertToMod(m_Wisdom);
		break;
	case Paladin:
		m_Health = PALADIN_HIT_DICE + ConvertToMod(m_Constitution);
		m_Fortitude += 2;
		m_Will += 2;
		m_BaseAttackBonus += 1;
		m_ArmorValue = 5;
		break;
	case Ranger:
		m_Health = RANGER_HIT_DICE + ConvertToMod(m_Constitution);
		m_Fortitude += 2;
		m_Reflex += 2;
		m_ArmorValue = 2;
		break;
	case Rogue:
		m_Health = ROGUE_HIT_DICE + ConvertToMod(m_Constitution);
		m_Reflex += 2;
		m_BaseAttackBonus += 1;
		m_ArmorValue = 2;
		break;
	case Sorcerer:
		m_Health = SORCERER_HIT_DICE + ConvertToMod(m_Constitution);
		m_Will += 2;
		m_ArmorValue = 1;
		break;
	case Wizard:
		m_Health = WIZARD_HIT_DICE + ConvertToMod(m_Constitution);
		m_Will += 2;
		m_ArmorValue = 1;
		break;
	}
	
	m_Fortitude += ConvertToMod(m_Constitution);
	m_Reflex += ConvertToMod(m_Dexterity);
	m_Will += ConvertToMod(m_Wisdom);
	if(m_Size == Small)
	{
		sizemod = -1;
	}
	else
	{
		sizemod = 0;
	}
	m_CombatManeuverBonus += (m_BaseAttackBonus + ConvertToMod(m_Strength) + sizemod);
	m_CombatManeuverDefense += (10 + m_BaseAttackBonus + ConvertToMod(m_Strength) + 
		ConvertToMod(m_Dexterity) + sizemod);
	m_ArmorClass += (10 + ConvertToMod(m_Dexterity) - sizemod + m_ArmorValue);
}

ushort* Character::RandomScore()
{
	srand(time(0));
	int score = rand() % 6;
	switch(score)
	{
	case 0:
		return &m_Strength;
	case 1:
		return &m_Dexterity;
	case 2:
		return &m_Constitution;
	case 3:
		return &m_Intelligence;
	case 4:
		return &m_Wisdom;
	case 5:
		return &m_Charisma;
	}
}

void Character::IncreaseScore(ushort* score, ushort value)
{
	*score += value;
}

short Character::ConvertToMod(ushort num)
{
	short mod = floor((double) (num - 10) / 2);
	return mod;
}