#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETATTRIBUTE_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETATTRIBUTE_H__

#include "BaseObject.h"

class CPetAttribute : public CBaseObjectAttribute
{
public:
	CPetAttribute() = default;
	~CPetAttribute() = default;

	virtual DWORD GetHp() CONST override;
	virtual DWORD GetMaxHP() CONST override;


	virtual DWORD GetMp() CONST override;
	virtual DWORD GetMaxMp() CONST override;


	virtual DWORD GetExp() CONST override;
	virtual DWORD GetMaxExp() CONST override;

	// �ȼ�
	DWORD	GetLevel() CONST;

	// ����
	std::wstring GetName() CONST;

	// ���Ե�
	DWORD	GetAttributePoint() CONST;

	// �ҳ϶�
	DWORD	GetLoyal() CONST;
private:

};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_PET_PETATTRIBUTE_H__
