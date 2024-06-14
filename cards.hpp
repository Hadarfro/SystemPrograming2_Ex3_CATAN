#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>
#include "resource.hpp"

using namespace std;
class Player;
//using namespace ResourceUtils;

// Base Card class
class Card {
public:
    virtual string getType() const = 0; // Pure virtual function
    virtual void display() const = 0; // Pure virtual function

    virtual ~Card() = default; // Virtual destructor
};

// Derived ResourceCard class
class ResourceCard : public Card {
public:
    
    ResourceCard(Resource type) : resource(type) {}

    string getType() const override {
        return "Resource";
    }

    Resource getResourceType() const {
        return resource;
    }

    void display() const override {
        cout << "Resource Card: " << resourceToString(resource) << endl;
    }

    // Implementing the less-than operator
    bool operator<(const ResourceCard& other) const {
        return static_cast<int>(resource) < static_cast<int>(other.resource);
    }

private:
    Resource resource;

};

// Derived DevelopmentCard class
class DevelopmentCard : public Card {
    public:
        enum class DevelopmentType { KNIGHT, VICTORY_POINT, ROAD_BUILDING, YEAR_OF_PLENTY, MONOPOLY , UNKNOWN};
        
        DevelopmentCard(string type) : type(type) {}

        string getType() const override {
            return "Development";
        }

        DevelopmentType getDevelopmentType() {
            return stringToDevelopmentType(type);
        }

        void display() const override {
            cout << "Development Card: " << type << "\n";
        }

        // Define the comparison operator
        bool operator<(const DevelopmentCard& other) const {
            // Implement the comparison logic. For example:
            if (type != other.type) {
                return type < other.type;
            }
            return false;
        }

    private:
        string type;

        string developmentTypeToString(DevelopmentType type) const {
            switch(type) {
                case DevelopmentType::KNIGHT: return "Knight";
                case DevelopmentType::VICTORY_POINT: return "Victory Point";
                case DevelopmentType::ROAD_BUILDING: return "Road Building";
                case DevelopmentType::YEAR_OF_PLENTY: return "Year of Plenty";
                case DevelopmentType::MONOPOLY: return "Monopoly";
                default: return "Unknown";
            }
        }

        DevelopmentType stringToDevelopmentType(const string& type) {
    if (type == "Knight") {
        return DevelopmentType::KNIGHT;
    } 
    else if (type == "Victory Point") {
        return DevelopmentType::VICTORY_POINT;
    } 
    else if (type == "Road Building") {
        return DevelopmentType::ROAD_BUILDING;
    } 
    else if (type == "Year of Plenty") {
        return DevelopmentType::YEAR_OF_PLENTY;
    } 
    else if (type == "Monopoly") {
        return DevelopmentType::MONOPOLY;
    } 
    else {
        return DevelopmentType::UNKNOWN;
    }

}
};

class KnightCard : public DevelopmentCard {
public:
    KnightCard() : DevelopmentCard("KNIGHT") {}
};

class VictoryPointCard : public DevelopmentCard {
public:
    VictoryPointCard() : DevelopmentCard("VICTORY_POINT") {}
};

class RoadBuildingCard : public DevelopmentCard {
public:
    RoadBuildingCard() : DevelopmentCard("ROAD_BUILDING") {}
};

class YearOfPlentyCard : public DevelopmentCard {
public:
    YearOfPlentyCard() : DevelopmentCard("YEAR_OF_PLENTY") {}
};

class MonopolyCard : public DevelopmentCard {
public:
    MonopolyCard() : DevelopmentCard("MONOPOLY") {}
};



#endif // CARD_HPP