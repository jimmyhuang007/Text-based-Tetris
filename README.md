# Text-based-Tetris
A Text-based Tetris constructed with C++14

![alt tag](https://github.com/jimmyhuang007/Text-based-Tetris/blob/master/Capture.PNG) 

To run, compile the file using Makefile and execute “quadris” on the command line.

Program supports following options on command line

Program supports following options on command line
•	“-text” which runs the game in text-only  
•	“-seed xxx” which sets the block random generator’s seed to xxx  
•	“-scriptfile xxx” use xxx instead of sequence.text as source of block generating at level 0  
•	“-startlevel n” starts the game in level n  

 
To play the game, all user inputs must be executed from the command line  
In game commands,   
•	“left” move current block one cell to the left  
•	“right” move current block one cell to the right  
•	“down” move current block one cell down  
•	“clockwise” rotate block 90 degrees clockwise  
•	“clockwise” rotate block 90 degrees clockwise  
•	“counterclockwise” rotate block 90 degrees counterclockwise  
•	“drop” drop the current black as far down as possible before contact either the bottom or a block  
•	“levelup” increase the game level by one  
•	“leveldown” decrease the game level by one  
•	“norandom xxx” relevant only at level 3 and 4. Makes these levels to take input from xxx file instead of random  
•	“random” relevant only at level 3 and 4. Restore random again  
•	“sequence xxx” Execute sequence of commands in xxx  
•	“I” replaces the current block with I-block  
•	“J” replaces the current block with J-block  
•	“L” replaces the current block with L-block  
•	“restart” clears the board and starts a new game  
