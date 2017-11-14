#include "stdafx.h"
#include "GameUi.h"
#include <MyTools/Character.h>
#include <MyTools/Log.h>
#include <MyTools/CLEchoException.h>
#include "CodeTransfer.h"
#include "GameCALL.h"

#define _SELF L"GameUi.cpp"
CGameUi::CGameUi(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	if(_dwNodeBase != NULL)
		SetName();
}

DWORD CGameUi::GetObj() CONST
{
	return ReadDWORD(GetNodeBase() + 0x8);
}

BOOL CGameUi::IsShow() CONST
{
	return ReadBYTE(GetObj() + UI�Ƿ���ʾƫ��) != 0;
}

BOOL CGameUi::IsShow_Fight() CONST
{
	return ReadBYTE(GetObj() + ����ս���˵�UIƫ��) != 0;
}

VOID CGameUi::SetName()
{
	DWORD dwNamePtr = 0;
	MyTools::CLEchoException::GetInstance().InvokeAction(__FUNCTIONW__, [&] 
	{
		DWORD dwObjectPtr = GetObj();
		DWORD dwValue = 0;
		__asm
		{
			MOV ECX, dwObjectPtr;
			MOV EAX, DWORD PTR DS : [ECX];
			MOV EAX, DWORD PTR DS : [EAX + UI_Name�麯��ƫ��];
			CALL EAX;
			MOV dwValue, EAX;
		}
		dwNamePtr = dwValue;
	});

	if (dwNamePtr != 0)
	{
		_wsName = MyTools::CCharacter::ASCIIToUnicode(std::string(reinterpret_cast<CHAR*>(dwNamePtr)));
	}
}

VOID CGameUi::Click() CONST
{
	LOG_C_D(L"ClickDlg[%s]", GetName().c_str());;
	CCodeTransfer::PushPtrToMainThread([this] { CGameCALL::ClickChildGameUi(GetObj()); });
}
