/******************************************************************************
 *
 * File Name: assg5.c
 *
 * Description:  File contains all functions based on the assignment 5 in Standard Diploma
 * each Task has its own Functionality and description individually
 * and the user which functionality he wants to use
 *
 *
 * Author: Yahia Hamimi
 ******************************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "assg5.h"

struct complex
{
	float real;
	float img;
} num1, num2, sum;
typedef struct
{
	int hours;
	int minutes;
	float seconds;
} TIME;
TIME t1, t2, time_diff;
typedef struct
{
	char name[30];
	int id;
	float grade;

} Student;

enum fan_level
{
	Level1,
	Level2,
	Level3
};
/**
 * @name Task3
 *
 * @details This function takes two complex numbers from the user and returns the sum of the two numbers
 *
 * @param n1 The first complex number
 * @param n2 The second complex number
 *
 * @return The sum of n1 and n2
 */
struct complex task3(struct complex n1, struct complex n2)
{
	struct complex temp;
	temp.real = n1.real + n2.real;
	temp.img = n1.img + n2.img;
	return (temp);
}

/**
 * @name Task4
 *
 * @details This function takes two time structures from the user and returns the difference between the two times
 *
 * @param tim1 The first time structure
 * @param tim2 The second time structure
 *
 * @return The difference between tim1 and tim2
 */
TIME task4(TIME tim1, TIME tim2)
{
	TIME diff;
	diff.hours = tim2.hours - tim1.hours;
	diff.minutes = tim2.minutes - tim1.minutes;
	diff.seconds = tim2.seconds - tim1.seconds;
	if (tim2.minutes < tim1.minutes)
	{
		diff.minutes = 60 - (tim1.minutes - tim2.minutes);
		diff.hours--;
	}
	if (tim2.seconds < tim1.seconds)
	{
		diff.seconds = 60 - (tim1.seconds - tim2.seconds);
		diff.minutes--;
	}
	return (diff);
}

/**
 * @name Task5_fill
 *
 * @details This function takes a pointer to a student structure and the size of the array and fills it with the information of the student
 *
 * @param stu_ptr A pointer to the student structure which is the first element of the array
 * @param size The size of the array
 *
 * @return None
 */
void task5_fill(Student *stu_ptr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Please Enter Name, Id and Grade for student number %d :", i + 1);
		// take inputs from user
		scanf("%s %d %f", stu_ptr->name, &(stu_ptr->id), &(stu_ptr->grade));
		printf("\n");
		stu_ptr++; // increment the pointer to get the next structure in the array
	}
}
/**
 * @name task5_printinfo
 *
 * @details This function takes a pointer to a student structure and the size of the array and prints the information of the student
 *
 * @param stu_ptr A pointer to the student structure which is the first element of the array
 * @param size The size of the array
 *
 * @return None
 */
void task5_printinfo(Student *stu_ptr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Student Number %d Information : \n", i + 1);
		printf("Name : %s \n", stu_ptr->name);
		printf("Id : %d \n", stu_ptr->id);
		printf("Grade : %f \n", stu_ptr->grade);
		stu_ptr++;
	}
}

/**
 * @brief This is the main function of the program
 *
 * @details It takes user input to select which task to operate and then operates on the selected task
 *
 * @return 0 if the program is executed successfully
 */
int main(void)
{
	/* set the stdout and stderr to be unbuffered to solve printf and scanf problems */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int task;
	printf("Enter the specific task to operate:\n");
	scanf("%d", &task);
	/* switch case to operate on the selected task */
	switch (task)
	{
	case 1:
	{
		struct student_collection
		{
			char name[20];
			int roll;
			float marks;
		} st1;
		printf("enter name information\n");
		getchar();
		gets(st1.name);
		printf("enter roll information\n");
		scanf("%d", &(st1.roll));
		printf("enter marks information\n");
		scanf("%f", &(st1.marks));
		printf("the student name is: ");
		puts(st1.name);
		printf("the student roll is: %d\n", st1.roll);
		printf("the student mark is: %f\n", st1.marks);
		;

		break;
	}
	case 2:
	{
		struct Distance
		{
			int feet;
			float inch;
		} dis1, dis2, sum;
		printf("Enter the first distance information\n");
		printf("Enter the distance by feet: ");
		scanf("%d", &dis1.feet);
		printf("Enter the distance by inch: ");
		scanf("%f", &dis1.inch);
		printf("Enter the second distance information\n");
		printf("Enter the distance by feet: ");
		scanf("%d", &dis2.feet);
		printf("Enter the distance by inch: ");
		scanf("%f", &dis2.inch);
		sum.feet = dis1.feet + dis2.feet;
		sum.inch = dis1.inch + dis2.inch;
		// If inch is greater than 12, changing it to feet.
		if (sum.inch > 12.0)
		{
			sum.inch = sum.inch - 12.0;
			sum.feet++;
		}
		printf("\nSum of distances = %d f,%.1f in", sum.feet, sum.inch);
		return 0;
		break;
	}
	case 3:
	{
		printf("Enter the first number:\n");
		printf("Enter the real part of the number:");
		scanf("%f", &num1.real);
		printf("Enter the imaginary part of the number:");
		scanf("%f", &num1.img);
		printf("Enter the second number:\n");
		printf("Enter the real part of the number:");
		scanf("%f", &num2.real);
		printf("Enter the imaginary part of the number:");
		scanf("%f", &num2.img);
		sum = task3(num1, num2);
		printf("Sum = %.1f + %.1fi", sum.real, sum.img);
		break;
	}
	case 4:
	{
		printf("Enter the two times and ensure that second time two is greater than or equal to first time\n");
		printf("Enter the first time respectively in form hh:mm:ss:\n");
		scanf("%d %d %f", &t1.hours, &t1.minutes, &t1.seconds);
		printf("Enter the second time respectively in form hh:mm:ss:\n");
		scanf("%d %d %f", &t2.hours, &t2.minutes, &t2.seconds);
		time_diff = task4(t1, t2);
		printf("the gap between the two times interval is %d:%d:%.1f", time_diff.hours, time_diff.minutes, time_diff.seconds);
		break;
	}
	case 5:
	{
		Student stud[Student_Size];
		// take care that array of structurae name is the first structure address
		task5_fill(stud, Student_Size);
		task5_printinfo(stud, Student_Size);
		break;
	}
	case 6:
	{
		union family_name
		{
			char first_name[30];
			char last_name[30];
		} person;

		strcpy(person.first_name, "Yahia Hamimi");
		printf("Last Name : %s \n", person.last_name);
		printf("Size of Union (family_name) is the size of its biggest element which equal to: %d \n", sizeof(union family_name));
		break;
	}
	case 7:
	{
		enum fan_level fan1 = Level1;
		printf("Level1 = %d\n", fan1);
		fan1 = Level2;
		printf("Level2 = %d\n", fan1);
		break;
	}
	default:
		printf("You have entered an invalid task number\n");
	}
}
