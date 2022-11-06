#pragma once
#include "Includes.h"
#include "Memory.h"
#include "Offsets.h"
using namespace hazedumper::netvars;
using namespace hazedumper::signatures;

class CheatM
{
public:
	struct FeatureM
	{
		void Bhop()
		{
			const auto mem = Memory("csgo.exe");
			const auto client = mem.GetModuleAddress("client.dll");
			System.Clean();
			System.Color.Green();
			std::cout << "Bhop has been enabled." << std::endl;
			while (true)
			{
				const uintptr_t LocalPlayer = mem.Read<uintptr_t>(client + dwLocalPlayer);
				const int32_t Flags = mem.Read<int32_t>(LocalPlayer + m_fFlags);

				if (GetAsyncKeyState(VK_SPACE) && Flags & (1 << 0))
				{
					mem.Write<int32_t>(client + dwForceJump, 5);
				}
				else
				{
					mem.Write<int32_t>(client + dwForceJump, 4);
				}
			}

		}

		void FOV()
		{
			const auto mem = Memory("csgo.exe");
			const auto client = mem.GetModuleAddress("client.dll");
			int val;
			std::cout << "Enter FOV Value: ";
			std::cin >> val;
			System.Clean();
			System.Color.Green();
			std::cout << "FOV value has been set to " << val << "." << std::endl;
			while (true)
			{
				const uintptr_t LocalPlayer = mem.Read<uintptr_t>(client + dwLocalPlayer);

				mem.Write<int32_t>(LocalPlayer + m_iFOV, val);

			}

		}

		void GlowESP()
		{
			const auto mem = Memory("csgo.exe");
			const auto client = mem.GetModuleAddress("client.dll");

			System.Clean();
			System.Color.Green();
			std::cout << "Glow ESP has been enabled.\nEnemies will glow in white color." << std::endl;

			uintptr_t GlowObjMgr = mem.Read<uintptr_t>(client + hazedumper::signatures::dwGlowObjectManager);
			while (true)
			{
				uintptr_t LocalPlayer = mem.Read<uintptr_t>(client + hazedumper::signatures::dwLocalPlayer);
				int LTeam = mem.Read<int>(LocalPlayer + hazedumper::netvars::m_iTeamNum);

				for (int i = 1; i < 32; i++)
				{
					uintptr_t Ent = mem.Read<uintptr_t>(client + hazedumper::signatures::dwEntityList + i * 0x10);
					int ETeam = mem.Read<int>(Ent + hazedumper::netvars::m_iTeamNum);
					int GlowIdx = mem.Read<int>(Ent + hazedumper::netvars::m_iGlowIndex);

					if (LocalPlayer && Ent != NULL)
					{
						if (LTeam != ETeam)
						{
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0x8, 255);
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0xC, 255);
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0x10, 255);
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0x14, 255);
						}
						else
						{
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0x8, 255);
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0xC, 255);
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0x10, 255);
							mem.Write<float>(GlowObjMgr + (GlowIdx * 0x38) + 0x14, 255);
						}
						mem.Write<bool>(GlowObjMgr + (GlowIdx * 0x38) + 0x28, true);
						mem.Write<bool>(GlowObjMgr + (GlowIdx * 0x38) + 0x29, false);
					}
				}
			}
		}

		void TriggerBot()
		{
			const auto mem = Memory("csgo.exe");
			const auto Base = mem.GetModuleAddress("client.dll");
			System.Clean();
			System.Color.Green();

			while (true)
			{
				uintptr_t LocalPlayer = mem.Read<uintptr_t>(Base + hazedumper::signatures::dwLocalPlayer);
				int LTeam = mem.Read<int>(LocalPlayer + hazedumper::netvars::m_iTeamNum);
				int CrosshairId = mem.Read<int>(LocalPlayer + hazedumper::netvars::m_iCrosshairId);
				for (int i = 1; i < 64; i++)
				{
					uintptr_t Ent = mem.Read<uintptr_t>(Base + hazedumper::signatures::dwEntityList + (CrosshairId - 1) * 0x10);
					int ETeam = mem.Read<int>(Ent + hazedumper::netvars::m_iTeamNum);

					if (!CrosshairId || CrosshairId > 64) continue;

					if (LTeam == ETeam) continue;

					mem.Write<int>(Base + hazedumper::signatures::dwForceAttack, 6);
					std::cout << "Enemy has been detected! " << "Entity List -> " << "0x" << std::hex << Ent << std::dec << std::endl;
					Sleep(2);
					mem.Write<int>(Base + hazedumper::signatures::dwForceAttack, 4);
				}
			}
		}

		void RadarHack()
		{
			const auto mem = Memory("csgo.exe");
			const auto Base = mem.GetModuleAddress("client.dll");
			System.Clean();
			System.Color.Green();
			std::cout << "Radar hack has been enabled.\nTake a look at the left corner." << std::endl;
			while (true)
			{
				uintptr_t LocalPlayer = mem.Read<uintptr_t>(Base + hazedumper::signatures::dwLocalPlayer);
				int LTeam = mem.Read<int>(LocalPlayer + hazedumper::netvars::m_iTeamNum);
				for (int i = 1; i < 32; i++)
				{
					uintptr_t Ent = mem.Read<uintptr_t>(Base + hazedumper::signatures::dwEntityList + i * 0x10);
					int ETeam = mem.Read<int>(Ent + hazedumper::netvars::m_iTeamNum);

					if (ETeam == LTeam) continue;

					mem.Write<bool>(Ent + hazedumper::netvars::m_bSpotted, true);
				}
			}
		}

		void ThirdPerson()
		{
			const auto mem = Memory("csgo.exe");
			const auto Base = mem.GetModuleAddress("client.dll");
			System.Clean();
			System.Color.Green();
			std::cout << "ThirdPerson has been enabled." << std::endl;
			while (true)
			{
				uintptr_t LocalPlayer = mem.Read<uintptr_t>(Base + hazedumper::signatures::dwLocalPlayer);

				if (LocalPlayer != NULL)
				{
					mem.Write<bool>(LocalPlayer + hazedumper::netvars::m_iObserverMode, true);
				}

				if (GetAsyncKeyState(VK_F4))
				{
					mem.Write<bool>(LocalPlayer + hazedumper::netvars::m_iObserverMode, false);
					Window = 0;
				}
			}
		}

		void FlashHunter()
		{
			const auto mem = Memory("csgo.exe");
			const auto Base = mem.GetModuleAddress("client.dll");
			int32_t CurFlashVal{};
			System.Clean();
			System.Color.Green();
			std::cout << "Anti FlashBang has been enabled.\nCurrent flash value: " << CurFlashVal << std::endl;
			while (true)
			{
				uintptr_t LocalPlayer = mem.Read<uintptr_t>(Base + hazedumper::signatures::dwLocalPlayer);

				CurFlashVal = mem.Read<int32_t>(LocalPlayer + m_flFlashDuration);

				if (LocalPlayer != NULL)
				{
					mem.Write<float>(LocalPlayer + hazedumper::netvars::m_flFlashDuration, 0.0f);
				}
			}
		}
	}Feature;
}Cheat;