# MVC time-dependent Simulation

## Buildings
- **Farm**. Creates boxes of crop every time unit.
- **Castle**. Can hold boxes of corp.

## Characters
- **Peasant**. Moves boxes of crop from farms to castles.
- **Knight**. Patrols between farms and castles.
- **Thug**. Attacks peasants and steal their crops.

## Commands
- **default**. Resets the map to its original position.
- **size** \<num\>. Changes the size of the map.
- **zoom** \<num\>. Changes the scale of the map.
- **pan** \<num\> \<num\>. Moves the origin of the map.
- **show**. print the map.
- **status**. lists the status of all the building and characters in the simulation.
- **go**. Inceremnt one time unit.
- **create \<name\> \<kind\> \<location\>**. Creates a new character.
- **\<name\> course \<angle\>**. Sets the direction of a specific character
- **\<name\> destination \<building name\>**. Sets the direction of the character to the building.
- **\<name\> stop**. Order the character to stop moving.
- **\<name\> attack \<name\>**. Order a thug to attack a peasant.

## Screenshot:
<img width="1389" alt="Screenshot" src="https://user-images.githubusercontent.com/58071878/141595021-eb71a71a-8db1-45d1-b9cb-7d37c79e31f8.png">

## Running instructions ##
1. Download repo
```
git clone https://github.com/golrol/MVC_Simulation ~/Desktop/MVC_Simulation
```
2. Navigate into the directory
```
cd ~/Desktop/MVC_Simulation
```
3. Compile the program
```
g++ -std=c++0x *.cpp -o run
```
4. Run the program with input files
```
./run castles.dat farms.dat
```
