//
// Created by 91601 on 2020/7/19.
//
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include"staff_system.h"

#include "structural_morphology.h"

#define  STAFF sizeof(struct staff)


//չʾ����Ա����Ϣ
int Disply_staff(struct staff *head)
{
	struct staff *node = head;
	int i = 0;
	while (node != NULL)  //�����Ǳ�β����ѭ����ӡ�ڵ����ֵ
	{
		printf("%s\t%s\t%s\t%d\t\t%d\n", node->id, node->passward, node->name, node->number, node->salary);
		node = node->next;  //��pָ����һ���ڵ�
		i++;//������
	}
	return i;    //���ص����ж��ٸ����
}

//�򿪹���Ա��Ϣ�ļ�
struct staff *readFile_staff()
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

//�������Ա��Ϣ
void storage_staff(struct staff* head)
{
	FILE* fp = NULL;
	fp = fopen("staff.txt", "w+");
	fprintf(fp, "�˺�\t����\t����\t��λ���\t����\n");
	struct staff *node = head;
	while (node != NULL)  //�����Ǳ�β����ѭ����ӡ�ڵ����ֵ
	{
		fprintf(fp, "%s\t%s\t%s\t%d\t%d\n", node->id, node->passward, node->name, node->number, node->salary);
		node = node->next;  //��pָ����һ���ڵ�
	}
	fclose(fp);
}

//���ӹ���Ա
void add_staff()
{
	printf("������������Ա��\n");
	printf("1--�ǣ� 0--��\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("���������Ա�˺�");
		char id[11];
		scanf("%s", id);

		int exit = 0;//����Ա�Ƿ����
		struct staff * head = readFile_staff();
		struct staff *index = NULL;
		index = (struct staff *)malloc(sizeof(struct staff));
		if (index == NULL)
		{
			printf("û���㹻���ڴ棡");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (strcmp(index->id, id) == 0)
			{
				exit = 1;
			}
			if (strcmp(index->next->id, id) == 0)
			{
				exit = 1;
			}
			index = index->next;
		}

		if (exit == 1)
		{
			printf("���������Ĺ���Ա�˺��Ѿ�����\n");
		}
		else
		{
			struct staff *new = NULL;
			new = (struct staff *)malloc(sizeof(struct staff));
			strcpy(new->id, id);
			printf("������Ҫ�����Ĺ���Ա���룺  ");
			scanf("%s", new->passward);
			printf("������Ҫ�����Ĺ���Ա������  ");
			scanf("%s", new->name);
			printf("������Ҫ�����Ĺ���Ա��λ��ţ�  ");
			scanf("%d", &new->number);
			printf("������Ҫ�����Ĺ���Ա���ʣ�  ");
			scanf("%d", &new->salary);
			new->next = NULL;
			index->next = new;
			printf("\n�˺�\t����\t����\t��λ���\t����\n");
			Disply_staff(new);
			printf("��������Ա�ɹ�!\n");
			storage_staff(head, "goods.txt");
		}

		printf("�㻹�������������Ա��\n");
		printf("1--�ǣ� 0--��\n");
		scanf("%d", &choice);
	}
	printf("�����˳���������Ա\n");
}

