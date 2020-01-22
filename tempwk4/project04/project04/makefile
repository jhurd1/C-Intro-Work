###############################################################
# Program:
#     moonLander, Makefiles
#     Brother Dudley, CS165
# Author:
#     Jamie Hurd
# Summary:
#     Classes for ground, point, and lander, controlling the
#location of objects in the Moon Lander game on a two dimensional
#geographic plane. Lander draws the lander object and exploits
#Point to control its location, landing, crashing, velocity,
#and fuel.
###############################################################
#atom may replace tabs with two spaces, which won't work for makefile
#must tab over the g++ lines(?)

# Insert your rule for a.out here:
a.out: lander.hpp lander.cpp velocity.hpp velocity.cpp point.hpp point.cpp main.cpp uiInteract.cpp uiInteract.hpp uiDraw.cpp uiDraw.hpp
	g++ lander.cpp main.cpp

# Insert your rule for robot.o here:
lander.o: lander.cpp lander.hpp
	g++ -c lander.cpp

# Insert your rule for point.o here:
point.o: point.cpp point.hpp
	g++ -c point.cpp

# ground.o
ground.o: ground.cpp ground.hpp
	g++ -c ground.cpp

# velocity.o
velocity.o: velocity.cpp velocity.hpp
	g++ -c velocity.cpp

# uiInteract.o
uiInteract.o:	uiInteract.cpp uiInteract.hpp
	g++ -c uiInteract.cpp uiInteract.hpp

#uiDraw.o
uiDraw.o: uiDraw.cpp uiDraw.hpp
	g++ -c uiDraw.cpp uiDraw.hpp

# Insert your rule for check06a.o here:
main.o: main.cpp
	g++ -c main.cpp
