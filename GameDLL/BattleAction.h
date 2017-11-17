#ifndef __GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEACTION_H__
#define __GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEACTION_H__

#include "Monster.h"
#include "PersonAttribute.h"

#define BATTLE_OPTION_SKILL		0x1	// ˦����
#define BATTLE_OPTION_CONTROL	0x2	// ʹ���ϰ�����
#define BATTLE_OPTION_HELP		0x4 // ʹ�ø�������
class CBattleAction
{
public:
	CBattleAction();
	~CBattleAction() = default;

	BOOL Fight();

	VOID ContinueAutoFight() CONST;
private:
	VOID RefreshData();

	CONST CMonster* FindPerson() CONST;

	CONST CMonster* FindPet() CONST;

	CONST CMonster* FindTarget() CONST;
private:
	VOID Fight_Classes_��() CONST;

	VOID Fight_Classes_ľ() CONST;

	VOID Fight_Classes_ˮ() CONST;

	VOID Fight_Classes_��() CONST;

	VOID Fight_Classes_��() CONST;

	VOID Fight_Classes_Pet() CONST;
private:
	std::vector<CMonster>	_VecMonster;
	std::wstring			_wsPersonName;
	CPersonAttribute::em_Family _emPersonFamily;
	CPersonAttribute		_PersonAttribute;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_FEATURE_BATTLE_BATTLEACTION_H__
