#include "./../include/raylib-cpp.hpp"
#include <vector>

class Automaton
{
private:
	void update();
	void render();
	void processEvents();
	void setup(int seed);
	std::vector<int> countNeighbors(int x, int y); // return an array where the index corresponds to the type of the cell and the value is the amount of them. 0: rock 1: paper 2: scissors

public:
	Automaton(int height, int width, int pixel_size, std::string window_name = "Cellular Automaton")
	{
		HEIGHT = height / pixel_size;
		WIDTH = width / pixel_size;
		this->pixel_size = pixel_size;
		WINDOW_NAME = window_name;
		window = new raylib::Window(height, width, this->WINDOW_NAME);
	}
	void run(int seed);

private:
	int HEIGHT;
	int WIDTH;
	int pixel_size;
	raylib::Window *window;
	std::string WINDOW_NAME;
	std::vector<std::vector<int>> grid;
	std::vector<std::vector<int>> grid_tmp;

	enum Types
	{
		rock = 1,
		paper = 2,
		scissors = 3
	};
};