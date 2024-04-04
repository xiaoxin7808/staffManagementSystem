#include"ordinaryStaff.h"

ordinaryStaff::ordinaryStaff(int id, string name, int deptId) //构造函数
{
	this->m_id = id; //员工id
	this->m_name = name; //员工姓名
	this->m_deptId = deptId; //员工部门编号
}

void ordinaryStaff::showInfo() //显示员工信息
{
	cout << "员工id：" << m_id<<"\t"
		 << "员工姓名：" << m_name<<"\t"
		 << "职位："    << getDeptName() <<"\t"
		 << "\t职责：完成经理下发的任务" << endl;
}

string ordinaryStaff::getDeptName() //获取岗位名称		
{
	return string("员工");
}


