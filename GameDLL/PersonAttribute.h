#ifndef __GITASKTAO_GAMEDLL_CORE_OBJECT_PERSON_PERSONATTRIBUTE_H__
#define __GITASKTAO_GAMEDLL_CORE_OBJECT_PERSON_PERSONATTRIBUTE_H__

#include "BaseObject.h"

// ���麯��������Ҫ����Alt+C�ſ��Բ鿴��������
class CPersonAttribute : public CBaseObjectAttribute
{
public:
	CPersonAttribute() = default;
	~CPersonAttribute() = default;

	virtual DWORD GetHp() CONST override;
	virtual DWORD GetMaxHP() CONST override;


	virtual DWORD GetMp() CONST override;
	virtual DWORD GetMaxMp() CONST override;


	virtual DWORD GetExp() CONST override;
	virtual DWORD GetMaxExp() CONST override;

	// ս��
	DWORD	GetTotalScore() CONST;

	// ����
	std::wstring GetName() CONST;

	// �ȼ�
	DWORD	GetLevel() CONST;

	// ����
	DWORD	GetReputation() CONST;

	// ����
	std::wstring GetPartyName() CONST;

	// �ﹱ
	DWORD	GetPartyContrib() CONST;

	// ����(/��)
	DWORD GetDaoXing() CONST;

	// Ǳ��
	DWORD	GetPot() CONST;

	// ��û�ӵ����Ե�
	DWORD	GetAttributePoint() CONST;

	// ��û�ӵ����Ե�
	DWORD	GetPolarPoint() CONST;

	// ���
	struct CashContent
	{
		DWORD dwCash	= 0;  // ���
		DWORD dwMoney	= 0; // �����
	};
	CashContent	GetMoney() CONST;

	// ����
	Point	GetPoint() CONST;

	// ��ͼ
	std::wstring GetMapName() CONST;

	// ��·
	std::wstring GetCurrentLine();

	// �Ƿ�ս����
	BOOL IsFighting() CONST;

	// ��ȡ����
	std::wstring GetFamily() CONST;

	// ����ʦ��
	std::wstring GetFamilyMaster() CONST;
};



#endif // !__GITASKTAO_GAMEDLL_CORE_OBJECT_PERSON_PERSONATTRIBUTE_H__
