#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;
enum class Resource { Wood, Brick, Sheep, Wheat, Ore, Sea, Desert, None };

// Function to get string representation of resource
std::string resourceToString(Resource resource) {
    switch (resource) {
        case Resource::Wood: return "Wood";
        case Resource::Brick: return "Brick";
        case Resource::Sheep: return "Sheep";
        case Resource::Wheat: return "Wheat";
        case Resource::Ore: return "Ore";
        case Resource::Sea: return "Sea";
        case Resource::None: return "None";
        case Resource::Desert: return "Desert";
        default:
            cerr << "Unknown resource type" << std::endl;
            return "Unknown";
    }
}

Resource stringToResource(const string& resourceStr) {
    if (resourceStr == "Wood") return Resource::Wood;
    if (resourceStr == "Brick") return Resource::Brick;
    if (resourceStr == "Sheep") return Resource::Sheep;
    if (resourceStr == "Wheat") return Resource::Wheat;
    if (resourceStr == "Ore") return Resource::Ore;
    return Resource::None;
}
