#pragma once
#include<iostream>
#include<string>
#include"staffBase.h"
using namespace std;

class ordinaryStaff:public staffBase //员工派生类
{
public:
	
	ordinaryStaff(int id, string name, int deptId); //构造函数
	
	void showInfo();//显示员工信息
	string getDeptName(); //获取岗位名称		
	
};