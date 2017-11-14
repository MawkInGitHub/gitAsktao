#include "stdafx.h"
#include "GameOffsetPtr.h"
#include <MyTools/Character.h>
#include "GameUi.h"
#include "GameStruct.h"

std::function<DWORD(CGameUi&)> CGameOffsetPtr::GetHpPtr()
{
	return [](CGameUi& GameUi) { return ReadDWORD(GameUi.GetObj() + ����HPƫ��); };
}

std::function<DWORD(CGameUi&)> CGameOffsetPtr::GetMaxHpPtr()
{
	return [](CGameUi& GameUi) { return ReadDWORD(GameUi.GetObj() + ����MAXHPƫ��); };
}

std::function<DWORD(CGameUi&)> CGameOffsetPtr::GetValue()
{
	return [](CGameUi& GameUi) 
	{
		auto pszText = reinterpret_cast<CHAR*>(GameUi.GetObj() + UI�ı�ƫ��);
		return pszText == nullptr ? 0 : static_cast<DWORD>(atoi(pszText));
	};
}

std::function<std::wstring(CGameUi&)> CGameOffsetPtr::GetText()
{
	return [](CGameUi& GameUi)
	{
		auto pszText = reinterpret_cast<CHAR*>(GameUi.GetObj() + UI�ı�ƫ��);
		return MyTools::CCharacter::ASCIIToUnicode(std::string(pszText));
	};
}

std::function<std::wstring(CGameUi&)> CGameOffsetPtr::GetEditText()
{
	return [](CGameUi& GameUi)
	{
		auto pszText = reinterpret_cast<CHAR*>(ReadDWORD(GameUi.GetObj() + UIEDITƫ��));
		return MyTools::CCharacter::ASCIIToUnicode(std::string(pszText));
	};
}