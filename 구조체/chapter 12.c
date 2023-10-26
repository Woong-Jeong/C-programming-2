/*

//구조체 선언 & 사용
#include<stdio.h>

struct human {									//구조체 정의
	char name[10];
	int age;
	float power;
};										//구조체 정의 마지막에 ; 꼭 붙이기

int main()
{
	struct human woong, tague;							// human구조체 변수 h1 선언
		
	strcpy(woong.name, "정웅");
	//	strcpy_s(woong.name, 10, "정웅");    // scanf_s와 비슷하며 크기를 제한해줌                  ---------------> 시험
	//woong.name = "정웅";				 //배열은 크기와 포인터 주소값 바꿀 수 없음 -> 그래서 strcpy() 함수를 써서 복사,변경해야함

	woong.age = 24;
	woong.power = 5.5;

	strcpy(tague.name, "허태규");
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



//구조체 변수선언 & 동시에 초기화

#include<stdio.h>

struct human {
	char name[10];
	int age;
	float power;
};

int main()
{
	struct human woong = { "정 웅", 24 , 5.5 }, tague = { "허태규", 23, },
				 jinsu = { NULL };		//구조체 선언과 동시에 초기화  -------> 앞에 구조체 선언한 순서대로 값 대입
										//선언을 비워두면 기본값이 들어감
										//선언할때 중간값만 선언하고 싶으면 woong = {"",24,};      ----> 이런식으로 선언
	printf("woong:%s, %d, %.1f\n", woong.name, woong.age, woong.power);
	printf("tague:%s, %d, %.1f\n", tague.name, tague.age, tague.power);
	printf("jinsu:%s, %d, %.1f\n", jinsu.name, jinsu.age, jinsu.power);

	return 0;
}



// 구조체 활용(사용자정의 자료형)

#define _CRT_SECURE_NO_WARNNINGS
#include<stdio.h>

typedef struct Human {
	char name[10];
	int age;
	float power;
}human;

int main()
{
	human woong, tague;															//typedef로 만든 구조체 변수선언
	printf("이름, 나이, 힘을 순서대로 입력: ");
	scanf("%s %d %.1f", woong.name, &woong.age, &woong.power);				//배열을 scanf_s에 사용할거면 배열의 크기도 써줘야함

	tague = woong;																//woong값을 tague로 대입, 구조체의 직접비교는 허용 x( tague == woong 는 x)
																				// 그러나 구조체 구성원끼리는 비교가능(woong.name == tague.age)

	printf("이름:%s ,나이:%d, 힘:%.1f", woong.name, woong.age, woong.power);
	printf("이름:%s ,나이:%d, 힘:%.1f", tague.name, tague.age, tague.power);

	return 0; 
}


// 멤버 구조체(구조체 안에 구조체)
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
		printf("woong이름 , 태어난 년도, 월,날짜 입력: ");
		scanf("%s %d %d %d", woong.name, &woong.bt.year, &woong.bt.mon, &woong.bt.day);
		printf("tague이름 , 태어난 년도, 월,날짜 입력: ");
		scanf("%s %d %d %d", tague.name, &tague.bt.year, &tague.bt.mon, &tague.bt.day);

		if (woong.bt.year < tague.bt.year) jud = 1;
		else if (woong.bt.year > tague.bt.year) jud = 2;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon < tague.bt.mon) jud = 1;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon > tague.bt.mon) jud = 2;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon == tague.bt.mon && woong.bt.day < tague.bt.day) jud = 1;
		else if (woong.bt.year == tague.bt.year && woong.bt.mon == tague.bt.mon && woong.bt.day > tague.bt.day) jud = 2;


		if (jud == 1) printf("%s 형님\n", woong.name);
		else if (jud == 2) printf("%s 형님\n", tague.name);
		else printf("둘은 친구\n");

		return 0;
	}
	
}


//구조체 배열

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


//구조체 배열값 바꾸기

#include<stdio.h>

typedef struct Human				//Human 구조체를 human변수로 사용
{
	char name[10];
	int age;
	float power;
}human;

int main()
{
	human ho[3] = { {"woong", 24, 5.5}, {"tague",23,5.5},{"jinsu",23,5.5} };

	human temp;									//내용물 바꾸기 위한 그릇 구조체 만듬
	int k;

	temp = ho[0];								//woong 과 jinsu를 바꾸는 과정
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
	
	for (k = 0; k < MAX; k++)											//bubble sort 정렬 알아두기!
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