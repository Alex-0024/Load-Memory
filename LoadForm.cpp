#include <iostream>
#include <vector>
#include <thread>
#include "LoadForm.h"

using namespace LoadMemory;

using std::cout;
using std::endl;

unsigned long long GB = 0;
bool flagDoin = true;
std::atomic<bool> flagFullMemory = false;
std::thread threadStartAsync;
int cntWhile = 0;
const unsigned long long coeff_for_mas = 250000000; // it depends on of size one element of mas (this is for int)

System::Decimal LoadForm::getCntGb()
{
	return cntGB->Value;
}

void startAsync()
{
	std::cout << "START" << std::endl;
	unsigned long long size = coeff_for_mas * GB;
	std::cout << size << std::endl;
	try
	{
		std::vector<int> mas(size);
		auto clear_mas = [&mas]() {
			mas.clear();
			std::vector<int>().swap(mas);
		};
		while (true)
		{
			for (auto& one : mas)
			{
				if (flagDoin) {
					one ^= 1;
				} else {
					clear_mas();
					return;
				}
			}
			flagFullMemory = true;
			cntWhile++;
		}
		clear_mas();
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "ERROR: Not enough memory! " << e.what() << endl;
	}
	catch (const std::exception& err)
	{
		std::cerr << "ERROR: " << err.what() << endl;
	}
}

System::Void LoadForm::btStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Are you sure you want to take " + getCntGb().ToString() + " GB memory.\n" + "It`ll can be DANGEROUS!!!",
		"Warning",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question
	);

	if (result == System::Windows::Forms::DialogResult::No)	{
		return;
	}

	flagDoin = true;
	flagFullMemory = false;
	
	btStart->BackColor = System::Drawing::SystemColors::Control;
	btStart->Enabled = false;
	
	btFinish->Enabled = true;
	btFinish->BackColor = System::Drawing::Color::Lime;
		
	GB = static_cast<unsigned long long>(getCntGb());
	threadStartAsync = std::thread(startAsync);
	threadStartAsync.detach();
};

System::Void LoadForm::btFinish_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::cout << "FINISH" << std::endl;
	
	btFinish->BackColor = System::Drawing::SystemColors::Control;
	btFinish->Enabled = false;
	
	flagDoin = false;

	btStart->Enabled = true;
	btStart->BackColor = System::Drawing::Color::Lime;

	flagFullMemory = false;
};

void LoadForm::checkMemory()
{
	static bool oldFlagFullMemory = true;
	if (flagFullMemory != oldFlagFullMemory)
	{
		textMessage->Text = flagFullMemory ? "Memory is full" : "Memory is empty";
		oldFlagFullMemory = flagFullMemory;
	}
}

System::Void LoadForm::timerCheckMemory(System::Object^ sender, System::EventArgs^ e)
{
	checkMemory();
	cout << "checkMemory" << endl;
	cout << "flagMemory: " << flagFullMemory << endl;
	cout << "cntWhile: " << cntWhile << endl;
}