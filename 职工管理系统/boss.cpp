#include"boss.h"

boss::boss(int id, string name, int deptId) //���캯��
{
	this->m_id = id; //Ա��id
	this->m_name = name; //Ա������
	this->m_deptId = deptId; //Ա�����ű��
}

void boss::showInfo() //��ʾԱ����Ϣ
{
	cout << "Ա��id��" << m_id<<"\t"
		 << "Ա��������" << m_name<<"\t"
		 << "ְλ��"<< getDeptName()<<"\t"
		 << "ְ���쵼������" << endl;
}

string boss::getDeptName() //��ȡ��������
{
	return string("�ϰ�");
}
