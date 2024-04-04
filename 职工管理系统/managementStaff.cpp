#include"managementStaff.h"

managementStaff::managementStaff() //���캯��
{
	//��ʼ��
	//1.�ļ�������
	ifstream ifs; 
	ifs.open(FILENAME, ios::in); //�Զ�ȡ��ʽ���ļ�
	
	if (ifs.is_open() != true) //�ж��ļ��Ƿ�򿪳ɹ����򿪳ɹ�����true
	{
		//cout << "�ļ�������" << endl;
		this->staffNum = 0; //Ա��������ʼ��Ϊ0
		this->satffArray = NULL; //Ա�������ʼ��Ϊ��
		this->fileIsEmpty= true; //�ļ��п� ��ֵΪ��
		ifs.close(); //�ر��ļ�
		return; 
	}
	
	//2.�ļ����ڣ����ļ���û������
	char ch;
	ifs >> ch; //���ļ��ж�ȡ���ĵ����ַ�����ch��
	if (ifs.eof() == true) //eof�����ж��ļ�����û�����ݣ�û�еĻ�����true 
	{
		
		this->staffNum = 0; //Ա��������ʼ��Ϊ0
		
		this->satffArray = NULL; //Ա�������ʼ��Ϊ��
	    
		this->fileIsEmpty = true; //�ļ��п� ��ֵΪ��
		
		ifs.close(); //�ر��ļ�
		
		return;
	}

	//3.�ļ����ڣ�ͬʱ�ļ���Ҳ������,��������д�뵽Ա��������
	this->satffArray = NULL; //Ա�������ʼ��Ϊ��
	
	int num = this->getStaffNum(); //��¼�ļ�������
	
	this->staffNum = num; //Ա��������ʼ��Ϊ�ļ���Ա������
	
	this->satffArray = new staffBase * [this->staffNum]; //���ٿռ�
	
	this->initStaff(); //��ʼ��Ա�����飬���ļ��е����ݴ��뵽������
	
	this->fileIsEmpty = false; //�ļ��п� ��ֵΪ�ǿ�
	return;

}

managementStaff::~managementStaff() //��������
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
		delete[] this->satffArray; //�ͷŶ������ٵ�����
		this->satffArray = NULL;
		cout << "��������" << endl;
	}
}

void managementStaff::menu()//�˵�
{
	cout << "Ա������ϵͳ v1.0" << endl;
	cout<<"------------------------------------------" << endl;
	cout<<"1.���Ա��           2.�鿴Ա����Ϣ" << endl;
	cout<<"3.ɾ����ְԱ��       4.�޸�Ա����Ϣ" << endl;
	cout<<"5.����Ա��           6.����" << endl;
	cout<<"7.����ϵͳ           0.�˳�"<< endl;
	cout<<"------------------------------------------" << endl;
}

void managementStaff::exitSystem() //�˳�
{
	cout << "�˳�" << endl;
	exit(0);
	system("pause");
	
}

