#include "stdafx.h"
#include "GameCALL.h"

CGameCALL::SendCALLPtr CGameCALL::_SendPtr = reinterpret_cast<CGameCALL::SendCALLPtr>(����CALL);
CGameCALL::FightCALLPtr CGameCALL::_FightPtr = reinterpret_cast<CGameCALL::SendCALLPtr>(ս��CALL);
CHAR CGameCALL::_szEmptyText[32] = { 0 };
VOID CGameCALL::UseItem_NoFight(_In_ DWORD dwItemId)
{
	__try
	{
		CONST static CHAR szText[] = { "pos = %d" };
		_SendPtr(dwItemId, szText, 0x220C);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"UseItem_NoFight", L"", NULL);
	}
}

VOID CGameCALL::NormalAttack(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwTarId, 0x2, 0x0, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"NormalAttack", L"", NULL);
	}
}

VOID CGameCALL::Defence(_In_ DWORD dwInvokeId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwInvokeId, 0x1, 0x0, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"Defence", L"", NULL);
	}
}

VOID CGameCALL::UseItem(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId, _In_ DWORD dwItemId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwTarId, 0x4, dwItemId, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"UseItem", L"", NULL);
	}
}

VOID CGameCALL::RunAway(_In_ DWORD dwPersonId)
{
	__try
	{
		_FightPtr(dwPersonId, dwPersonId, 0x7, 0x0, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"RunAway", L"", NULL);
	}
}

VOID CGameCALL::UseSKill(_In_ DWORD dwInvokeId, _In_ DWORD dwTarId, _In_ em_SkillId SkillId)
{
	__try
	{
		_FightPtr(dwInvokeId, dwTarId, 0x3, SkillId, _szEmptyText, _szEmptyText, _szEmptyText, 0, _szEmptyText);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"UseSKill", L"", NULL);
	}
}

VOID CGameCALL::Walk(_In_ DWORD dwX, _In_ DWORD dwY)
{
	__try
	{
		dwX *= 0x18;
		dwY *= 0x18;
		__asm
		{
			MOV EAX, ��·CALL��ַ;
			MOV EAX, DWORD PTR DS : [EAX];
			MOV ESI, DWORD PTR DS : [EAX];
			MOV EDX, DWORD PTR DS : [ESI + ��·ƫ��];

			PUSH dwX;
			PUSH dwY;

			MOV ECX, ��·��ַ;
			MOV ECX, DWORD PTR DS : [ECX];
			CALL EDX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"Walk", L"", NULL);
	}
}

VOID CGameCALL::ClickChildGameUi(_In_ DWORD dwUiObject)
{
	__try
	{
		CONST static CHAR szText[] = { "CLICKED_BTN"};
		__asm
		{
			PUSH 0x0;
			LEA EAX, szText;
			PUSH EAX;

			MOV ECX, dwUiObject;
			MOV EAX, �����CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"ClickChildGameUi", L"", NULL);
	}
}

VOID CGameCALL::FindPath(_In_ LPCSTR pszText)
{
	__try
	{
		DWORD dwArray[128] = { 0 };
		dwArray[Ѱ·Bufferƫ�� / 4] = 0xC136;

		__asm
		{
			MOV EAX, pszText;
			PUSH EAX;
			
			LEA ECX, dwArray;
			MOV EAX, Ѱ·CALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"FindPath", L"", NULL);
	}
}

VOID CGameCALL::PetAddHp(_In_ DWORD dwPetObject)
{
	__try
	{
		CONST static CHAR szText[] = { "life" };
		__asm
		{
			MOV ECX, ���ﲹѪ��ַ;
			MOV ECX, DWORD PTR DS : [ECX];

			PUSH 0;
			PUSH 0x64;
			
			LEA EAX, szText;
			PUSH EAX;

			PUSH dwPetObject;

			MOV EAX, ���ﲹѪCALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"PetAddHp", L"", NULL);
	}
}

VOID CGameCALL::PetAddMp(_In_ DWORD dwPetObject)
{
	__try
	{
		CONST static CHAR szText[] = { "mana" };
		__asm
		{
			MOV ECX, ���ﲹѪ��ַ;
			MOV ECX, DWORD PTR DS : [ECX];

			PUSH 0;
			PUSH 0x64;

			LEA EAX, szText;
			PUSH EAX;

			PUSH dwPetObject;

			MOV EAX, ���ﲹѪCALL;
			CALL EAX;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		::MessageBoxW(NULL, L"PetAddHp", L"", NULL);
	}
}
