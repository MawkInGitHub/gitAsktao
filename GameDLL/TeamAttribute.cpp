#include "stdafx.h"
#include "TeamAttribute.h"
#include <MyTools/Character.h>
#include "GameUi.h"
#include "ObjectFunction.h"

UINT CTeamAttribute::GetTeamMemberCount() CONST
{
	return ReadDWORD(ReadDWORD(����������ַ) + ��������ƫ��);
}

BOOL CTeamAttribute::IsCaptain() CONST
{
	return FALSE;
}
