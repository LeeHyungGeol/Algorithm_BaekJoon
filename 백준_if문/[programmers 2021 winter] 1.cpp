#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct Player {
    int HP, Attack, Shield;
}Player;

typedef struct Monster {
    string Name;
    int EXP, HP, Attack, Shield;
}Monster;

typedef struct Node {
    string name;
    double timePerExp;
    int exp, index;
}Node;

int Time;
stringstream SS;
Player Character;
Monster Goblin;
vector<Node> Arr;

void characterAttack();
void goblinAttack();
bool compare(const Node& a, const Node& b);

string solution(string character, vector<string> monsters) {
    string answer = "";
    int playerHp, hp, attack, shield, exp;
    string name;

    SS.str(character);
    SS >> playerHp >> attack >> shield;

    Character = { playerHp, attack, shield };

    for (int i = 0; i < monsters.size(); ++i) {
        SS.clear();
        SS.str(monsters[i]);
        SS >> name >> exp >> hp >> attack >> shield;
        Goblin = { name, exp, hp, attack, shield };
        bool playerDead = false;
        Time = 0;
        Character.HP = playerHp;

        while (true) {
            if (Character.Attack - Goblin.Shield <= 0) {
                playerDead = true;
                break;
            }
            characterAttack();
            if (Goblin.HP <= 0) break;
            goblinAttack();
            if (Character.HP <= 0) {
                playerDead = true;
                break;
            }
            Character.HP = playerHp;
        }

        if (!playerDead) {
            Arr.push_back({ name, (double)exp / Time, exp, i });
        }
    }

    sort(Arr.begin(), Arr.end(), compare);

    answer = Arr.front().name;

    return answer;
}

void characterAttack() {
    ++Time;
    if (Character.Attack - Goblin.Shield > 0) Goblin.HP -= Character.Attack - Goblin.Shield;
}

void goblinAttack() {
    if (Goblin.Attack - Character.Shield > 0) Character.HP -= Goblin.Attack - Character.Shield;
}

bool compare(const Node& a, const Node& b) {
    if (a.timePerExp == b.timePerExp) {
        if (a.exp == b.exp) {
            return a.index < b.index;
        }
        return a.exp > b.exp;
    }
    return a.timePerExp > b.timePerExp;
}