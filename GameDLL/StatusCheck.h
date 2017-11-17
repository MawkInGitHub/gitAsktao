#ifndef __GITASKTAO_GAMEDLL_CORE_FEATURE_CHECK_STATUSCHECK_H__
#define __GITASKTAO_GAMEDLL_CORE_FEATURE_CHECK_STATUSCHECK_H__

#include "PersonAttribute.h"

class CStatusCheck
{
public:
	CStatusCheck() = default;
	~CStatusCheck() = default;

	// ���Ѫ���Ƿ񽡿�
	VOID CheckHealth() CONST;

	// �����ħ��
	VOID CheckExorcism() CONST;

	// ��������
	VOID CheckDaoDaoDao() CONST;
private:
	CPersonAttribute _PersonAttribute;
	
};



#endif // !__GITASKTAO_GAMEDLL_CORE_FEATURE_CHECK_STATUSCHECK_H__
