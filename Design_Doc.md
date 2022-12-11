Project Design:

This project is a basic working model of intercommunication between autonomous vehicles. The situation we have selected to implement is a car between two motorcycles. We did write a truck class but did not utilize it in our implementation. 

All the vehicle classes inherit the auto_v class, which contains most of our program’s variables and methods pertaining to the vehicles. The variables we chose to include were the number of passengers, safety score, and average age of passengers, emergency objective, and average weight. There are getters and setters for these variables as well as constructors for the objects. We have also added a print function, dump2JSON function, and JSON2Object function, all used in our code. We also have a “braceForImpact” function that details the notification process once a crash target has been selected. Lastly, we have a “chooseCrash” method, which chooses where to crash in case of danger. We have done the project under the philosophy that the car should never sacrifice itself. This method compares two autonomous vehicles and gives each a score out of 500 to rank its “crash-ability”. First, the score accounts for each vehicle's score out of 100. Then it also adds a score out of 100 for average age, with the score being higher for lower average age (protect the youth!). We give 20 points per passenger, giving 5 passenger cars a perfect score of 100. If the vehicle has an emergency objective, we award it 100 points. Lastly, we divide 10,000 by the average weight of the passengers to obtain a coefficient that seeks to protect frailer riders. It then returns the autonomous vehicle that will receive the crash, so a danger message can be sent. 

Both of our executables are unique servers, as well as clients that interact to send and obtain information between each other. 

Chronological order:
A car detects that danger is present and decides it needs to crash
It is surrounded by 2 motorcycles, both of which are also autonomous vehicles
It sends an info request to a shared server to get info on the vehicles and the passengers
It uses this data to determine which vehicle to crash into
It sends a message on the server to the vehicle that is about to be crashed into to “brace for impact”
At that point, that vehicle would prepare physically for the crash
Crash happens
