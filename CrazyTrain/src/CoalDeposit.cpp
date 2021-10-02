#include <string>

#include "CoalDeposit.h"
#include "Program.h"

void CoalDeposit::Init()
{
	rect = Rectangle{ 200, Program::GroundHeight - 20, 50, 50 };
}

void CoalDeposit::Render()
{
	DrawRectangleRec(rect, BLACK);
}
