//
// 2020.7.20
//

#ifndef SUPERMARKET_GOODS_SYSTEM_H
#define SUPERMARKET_GOODS_SYSTEM_H
#include<stdio.h>
#include"definition.h"
void save_to_file(struct goods *head, char name[]);

struct good *read_file();

int display(struct node *head);

int goods_memu();

double add_goods();

int change_goods();

int find_goods();

double del_goods();

int sort_goods();



#endif //SUPERMARKET_GOODS_SYSTEM_H
