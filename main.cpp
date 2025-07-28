#include "LoadForm.h"

using namespace LoadMemory;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoadForm form;
	Application::Run(% form);
}