//
// Created by 91601 on 2020/7/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "goods_system.h"

#include "structural_morphology.h"

#define GOODS sizeof(struct goods)

int Disply(struct goods *head)
{
	struct goods *node = head;
	int i = 0;
	while (node != NULL)  //�����Ǳ�β����ѭ����ӡ�ڵ����ֵ
	{
		printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_number);
		node = node->next;  //��pָ����һ���ڵ�
		i++;//������
	}
	return i;    //���ص����ж��ٸ����
}

struct good *readFile()
{
	FILE *fp = NULL;
	fp = fopen("goods.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		return NULL;
	}

	char buf[528];
	fgets(buf, 528, fp);  //������һ��

	struct goods *head = NULL;
	head = (struct goods*)malloc(sizeof(struct goods));
	if (head == NULL)
	{
		printf("û���㹻���ڴ棡");
		return NULL;
	}
	head->next = NULL;
	struct goods *L = head;
	while (!feof(fp))
	{
		struct goods *node = NULL;
		node = (struct goods*)malloc(sizeof(struct goods));
		fscanf(fp, "%d\t%s\t%lf\t%lf\t%d\t%d\n", &node->number, node->name, &node->cost, &node->price, &node->sale_number, &node->stay_number);
		//printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_munber);
		L->next = node;
		L = L->next;
	}
	L->next = NULL;

	fclose(fp);
	return head->next;
}

void saveToFile(struct goods *head, char name[])
{
	FILE* fp = NULL;
	fp = fopen(name, "w+");
	fprintf(fp, "���\t����\t����\t�ۼ�\t����\t���\n");
	struct goods *node = head;
	while (node != NULL)  //�����Ǳ�β����ѭ����ӡ�ڵ����ֵ
	{
		fprintf(fp, "%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_number);
		node = node->next;  //��pָ����һ���ڵ�
	}
	fclose(fp);
}

//������Ʒ
int findgoods()
{
	int choice=1;
	while (choice == 1)
	{
		printf("����������ҵ���Ʒ�ı��\n");
		int number;
		scanf("%d", &number);

		int exit = 0;//��Ʒ�Ƿ����
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		struct goods *currtentNode = NULL;
		currtentNode = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("û���㹻���ڴ棡");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->number == number)
			{
				currtentNode = index;
				exit = 1;
			}
			index = index->next;
		}
		if (exit == 0)
		{
			printf("���������Ʒ����Ʒ������\n");
			return 0;
		}
		else
		{
			printf("���������Ʒ����Ʒ����\n");
			printf("\n���\t����\t����\t\t�ۼ�\t\t����\t���\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			return 1;
		}
		printf("�㻹�����������Ʒ��\n");
		printf("1--�ǣ� 0--��\n");
		scanf("%d", &choice);
	}
	printf("�˳�������Ʒ\n");
}

//��Ʒ¼��
double addgoods()
{
	double pay = 0.0;
	printf("����������Ʒ��\n");
	printf("1--�ǣ� 0--��\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("��������Ʒ�ı��");
		int number;
		scanf("%d", &number);

		int exit = 0;//��Ʒ�Ƿ����
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("û���㹻���ڴ棡");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->number == number)
			{
				exit = 1;
			}
			if (index->next->number == number)
			{
				exit = 1;
			}
			index = index->next;
		}

		if (exit == 1)
		{
			printf("����������Ʒ����Ʒ����Ѿ�����\n");
		}
		else
		{
			struct goods *new = NULL;
			new = (struct goods *)malloc(sizeof(struct goods));
			new->number = number;
			printf("��������Ʒ���ƣ�  ");
			scanf("%s", new->name);
			printf("��������Ʒ���ۣ�  ");
			scanf("%lf", &new->cost);
			printf("��������Ʒ�ۼۣ�  ");
			scanf("%lf", &new->price);
			printf("��������Ʒ�����������������  ");
			scanf("%d", &new->stay_number);
			new->sale_number = 0;
			new->next = NULL;
			index->next = new;
			printf("\n���\t����\t����\t\t�ۼ�\t\t����\t���\n");
			Disply(new);
			printf("������Ʒ�ɹ�!\n");
			saveToFile(head, "goods.txt");
			pay += new->cost*new->stay_number;
		}

		printf("�㻹�����������Ʒ��\n");
		printf("1--�ǣ� 0--��\n");
		scanf("%d", &choice);
	}
	printf("�˳�������Ʒ\n");
	return pay;//����ֵ�ǻ����˶���Ǯ
}

