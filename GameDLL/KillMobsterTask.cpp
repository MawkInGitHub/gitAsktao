#include "stdafx.h"
#include "KillMobsterTask.h"
#include <MyTools/Log.h>
#include <MyTools/TimeTick.h>
#include "ObjectFunction.h"

#define _SELF L"KillMobsterTask.cpp"
BOOL CKillMobsterTask::Run()
{
	g_IsRuning = TRUE;
	int nExixstTalkMenuDlgCount = 0;


	auto wsPersonName = _PersonAttribute.GetName();
	while (g_IsRuning)
	{
		auto emPersonStatus = _PersonAttribute.GetPersonStatus();
		if (emPersonStatus == CPersonAttribute::em_PersonStatus::War)
		{
			_BattleAction.Fight();

			// ���Զ�ս��
			CObjectFunction::GetInstance().RefreshStaticMapGameUi();
			_BattleAction.ContinueAutoFight();
			continue;
		}
		else if (emPersonStatus == CPersonAttribute::em_PersonStatus::VerCode)
		{
			LOG_C_D(L"������֤����⡭��");
			::Sleep(1000);
			continue;
		}

		/*if (wsPersonName != L"��Į��ѩ") // ���Ѳ���
		{
			::Sleep(1000);
			continue;
		}*/


		CObjectFunction::GetInstance().RefreshStaticMapGameUi();

		_StatusCheck.CheckDaoDaoDao();
		if (ExistTask())
		{
			::Sleep(1000);
			continue;
		}

		auto pTalkMenuDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TalkMenuDlg");
		if (pTalkMenuDlg == nullptr || !pTalkMenuDlg->IsShow())
		{
			::Sleep(1000);
			continue;
		}

		LOG_C_D(L"����Npc�Ի���! Name=%s, IsShow=%X, Obj=%X", pTalkMenuDlg->GetName().c_str(), pTalkMenuDlg->IsShow(), pTalkMenuDlg->GetObj());
		// 10s ֮�ڻ����ڵĻ�...
		if (nExixstTalkMenuDlgCount++ <= 5)
		{
			::Sleep(2000);
			continue;
		}

		nExixstTalkMenuDlgCount = 0;
		LOG_C_D(L"10������Ӧ����������~");
		auto pTalkContinueDlg = CObjectFunction::GetInstance().FindGameUi_For_StaticMap_By_MapKey(L"TalkMenuDlg.[��Ը��������������]");
		if (pTalkContinueDlg == nullptr)
		{
			LOG_C_E(L"��������ѡ����ˡ���");
			continue;
		}

		LOG_C_D(L"��������!");
		pTalkContinueDlg->ClickOption();
		::Sleep(1000);
	}

	LOG_C_D(L"ֹͣ�������񡭡�");
	return TRUE;
}

BOOL CKillMobsterTask::ExistTask() CONST
{
	return _TaskExtend.ExistTask(L"Ϊ�����");
}
