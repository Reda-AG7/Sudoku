default:
	g++ -std=c++20 -o game *.cpp States/*.cpp Components/*.cpp -lsfml-window -lsfml-graphics -lsfml-system

	./game