//ɾ��ָ������Ա����Ϣ
void delete_staff()
{
	printf("����ɾ������Ա��\n");
	printf("1--�ǣ� 0--��\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("��������ɾ���Ĺ���Ա���˺�\n");
		char id[11];
		scanf("%s", id);
		struct staff *currtentNode = NULL;
		currtentNode = (struct staff *)malloc(sizeof(struct staff));
		struct staff *lastNode = NULL;
		lastNode = (struct staff *)malloc(sizeof(struct staff));

		int exit = 0;//�˺��Ƿ����
		struct staff *head = readFile_staff();
		struct staff *index = NULL;
		index = (struct staff *)malloc(sizeof(struct staff));
		if (index == NULL)
		{
			printf("û���㹻���ڴ棡");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (strcmp(index->id, id) == 0)
			{
				lastNode = index;
			}
			if (strcmp(index->next->id, id) == 0)
			{
				exit = 1;
				currtentNode = index->next;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("����ɾ���Ĺ���Ա���˺Ų�����\n");
		}
		else
		{
			printf("��ȷ��ɾ����������Ա�˺ţ�\n1--ȷ�� 0--�˳�\n\n");
			printf("\n�˺�\t����\t����\t��λ���\t\t����\n");
			printf("%s\t%s\t%s\t%d\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
			int a;
			scanf("%d", &a);
			if (a == 1)
			{
				lastNode->next = currtentNode->next;
				printf("ɾ������Ա�ɹ�!\n");
				storage_staff(head);
			}
			else
			{
				printf("ɾ������Աʧ��!\n");
			}
		}
		printf("�㻹�����ɾ������Ա��\n");
		printf("1--�ǣ� 0--��\n");
		scanf("%d", &choice);
	}
	printf("�����˳�ɾ������Ա\n");
}

//�޸�ָ������Ա����Ϣ
void change_staff()
{
	printf("�����޸Ĺ���Ա��\n");
	printf("1--�ǣ� 0--��\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("���������Ա���˺�");
		char id[11];
		scanf("%s", id);
		struct staff *currtentNode = NULL;
		currtentNode = (struct staff *)malloc(sizeof(struct staff));

		int exit = 0;//����Ա�Ƿ����
		struct staff *head = readFile_staff();
		struct staff *index = NULL;
		index = (struct staff *)malloc(sizeof(struct staff));
		if (index == NULL)
		{
			printf("û���㹻���ڴ棡");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (strcmp(index->id, id) == 0)
			{
				exit = 1;
				currtentNode = index;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("�����޸ĵĹ���Ա���˺Ų�����\n");
		}
		else
		{
			printf("\n�˺�\t����\t����\t��λ���\t����\n");
			printf("%s\t%s\t%s\t%d\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
			printf("��ѡ����Ҫ�޸ĵ�ѡ��\n");
			printf("1--�˺�\t2--����\t3--ְλ���\t4--����\n");
			int choice2;
			scanf("%d", &choice2);
			switch (choice2)
			{
			case 1:
			{
					  char id1[7];
					  int i = 0;
					  printf("�������޸ĺ����Ա�˺ţ�  ");
					  scanf("%s", id1);
					  do
					  {
						  i = 0;
						  index = head;
						  while (index->next != NULL)
						  {
							  if (strcmp(index->id, id1) == 0)
							  {
								  i = 1;
								  printf("%s�����й���Ա�˺��ظ�������������!", id1);
								  scanf("%s", id1);
							  }
							  index = index->next;
						  }
					  } while (i);
					  strcpy(currtentNode->id, id1);
					  break;
			}
			case 2:
			{
					  printf("�������޸ĺ�Ĺ���Ա������  ");
					  scanf("%s", currtentNode->name);
					  break;
			}
			case 3:
			{
					  printf("�������޸ĺ�Ĺ���Աְλ��ţ�  ");
					  scanf("%d", &currtentNode->number);
					  break;
			}
			case 4:
			{
					  printf("�������޸ĺ�Ĺ���Աְλ����");
					  scanf("%d", &currtentNode->salary);
					  break;
			}
			}
			printf("�޸Ĺ���Ա��Ϣ�ɹ�!\n");
			printf("\n�˺�\t����\t����\t��λ���\t����\n");
			printf("%s\t%s\t%s\t%d\t\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
			storage_staff(head);
		}

		printf("�㻹������޸Ĺ���Ա��Ϣ��\n");
		printf("1--�ǣ� 0--��\n");
		scanf("%d", &choice);
	}
	printf("�����˳��޸Ĺ���Ա��Ϣ\n");
}

//�����������
void change_password()
{
	printf("���������ĵ��˺�");
	char id[11];
	scanf("%s", id);
	struct staff *currtentNode = NULL;
	currtentNode = (struct staff *)malloc(sizeof(struct staff));
	int exit = 0;//����Ա�Ƿ����
	struct staff *head = readFile_staff();
	struct staff *index = NULL;
	index = (struct staff *)malloc(sizeof(struct staff));
	if (index == NULL)
	{
		printf("û���㹻���ڴ棡");
		return 0;
	}
	index = head;
	while (index->next != NULL)
	{
		if (strcmp(index->id, id) == 0)
		{
			exit = 1;
			currtentNode = index;
		}
		index = index->next;
	}

	if (exit == 0)
	{
		printf("�����޸ĵĹ���Ա���˺Ų�����\n");
	}
	else
	{
		printf("���������ĵ�����\n");
		char password[7];
		scanf("%s", password);
		if (strcmp(password, currtentNode->passward) == 0)
		{

			printf("\n�˺�\t����\t����\t��λ���\t����\n");
			printf("%s\t%s\t%s\t%d\t\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);

			printf("�������޸ĺ������\n");
			char passward1[7];
			scanf("%s", passward1);
			printf("���ٴ������޸ĺ��������ȷ��\n");
			char passward2[7];
			scanf("%s", passward2);
			if (strcmp(passward1, passward2) == 0)
			{
				strcpy(currtentNode->passward, passward1);
				printf("�޸Ĺ���Ա��Ϣ�ɹ�!\n");
				printf("\n�˺�\t����\t����\t��λ���\t����\n");
				printf("%s\t%s\t%s\t%d\t\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
				storage_staff(head);
			}
			else
			{
				printf("�������벻һ��������\n");
			}
		}
		else
		{
			printf("�������");
		}
	}
	printf("�����˳��޸Ĺ���Ա��Ϣ\n");
}






