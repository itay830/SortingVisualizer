#include "include/Simulation.h"

int main() {
	Simulation simulation{0, 0, "Sorting Visualizer"};
	ChangeDirectory(GetWorkingDirectory());
	simulation.run();
	return 0;
}
