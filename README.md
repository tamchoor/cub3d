# cub3d
This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.


This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
To conclude cub3D is a remarkable playground to explore the playful practical appli- cations of mathematics without having to understand the specifics.
With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.

External functs.

• open, close, read, write, printf, malloc, free, perror, strerror, exit
• All functions of the math library (-lm man man 3 math)
• All functions of the MinilibX


The constraints are as follows:

• You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part.

• The management of your window must remain smooth: changing to another win- dow, minimizing, etc.

• Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).

Your program must be able to set the floor and ceiling colors to two different ones.

• The program displays the image in a window and respects the following rules:

◦ The left and right arrow keys of the keyboard must allow you to look left and
right in the maze.
◦ The W, A, S, and D keys must allow you to move the point of view through the maze.
◦ Pressing ESC must close the window and quit the program cleanly.
◦ Clicking on the red cross on the window’s frame must close the window and
quit the program cleanly.
◦ The use of images of the minilibX is strongly recommended.

• Your program must take as a first argument a scene description file with the .cub extension.

◦ The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation.
◦ The map must be closed/surrounded by walls, if not the program must return an error.
◦ Except for the map content, each type of element can be separated by one or more empty line(s).
◦ Except for the map content which always has to be the last, each type of element can be set in any order in the file.
◦ Except for the map, each type of information from an element can be separated by one or more space(s).
◦ The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.
◦ Each element (except the map) firsts information is the type identifier (com- posed by one or two character(s)), followed by all specific informations for each object in a strict order

∗ North texture:
         NO ./path_to_the_north_texture
· identifier: NO
· path to the north texure 

∗ South texture:
         SO ./path_to_the_south_texture
· identifier: SO
· path to the south texure 

∗ West texture:
         WE ./path_to_the_west_texture
· identifier: WE
· path to the west texure 

∗ East texture:
         EA ./path_to_the_east_texture
· identifier: EA
· path to the east texure 

∗ Floor color:
F 220,100,0
· identifier: F
· R,G,B colors in range [0,255]: 0, 255, 255

∗ Ceilling color:
C 225,30,0
· identifier: C
· R,G,B colors in range [0,255]: 0, 255, 255

If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.

Bonus list:

• Wall collisions.

• A minimap system.

• Doors which can open and close.

• animated sprite.

• Rotate the point of view with the mouse.

