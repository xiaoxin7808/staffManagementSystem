#pragma once
#include<iostream>
#include<string>
#include"staffBase.h"

using namespace std;

class manager :public staffBase //������
{
public:
	manager(int id, string name, int deptId); //���캯��
	virtual void showInfo(); //��ʾԱ����Ϣ
	virtual string getDeptName(); //��ȡ��������
};