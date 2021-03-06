#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_GAMEUI_GAMEUI_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_GAMEUI_GAMEUI_H__

#include "BaseObject.h"

class CGameUi : public CBaseObject
{
public:
	CGameUi(_In_ DWORD dwNodeBase);
	~CGameUi() = default;

	DWORD GetObj() CONST;

	BOOL IsShow() CONST;

	BOOL IsShow_Fight() CONST;

	VOID SetName();

	VOID Click() CONST;

	std::wstring GetTeamMemberName();

	VOID ClickOption() CONST;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_GAMEUI_GAMEUI_H__
