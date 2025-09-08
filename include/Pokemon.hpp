#include <iostream>
#include <string>

using std::string;

class Pokemon{

    private:
        int id;
        string name;
        string evolution;
        double maxHitPoint;
        double currHitPoint;
        double attack;
        double defense;

    public:

        Pokemon(int id, string name, double maxhitPoint, double currhitPoint, double attack, double defense): 
            id(id), 
            name(name), 
            maxHitPoint(maxHitPoint),
            currHitPoint(currHitPoint), 
            attack(attack), 
            defense(defense) {
            }
        
        Pokemon(const Pokemon& other): 
            id(other.id),
            name(other.name),
            maxHitPoint(other.maxHitPoint),
            currHitPoint(other.currHitPoint),
            attack(other.attack),
            defense(other.defense){
                std::cout << "Constructeur de copie appelé" << std::endl;
                std::cout << std::endl;
            }

        ~Pokemon(){
            std::cout << "Destructeur appelé: " << name << " détruit" << std::endl;
            std::cout << std::endl;
        }

        // Getters
        int getId() const { return id; }
        string getName() const { return name; }
        double getMaxHitPoint() const { return maxHitPoint; }
        double getCurrHitPoint() const { return currHitPoint; }
        double getAttack() const { return attack; }
        double getDefense() const { return defense; }

        // Setters
        void setName(const string& n) { name = n; }
        void setMaxHitPoint(double maxhp) { maxHitPoint = maxhp; }
        void setCurrHitPoint(double currhp) { currHitPoint = currhp; }
        void setAttack(double atk) { attack = atk; }
        void setDefense(double def) { defense = def; }

        void displayInfo(){
            std::cout << "ID: " << id << std::endl;
            std::cout << "Nom: " << name << std::endl;
            std::cout << "HP maximum: " << maxHitPoint << std::endl;
            std::cout << "HP actuel: " << currHitPoint << std::endl;
            std::cout << "Attaque: " << attack << std::endl;
            std::cout << "Défense: " << defense << std::endl;
            std::cout << std::endl;
        }

        void launch_attack(Pokemon &attacked){
            std::cout << name << " a attaqué " << attacked.name << "!" << std::endl;
            if (attack > attacked.defense){
                double dommage = attack - attacked.defense;
                attacked.hitPoint -= dommage;
                std::cout << attacked.name << " a perdu " << dommage << " hitpoints!" << std::endl;
                std::cout << std::endl;
                if (attacked.hitPoint <= 0) {
                    attacked.hitPoint = 0;
                    std::cout << attacked.name << " s'est decédé!" << std::endl;
                    std::cout << std::endl;
                }
            } else {
                std::cout << "L'attaque de " << name << " n'a été pas assez forte!" << std::endl;
                std::cout << std::endl;
            }
        }

};