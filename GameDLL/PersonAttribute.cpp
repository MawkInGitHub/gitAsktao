#include "stdafx.h"
#include "PersonAttribute.h"
#include <MyTools/Character.h>
#include <MyTools/Log.h>
#include "ObjectFunction.h"
#include "GameUi.h"
#include "GameOffsetPtr.h"

#define _SELF L"PersonAttribute.cpp"
DWORD CPersonAttribute::GetHp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"life");
}

DWORD CPersonAttribute::GetMaxHP() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanMeDlg.Life", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPersonAttribute::GetMp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"mana");
}

DWORD CPersonAttribute::GetMaxMp() CONST
{
	return CObjectFunction::GetInstance().GetGameUiValue_By_MapKey(L"PanMeDlg.Mana", CGameOffsetPtr().GetMaxHpPtr());
}

DWORD CPersonAttribute::GetExp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"exp");
}

DWORD CPersonAttribute::GetMaxExp() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"exp_to_next_level");
}

DWORD CPersonAttribute::GetTotalScore() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(), L"total_score");
}

std::wstring CPersonAttribute::GetName() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"name");
}

DWORD CPersonAttribute::GetLevel() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"level");
}

DWORD CPersonAttribute::GetReputation() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"reputation");
}

std::wstring CPersonAttribute::GetPartyName() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"party");
}

DWORD CPersonAttribute::GetPartyContrib() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"party/contrib");
}

DWORD CPersonAttribute::GetDaoXing() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"tao") / 360;
}

DWORD CPersonAttribute::GetPot() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"pot");
}

DWORD CPersonAttribute::GetAttributePoint() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"attrib_point");
}

DWORD CPersonAttribute::GetPolarPoint() CONST
{
	return CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"polar_point");
}

CPersonAttribute::CashContent CPersonAttribute::GetMoney() CONST
{
	CashContent Content =
	{
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"cash"),
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"voucher")
	};
	return Content;
}

Point CPersonAttribute::GetPoint() CONST
{
	return Point(
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"x"),
		CObjectFunction::GetInstance().GetAttributeValue_By_Key(GetAttributeTreeHead(),L"y"));
}

std::wstring CPersonAttribute::GetMapName() CONST
{
	// MainThread Get MapName
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"map_name");
}

std::wstring CPersonAttribute::GetCurrentLine()
{
	return MyTools::CCharacter::ASCIIToUnicode(std::string(reinterpret_cast<CONST CHAR*>(线路基址 + 0x4)));
}

BOOL CPersonAttribute::IsFighting() CONST
{
	//return ReadBYTE(ReadDWORD(是否战斗中基址) + 0xC) == 0x9;
	return GetPersonStatus() == em_PersonStatus::War;
}

std::wstring CPersonAttribute::GetFamily() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"family");
}

std::wstring CPersonAttribute::GetFamilyMaster() CONST
{
	return CObjectFunction::GetInstance().GetAttributeText_By_Key(GetAttributeTreeHead(), L"master");
}

CPersonAttribute::em_Family CPersonAttribute::GetFamilyType() CONST
{
	auto wsText = GetFamily();
	if (wsText == L"五龙山云霄洞")
		return em_Family::em_Family_金;
	if (wsText == L"终南山玉柱洞宫")
		return em_Family::em_Family_木;
	if (wsText == L"问道凤凰山斗阙")
		return em_Family::em_Family_水;
	if (wsText == L"乾元山金光洞")
		return em_Family::em_Family_火;
	if (wsText == L"骷髅山白骨洞")
		return em_Family::em_Family_土;

	return em_Family::em_Family_UnKnow;
}

CPersonAttribute::em_PersonStatus CPersonAttribute::GetPersonStatus() CONST
{
	auto dwValue = ReadDWORD(战斗状态基址);
	if (dwValue == 1)
		return em_PersonStatus::Normal;
	else if (dwValue == 3)
		return em_PersonStatus::War;
	else if (dwValue == 2)
		return em_PersonStatus::VerCode;

	LOG_C_E(L"GetPersonStatus=%X", dwValue);
	return em_PersonStatus::Normal;
}

DWORD CPersonAttribute::GetAttributeTreeHead() CONST
{
	return ReadDWORD(ReadDWORD(ReadDWORD(人物属性基址) + 人物属性偏移 + 0x4 + 0x4) + 0x4);
}
