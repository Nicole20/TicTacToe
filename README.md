# TicTacToe

For this Tic Tac Toe game, I decided to have an AI player, instead of two user players. This allowed me to focus on making a strategy for the computer to use.

#GLUT setup

Include your GLUT files in your project properties.
C/C++ -> General -> Additional Include Directories: add the folder where the GLUT include file is located.
Linkers -> General -> Additional Lirbary Directories: add the folder where the GLUT library file is located.
Linkers -> Input -> add the following:
opengl32.lib
glu32.lib
freeglut.lib
glut32.lib
