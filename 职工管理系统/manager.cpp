#include"manager.h"


	manager::manager(int id, string name, int deptId) //构造函数
	{
		this->m_id = id; //员工id
		this->m_name = name; //员工姓名
		this->m_deptId = deptId; //员工部门编号
	}
	void manager::showInfo() //显示员工信息
	{
		cout << "员工id：" << m_id << "\t"
			 << "员工姓名：" << m_name << "\t"
			 << "职位：" << getDeptName() << "\t"
			 << "\t职责：完成老板下发的任务，并为下级分发任务" << endl;
	}
	
	 string manager::getDeptName() //获取部门名称
	{
		return string("经理");
	}
