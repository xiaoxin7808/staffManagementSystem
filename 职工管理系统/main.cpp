#include"managementStaff.h"
#include"ordinaryStaff.h"
#include"manager.h"
#include"boss.h"

int main()
{
	
	int input = 0;//用户输入
	managementStaff m1;//实例化管理类
	while(true)
	{
		m1.menu();//菜单
		cout << "请输入需要使用的功能" << endl;
		cin >> input;
		switch (input)
		{
		
		case 0:
			m1.exitSystem(); //退出
			break;
		
		case 1: 
			m1.AddStaff(); //添加员工
			m1.save(); //保存
			break;
		
		case 2:
			m1.showStaffInfo(); //查看所有员工信息
			break;
		
		case 3:
			m1.deleteStaff(); //删除离职员工
			break;
		
		case 4:
			m1.modStaffInfo(); //修改员工信息
			break;
		
		case 5:
			m1.findStaff(); //查找员工
			break;
		
		case 6:
			m1.sort(); //排序
			break;
		
		case 7:
			m1.reseSystem(); //
			break;
			
		default:
			cout << "输入有误，请重新输入" << endl;
			this_thread::sleep_for(chrono::seconds(1));//暂停一秒
			system("cls");
			break;
		}
	}
	
	return 0;
}