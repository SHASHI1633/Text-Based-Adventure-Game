# Text-Based-Adventure-Game
This code implements a simple text-based adventure game where the player can navigate between locations and encounter events. The Location class represents different locations in the game world, such as towns or forests, and tracks their name, description, and connected locations. Each location can be connected to other locations, allowing the player to move between them. The Event class represents events that can occur in the game, such as finding treasure or encountering monsters. Each event has a name, description, associated location, and a function pointer to execute the event's actions.

The main function initializes the game world by creating locations and adding events to the event heap. The game then enters a loop where it displays the current location, connected locations, and any upcoming events. If an event is applicable to the current location, it executes the event's actions. The player can then choose to move to a connected location or quit the game. The game continues until the player decides to quit. Overall, this code provides a framework for a simple interactive adventure game with basic location navigation and event encounters.

Several data structures and algorithms concepts are used in this code:

1  Classes: The Location and Event classes are used to organize data and behavior related to locations and events in the game.
2  Vectors: Vectors are used to store connected locations in the Location class and events in the event heap.
3  Function Pointers (std::function): Function pointers are used in the Event class to define the behavior of events.    std::function<void()> allows flexibility in defining event handlers.
4  Heap (Simplified Min-Heap): The eventHeap vector is used as a simplified form of a min-heap to manage events based on their names.    This allows events to be executed in a specific order.
5  Dynamic Memory Management (Pointers): Pointers are used to manage connected locations in the Location class and to execute events    associated with locations.
   Input/Output: Basic input/output operations are used to interact with the player, such as displaying information and reading user    input.

   
Alternative approaches and improvements could include:

1  Using a Map for Locations: Instead of using a vector for connected locations, a map could be used to associate each location with its    connected locations. This would provide faster access to connected locations.
2  Event Queue: Instead of using a simplified min-heap, an actual priority queue could be used to manage events based on their priority.    This would allow for more efficient event management.
3  Command Design Pattern: Use the Command design pattern to represent events. Each event could be a command object with an execute    method, allowing for more flexibility and extensibility in defining event behavior.
4  Object-Oriented Design Patterns: Use other object-oriented design patterns, such as Observer pattern for events, to decouple event    execution from event definition and allow for more complex event interactions.
5  Enhanced Event Handling: Implement a more robust event handling system that allows for more complex event logic, such as event    chains, conditional events, and event cancellation.
