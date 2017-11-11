#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEM_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEM_H__

#include "BaseObject.h"

class CBagItem : public CBaseObject
{
public:
	CBagItem(_In_ DWORD dwNodeBase);
	CBagItem();
	~CBagItem() = default;

	VOID SetName();

	// ����ָ��
	DWORD GetObjAddr() CONST;

	// ����
	DWORD GetItemType() CONST;

	// �־ö�
	DWORD GetDurability() CONST;

	// ����
	DWORD GetCount() CONST;

	// ID
	DWORD GetId() CONST;

public:
	VOID UseItem_NoFight();
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_BAG_BAGITEM_H__
