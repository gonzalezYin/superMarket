//
// 2020.7.20
//

#ifndef SUPERMARKET_STRUCTURAL_MORPHOLOGY_H
#define SUPERMARKET_STRUCTURAL_MORPHOLOGY_H
//��Ʒ����
typedef struct goods
{
	int number;  //��Ʒ���
	char name[10];//��Ʒ����
	double cost; //��Ʒ�Ľ���
	double price;//��Ʒ���ۼ�
	int sale_number;//��Ʒ����������
	int stay_number;//��Ʒ���
	struct goods* next;
}goods;

//������
typedef struct staff
{
	char id[11];  //�˺�
	char passward[7];  //����
	char name[16];//Ա������
	int number;//ְλ���
	int salary;//����
	struct staff* next;
}staff;

#endif //SUPERMARKET_STRUCTURAL_MORPHOLOGY_H
