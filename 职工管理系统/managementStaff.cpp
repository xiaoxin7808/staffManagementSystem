#include"managementStaff.h"

managementStaff::managementStaff() //构造函数
{
	//初始化
	//1.文件不存在
	ifstream ifs; 
	ifs.open(FILENAME, ios::in); //以读取方式打开文件
	
	if (ifs.is_open() != true) //判断文件是否打开成功，打开成功返回true
	{
		//cout << "文件不存在" << endl;
		this->staffNum = 0; //员工数量初始化为0
		this->satffArray = NULL; //员工数组初始化为空
		this->fileIsEmpty= true; //文件判空 赋值为空
		ifs.close(); //关闭文件
		return; 
	}
	
	//2.文件存在，但文件中没有数据
	char ch;
	ifs >> ch; //将文件中读取出的单个字符存入ch中
	if (ifs.eof() == true) //eof用于判断文件中有没有数据，没有的话返回true 
	{
		
		this->staffNum = 0; //员工数量初始化为0
		
		this->satffArray = NULL; //员工数组初始化为空
	    
		this->fileIsEmpty = true; //文件判空 赋值为空
		
		ifs.close(); //关闭文件
		
		return;
	}

	//3.文件存在，同时文件中也有数据,并将数据写入到员工数组中
	this->satffArray = NULL; //员工数组初始化为空
	
	int num = this->getStaffNum(); //记录文件中人数
	
	this->staffNum = num; //员工数量初始化为文件中员工人数
	
	this->satffArray = new staffBase * [this->staffNum]; //开辟空间
	
	this->initStaff(); //初始化员工数组，将文件中的数据存入到数组中
	
	this->fileIsEmpty = false; //文件判空 赋值为非空
	return;

}

managementStaff::~managementStaff() //析构函数
{
	if(this->satffArray != NULL)
	{
		for (int i = 0; i < this->staffNum; i++)
		{
			if (this->satffArray[i] != NULL)
			{
				delete this->satffArray[i];
				this->satffArray[i] = NULL;
			}
		}
		delete[] this->satffArray; //释放堆区开辟的数组
		this->satffArray = NULL;
		cout << "析构函数" << endl;
	}
}

void managementStaff::menu()//菜单
{
	cout << "员工管理系统 v1.0" << endl;
	cout<<"------------------------------------------" << endl;
	cout<<"1.添加员工           2.查看员工信息" << endl;
	cout<<"3.删除离职员工       4.修改员工信息" << endl;
	cout<<"5.查找员工           6.排序" << endl;
	cout<<"7.重置系统           0.退出"<< endl;
	cout<<"------------------------------------------" << endl;
}

void managementStaff::exitSystem() //退出
{
	cout << "退出" << endl;
	exit(0);
	system("pause");
	
}

void managementStaff::AddStaff() //添加员工函数
{
	cout << "请输入需要添加的员工数量：" << endl;
	int input = 0; //保存输入的值
	cin >> input;
	if (input > 0)
	{
		int newSize = this->staffNum + input; //保存新空间的大小
		staffBase**	newSpace= new staffBase* [newSize]; //开辟新空间
	    
		for(int i =0 ;i < this->staffNum; i++)	
		{
			if (this->satffArray != NULL)
			{
				newSpace[i] = this->satffArray[i];
			}
		}

		int i = 0;
		for (i = 0;i < input;i++) //添加员工
		{
			string name;
			int id;
			int deptSelect;
			cout << "请输入第" << i + 1 << "个员工的信息" << endl;
			cout << "请输入员工id" << endl;
			cin>>id;
			cout << "请输入员工姓名" << endl;
			cin >>name;
			cout << "请输入员工岗位编号" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >>deptSelect;
			
			staffBase* staffBase = NULL; 
			switch (deptSelect)
			{
			case 1:
				staffBase = new ordinaryStaff(id, name, deptSelect);
				break;
			case 2:
				staffBase = new manager(id, name, deptSelect);
				break;
			case 3:
				staffBase = new boss(id, name, deptSelect);
				break;
			default:
				break;
			}
			newSpace[this->staffNum +i]= staffBase;
		}
		this->satffArray = newSpace; //指向新空间
		cout << "成功添加"<<i<<"个员工信息" << endl;
		this->fileIsEmpty = false; //文件判空
		this->staffNum = newSize; //更新员工数量
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");

	system("cls");
}

void managementStaff::save() //写文件函数 （把数组里的员工数据写入到文件中保存）
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件，写文件
	
	for (int i = 0; i < this->staffNum; i++) //把每个人的信息循环写入到文件中
	{
		ofs << this->satffArray[i]->m_id << "  " 
			<< this->satffArray[i]->m_name<< "  " 
			<< this->satffArray[i]->m_deptId << endl;
	}
	ofs.close(); // 关闭文件
}

