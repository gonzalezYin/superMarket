//
// 2020.7.20

#ifndef SUPERMARKET_STAFF_SYSTEM_H
#define SUPERMARKET_STAFF_SYSTEM_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structural_morphology.h"

//չʾ����Ա����Ϣ
int Disply_staff(struct node *head);

//ɾ��ָ������Ա����Ϣ
void delete_staff();

//�޸�ָ������Ա����Ϣ
void change_staff();

//���ӹ���Ա
void add_staff();

//�򿪹���Ա��Ϣ�ļ�
struct staff *readFile_staff();

//�������Ա��Ϣ
void storage_staff(struct staff* head);

//�����������
void change_password();

#endif //SUPERMARKET_STAFF_SYSTEM_H
