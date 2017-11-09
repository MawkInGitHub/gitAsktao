#include "stdafx.h"
#include "GameUi.h"
#include <MyTools/Character.h>
#include <MyTools/Log.h>

#define _SELF L"GameUi.cpp"
CGameUi::CGameUi(_In_ DWORD dwNodeBase)
{
	_dwNodeBase = dwNodeBase;
	auto pszNamePtr = reinterpret_cast<CHAR*>(GetObj() + UINameƫ��);
	_wsName = MyTools::CCharacter::ASCIIToUnicode(std::string(pszNamePtr));
}

DWORD CGameUi::GetObj() CONST
{
	return ReadDWORD(GetNodeBase() + 0x8);
}

BOOL CGameUi::IsShow() CONST
{
	return ReadBYTE(GetObj() + ����ս���˵�UIƫ��) != 0;
}
