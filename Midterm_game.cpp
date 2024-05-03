#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void space() {
	cout << endl;
}

void cont() {
	cout << endl;
	cout << "Press 'ENTER' key to continue." << endl;
	string go;
	getline(cin, go);
}


int main() {
	int player_odds = 10;
	int player_health = 1;

	int x = time(0);
	srand(x);
	int village_attack = 1 + rand() % player_odds;

	int y = time(0);
	srand(y);
	int boss_attack_1 = 1 + rand() % player_odds;

	int z = time(0);
	srand(z);
	int boss_attack_2 = 1 + rand() % player_odds;


	//game start
	cout << "You are at 1 health. You will be given opportunities throughout this playthrough to gain more health points." << endl;
	space();

	string name;
	cout << "Welcome traveler. What is your name? ";
	getline(cin, name);

	space();

	cout << "Welcome " << name << endl;
	space();
	cout << "You find yourself wandering in the forest and you stumble upon two items. Which do you choose? (Enter SWORD or POTION)" << endl;
	space();
	cout << "        Sword              Life Potion  " << endl;
	cout << " (+10% success chance)       (+1 life)" << endl;
	space();
	cout << "Enter 'SWORD' or 'POTION'" << endl;

	string start_choice;
	getline(cin, start_choice);

	if (start_choice == "SWORD") {
		player_odds = player_odds - 1;
		space();
		cout << "Your chances in battle have increased" << endl;
	}
	else if (start_choice == "POTION") {
		player_health++;
		space();
		cout << "Good Choice, You are now at " << player_health << " health." << endl;
	}
	else {
		cout << "INVALID CHOICE" << endl;
		return 1;
	}
	//troll
	space();
	cout << "You are walking through the forest and you find an abandoned path. Do you travel it? (YES or NO)" << endl;
	space();
	string bridge;
	getline(cin, bridge);
	space();

	if (bridge == "YES") {
		cout << "You travel the path less taken and you find yourself at a suspension bridge. Do you cross it? (YES or NO)" << endl;
		space();
		string choice_1;
		getline(cin, choice_1);
		if (choice_1 == "YES") {
			space();
			cout << "You find yourself facing a troll. He demands that you fight him in order to cross the bridge. Do you fight? (YES or NO) " << endl;
			space();
			string fight;
			getline(cin, fight);

			if (fight == "YES") {
				int prob = time(0);
				srand(prob);
				int troll = 1 + rand() % player_odds;
				if (troll <= 5) {
					cout << "You have bested the troll. He lets you cross the bridge, and you find a health potion!" << endl;
					space();
					player_health = player_health + 1;
					cout << "1 health has been added to your total. You are now at " << player_health << " health." << endl;
					space();
					cout << "You continue on the path of the bridge, but realize that it is a dead end." << endl;
					cout << "You turn around and return to the path you were originally traveling." << endl;
				}
				else {
					space();
					cout << "The troll has defeated you and sent you back on your way. ";
					space();
				}
			}
			else if (fight == "NO") {
				space();
				cout << "You turn around and continue on the path you were traveling." << endl;
				space();
			}
			else {
				cout << "INVALID INPUT" << endl;
				return 1;
			}
		}
		else if (choice_1 == "NO") {
			space();
			cout << "You turn around and continue on the path you were traveling." << endl;
			space();
		}
		else {
			cout << "INVALID INPUT" << endl;
			return 1;
		}
	}
	else if (bridge == "NO") {
		cout << "You continue on the path you were traveling." << endl;
		space();
	}
	else {
		cout << "INVALID INPUT" << endl;
		return 1;
	}

	cont();

	//village
	space();
	cout << "The path splits. You see a castle off in the distance, and a village close by. Which way do you go? (VILLAGE or CASTLE)" << endl;
	string vil_or_cast;
	getline(cin, vil_or_cast);
	space();

	if (vil_or_cast == "VILLAGE") {

		cout << "You see the village in the distance." << endl;
		cout << "As you get closer you find that the village is under attack by bandits." << endl;

		space();

		cout << name << "!! They cried. Please help us!!" << endl;
		cout << "Would you like to join the fight, or run away? (Choose: 'FIGHT' or 'RUN') " << endl;
		string response;
		getline(cin, response);

		space();

		if (response == "FIGHT") {
			if (village_attack <= 6) {
				cout << "You have defeated most of the bandits." << endl;
			}
			else {
				player_health--;
				if (player_health == 0) {
					cout << "You have been defeated in battle." << endl;
					cout << "GAME OVER" << endl;
					return 0;
				}
				else if (player_health == 1 || player_health == 2) {
					cout << "You have suffered major damages but won the fight." << endl;
					cout << "You are now at " << player_health << " health." << endl;
				}
			}
			cout << "One foe stands between you and victory!" << endl;
		}
		else if (response == "RUN") {
			cout << "As you leave, you hear the screams behind you." << endl;
			cout << "Children run in terror as the villagers fend off their home." << endl;
			cout << "You turn and see smoke rise over the trees." << endl;
			cout << "After some thought, you turn back to save the village." << endl;
			cout << "You arrive at the village and prepare yourself for battle." << endl;

			cont();

			if (village_attack <= 6) {
				cout << "You have defeated most of the bandits." << endl;
			}
			else {
				player_health--;
				if (player_health == 0) {
					cout << "You have been defeated by the bandits and are now at " << player_health << " health." << endl;
					cout << "GAME OVER" << endl;
					return 0;
				}
				else if (player_health == 1 || player_health == 2) {
					cout << "You have suffered damages but won the fight." << endl;
					cout << "You are now at " << player_health << " health." << endl;
				}
			}
		}
		else {
			cout << "INVALID INPUT" << endl;
			return 1;
		}

		cont();

		cout << "The chief of the bandits approaches as you clench your weapon." << endl;

		space();

		if (boss_attack_1 <= 4) {
			cout << "You have defeated the chief and are the hero of the village!" << endl;
			return 0;
		}
		else {
			player_health--;
			if (player_health > 0) {
				cout << "You have suffered damages from the chief and are now at " << player_health << " health." << endl;
			}
			else {
				cout << "You have been defeated by the chief." << endl;
				cout << "GAME OVER" << endl;
				return 0;
			}
		}
		cout << "You pick yourself up and prepare to fight again." << endl;

		cont();

		//must have 3 health to access this
		cout << "In the distance you notice a weapon in the dirt." << endl;
		cout << "It's a futuristic lasar weapon that was left behind." << endl;
		cout << "If you choose to pick up this weapon, the chief will get a hit on you, resulting in you losing 1 health point." << endl;
		if (player_health == 1) {
			cout << "WARNING: You are only at " << player_health << " health." << endl;
		}
		else {
			cout << "You are at " << player_health << " health." << endl;
		}
		cout << "Would you like to use this ability? (Enter: 'YES' or 'NO')" << endl;

		string ability_choice;
		getline(cin, ability_choice);
		if (ability_choice == "YES") {
			player_health--;
			if (player_health < 1) {
				space();
				cout << "You are at " << player_health << " health." << endl;
				cout << "GAME OVER" << endl;
				return 0;
			}
			else {
				space();
				cout << "You have chosen go for the weapon." << endl;
				cout << "You are now at " << player_health << " health." << endl;
				cout << "You have defeated the chief and are the hero of the village!" << endl;
				return 0;
			}
		}
		else if (ability_choice == "NO") {
			space();
			cout << "You chose not to go for the weapon." << endl;
			cout << "You are at " << player_health << " health." << endl;

			space();

			cout << "You charge at each other.";
			if (boss_attack_2 <= 4) {
				cout << "You have defeated the chief and are the hero of the village!" << endl;
				return 0;
			}
			else {
				cout << "You have been defeated by the chief and the village has been destroyed." << endl;
				return 0;
			}
		}
		else {
			cout << "INVALID INPUT" << endl;
			return 1;
		}
	}
	//castle
	else if (vil_or_cast == "CASTLE") {
		cout << "You see a big medieval castle in the distance up ahead." << endl;
		cout << "When you entered the castle, you were approached by a jester." << endl;
		cont();
		cout << "The jester then says:" << endl;
		cout << name << ", solve this riddle..." << endl;
		space();
		cout << "In caverns deep where darkness reigns," << endl;
		cout << "I slumber still with fiery chains." << endl;
		cout << "With scales that gleam like midnight skies," << endl;
		cout << "I soar above with piercing eyes." << endl;
		space();

		cout << "(Answer in all caps)" << endl;
		cout << "I'm a?: ";
		string rid_ans;
		getline(cin, rid_ans);

		if (rid_ans == "DRAGON") {
			cout << endl;
			cout << "Hmm, you're a smart one indeed. You have solved this riddle!" << endl;
			cout << "But look at that. The sun is setting, and it's time for me to go. Good luck, " << name << "." << endl;
			cout << endl;
			cout << "The jester then leaves." << endl;
			cout << endl;
		}
		else {
			cout << endl;
			cout << "Nope that's wrong sillyhead! The answer was 'DRAGON'." << endl;
			cout << "The jester then proceeds to quickly stab you with a sharp blade that was hidden under his sleeve." << endl;
			cout << endl;
			cout << "The jester has run off into the distance." << endl;
			cout << endl;
			player_health -= 1;
			cout << "You're health is: ";
			cout << player_health << endl;
		}

		if (player_health < 1) {
			cout << endl;
			cout << "You have died." << endl;
			cout << "GAME OVER" << endl;

			return 1;
		}

		cout << endl;
		cout << "After the encounter with the jester, you continue to explore the castle." << endl;
	}
	else {
		cout << "INVALID INPUT" << endl;
		return 1;
	}
	std::cout << "You have stumbled upon a massive magical fire-breathing dragon, would you like fight or bargain with the dragon?" << std::endl;
	std::cout << "(Choose 'FIGHT' of 'BARGAIN')" << std::endl;
	std::string response;
	std::getline(std::cin, response);
	if (response == "FIGHT") {
		int d = time(0);
		srand(d);
		int dragon_attack = 1 + rand() % player_odds;

		space();

		if (dragon_attack <= 4) {
			std::cout << "Congratulations, " << name << " you have defeated the dragon. All of his spoils are yours!" << std::endl;
			return 0;
		}
		else {
			std::cout << "You have failed to slay the dragon " << std::endl;
			player_health = player_health - 1;
			if (player_health > 0) {
				std::cout << "Your health is now at " << player_health << std::endl;
				std::cout << "The dragon knocks you down, but you ready yourself again . . . type FIGHT " << std::endl;

				std::string fight2;
				std::getline(std::cin, fight2);
				if (fight2 == "FIGHT") {
					int y = time(0);
					srand(y);
					int dragon_fight2 = 1 + rand() % player_odds;
					if (dragon_fight2 <= 4) {
						std::cout << "Congratulations, " << name << " you have defeated the dragon. All of his spoils are yours!" << std::endl;
						return 0;
					}
					else {
						player_health = player_health - 1;
						if (player_health > 0) {
							std::cout << "Your health is now at " << player_health << std::endl;
							std::cout << "The dragon knocks you down, but you ready yourself again . . . type FIGHT " << std::endl;
						}
						else {
							std::cout << "You have been defeated by the dragon." << std::endl;
							return 0;
						}
						std::string fight3;
						std::getline(std::cin, fight3);
						if (fight3 == "FIGHT") {
							int f = time(0);
							srand(f);
							int dragon_fight3 = 1 + rand() % player_odds;
							if (dragon_fight3 <= 5) {
								std::cout << "Congratulations, " << name << " you have defeated the dragon. All of his spoils are yours!" << std::endl;
								return 0;
							}
							else {
								std::cout << "You have failed to slay the dragon ... GAME OVER" << std::endl;
								return 0;
							}
						}
					}
				}
			}
			else {
				std::cout << "You have failed to slay the dragon GAME OVER. " << std::endl;
				return 0;
			}

		}
	}
	else if (response == "BARGAIN") {
		int x = time(0);
		srand(x);
		int dragon_bargain = 1 + rand() % 10;

		std::cout << "You have chose to bargain with the dragon let's see how you do" << std::endl;
		if (dragon_bargain <= 5) {
			std::cout << "You have outsmarted the dragon and have taken the gold, congratulations." << std::endl;
			return 0;
		}
		else {
			std::cout << "The dragon despises your lies and attacks you. " << std::endl;
			player_health = player_health - 1;
			std::cout << "Your health is now " << player_health << std::endl;
			if (player_health < 1) {
				std::cout << "You have failed miserably . . .The dragon has tore each limb off your body one at a time and ate it in front of you. " << std::endl;
				return 0;
			}
			else {
				std::cout << "You're ready to fight him . . . you can choose to fight or try to run, but the odds are heavily against you. (FIGHT or RUN)" << std::endl;
				std::string rematch;
				std::getline(std::cin, rematch);
				if (rematch == "FIGHT") {
					int a = time(0);
					srand(a);
					int dragon_rematch = 1 + rand() % player_odds;

					if (dragon_rematch <= 4) {
						std::cout << "Congratulations, " << name << " you have defeated the dragon. All of his spoils are yours!" << std::endl;
						return 0;
					}
					else {
						std::cout << "You have failed to slay the dragon . . . you are now dead." << std::endl;
						return 0;
					}
				}
				else if (rematch == "RUN") {
					int a = time(0);
					srand(a);
					int dragon_escape = 1 + rand() % 10;

					if (dragon_escape <= 6) {
						cout << "You have been caught by the dragon and torn limb for limb" << endl;
						cout << "GAME OVER" << endl;
						return 0;
					}
					else {
						cout << "You narrowly escape the dragon and flee with a small pocketful of gold." << endl;
						return 0;
					}
				}
				else {
					std::cout << "INVALID INPUT" << std::endl;
				}
			}
		}
	}
	else {
		cout << "INVALID INPUT" << endl;
		return 0;
	}
	return 0;
}