#include "Includes.h"


int main()
{
	switch (Window)
	{
	case 0:
		if ((Window == 0))
		{
			std::cout << "Welcome To Lyonzon's Multi Tool!" << std::endl;

			Sleep(20);

			for (int i = 0; i < 20; ++i)
			{
				std::cout << "Checking for malwares...";
				System.Clean();
				System.Color.Green();
				System.Color.Red();
			}

			NiggerCheck();

			System.Color.Green();

			std::cout << "No Shit You're Not A Skid!!" << std::endl;

			Sleep(20);

			Window = 1;
		}
	case 1:
		if ((Window == 1))
		{
			NiggerCheck();

			std::cout << "Choose Where U Want To Go: " << std::endl;

			std::cout << "[2] Calculator" << std::endl;

			std::cout << "[3] CSGO Cheat" << std::endl;

			auto start = std::chrono::system_clock::now();
			// Some computation here
			auto end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "" << std::endl;

			std::cout << "" << std::ctime(&end_time) << "" << std::endl;

			std::cout << "Answer? : ";

			std::cin >> Window;

			System.Clean();
		}
	case 2:
		if ((Window == 2))
		{
			System.Clean();

			NiggerCheck();

			std::cout << "Choose Your Calculation Method: " << std::endl;

			std::cout << "[1] Essay" << std::endl;
			while (GetAsyncKeyState(0x50))
			{
				Calculator.Calculate.P();
			}

			std::cout << "[2] Subtraction" << std::endl;
			while (GetAsyncKeyState(0x53))
			{
				Calculator.Calculate.Minus();
			}

			std::cout << "[3] Multiplication" << std::endl;
			while (GetAsyncKeyState(0x4D))
			{
				Calculator.Calculate.M();
			}

			std::cout << "[4] Division" << std::endl;
			while (GetAsyncKeyState(0x44))
			{
				Calculator.Calculate.Devide();
			}

			std::cout << ">> ";
			int choose;
			std::cin >> choose;
			if (choose == 1 )
			{
				Calculator.Calculate.P();
			}
			else if (choose == 2)
			{
				Calculator.Calculate.Minus();
			}
			else if (choose == 3)
			{
				Calculator.Calculate.M();
			}
			else if (choose == 4)
			{
				Calculator.Calculate.Devide();
			}
			System.Stop();
		}
	case 3:
		if ((Window == 3))
		{
			NiggerCheck();

			std::cout << "Choose Where U Want To Go: " << std::endl;

			std::cout << "[1] Bhop" << std::endl;

			std::cout << "[2] FOV Changer" << std::endl;

			std::cout << "[3] Glow ESP" << std::endl;

			std::cout << "[4] TriggerBot" << std::endl;

			std::cout << "[5] RadarHack" << std::endl;

			std::cout << "[6] Anti FlashBang" << std::endl;


			std::cout << ">> ";
			int ans;
			std::cin >> ans;
			if (ans == 1)
			{
				Cheat.Feature.Bhop();
			}
			if (ans == 2)
			{
				Cheat.Feature.FOV();
			}
			if (ans == 3)
			{
				Cheat.Feature.GlowESP();
			}
			if (ans == 4)
			{
				Cheat.Feature.TriggerBot();
			}
			if (ans == 5)
			{
				Cheat.Feature.RadarHack();
			}
			if (ans == 6)
			{
				Cheat.Feature.FlashHunter();
			}
		}
	}
}