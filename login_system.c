//
// Created by 91601 on 2020/7/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "login_system.h"
#include "structural_morphology.h"

//���ļ�����½�������Ϣ
struct good *readFile2()
{
	FILE *fp = NULL;
	fp = fopen("staff.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		return NULL;
	}

	char buf[528];
	fgets(buf, 528, fp);  //������һ��
	fgets(buf, 528, fp);  //�����ڶ���

	struct staff *head = NULL;
	head = (struct staff*)malloc(sizeof(struct staff));
	if (head == NULL)
	{
		printf("û���㹻���ڴ棡");
		return NULL;
	}
	head->next = NULL;
	struct staff *L = head;
	while (!feof(fp))
	{
		struct staff *node = NULL;
		node = (struct staff*)malloc(sizeof(struct staff));
		fscanf(fp, "%s\t%s\t%s\t%d\t%d\n", node->id, node->passward, node->name, &node->number, &node->salary);
		//printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_munber);
		L->next = node;
		L = L->next;
	}
	L->next = NULL;
	fclose(fp);
	return head->next;
}


//��½ϵͳ
int login(int person)
{
	char passward[7];
	char id[11];
	
	if (person == 1)
	{
		printf("\n\n\n\t\t\t\t��ӭ������������Ա\n");
		printf("\n\n\n\t\t\t�������������룺");
		scanf("%s", passward);
		FILE* fp = NULL;
		fp = fopen("staff.txt", "r");
		if (fp == NULL)
		{
			printf("�ļ���ʧ��");
			return 0;
		}

		char buf[528];
		fgets(buf, 528, fp);  //������һ��

		struct staff *node = NULL;
		node = (struct staff*)malloc(sizeof(struct staff));
		fscanf(fp, "%s\t%s\t%s\t%d\t%d\n", node->id, node->passward, node->name, &node->number, &node->salary);
		//printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_munber);
		if (strcmp(passward, node->passward) == 0)
		{
			printf("��������Ա��½�ɹ�\n");
			printf("��ӭ����%s\n\n",node->name);
			fclose(fp);
			return 1;
		}
		else
		{
			printf("������������µ�¼\n");
			fclose(fp);
			return 0;
		}
	}
	else if (person == 2)
	{
		struct staff *head = NULL;
		head = (struct staff *)malloc(sizeof(struct staff));
		head = readFile2();
		struct staff *node = head;
		int exit = 0,pass=0;
		printf("�������˺�\n");
		scanf("%s",id);
		while (node != NULL)  //�����Ǳ�β����ѭ����ӡ�ڵ����ֵ
		{
			if (strcmp(id, node->id) == 0)
			{
				exit = 1;
				printf("����������\n");
				scanf("%s", passward);
				if (strcmp(passward, node->passward)==0)
				{
					pass = 1;
				}
			}
			node = node->next;
		}
		if (exit== 0)
		{
			printf("�˺Ų����ڣ����顣\n");
			return 0;
		}
		else if (exit == 1 && pass == 0)
		{
			printf("����������顣\n");
			return 0;
		}
		else if (exit == 1 && pass == 1)
		{
			printf("��½�ɹ���\n");
			return 2;
		}
	}

}
