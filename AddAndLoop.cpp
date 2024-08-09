#include <iostream>
#include <vector>

int playersInGame;

struct vec3
{
	float x, y, z;
};

class PLAYER
{   //these variables are already private
	float health;
	vec3 pos;
	std::string name;
public:
	                         //Literally the equivalent setting the values like(this->health = health)
	PLAYER(float health, const std::string name) : health(health), name(name) { playersInGame++; }

	void SetPosition(float x, float y, float z)
	{
		this->pos.x = x, this->pos.y = y, this->pos.z = z;
	}
	vec3 GetPosition()
	{
		return pos;
	}
	std::string GetName()
	{
		return name;
	}
	float GetHealth()
	{
		return health;
	}
};

int main()
{
	PLAYER* player = new PLAYER(50, "Hi");
	player->SetPosition(60, 50, 60);
	

	PLAYER* player2 = new PLAYER(20, "Poop");
	player2->SetPosition(999, 4444, 2020);
	
	std::vector<PLAYER> playersList;

	playersList.push_back(*player);
	playersList.push_back(*player2);

	for (int i = 0; i < playersList.size(); ++i)
	{
		std::cout << playersList[i].GetName() << std::endl;
		std::cout << playersList[i].GetHealth() << std::endl;
		std::cout << playersList[i].GetPosition().x << std::endl;
		std::cout << playersList[i].GetPosition().y << std::endl;
		std::cout << playersList[i].GetPosition().z << std::endl;

	}

	std::cout << "Players in Game: " << playersInGame << std::endl;


	//flush player class pointer when we are done using
	//if we dont delete heap allocations(aka dynamic memory) then we will have a memory link
	//if this were on the stack it would be okay to not delete because once the object is out of
	//scope it will die
	//the reason we are using heap allocation method is because this player needs to be alive for the entire time  
	//until the said player dies or deallocates. 
	delete player;
	delete player2;

	return 0;
}
