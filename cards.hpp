#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>
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
    enum class ResourceType { WOOD, BRICK, SHEEP, WHEAT, ORE };
    
    ResourceCard(ResourceType type) : type(type) {}

    string getType() const override {
        return "Resource";
    }

    ResourceType getResourceType() const {
        return type;
    }

    void display() const override {
        cout << "Resource Card: " << resourceTypeToString(type) << endl;
    }

private:
    ResourceType type;

    string resourceTypeToString(ResourceType type) const {
        switch(type) {
            case ResourceType::WOOD: return "Wood";
            case ResourceType::BRICK: return "Brick";
            case ResourceType::SHEEP: return "Sheep";
            case ResourceType::WHEAT: return "Wheat";
            case ResourceType::ORE: return "Ore";
            default: return "Unknown";
        }
    }
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
