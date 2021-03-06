// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <MyTools/CLProcess.h>
#include <MyTools/Log.h>
#include <MyTools/CLPublic.h>
#include <MyTools/CmdLog.h>
#include <MyTools/CLAsync.h>
#include <MyTools/Character.h>
#include <MyTools/CLEchoException.h>
#include "Expr.h"
#include "GameVariable.h"
#include "CodeTransfer.h"

#define _SELF L"dllmian.cpp"

HANDLE hWorkThread = NULL;
DWORD WINAPI _WorkThread(LPVOID)
{
	MyTools::CLAsync::GetInstance().Run();
	MyTools::CLog::GetInstance().SetClientName(L"Game", MyTools::CLPublic::MakeCurrentPath(L"\\DLog\\"));
	
	MyTools::CCmdLog::GetInstance().Run(L"Game", CExpr::GetInstance().GetVec());
	MyTools::CLEchoException::GetInstance().InvokeAction(__FUNCTIONW__, [] {CCodeTransfer::Hook(); });
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hWorkThread = cbBEGINTHREADEX(NULL, NULL, _WorkThread, NULL, NULL, NULL);
		::CloseHandle(hWorkThread);
		::DisableThreadLibraryCalls(hModule);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport)  VOID WINAPIV ExitDLL()
{
	CCodeTransfer::UnHook();
	MyTools::CCmdLog::GetInstance().Stop();
	MyTools::CLAsync::GetInstance().Stop();
	MyTools::CLog::GetInstance().Release();
}