int managementStaff::getStaffNum() //获取文件中员工人数
{
	int num =0; //记录人数
	ifstream ifs;
	int id;
	string name;
	int deptId;
	ifs.open(FILENAME, ios::in); //打开文件 读
 	while(ifs>>id && ifs>>name && ifs>>deptId)
	{
		num++;
	}
	return num;
}

void managementStaff::initStaff() //初始化员工数组
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读
	int id;
	string name;
	int deptId;
	staffBase* staff = NULL;
	for (int i = 0; i<this->staffNum; i++ )
	{
		ifs >> id;
		ifs >> name;
		ifs >> deptId;
		if (deptId == 1) //普通员工
		{
			staff = new ordinaryStaff(id, name, deptId); //new一个普通员工类，并把从文件中读出的id ，name，deptid传过去
		}

		if (deptId == 2) //经理
		{
			staff = new manager(id, name, deptId);
		}

		if (deptId == 3) //老板
		{
			staff = new boss(id, name, deptId);
		}

		this->satffArray[i] = staff;
	}
	ifs.close(); //关闭文件
}

void managementStaff::showStaffInfo() //查看所有员工信息
{
	if (this->satffArray == NULL) //判断数组中有没有员工信息
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause"); //暂停
		system("cls"); //清空屏幕
		return;
	}

	else
	{
		for(int i = 0; i < this->staffNum; i++) //循环打印员工信息
		{
			this->satffArray[i]->showInfo();
		}
	}
	system("pause"); //暂停
	system("cls"); //清空屏幕
}

int managementStaff::staffIsExist(int id) //查找员工,传入员工id,找到返回员工下标,没找到返回-1，文件不存在或记录为空返回-2
{
	if (this->satffArray == NULL) 
	{
		//文件不存在
		return -2;
	}
	else
	{
		//找到了
		for (int i = 0; i < this->staffNum; i++)
		{
			if (this->satffArray[i]->m_id == id)
			{
				return i;
			}
			
		}

		//没找到
		return -1;
	}
}
void managementStaff::deleteStaff() //删除员工函数 (传参:员工id,利用查找员工函数找到并删除)
{
	int input = 0;
	cout << "请输入需要删除的员工id:"<<endl;
	cin >> input;
	int ret = 0; //保存查找函数的返回值
	ret = this->staffIsExist(input);
	if (ret == -1) //没找到
	{
		cout << "没有找到此员工" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (ret == -2)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else //找到,删除
	{
		for(int i = ret;i< this->staffNum-1; i++)
		{
			this->satffArray[i] = this->satffArray[i + 1];
		}
		this->staffNum--; //更新员工人数,人数减一

		//同步文件中的数据
		this->save(); //重新把数组中的数据写入到文件中
		cout << "删除成功" << endl;
		system("pause");
		system("cls");

	}
}

void managementStaff::modStaffInfo() //修改员工信息
{
	int ret = 0; //保存查找员工函数的返回值
	int input = 0; //保存输入值

	int id = 0;
	string name = "";
	int deptId = 0;
	staffBase* staff = NULL;

	cout << "请输入被修改人的id："<< endl;
	cin >> input;
	ret = this->staffIsExist(input); //查找员工，找到返回下标，反之返回-1
	if (ret == -1)
	{
		cout << "没有找到此员工" << endl;
		system("pause");
		system("cls");
		return;
	}

	else if (ret == -2)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
		return;
	}

	else
	{
		this->satffArray[ret]->showInfo();
		cout << "请输入新的员工id:" << endl;
		cin >> id;
		cout << "请输入新的员工姓名:" << endl;
		cin >> name;
		cout << "请输入新的员工岗位编号:" << endl;
		cout << "1.普通员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> deptId;
	
		if (deptId == 1) //普通员工
		{
			staff = new ordinaryStaff(id, name, deptId); //new一个普通员工类，并把从文件中读出的id ，name，deptid传过去
		}

		if (deptId == 2) //经理
		{
			staff = new manager(id, name, deptId);
		}

		if (deptId == 3) //老板
		{
			staff = new boss(id, name, deptId);
		}
		this->satffArray[ret] = staff;

		cout << "修改成功"<<endl;
		
		this->save(); //同步更新文件中的数据
		
		system("pause");
		system("cls");
	}
}

