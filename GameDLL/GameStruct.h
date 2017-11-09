#ifndef __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__
#define __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__


#define UI������ַ			0xD91460
#define UINameƫ��			0x94
#define UI����ƫ��1			0x1E4
#define ����HPƫ��			0x1F0
#define ����MAXHPƫ��		0x1E8
#define UI�ı�ƫ��			0xC
#define UIEDITƫ��			0x1E0
#define UI����TEXTƫ��		0x29C
#define ��������ƫ��			0x16C
#define ����IDƫ��			0x8
#define ���������ַ			0xD90F68
#define �������ƫ��			0x2A0
#define ��ǰ��ͼ��ַ			0xD91498
#define �Ƿ�ս���л�ַ		0xD97D44
#define ����ս���˵�UIƫ��	0x40
#define ����HPƫ��			0x3F8
#define ����MAXHPƫ��		0x3FC
#define �������Ի�ַ			0xD97F74
#define ��������ƫ��			0xE4

#define ReadDWORD(Addr) MyTools::CCharacter::ReadDWORD(Addr)
#define ReadBYTE(Addr)  MyTools::CCharacter::ReadBYTE(Addr)

enum class em_VariableName
{

};

struct Point
{
	DWORD X, Y;

	Point()
	{
		X = Y = NULL;
	}

	Point(_In_ DWORD dwX, _In_ DWORD dwY) : X(dwX), Y(dwY)
	{

	}

	bool operator == (CONST Point& Point_) CONST
	{
		return this->X == Point_.X && this->Y == Point_.Y;
	}

	bool operator != (CONST Point& Point_) CONST
	{
		return this->X != Point_.X || this->Y != Point_.Y;
	}
};

#endif // !__GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__
