#include"boss.h"

boss::boss(int id, string name, int deptId) //构造函数
{
	this->m_id = id; //员工id
	this->m_name = name; //员工姓名
	this->m_deptId = deptId; //员工部门编号
}

void boss::showInfo() //显示员工信息
{
	cout << "员工id：" << m_id<<"\t"
		 << "员工姓名：" << m_name<<"\t"
		 << "职位："<< getDeptName()<<"\t"
		 << "职责：领导各部门" << endl;
}

string boss::getDeptName() //获取部门名称
{
	return string("老板");
}
