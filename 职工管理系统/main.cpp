#include"managementStaff.h"
#include"ordinaryStaff.h"
#include"manager.h"
#include"boss.h"

int main()
{
	
	int input = 0;//�û�����
	managementStaff m1;//ʵ����������
	while(true)
	{
		m1.menu();//�˵�
		cout << "��������Ҫʹ�õĹ���" << endl;
		cin >> input;
		switch (input)
		{
		
		case 0:
			m1.exitSystem(); //�˳�
			break;
		
		case 1: 
			m1.AddStaff(); //���Ա��
			m1.save(); //����
			break;
		
		case 2:
			m1.showStaffInfo(); //�鿴����Ա����Ϣ
			break;
		
		case 3:
			m1.deleteStaff(); //ɾ����ְԱ��
			break;
		
		case 4:
			m1.modStaffInfo(); //�޸�Ա����Ϣ
			break;
		
		case 5:
			m1.findStaff(); //����Ա��
			break;
		
		case 6:
			m1.sort(); //����
			break;
		
		case 7:
			m1.reseSystem(); //
			break;
			
		default:
			cout << "������������������" << endl;
			this_thread::sleep_for(chrono::seconds(1));//��ͣһ��
			system("cls");
			break;
		}
	}
	
	return 0;
}