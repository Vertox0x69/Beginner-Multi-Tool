#pragma once
#include "Includes.h"


class Systemanager
{
public:
	void Clean()
	{
		system("cls");
	}

	void Stop()
	{
		system("Pause");
	}

	void Exit()
	{
		exit(48);
	}

	struct ColorMgr
	{

		void Green()
		{
			system("color 2");
		}

		void Red()
		{
			system("color 4");
		}
	}Color;

	DWORD_PTR GetProcessIdByName(const std::string process_name) {
		PROCESSENTRY32 process_info;
		process_info.dwSize = sizeof(process_info);

		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		if (snapshot == INVALID_HANDLE_VALUE)
			return 0;

		Process32First(snapshot, &process_info);
		if (!process_name.compare(process_info.szExeFile)) {
			CloseHandle(snapshot);
			return process_info.th32ProcessID;
		}

		while (Process32Next(snapshot, &process_info)) {
			if (!process_name.compare(process_info.szExeFile)) {
				CloseHandle(snapshot);
				return process_info.th32ProcessID;
			}
		}

		CloseHandle(snapshot);


		return 0;
	}

}System;


void NiggerCheck()
{
	uintptr_t ProcessHacker = System.GetProcessIdByName("ProcessHacker.exe");
	uintptr_t IDA = System.GetProcessIdByName("ida.exe"); // This is a 32Bit app there's no reason someone will reverse it in ida64.exe.
	uintptr_t Dnspy = System.GetProcessIdByName("dnSpy.exe");

	while (ProcessHacker)
	{
		System.Clean();
		System.Color.Red();
		std::cout << "Process Hacker Is Running!" << std::endl;
		std::cout << "Bye Bye" << std::endl;
		System.Stop();
		Sleep(20);
		System.Exit();
	}

	while (IDA)
	{
		System.Clean();
		System.Color.Red();
		std::cout << "IDA Is Running!" << std::endl;
		std::cout << "Bye Bye" << std::endl;
		System.Stop();
		Sleep(20);
		System.Exit();
	}

	while (Dnspy)
	{
		System.Clean();
		System.Color.Red();
		std::cout << "Dnspy Is Running!" << std::endl;
		std::cout << "Bye Bye" << std::endl;
		System.Stop();
		Sleep(20);
		System.Exit();
	}

}