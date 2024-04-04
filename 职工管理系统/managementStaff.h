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

class managementStaff//������
{
public:
	managementStaff(); //���캯��
	 ~managementStaff(); //��������
	
	int staffNum; //��¼����Ա��������
	staffBase** satffArray; // ָ��Ա�������ָ��
	bool fileIsEmpty; //�ж��ļ��Ƿ�Ϊ�գ��� = true �ǿ� = false

	void menu(); //�˵�����

	void exitSystem(); //�˳�ϵͳ

	void AddStaff(); //���Ա������

	void save(); //д�ļ�����������Ա������

	int getStaffNum(); //��ȡ�ļ���Ա������

	void initStaff(); //��ʼ��Ա������

	void showStaffInfo(); //�鿴Ա����Ϣ

	int staffIsExist(int id); //ͨ��id�ж�Ա���Ƿ���� (����:Ա��id ,����Ա���±�,���򷵻�-1)

	void deleteStaff(); //ɾ����ְԱ�� (����:Ա��id,���ò���Ա�������ҵ���ɾ��)

	void modStaffInfo(); //�޸�Ա����Ϣ

	void findStaff(); //����Ա��

	void sort(); //������

	void  reseSystem(); //����ϵͳ
};