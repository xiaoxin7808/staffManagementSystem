#include"manager.h"


	manager::manager(int id, string name, int deptId) //���캯��
	{
		this->m_id = id; //Ա��id
		this->m_name = name; //Ա������
		this->m_deptId = deptId; //Ա�����ű��
	}
	void manager::showInfo() //��ʾԱ����Ϣ
	{
		cout << "Ա��id��" << m_id << "\t"
			 << "Ա��������" << m_name << "\t"
			 << "ְλ��" << getDeptName() << "\t"
			 << "\tְ������ϰ��·������񣬲�Ϊ�¼��ַ�����" << endl;
	}
	
	 string manager::getDeptName() //��ȡ��������
	{
		return string("����");
	}
