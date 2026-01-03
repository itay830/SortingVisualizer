#include "include/Simulation.h"

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	Simulation simulation{800, 800, "Sorting Visualizer"};
	ChangeDirectory(GetWorkingDirectory());
	simulation.run();
	return 0;
}
