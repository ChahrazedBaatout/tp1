#include <iostream>
#include <string>

using std::string;

class Pokemon{
    private:
        int id;
        string name;
        double hitPoint;
        double attack;
        double defense;
        int generation;
    public:

        Pokemon(int id, string name, double hitPoint, double attack, double defense, int generation): 
            id(id), 
            name(name), 
            hitPoint(hitPoint), 
            attack(attack), 
            defense(defense), 
            generation(generation) {}
        
        Pokemon(const Pokemon& other): 
            id(other.id),
            name(other.name),
            hitPoint(other.hitPoint),
            attack(other.attack),
            defense(other.defense),
            generation(other.generation){
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
        double getHitPoint() const { return hitPoint; }
        double getAttack() const { return attack; }
        double getDefense() const { return defense; }
        int getGeneration() const { return generation; }

        // Setters
        void setName(const string& n) { name = n; }
        void setHitPoint(double hp) { hitPoint = hp; }
        void setAttack(double atk) { attack = atk; }
        void setDefense(double def) { defense = def; }
        void setGeneration(int gen) { generation = gen; }

        void displayInfo(){
            std::cout << "ID: " << id << std::endl;
            std::cout << "Nom: " << name << std::endl;
            std::cout << "HP: " << hitPoint << std::endl;
            std::cout << "Attaque: " << attack << std::endl;
            std::cout << "Défense: " << defense << std::endl;
            std::cout << "Generation: " << generation << std::endl;
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
