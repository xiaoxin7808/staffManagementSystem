#pragma once
#pragma once
#include<iostream>
#include<string>
#include"staffBase.h"

using namespace std;

class boss :public staffBase //经理类
{
public:
	boss(int id, string name, int deptId); //构造函数
	virtual void showInfo(); //显示员工信息
	virtual string getDeptName(); //获取部门名称
};