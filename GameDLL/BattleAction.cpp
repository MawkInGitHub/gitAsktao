#include "stdafx.h"
#include "BattleAction.h"
#include <MyTools/Log.h>
#include <MyTools/Character.h>
#include <MyTools/CLPublic.h>
#include <MyTools/TimeTick.h>
#include "PersonAttribute.h"
#include "PetObject.h"
#include "PetExtend.h"
#include "ObjectFunction.h"
#include "BattleAttribute.h"
#include "CodeTransfer.h"
#include "GameCALL.h"
#include "StatusCheck.h"

#define _SELF L"BattleAction.cpp"
CBattleAction::CBattleAction()
{
	_wsPersonName = _PersonAttribute.GetName();
	_emPersonFamily = _PersonAttribute.GetFamilyType();
}

BOOL CBattleAction::Fight()
{
	LOG_C_D(L"��ʼս��");

	while (g_IsRuning && _PersonAttribute.IsFighting())
	{
		CObjectFunction::GetInstance().RefreshStaticMapGameUi();
		//auto pAutoFightDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"AutoFightDlg.ContinueBtn");
		auto pTalkMenuDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TalkNoMenuDlg");
		if (pTalkMenuDlg != nullptr && pTalkMenuDlg->IsShow())
		{
			LOG_C_D(L"���־���Ի�����");
			pTalkMenuDlg->Click();
			::Sleep(1000);
			continue;
		}
		//if (pAutoFightDlg != nullptr && pAutoFightDlg->IsShow())
		//{
		//	LOG_C_D(L"�Զ�ս���С���");
		//	::Sleep(3 * 1000);
		//	continue;
		//}
		
		/*if (BattleAttribute.IsExistFightMeMenu())
		{
			LOG_C_D(L"�ֵ������ж���!");
			switch (_emPersonFamily)
			{
			case CPersonAttribute::em_Family::em_Family_UnKnow:
				LOG_MSG_CF(L"δְ֪ҵ����");
				break;
			case CPersonAttribute::em_Family::em_Family_��:
				Fight_Classes_��();
				break;
			case CPersonAttribute::em_Family::em_Family_ľ:
				Fight_Classes_ľ();
				break;
			case CPersonAttribute::em_Family::em_Family_ˮ:
				Fight_Classes_ˮ();
				break;
			case CPersonAttribute::em_Family::em_Family_��:
				Fight_Classes_��();
				break;
			case CPersonAttribute::em_Family::em_Family_��:
				Fight_Classes_��();
				break;
			default:
				break;
			}

			Fight_Classes_Pet();
		}*/
		
		::Sleep(1000);
	}

	CStatusCheck().CheckHealth();
	LOG_C_D(L"ս������");
	return TRUE;
}

VOID CBattleAction::ContinueAutoFight() CONST
{
	LOG_C_D(L"��һ���Զ�ս��");
	auto pAutoFightDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"AutoFightDlg.ContinueBtn");
	if (pAutoFightDlg == nullptr)
		return;

	pAutoFightDlg->Click();
}

VOID CBattleAction::RefreshData()
{
	CObjectFunction::GetInstance().GetVecMonster(_VecMonster);
	std::sort(_VecMonster.begin(), _VecMonster.end(), [](CONST CMonster& itm1, CONST CMonster& itm2) { return itm1.GetId() < itm2.GetId(); });
}

CONST CMonster* CBattleAction::FindPerson() CONST
{
	return MyTools::CLPublic::Vec_find_if_Const(_VecMonster, [this](CONST CMonster& itm)
	{
		return itm.GetName() == _wsPersonName;
	});
}

CONST CMonster* CBattleAction::FindPet() CONST
{
	return MyTools::CLPublic::Vec_find_if_Const(_VecMonster, [] (CONST CMonster& itm)
	{
		return itm.GetId() == CPetObject::GetJoinWarPetId();
	});
}

CONST CMonster* CBattleAction::FindTarget() CONST
{
	return MyTools::CLPublic::Vec_find_if_Const(_VecMonster, [](CONST CMonster& itm)
	{
		return itm.GetType() == CMonster::em_Type::em_Type_Monster;
	});
}

VOID CBattleAction::Fight_Classes_��() CONST
{
	auto pPerson = FindPerson();
	if (pPerson == nullptr)
	{
	//	LOG_C_D(L"Empty Person");
		return;
	}

	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		//LOG_C_D(L"pTarget = nullptr");
		return;
	}

	if (pPerson->GetPercentMp() <= 10)
	{
		//LOG_C_D(L"������������, ����");
		pPerson->Defence();
		return;
	}

	pPerson->UseSkill(*pTarget, em_SkillId_��_���է��);
	::Sleep(1000);
}

VOID CBattleAction::Fight_Classes_ľ() CONST
{
	auto pPerson = FindPerson();
	if (pPerson == nullptr)
	{
		//	LOG_C_D(L"Empty Person");
		return;
	}

	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		//LOG_C_D(L"pTarget = nullptr");
		return;
	}

	if (pPerson->GetPercentMp() <= 10)
	{
		//LOG_C_D(L"������������, ����");
		pPerson->Defence();
		return;
	}

	pPerson->UseSkill(*pTarget, em_SkillId_ľ_ժҶ�ɻ�);
	::Sleep(1000);
}

VOID CBattleAction::Fight_Classes_ˮ() CONST
{
	auto pPerson = FindPerson();
	if (pPerson == nullptr)
	{
		//	LOG_C_D(L"Empty Person");
		return;
	}

	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		//LOG_C_D(L"pTarget = nullptr");
		return;
	}

	if (pPerson->GetPercentMp() <= 10)
	{
		//LOG_C_D(L"������������, ����");
		pPerson->Defence();
		return;
	}

	pPerson->UseSkill(*pTarget, em_SkillId_ˮ_��ˮʯ��);
	::Sleep(1000);
}

VOID CBattleAction::Fight_Classes_��() CONST
{

}

VOID CBattleAction::Fight_Classes_��() CONST
{

}

VOID CBattleAction::Fight_Classes_Pet() CONST
{
	auto pPet = FindPet();
	if (pPet == nullptr)
		return;

	if (pPet->GetPercentMp() <= 10)
	{
		LOG_C_D(L"BB��������, ����");
		pPet->Defence();
		return;
	}
	
	auto pTarget = FindTarget();
	if (pTarget == nullptr)
	{
		LOG_C_D(L"pTarget = nullptr");
		return;
	}
	pPet->UseSkill(*pTarget, em_SkillId_��_���է��);
	::Sleep(1000);
}
