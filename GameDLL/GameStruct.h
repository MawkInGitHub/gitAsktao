#ifndef __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__
#define __GITASKTAO_GAMEDLL_CORE_COMMON_GAMESTRUCT_H__


#define UI������ַ			0xD97120
#define ���������ַ			0xD96C28
#define �������ƫ��			0x2A0
#define ��ǰ��ͼ��ַ			0xD97158
#define �Ƿ�ս���л�ַ		0xD9DA0C
#define ����HPƫ��			0x3FC
#define ����MAXHPƫ��		0x400
#define �������Ի�ַ			0xD9ABB4
#define ��������ƫ��			0xE4
#define ��·��ַ				0xD94CCC
#define ������ַ				0xD9733C
#define ����CALL				0x713890
#define ���﹥��ID�麯��ƫ�� 0xE4
#define ս��CALL				0x4E1D60
#define UI_Name�麯��ƫ��	0x38
#define UI����ƫ��1			0x1E4
#define ����MAXHPƫ��		0x1E8
#define ����ս���˵�UIƫ��	0x40
#define ��������ƫ��			0x168
#define ��·CALL��ַ			0xD9ABB4
#define ��·��ַ				0xD9ABB4
#define ��·ƫ��				0x198
#define �����CALL			0x45CE60
#define UI�Ƿ���ʾƫ��		0x194
#define ��Ϸ����ַ			0xD9DE44
#define Ѱ·CALL				0x461680
#define Ѱ·Bufferƫ��		0x1E0
#define �����ַ				0xD99E40
#define �����սIDƫ��		0x48
#define ���ﲹѪ��ַ			0xD963F0
#define ���ﲹѪCALL			0x53E950
#define ���������ַ			0xD9A0D0
#define �������ƫ��			0x94


///----���������ƫ��-------------------------
#define ս�����Ƿ����ƫ��	0x54
#define ����HPƫ��			����MAXHPƫ�� + 0x8
#define UI�ı�ƫ��			0xC
#define UIEDITƫ��			0x1E0
#define ����IDƫ��			0x8
#define �ָ�VirtualProtect  0x77A40028
#define NTDLL��ַ			0x77A20000

#define ReadDWORD(Addr) MyTools::CCharacter::ReadDWORD(Addr)
#define ReadBYTE(Addr)  MyTools::CCharacter::ReadBYTE(Addr)

enum class em_VariableName
{
	NewPeekMessageAddr,
};

enum em_SkillId
{
	em_SkillId_��_���է�� = 0xB,
	em_SkillId_��_���⽣Ӱ = 0xC,
	em_SkillId_��_������ = 0xD,
	em_SkillId_��_������� = 0xE,
	em_SkillId_��_�������� = 0x15,
	em_SkillId_��_�������� = 0x16,
	em_SkillId_��_������� = 0x17,
	em_SkillId_��_���γ��� = 0x18,
	em_SkillId_��_�������� = 0x1F,
	em_SkillId_��_���嶷ţ = 0x20,
	em_SkillId_��_��ţ���� = 0x21,
	em_SkillId_��_�绢���� = 0x22,
	em_SkillId_����ǧ��	  = 0x1F5,
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
