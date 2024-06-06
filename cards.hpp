#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>
#include "resource.hpp"
using namespace std;

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
    
    ResourceCard(Resource type) : type(type) {}

    string getType() const override {
        return "Resource";
    }

    Resource getResourceType() const {
        return type;
    }

    void display() const override {
        cout << "Resource Card: " << resourceToString(type) << endl;
    }

private:
    Resource type;

    // string resourceTypeToString(Resource type) const {
    //     switch(type) {
    //         case Resource::Wood: return "Wood";
    //         case Resource::Brick: return "Brick";
    //         case Resource::Sheep: return "Sheep";
    //         case Resource::Wheat: return "Wheat";
    //         case Resource::Ore: return "Ore";
    //         default: return "Unknown";
    //     }
    // }
};

// Derived DevelopmentCard class
class DevelopmentCard : public Card {
public:
    enum class DevelopmentType { KNIGHT, VICTORY_POINT, ROAD_BUILDING, YEAR_OF_PLENTY, MONOPOLY };
    
    DevelopmentCard(DevelopmentType type) : type(type) {}

    std::string getType() const override {
        return "Development";
    }

    DevelopmentType getDevelopmentType() const {
        return type;
    }

    void display() const override {
        std::cout << "Development Card: " << developmentTypeToString(type) << "\n";
    }

private:
    DevelopmentType type;

    std::string developmentTypeToString(DevelopmentType type) const {
        switch(type) {
            case DevelopmentType::KNIGHT: return "Knight";
            case DevelopmentType::VICTORY_POINT: return "Victory Point";
            case DevelopmentType::ROAD_BUILDING: return "Road Building";
            case DevelopmentType::YEAR_OF_PLENTY: return "Year of Plenty";
            case DevelopmentType::MONOPOLY: return "Monopoly";
            default: return "Unknown";
        }
    }
};

#endif // CARD_HPP
