#pragma once
#include<iostream>
#include<string>
#include <thread>
#include <windows.h>
#include"staffBase.h"
#include"ordinaryStaff.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "staffFile.txt"

using namespace std;

class managementStaff//管理类
{
public:
	managementStaff(); //构造函数
	 ~managementStaff(); //析构函数
	
	int staffNum; //记录存入员工的数量
	staffBase** satffArray; // 指向员工数组的指针
	bool fileIsEmpty; //判断文件是否为空，空 = true 非空 = false

	void menu(); //菜单声明

	void exitSystem(); //退出系统

	void AddStaff(); //添加员工函数

	void save(); //写文件函数，保存员工数据

	int getStaffNum(); //获取文件中员工人数

	void initStaff(); //初始化员工数组

	void showStaffInfo(); //查看员工信息

	int staffIsExist(int id); //通过id判断员工是否存在 (传参:员工id ,返回员工下标,否则返回-1)

	void deleteStaff(); //删除离职员工 (传参:员工id,利用查找员工函数找到并删除)

	void modStaffInfo(); //修改员工信息

	void findStaff(); //查找员工

	void sort(); //排序函数

	void  reseSystem(); //重置系统
};