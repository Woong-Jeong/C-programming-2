/*

//����ü ���� & ���
#include<stdio.h>

struct human {									//����ü ����
	char name[10];
	int age;
	float power;
};										//����ü ���� �������� ; �� ���̱�

int main()
{
	struct human woong, tague;							// human����ü ���� h1 ����
		
	strcpy(woong.name, "����");
	//	strcpy_s(woong.name, 10, "����");    // scanf_s�� ����ϸ� ũ�⸦ ��������                  ---------------> ����
	//woong.name = "����";				 //�迭�� ũ��� ������ �ּҰ� �ٲ� �� ���� -> �׷��� strcpy() �Լ��� �Ἥ ����,�����ؾ���

	woong.age = 24;
	woong.power = 5.5;

	strcpy(tague.name, "���±�");
	tague.age = 23;
	tague.power = 5.5;

	printf("woong name = %s\n", woong.name);
	printf("woong age = %d\n", woong.age);
	printf("woong power = %f\n\n", woong.power);

	printf("tague name = %s\n", tague.name);
	printf("tague age = %d\n", tague.age);
	printf("tague power = %f\n", tague.power);

	return 0;	

}



//����ü �������� & ���ÿ� �ʱ�ȭ

#include<stdio.h>

struct human {
	char name[10];
	int age;
	float power;
};

int main()
{
	struct human woong = { "�� ��", 24 , 5.5 }, tague = { "���±�", 23, },
				 jinsu = { NULL };		//����ü ����� ���ÿ� �ʱ�ȭ  -------> �տ� ����ü ������ ������� �� ����
										//������ ����θ� �⺻���� ��
										//�����Ҷ� �߰����� �����ϰ� ������ woong = {"",24,};      ----> �̷������� ����
	printf("woong:%s, %d, %.1f\n", woong.name, woong.age, woong.power);
	printf("tague:%s, %d, %.1f\n", tague.name, tague.age, tague.power);
	printf("jinsu:%s, %d, %.1f\n", jinsu.name, jinsu.age, jinsu.power);

	return 0;
}



// ����ü Ȱ��(��������� �ڷ���)

#define _CRT_SECURE_NO_WARNNINGS
#include<stdio.h>

typedef struct Human {
	char name[10];
	int age;
	float power;
}human;

int main()
{
	human woong, tague;															//typedef�� ���� ����ü ��������
	printf("�̸�, ����, ���� ������� �Է�: ");
	scanf("%s %d %.1f", woong.name, &woong.age, &woong.power);				//�迭�� scanf_s�� ����ҰŸ� �迭�� ũ�⵵ �������

	tague = woong;																//woong���� tague�� ����, ����ü�� �����񱳴� ��� x( tague == woong �� x)
																				// �׷��� ����ü ������������ �񱳰���(woong.name == tague.age)

	printf("�̸�:%s ,����:%d, ��:%.1f", woong.name, woong.age, woong.power);
	printf("�̸�:%s ,����:%d, ��:%.1f", tague.name, tague.age, tague.power);

	return 0; 
}


// ��� ����ü(����ü �ȿ� ����ü)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct date 
{
	int year, mon, day;
};

struct human 
{
	char name[10];
	struct date bt;
};

int main()
{
	struct human woong, tague;
	int jud;

	while (1)
	{
		printf("woong�̸� , �¾ �⵵, ��,��¥ �Է�: ");
		scanf("%s %d %d %d", woong.name, &woong.bt.year, &woong.bt.mon, &woong.bt.day);
		printf("tague�̸� , �¾ �⵵, ��,��¥ �Է�: ");
		scanf("%s %d %d %d", tague.name, &tague.bt.year, &tague.bt.mon, &tague.bt.day);

		if (woong.bt.year < tague.bt.year) jud = 1;
		else if (woong.bt.year > tague.bt.year) jud = 2;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon < tague.bt.mon) jud = 1;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon > tague.bt.mon) jud = 2;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon == tague.bt.mon && woong.bt.day < tague.bt.day) jud = 1;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon == tague.bt.mon && woong.bt.day > tague.bt.day) jud = 2;


		if (jud == 1) printf("%s ����\n", woong.name);
		else if (jud == 2) printf("%s ����\n", tague.name);
		else printf("���� ģ��\n");

		return 0;
	}
	
}


//����ü �迭

#include<stdio.h>

struct human
{
	char name[10];
	int age;
	float power;
};

int main()
{
	struct human ho[3] = { {"woong", 24, 5.5}, {"tague",23,5.5},{"jinsu",23,5.5} };

	int k;

	for (k = 0; k < 3; k++)
		printf("%d:%s %d %.1f \n", k, ho[k].name, ho[k].age, ho[k].power);

	return 0;

}


//����ü �迭�� �ٲٱ�

#include<stdio.h>

typedef struct Human				//Human ����ü�� human������ ���
{
	char name[10];
	int age;
	float power;
}human;

int main()
{
	human ho[3] = { {"woong", 24, 5.5}, {"tague",23,5.5},{"jinsu",23,5.5} };

	human temp;									//���빰 �ٲٱ� ���� �׸� ����ü ����
	int k;

	temp = ho[0];								//woong �� jinsu�� �ٲٴ� ����
	ho[0] = ho[2];
	ho[2] = temp;

	for (k = 0; k < 3; k++)
		printf("%d:%s %d %.1f \n", k, ho[k].name, ho[k].age, ho[k].power);

	return 0;

}
*/

#include<stdio.h>

#define MAX 4

typedef struct HUMAN
{
	char name[10];
	int age;
	float power;
}human;

int main()
{
	human ho[MAX] = { {"woong",24,5.5},{"tague",23,5.5},{"jinsu",25,6.5},{"jaeyoung", 22, 2.2} },temp;

	int j, k;
	
	for (k = 0; k < MAX; k++)											//bubble sort ���� �˾Ƶα�!
	{
		for (j = 0; j < MAX; j++)
		{
			if (ho[j - 1].age > ho[j].age)
			{
				temp = ho[j - 1];
				ho[j - 1] = ho[j];
				ho[j] = temp;
			}
		}
	}
	for (k = 0; k < MAX; k++)
		printf("%d: %s %d %.1f", k, ho[k].name, ho[k].age, ho[k].power);

	return 0;
}