//��Ʒ�޸�
int changegoods(double arr[])
{
	printf("�����޸���Ʒ��\n");
	printf("1--�ǣ� 0--��\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("��������Ʒ�ı��");
		int number;
		scanf("%d", &number);
		struct goods *currtentNode = NULL;
		currtentNode = (struct goods *)malloc(sizeof(struct goods));

		int exit = 0;//��Ʒ�Ƿ����
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("û���㹻���ڴ棡");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->number == number)
			{
				exit = 1;
				currtentNode = index;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("�����޸���Ʒ����Ʒ������\n");
		}
		else
		{
#if(0)
			printf("�������޸ĺ���Ʒ��ţ�  ");
			scanf("%d", &currtentNode->number);
			printf("�������޸ĺ���Ʒ���ƣ�  ");
			scanf("%s", currtentNode->name);
			printf("�������޸ĺ���Ʒ���ۣ�  ");
			scanf("%lf", &currtentNode->cost);
			printf("�������޸ĺ���Ʒ�ۼۣ�  ");
			scanf("%lf", &currtentNode->price);
			printf("�������޸ĺ���Ʒ����������  ");
			scanf("%lf", &currtentNode->sale_number);
			printf("�������޸ĺ���Ʒ�Ŀ������  ");
			scanf("%d", &currtentNode->stay_munber);
#endif
			printf("\n���\t����\t����\t�ۼ�\t����\t���\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			printf("��ѡ����Ҫ�޸ĵ�ѡ��\n");
			printf("1--���\t2--����\t3--�ۼ�\n");
			printf("4--��Ʒ�����ı仯��+���������-�����۳�\n");
			int choice2;
			scanf("%d", &choice2);
			switch (choice2)
			{
			case 1:
			{
					  int number1;
					  int i = 0;
					  printf("�������޸ĺ���Ʒ��ţ�  ");
					  scanf("%d", &number1);
					  do
					  {
						  i = 0;
						  index = head;
						  while (index->next != NULL)
						  {
							  if (index->number == number1)
							  {
								  i = 1;
								  printf("%d��������Ʒ�ı���ظ�������������!", number1);
								  scanf("%d", &number1);
							  }
							  index = index->next;
						  }
					  } while (i);
					  currtentNode->number = number1;
					  break;
			}
			case 2:
			{
					  printf("�������޸ĺ���Ʒ���ƣ�  ");
					  scanf("%s", currtentNode->name);
					  break;
			}
			case 3:
			{
					  printf("�������޸ĺ���Ʒ�ۼۣ�  ");
					  scanf("%lf", &currtentNode->price);
					  break;
			}
			case 4:
			{
					  printf("��������Ʒ�����ı仯��+���������-�����۳�");
					  int change;
					  scanf("%d", &change);
					  if (change > 0)
					  {
						  currtentNode->stay_number = change + currtentNode->stay_number;
						  arr[1] += (currtentNode->cost)*change;

					  }
					  else if (change < 0)
					  {
						  printf("%d", currtentNode->sale_number);
						  currtentNode->sale_number = -change + currtentNode->sale_number;
						  currtentNode->stay_number += change;
						  arr[0] += (currtentNode->price)*(-1)*change;
					  }
					  else{
						  printf("�ޱ仯��");
					  }
					  break;
			}
			}
			printf("�޸���Ʒ�ɹ�!\n");
			printf("\n���\t����\t����\t�ۼ�\t����\t���\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			saveToFile(head, "goods.txt");
		}

		printf("�㻹������޸���Ʒ��\n");
		printf("1--�ǣ� 0--��\n");
		scanf("%d", &choice);
	}
	printf("�˳��޸���Ʒ\n");
}

//��Ʒɾ��
double delgoods()
{
	double income = 0.0;
	printf("����ɾ����Ʒ��\n");
	printf("1--�ǣ� 0--��\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("��������ɾ������Ʒ�ı��\n");
		int number;
		scanf("%d", &number);
		struct goods *currtentNode = NULL;
		currtentNode = (struct goods *)malloc(sizeof(struct goods));
		struct goods *lastNode = NULL;
		lastNode = (struct goods *)malloc(sizeof(struct goods));

		int exit = 0;//��Ʒ�Ƿ����
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("û���㹻���ڴ棡");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->next->number == number)
			{
				lastNode = index;
			}
			if (index->number == number)
			{
				exit = 1;
				currtentNode = index;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("����ɾ����Ʒ����Ʒ������\n");
		}
		else
		{
			printf("��ȷ��ɾ��������Ʒ��\n1--ȷ�� 0--�˳�\n\n");
			printf("\n���\t����\t����\t\t�ۼ�\t\t����\t���\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			int a;
			scanf("%d", &a);
			if (a == 1)
			{
				lastNode->next = currtentNode->next;
				printf("ɾ����Ʒ�ɹ�!\n");
				saveToFile(head, "goods.txt");
				income += currtentNode->stay_number*currtentNode->price;
			}
			else
			{
				printf("ɾ����Ʒʧ��!\n");
			}
		}
		printf("�㻹�����ɾ����Ʒ��\n");
		printf("1--�ǣ� 0--��\n");
		scanf("%d", &choice);
	}
	printf("�˳�ɾ����Ʒ\n");
	return income;
}

//��Ʒͳ��
int sortgoods()
{
	struct goods *head = NULL;
	head = (struct goods*)malloc(sizeof(struct goods));
	head = readFile();
	int a = 0; //���������ܺ�  
	double b = 0; //���۽���ܺ�  
	int c = 0;  //��Ʒ�����ܺ�
	double d = 0;  //��������ܺ� 
	struct goods *p = NULL;
	for (p = head; p; p = p->next)
	{
		a += p->sale_number;
		b += p->price*p->sale_number;
		c++;
		d += p->cost*p->stay_number;
	}
	printf("ͳ�����ݺ��֪��\n");       //ͳ���Ժ󽫽���������û� 
	printf("1������%d����Ʒ\n", c);
	printf("2����Ʒ�Ľ�������ܺ�Ϊ��%g\n", d);
	printf("3����Ʒ�����������ܺ�Ϊ��%d\n", a);
	printf("4����Ʒ�����۽���ܺ�Ϊ��%g\n", b);
	return 0;
}



	
