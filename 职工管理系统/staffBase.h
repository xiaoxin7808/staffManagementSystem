#pragma once
#include<iostream>
#include<string>
using namespace std;


class staffBase //Ա��������
{
public: 
	
	virtual void showInfo() = 0; //��ʾԱ����Ϣ
	virtual string getDeptName() = 0; //��ȡ��λ����		
	
	int m_id; //Ա��id
	string m_name; //Ա������
	int m_deptId; //���ű��
}; 