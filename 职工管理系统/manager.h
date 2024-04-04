#pragma once
#include<iostream>
#include<string>
#include"staffBase.h"

using namespace std;

class manager :public staffBase //经理类
{
public:
	manager(int id, string name, int deptId); //构造函数
	virtual void showInfo(); //显示员工信息
	virtual string getDeptName(); //获取部门名称
};