#include"ordinaryStaff.h"

ordinaryStaff::ordinaryStaff(int id, string name, int deptId) //���캯��
{
	this->m_id = id; //Ա��id
	this->m_name = name; //Ա������
	this->m_deptId = deptId; //Ա�����ű��
}

void ordinaryStaff::showInfo() //��ʾԱ����Ϣ
{
	cout << "Ա��id��" << m_id<<"\t"
		 << "Ա��������" << m_name<<"\t"
		 << "ְλ��"    << getDeptName() <<"\t"
		 << "\tְ����ɾ����·�������" << endl;
}

string ordinaryStaff::getDeptName() //��ȡ��λ����		
{
	return string("Ա��");
}


