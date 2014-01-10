#include <string>

typedef unsigned short ushort;

enum Race
{
	Dwarf = 0,
	Elf,
	Gnome,
	HalfElf,
	HalfOrc,
	Halfling,
	Human
};

enum Class
{
	Barbarian = 0,
	Bard,
	Cleric,
	Druid,
	Fighter,
	Monk,
	Paladin,
	Ranger,
	Rogue,
	Sorcerer,
	Wizard
};

enum Size
{
	Fine,
	Diminutive,
	Tiny,
	Small,
	Medium,
	Large,
	Huge,
	Gargantuan,
	Colossal
};

class Character
{
public:
	//Constructors/Deconstructor
	Character();
	Character(const char* name);
	Character(const char* name, Race race, Class characterClass);
	~Character();

	//Accessors
	std::string Name();
	ushort* Strength();
	ushort* Dexterity();
	ushort* Constitution();
	ushort* Intelligence();
	ushort* Wisdom();
	ushort* Charisma();

	//Print out character information to the console
	void Print();
	
	//Print out character information to a file
	void Export();

	//Adds the player's details to the party file
	void AddToParty();

	//Use to assign scores to members
	void GenerateAbilityScores();

	//Randomly choose race and class
	void GenerateRaceAndClass();

	//Adjust Stats after choosing race and class
	void MakeAdjustments();

	//Chooses a random ability score
	ushort* RandomScore();

	//Increases the ability score of choice by given value
	void IncreaseScore(ushort* score, ushort value = 1);

	//Converts an ability score to its modifier
	short ConvertToMod(ushort num);
private:
	//Character name
	std::string m_Name;

	//Character race
	Race m_Race;

	//Character class
	Class m_Class;

	Size m_Size;

	//Character level
	ushort m_Level;

	//Ability Scores    
	ushort m_Strength;
	ushort m_Dexterity;
	ushort m_Constitution;
	ushort m_Intelligence;
	ushort m_Wisdom;
	ushort m_Charisma;

	//Misc Stats
	ushort m_Health;
	ushort m_Speed;
	
	//Defensive Stats
	ushort m_ArmorClass;
	short m_Fortitude;
	short m_Reflex;
	short m_Will;
	short m_CombatManeuverDefense;
	ushort m_ArmorValue;

	//Offensive Stats
	short m_BaseAttackBonus;
	short m_CombatManeuverBonus;
};