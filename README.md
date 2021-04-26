# ENGG1340_Course_Project_Group_91
# Group No.: 91
# Group members: Ting Chun Tat, Wong Chak Man
# Topic: Call of Cthulhu ( CoC )


## Introduction: CoC is a tabletop role playing game. Every choices the player make will affect the plot of the game. The player can achieve different endings based on the choices that he/ she made.


## Game rules:
### 1. Avoid entering invalid inputs, all valid inputs are shown on screen for you. The plot will not advance if invalid inputs are received.
### 2. Do not regenerate statistics by deleting stats.txt over and over again to get better statistics.
### 3. Do not edit stats.txt directly and change the player status stored inside.
### 4. Try to avoid letting the character die. Once the character die, the game is over.
### 5. Enjoy the game.


## list of features:
### 1. Customized investigator statistic generation. Player can distribute their arrtibute points freely or let the program distribute remaining points randomly. (element 1, generation of random game sets) (element 5, statistic generation is stored in a seperate program)
### 2. Typerwriter effect when displaying text of the game. This can provide player with more immersive experience. The sleep function in <unistd.h> library is used for this feature.
### 3. Random events. The success rate of player's action and the occurrence rate of some special event will be based on his/her investigator statistics.(element 1, Generation of random events)
### 4. Combat system. Some monsters may come out and the player may have to fight them to advance the plot. (element 3, dynamic memory management, monster's status will be deleted after it is defeated) (element 5, combat system is stored in a seperate program)
### 5. Different ending base on the choices of player, the player's choices will affect the plot of the game.
### 6. Inventory system. All the player's status including inventory will be stored in a singel struct called player. The player can pick up items in theie gameplay and store them in his/ her inventory and use them later.(element 2, data structures for storing player's status) 
### 7. Save and load function. A file stats.txt will be created to save player's status of the game and it will be autoamtically updated when player wnter a new room. When player launch the game, the program will check if stats.txt exist. If stats.txt exist, data will be read and player can resume their game. If stats.txt doesn't exist, player need to create a new investigator. (element 4, file input/output for loading/saving game status)


## list of non-standard C/C++ libraries:
### <unistd.h> is used for the typrewriter effect to display text charcter by character using the sleep function.


## Compilation and execution instructions:
### 1. Download all the files and store them in 1 directory
### 2. Use the command 'make main' under that directory to compile the program
### 3. Use the command './main' to launch the game

### To resume previous game, simply use command './main' to launch the game again and the game will resume at the point of you last time entering a new room.
### To delete your previous investigator and start the game all over again, use command 'make restart' when the game is not running, then launch the game with './main'.


The program has been tested in academy21 server