void managementStaff::findStaff() //查找员工
{
	int input = 0;
	cout << "请选择查找的方式:" << endl << "1.id" << endl<<"2.姓名"<<endl;
	cin >> input; //存放输入的查找方式
	if (input == 1)
	{
		int ret = 0; //存放staffIsExist的返回值
		int input2 = 0; //存放输入的id
		cout << "请输入员工id" << endl;
		cin >> input2;
		ret = this->staffIsExist(input2);
		if (ret == -1)
		{
			cout << "没有找到此员工" << endl;
			system("pause");
			system("cls");
			return;
		}

		else if (ret == -2)
		{
			cout << "文件不存在或记录为空" << endl;
			system("pause");
			system("cls");
			return;
		}

		else
		{
			this->satffArray[ret]->showInfo();
			system("pause");
			system("cls");
		}
	}
	else if (input == 2)
	{
		bool flag = false; //记录有没有查到过员工。找到过 = true 反之 = false
 		string name = ""; //存放输入的姓名
		cout << "请输入员工姓名："<<endl;
		cin >> name;
		if (this->fileIsEmpty == true)
		{
			cout << " 文件为空或记录不存在" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			for (int i = 0;i<this->staffNum; i++)
			{
				if (this->satffArray[i]->m_name == name)
				{
					this->satffArray[i]->showInfo();
					flag = true;
				}
			}
			if(flag == true)
			{
				system("pause");
				system("cls");
			}
			else if(flag ==false)
			{
				cout << "没有找到此员工" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

void managementStaff::sort() //排序函数
{
	if (this->fileIsEmpty == true) //判空
	{
		cout << "文件为空或记录不存在" << endl;
		system("pause");
		system("cls");
		return;
	}

	//冒泡排序
	cout << "请选择排序方式：" << endl << "1.升序" << endl << "2.降序" << endl;
	int input = 0;
	cin >> input;
	int i = 0;
	int j = 0;
	
	//升序
	if (input == 1)
	{
		for(i = 0;i < this->staffNum; i++)
		{
			for(j = 0;j < this->staffNum-1-i; j++)
			{
				if (this->satffArray[j]->m_id > this->satffArray[j+1]->m_id)
				{
					staffBase* staff = NULL;
					staff = this->satffArray[j];
					this->satffArray[j] = this->satffArray[j + 1];
					this->satffArray[j + 1] = staff;
				}
			}
		}
		cout << "排序完成" << endl;
		this->save(); //同步更新文件中的数据
		this->showStaffInfo(); //输出员工信息
	}

	//降序
	else
	{
		for (i = 0; i < this->staffNum; i++)
		{
			for (j = 0; j < this->staffNum - 1 - i; j++)
			{
				if (this->satffArray[j]->m_id < this->satffArray[j + 1]->m_id)
				{
					staffBase* staff = NULL;
					staff = this->satffArray[j];
					this->satffArray[j] = this->satffArray[j + 1];
					this->satffArray[j + 1] = staff;
				}
			}
		}
		cout << "排序完成" << endl;
		this->save(); //同步更新文件中的数据
		this->showStaffInfo(); //输出员工信息
	}
}

void managementStaff::reseSystem() //重置系统
{
	string input = "";
	cout << "确认重置系统吗？此操作将清空所有数据！（请输入“确认”或“取消”）" << endl;
	cin >> input;
	if(input == "确认")
	{
		ofstream ofs(FILENAME, ios::trunc);//如果文件存在删除并重新创建
		ofs.close();
		if (this->satffArray != NULL)
		{
			for(int i = 0 ;i< this->staffNum; i++)
			{
				if (this->satffArray[i] != NULL)
				{
					//释放堆区new的每一个对象
					delete this->satffArray[i];
					this->satffArray[i] = NULL;
				}
			}
		}
		this->staffNum = 0; //员工数量重置为0

		delete[] this->satffArray; //释放堆区开辟的数组
		this->satffArray = NULL; //员工数组重置为空

		this->fileIsEmpty = true; //文件判空 赋值为空
		cout << "重置完成" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "已取消" << endl;
		system("pause");
		system("cls");
	}
}