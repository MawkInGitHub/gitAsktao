#include "stdafx.h"
#include "StatusCheck.h"
#include <MyTools/Log.h>
#include "CodeTransfer.h"
#include "PetExtend.h"
#include "PetObject.h"
#include "GameCALL.h"
#include "TaskExtend.h"
#include "BagItemAction.h"
#include "BagItemExtend.h"
#include "ObjectFunction.h"

#define _SELF L"StatusCheck.cpp"
VOID CStatusCheck::CheckHealth() CONST
{
	if (_PersonAttribute.IsFighting())
		return;


	if (_PersonAttribute.GetPercentHp() <= 70)
	{
		LOG_C_D(L"���ﲹѪ");
		CCodeTransfer::PushPtrToMainThread([] { CGameCALL::PersonAddHp(); });
	}
	if (_PersonAttribute.GetPercentMp() <= 70)
	{
		LOG_C_D(L"���ﲹ��");
		CCodeTransfer::PushPtrToMainThread([] { CGameCALL::PersonAddMp(); });
	}

	CPetObject Pet(0);
	if (CPetExtend().FindJoinWarPet(Pet))
	{
		if (Pet.GetPercentHp() <= 70)
		{
			LOG_C_D(L"���ﲹѪ");
			CCodeTransfer::PushPtrToMainThread([Pet] { CGameCALL::PetAddHp(Pet.GetObj()); });
		}
		if (Pet.GetPercentMp() <= 70)
		{
			LOG_C_D(L"���ﲹ��");
			CCodeTransfer::PushPtrToMainThread([Pet] { CGameCALL::PetAddMp(Pet.GetObj()); });
		}
		if (Pet.GetLoyalty() < 80)
		{
			LOG_C_E(L"�����ҳ϶Ȳ����ˡ���");
		}
	}
}

VOID CStatusCheck::CheckExorcism() CONST
{
	if (!CTaskExtend().ExistTask(L"��ħ��") && !CTaskExtend().ExistTask(L"ǿ����ħ��"))
	{
		CBagItemExtend BagItemExtend;
		if (BagItemExtend.GetCount_By_ItemName(L"ǿ����ħ��") != 0)
		{
			CBagItemAction().UseItem_By_ItemName_In_NoFight(L"ǿ����ħ��");
			::Sleep(1000);
		}
		else if (BagItemExtend.GetCount_By_ItemName(L"��ħ��") != 0)
		{
			CBagItemAction().UseItem_By_ItemName_In_NoFight(L"��ħ��");
			::Sleep(1000);
		}
	}
}

VOID CStatusCheck::CheckDaoDaoDao() CONST
{
	auto pTaoTaoTaoDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TaoTaoTaoDlg.StartBtn");
	if (pTaoTaoTaoDlg != nullptr && pTaoTaoTaoDlg->IsShow())
	{
		LOG_C_D(L"��������ҡ��");
		pTaoTaoTaoDlg->Click();
		::Sleep(8 * 1000);
	}
}
