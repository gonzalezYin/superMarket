//���˵�
int main_menu()
{
	int choice;
	printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               ��ӭ����������Ϣ����ϵͳ                *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*             �����������������Ӧ����ţ�            *\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                1. ��������Ա                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                2. ��ͨ����Ա                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                0. �˳���ǰ����                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("���������ѡ��");
	scanf("%d", &choice);
	return choice;
}

int staffmemu()  //����Ա��Ϣ����Ŀ¼
{
	int a = 0;       //����һ��������¼�����ڹ���Ա��Ϣ�����ϵľ���
	printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               ��ӭ��������Ա����ϵͳ                  *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  1����ӹ���Ա                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  2��ɾ������Ա                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  3���޸Ĺ���Ա                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  4��չʾ����Ա                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("���������ѡ��\n");
	scanf("%d", &a);
	return a;
}

//�������ϵͳ�˵�����
int financememu()
{
	int a = 0;
	printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               ��ӭ�����������ϵͳ                    *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  1����������                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  2������֧��                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  3������ӯ��                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  0���˳�                              *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("���������ѡ��\n");
	scanf("%d", &a);
	return a;
}

//ѡ��չʾ
int goodsmemu()
{
	int a = 0;
	printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               ��ӭ������Ʒ����ϵͳ                    *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  1�������Ʒ                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  2��ɾ����Ʒ                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  3���޸���Ʒ                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  4��ͳ����Ʒ                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  5��չʾ������Ʒ                      *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  6��������Ʒ                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  0���˳�                              *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("���������ѡ��\n");
	scanf("%d", &a);
	return a;
}