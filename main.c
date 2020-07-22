#include<stdio.h>
#include"finance_system.h"//�������ϵͳ
#include"goods_system.h"//��Ʒ����ϵͳ
#include"login_system.h"//���˵�
#include"staff_system.h"//����Ա����ϵͳ
#include "structural_morphology.h"

void goods_inquiry();
void staff_inquiry();
void finance_inquiry();
void super_staff_menu();
void staff_menu();

#define SUPER_STAFF 1
#define STAFF 2

int main()
{
	//system("color 7D");
	int choice;           //��¼�û��Ĺ���ѡ�� 
	char c;
	int identity = 0;
	double finance[2] = { 0.0, 0.0 }; //income and pay
	while (1)
	{
		
		choice = main_menu();
		system("cls");  //��ʱ�������������� 
		if (choice == 1)
		{
			
				identity = login(1);
				if (identity == 1)
				{
					super_staff_menu(finance);
				}
				else
				{
					printf("��������Աϵͳ��½ʧ���ˣ�\n\n\n");
				}
			
		}
		else if (choice == 2)
		{
			
				identity = login(2);
				if (identity == 2)
				{
					staff_menu(finance);
				}
				else
				{
					printf("����Աϵͳ��½ʧ���ˣ�\n\n\n");
				}
			
		}
		else if (choice == 0)
		{
			system("cls");
			printf("���й���ϵͳ��ӭ�ٴ�Ϊ�������ټ�~\n");
			exit(0);
		}
		else 
		{
			printf("��������������\n");
		}
		system("pause");
	}
	return 0;
}
//ʹ��
void super_staff_menu(double finance[]){
	int choice = 0;
	while (choice != 4) {
		printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*             ��ӭ������������Ա��Ϣ��ѯϵͳ            *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  1. ��ѯ������Ϣ                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  2. ��ѯ������Ϣ                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  3. �޸����빦��                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  4. �˳���ǰ����                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n\n");
		printf("���������ѡ��\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			staff_inquiry();
			break;
		case 2:
			finance_inquiry(finance);
			break;
		case 3:
			change_password();
			break;
		case 4:
			printf("��ѡ�����˳�ϵͳ��ף��������졣\n");
			exit(0);
			break;
		default:
			printf("������Ч����ȷ�Ϻ��������롣\n");
		}
	}
}
void staff_menu(double finance[]){
	int choice = 0;
	while (choice != 3) {
		printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*             ��ӭ������ͨ����Ա��Ϣ��ѯϵͳ            *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  1. ��ѯ��Ʒ��Ϣ                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  2. �޸����빦��                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  3. �˳���ǰ����                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n\n");
		printf("���������ѡ��\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			goods_inquiry(finance);
			break;
		case 2:
			change_password();
			break;
		case 3:
			printf("��ѡ�����˳�ϵͳ��ף��������졣\n");
			break;
		default:
			printf("������Ч����ȷ�Ϻ��������롣\n");
		}
	}
}
//ʹ�û������ϵͳ
void goods_inquiry(double finance[]){
	int i;
	system("pause");
	system("cls");
	i = goodsmemu();
	while (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6)
	{
		if (i == 1)  //�����Ʒ
		{
			system("cls");
			finance[1] +=addgoods(); //���������Ʒ�ĺ��� 
			system("pause");
			system("cls");
		}
		if (i == 2) //ɾ����Ʒ
		{
			system("cls");
			finance[0] += delgoods(); //����ɾ����Ʒ�ĺ��� 
			system("pause");
			system("cls");
		}
		if (i == 3)  //�޸���Ʒ
		{
			system("cls");
			changegoods(finance); //�����޸���Ʒ�ĺ���
			system("pause");
			system("cls");
		}
		if (i == 4)  //ͳ����Ʒ 
		{
			system("cls");
			sortgoods(); //����ͳ����Ʒ�ĺ��� 
			system("pause");
			system("cls");
		}
		if (i == 5)  //չʾ��Ʒ
		{
			system("cls");
			printf("\n���\t����\t����\t\t�ۼ�\t\t����\t���\n");
			Disply(readFile()); //����չʾ��Ʒ�ĺ���
			system("pause");
			system("cls");
		}
		if (i == 6)  //������Ʒ
		{
			system("cls");
			findgoods(); //���ò�����Ʒ�ĺ���
			system("pause");
			system("cls");
		}
		i = goodsmemu();
	}
	system("cls");
	system("pause");
	printf("��Ʒ����ϵͳ��ӭ�ٴ�Ϊ�������ټ�~\n");
}
//ʹ�ù���Ա����ϵͳ
void staff_inquiry(){
	int i;
	system("pause");
	system("cls");
	i = staffmemu();
	while (i == 1 || i == 2 || i == 3 || i == 4)
	{
		if (i == 1)  //��ӹ���Ա
		{
			system("cls");
			add_staff();
			system("pause");
			system("cls");
		}
		if (i == 2) //ɾ������Ա 
		{
			system("cls");
			delete_staff();
			system("pause");
			system("cls");
		}
		if (i == 3)  //�޸Ĺ���Ա 
		{
			system("cls");
			change_staff();
			system("pause");
			system("cls");
		}
		if (i == 4)  //չʾ����Ա����Ϣ 
		{
			system("cls");
			Disply_staff(readFile_staff());
			system("pause");
			system("cls");
		}
		i = staffmemu();
	}
	system("cls");
	system("pause");
	printf("����Ա����ϵͳ��ӭ�ٴ�Ϊ�������ټ�~\n");
}

//ʹ�ò������ϵͳ
void finance_inquiry(double finance[]){
	int i;
	system("pause");
	system("cls");
	i = financememu();
	while (i == 1 || i == 2 || i == 3)
	{
		if (i == 1)  //��������
		{
			system("cls");
			printf("��������:%5lfԪ", income(finance));
			system("pause");
			system("cls");
		}
		if (i == 2) //����֧�� 
		{
			system("cls");
			printf("����֧��:%5lfԪ", pay(finance));
			system("pause");
			system("cls");
		}
		if (i == 3)  //����ӯ��
		{
			system("cls");
			printf("����ӯ��:%5lfԪ", gain(finance));
			system("pause");
			system("cls");
		}
		i = financememu();
	}
	system("pause");
	system("cls");
	printf("�������ϵͳ��ӭ�ٴ�Ϊ�������ټ�~\n");
}