void managementStaff::AddStaff() //���Ա������
{
	cout << "��������Ҫ��ӵ�Ա��������" << endl;
	int input = 0; //���������ֵ
	cin >> input;
	if (input > 0)
	{
		int newSize = this->staffNum + input; //�����¿ռ�Ĵ�С
		staffBase**	newSpace= new staffBase* [newSize]; //�����¿ռ�
	    
		for(int i =0 ;i < this->staffNum; i++)	
		{
			if (this->satffArray != NULL)
			{
				newSpace[i] = this->satffArray[i];
			}
		}

		int i = 0;
		for (i = 0;i < input;i++) //���Ա��
		{
			string name;
			int id;
			int deptSelect;
			cout << "�������" << i + 1 << "��Ա������Ϣ" << endl;
			cout << "������Ա��id" << endl;
			cin>>id;
			cout << "������Ա������" << endl;
			cin >>name;
			cout << "������Ա����λ���" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		this->satffArray = newSpace; //ָ���¿ռ�
		cout << "�ɹ����"<<i<<"��Ա����Ϣ" << endl;
		this->fileIsEmpty = false; //�ļ��п�
		this->staffNum = newSize; //����Ա������
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");

	system("cls");
}

void managementStaff::save() //д�ļ����� �����������Ա������д�뵽�ļ��б��棩
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //������ķ�ʽ���ļ���д�ļ�
	
	for (int i = 0; i < this->staffNum; i++) //��ÿ���˵���Ϣѭ��д�뵽�ļ���
	{
		ofs << this->satffArray[i]->m_id << "  " 
			<< this->satffArray[i]->m_name<< "  " 
			<< this->satffArray[i]->m_deptId << endl;
	}
	ofs.close(); // �ر��ļ�
}

int managementStaff::getStaffNum() //��ȡ�ļ���Ա������
{
	int num =0; //��¼����
	ifstream ifs;
	int id;
	string name;
	int deptId;
	ifs.open(FILENAME, ios::in); //���ļ� ��
 	while(ifs>>id && ifs>>name && ifs>>deptId)
	{
		num++;
	}
	return num;
}

void managementStaff::initStaff() //��ʼ��Ա������
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//��
	int id;
	string name;
	int deptId;
	staffBase* staff = NULL;
	for (int i = 0; i<this->staffNum; i++ )
	{
		ifs >> id;
		ifs >> name;
		ifs >> deptId;
		if (deptId == 1) //��ͨԱ��
		{
			staff = new ordinaryStaff(id, name, deptId); //newһ����ͨԱ���࣬���Ѵ��ļ��ж�����id ��name��deptid����ȥ
		}

		if (deptId == 2) //����
		{
			staff = new manager(id, name, deptId);
		}

		if (deptId == 3) //�ϰ�
		{
			staff = new boss(id, name, deptId);
		}

		this->satffArray[i] = staff;
	}
	ifs.close(); //�ر��ļ�
}

void managementStaff::showStaffInfo() //�鿴����Ա����Ϣ
{
	if (this->satffArray == NULL) //�ж���������û��Ա����Ϣ
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause"); //��ͣ
		system("cls"); //�����Ļ
		return;
	}

	else
	{
		for(int i = 0; i < this->staffNum; i++) //ѭ����ӡԱ����Ϣ
		{
			this->satffArray[i]->showInfo();
		}
	}
	system("pause"); //��ͣ
	system("cls"); //�����Ļ
}

