#include "pch.h"
#include <stdio.h>
#include "mainHackLoop.h"
#include "consoleAndInput.h"
#include "setupHooksAndNops.h"

// Funktion, die als Thread ausgeführt wird, wenn die DLL geladen wird
void WINAPI HackThread(HMODULE hModule)
{
	// Konsole erstellen
	ToggleConsole();

	// Hooks und NOPs einrichten
	setupHooksandNops();

	// Aktivieren der gewünschten Hooks
	mainHackLoopTramp.ToggleTrampSBF();
	//harvestDataTramp.ToggleTrampSBF();
	

	// Konsole ausgeben
	PrintConsole();

	// Hauptschleife des Hacks
	while (!bBreakHackThreadWhileLoop)
	{
		// Hack-Logik oder Überprüfung auf Beendigung hier hinzufügen
		// Zum Beispiel: Sleep(100);
	}

	// Konsole freigeben
	ToggleConsole();

	// Bibliothek entladen und Thread sicher beenden
	FreeLibraryAndExitThread(hModule, 0);
}

// DLL-Einstiegspunkt
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// Ein neuer Thread wird erstellt, um HackThread auszuführen
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
