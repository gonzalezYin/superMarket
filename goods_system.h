//
// 2020.7.20
//

#ifndef SUPERMARKET_GOODS_SYSTEM_H
#define SUPERMARKET_GOODS_SYSTEM_H
#include<stdio.h>
void saveToFile(struct goods *head, char name[]);

struct good *readFile();

int Disply(struct node *head);

//ѡ��չʾ
int goodsmemu();

//��Ʒ¼��
double addgoods();

//��Ʒ�޸�
int changegoods();

//������Ʒ
int findgoods();

//��Ʒɾ��
double delgoods();

//��Ʒͳ��
int sortgoods();



#endif //SUPERMARKET_GOODS_SYSTEM_H