int managementStaff::staffIsExist(int id) //����Ա��,����Ա��id,�ҵ�����Ա���±�,û�ҵ�����-1���ļ������ڻ��¼Ϊ�շ���-2
{
	if (this->satffArray == NULL) 
	{
		//�ļ�������
		return -2;
	}
	else
	{
		//�ҵ���
		for (int i = 0; i < this->staffNum; i++)
		{
			if (this->satffArray[i]->m_id == id)
			{
				return i;
			}
			
		}

		//û�ҵ�
		return -1;
	}
}
void managementStaff::deleteStaff() //ɾ��Ա������ (����:Ա��id,���ò���Ա�������ҵ���ɾ��)
{
	int input = 0;
	cout << "��������Ҫɾ����Ա��id:"<<endl;
	cin >> input;
	int ret = 0; //������Һ����ķ���ֵ
	ret = this->staffIsExist(input);
	if (ret == -1) //û�ҵ�
	{
		cout << "û���ҵ���Ա��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (ret == -2)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else //�ҵ�,ɾ��
	{
		for(int i = ret;i< this->staffNum-1; i++)
		{
			this->satffArray[i] = this->satffArray[i + 1];
		}
		this->staffNum--; //����Ա������,������һ

		//ͬ���ļ��е�����
		this->save(); //���°������е�����д�뵽�ļ���
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");

	}
}

void managementStaff::modStaffInfo() //�޸�Ա����Ϣ
{
	int ret = 0; //�������Ա�������ķ���ֵ
	int input = 0; //��������ֵ

	int id = 0;
	string name = "";
	int deptId = 0;
	staffBase* staff = NULL;

	cout << "�����뱻�޸��˵�id��"<< endl;
	cin >> input;
	ret = this->staffIsExist(input); //����Ա�����ҵ������±꣬��֮����-1
	if (ret == -1)
	{
		cout << "û���ҵ���Ա��" << endl;
		system("pause");
		system("cls");
		return;
	}

	else if (ret == -2)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	else
	{
		this->satffArray[ret]->showInfo();
		cout << "�������µ�Ա��id:" << endl;
		cin >> id;
		cout << "�������µ�Ա������:" << endl;
		cin >> name;
		cout << "�������µ�Ա����λ���:" << endl;
		cout << "1.��ͨԱ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> deptId;
	
		if (deptId == 1) //��ͨԱ��
		{
			staff = new ordinaryStaff(id, name, deptId); //newһ����ͨԱ���࣬���Ѵ��ļ��ж�����id ��name��deptid����ȥ
		}

		if (deptId == 2) //����
		{
			staff = new manager(id, name, deptId);
		}

		if (deptId == 3) //�ϰ�
		{
			staff = new boss(id, name, deptId);
		}
		this->satffArray[ret] = staff;

		cout << "�޸ĳɹ�"<<endl;
		
		this->save(); //ͬ�������ļ��е�����
		
		system("pause");
		system("cls");
	}
}

void managementStaff::findStaff() //����Ա��
{
	int input = 0;
	cout << "��ѡ����ҵķ�ʽ:" << endl << "1.id" << endl<<"2.����"<<endl;
	cin >> input; //�������Ĳ��ҷ�ʽ
	if (input == 1)
	{
		int ret = 0; //���staffIsExist�ķ���ֵ
		int input2 = 0; //��������id
		cout << "������Ա��id" << endl;
		cin >> input2;
		ret = this->staffIsExist(input2);
		if (ret == -1)
		{
			cout << "û���ҵ���Ա��" << endl;
			system("pause");
			system("cls");
			return;
		}

		else if (ret == -2)
		{
			cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		bool flag = false; //��¼��û�в鵽��Ա�����ҵ��� = true ��֮ = false
 		string name = ""; //������������
		cout << "������Ա��������"<<endl;
		cin >> name;
		if (this->fileIsEmpty == true)
		{
			cout << " �ļ�Ϊ�ջ��¼������" << endl;
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
				cout << "û���ҵ���Ա��" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

void managementStaff::sort() //������
{
	if (this->fileIsEmpty == true) //�п�
	{
		cout << "�ļ�Ϊ�ջ��¼������" << endl;
		system("pause");
		system("cls");
		return;
	}

	//ð������
	cout << "��ѡ������ʽ��" << endl << "1.����" << endl << "2.����" << endl;
	int input = 0;
	cin >> input;
	int i = 0;
	int j = 0;
	
	//����
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
		cout << "�������" << endl;
		this->save(); //ͬ�������ļ��е�����
		this->showStaffInfo(); //���Ա����Ϣ
	}

	//����
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
		cout << "�������" << endl;
		this->save(); //ͬ�������ļ��е�����
		this->showStaffInfo(); //���Ա����Ϣ
	}
}

void managementStaff::reseSystem() //����ϵͳ
{
	string input = "";
	cout << "ȷ������ϵͳ�𣿴˲���������������ݣ��������롰ȷ�ϡ���ȡ������" << endl;
	cin >> input;
	if(input == "ȷ��")
	{
		ofstream ofs(FILENAME, ios::trunc);//����ļ�����ɾ�������´���
		ofs.close();
		if (this->satffArray != NULL)
		{
			for(int i = 0 ;i< this->staffNum; i++)
			{
				if (this->satffArray[i] != NULL)
				{
					//�ͷŶ���new��ÿһ������
					delete this->satffArray[i];
					this->satffArray[i] = NULL;
				}
			}
		}
		this->staffNum = 0; //Ա����������Ϊ0

		delete[] this->satffArray; //�ͷŶ������ٵ�����
		this->satffArray = NULL; //Ա����������Ϊ��

		this->fileIsEmpty = true; //�ļ��п� ��ֵΪ��
		cout << "�������" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "��ȡ��" << endl;
		system("pause");
		system("cls");
	}
}