#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Location {
public:
  string name;
  string description;
  vector<Location*> connectedLocations;
  int spawnChance; // Chance (0-100) for event/quest spawn

  Location(const string& name, const string& description, int spawnChance = 0) :
      name(name), description(description), spawnChance(spawnChance) {}

  void addConnection(Location* location) {
    connectedLocations.push_back(location);
  }

  int getDistance(const Location* other) const {
    for (size_t i = 0; i < connectedLocations.size(); ++i) {
      if (connectedLocations[i] == other) {
        return i; // Return index as distance
      }
    }
    return -1;
  }
};

class Event {
public:
  string name;
  string description;
  Location* location;
  void (*executeEvent)(); // Function pointer to execute the event

  Event(const string& name, const string& description, Location* location, void (*executeEvent)()) :
      name(name), description(description), location(location), executeEvent(executeEvent) {}
};

// Simplified Min-Heap (placeholder, use a library for real implementation)
vector<Event*> eventHeap;

void addToHeap(Event* event) {
  eventHeap.push_back(event);
  // Maintain heap property (bubble up element if priority is lower than parent)
  int currentIndex = eventHeap.size() - 1;
  while (currentIndex > 0 && eventHeap[currentIndex]->name < eventHeap[(currentIndex - 1) / 2]->name) { // Simple priority based on event name (replace with appropriate logic)
    swap(eventHeap[currentIndex], eventHeap[(currentIndex - 1) / 2]);
    currentIndex = (currentIndex - 1) / 2;
  }
}

Event* getTopEvent() {
  if (eventHeap.empty()) {
    return nullptr;
  }
  return eventHeap[0];
}

void removeTopEvent() {
  if (eventHeap.empty()) {
    return;
  }
  // Move last element to top and bubble down to maintain heap property
  eventHeap[0] = eventHeap[eventHeap.size() - 1];
  eventHeap.pop_back();
  int currentIndex = 0;
  while ((currentIndex * 2 + 1) < eventHeap.size()) {
    int swapIndex = currentIndex * 2 + 1;
    if ((currentIndex * 2 + 2) < eventHeap.size() && eventHeap[swapIndex]->name > eventHeap[swapIndex + 1]->name) {
      swapIndex++;
    }
    if (eventHeap[currentIndex]->name <= eventHeap[swapIndex]->name) {
      break;
    }
    swap(eventHeap[currentIndex], eventHeap[swapIndex]);
    currentIndex = swapIndex;
  }
}

// Function prototypes for event executions (replace with actual logic)
void winGoldEvent() {
  cout << "You found a hidden gold stash!" << endl;
}

void monsterEncounterEvent() {
  cout << "A ferocious monster appears!" << endl;
}

int main() {
  Location town("Town", "A bustling hub with shops and quests.");
  Location forest("Forest", "A dense forest with hidden paths and dangers.");
  town.addConnection(&forest);

  // Add some test events (replace with generation logic based on location/spawn chance)
  addToHeap(new Event("Win Gold!", "Find a hidden gold stash in the forest", &forest, winGoldEvent));
  addToHeap(new Event("Monster Encounter!", "A ferocious monster lurks in the forest", &forest, monsterEncounterEvent));

  Location* currentLocation = &town;

  while (true) {
    cout << "\nYou are currently in: " << currentLocation->name << endl;
    cout << currentLocation->description << endl;

    // Display connected locations
    if (!currentLocation->connectedLocations.empty()) {
      cout << "Connected Locations:" << endl;
      for (auto connected : currentLocation->connectedLocations) {
        cout << "\t- " << connected->name << endl;
      }
    }

    // Display upcoming event
    Event* topEvent = getTopEvent();
    if (topEvent != nullptr) {
      cout << "Upcoming Event: " << topEvent->name << endl;
    } else {
      cout << "No upcoming events." << endl;
    }

    // Execute event
    if (topEvent != nullptr && topEvent->location == currentLocation) {
      topEvent->executeEvent();
      removeTopEvent();
    }

    // Move to connected location
    string input;
    cout << "Enter a connected location to move to (or 'q' to quit): ";
    cin >> input;
    if (input == "q") {
      break;
    }
    for (auto connected : currentLocation->connectedLocations) {
      if (connected->name == input) {
        currentLocation = connected;
        break;
      }
    }
  }

  return 0;
}
