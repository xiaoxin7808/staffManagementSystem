#pragma once
#include<iostream>
#include<string>
#include"staffBase.h"
using namespace std;

class ordinaryStaff:public staffBase //Ա��������
{
public:
	
	ordinaryStaff(int id, string name, int deptId); //���캯��
	
	void showInfo();//��ʾԱ����Ϣ
	string getDeptName(); //��ȡ��λ����		
	
};