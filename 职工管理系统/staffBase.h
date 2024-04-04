#pragma once
#include<iostream>
#include<string>
using namespace std;


class staffBase //员工抽象类
{
public: 
	
	virtual void showInfo() = 0; //显示员工信息
	virtual string getDeptName() = 0; //获取岗位名称		
	
	int m_id; //员工id
	string m_name; //员工姓名
	int m_deptId; //部门编号
}; 