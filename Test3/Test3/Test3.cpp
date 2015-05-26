// Test3.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <iostream>
#include <cstdlib>

using namespace Test3;
int temp=0;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	
	Application::Run(gcnew Form1());
	return 0;
}
// ciekawy program
// wybitna edycja
// kolejna super turbo linia
//nowy branch kolejna zmiana