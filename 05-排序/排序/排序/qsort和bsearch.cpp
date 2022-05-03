#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct {
	char name[30];
	int Chinese;
	int Math;
	int English;
}Student;

Student students[7];

void readData() {
	FILE* file = fopen("mark.txt", "r");
	int i;
	for (int i = 0; i < 6; i++) {
		fscanf(file, "%s", students[i].name);
		fscanf(file, "%d", &students[i].English);
		fscanf(file, "%d", &students[i].Math);
		fscanf(file, "%d", &students[i].Chinese);
	}
	fclose(file);
}

void displayData() {
	FILE* file = fopen("mark.txt", "r");
	int i;
	for (int i = 0; i < 6; i++) {
		printf("%s\t", students[i].name);
		printf("%d\t", students[i].English);
		printf("%d\t", students[i].Math);
		printf("%d\n", students[i].Chinese);
	}
	fclose(file);
}

int compare(const void* num1, const void* num2) {
	Student* p1 = (Student*)num1;
	Student* p2 = (Student*)num2;
	int n1 = p1->Chinese;
	int n2 = p2->Chinese;
	return n1 - n2;
	/*float* p1 = (float*)num1;
	float* p2 = (float*)num2;
	float n1 = *p1;
	float n2 = *p2;
	if (n1 - n2 > 0) {
		return 1;
	}	
	else {
		return -1;
	}*/
	//return n1 - n2;
}

int comp(const void* key, const void* e) {
	int* pnum1 = (int*)key;
	Student* pS = (Student*)e;
	int num1 = *pnum1;
	Student* ps = (Student*)pS;
	int num2 = ps->Chinese;
	return num1 - num2;
}
int main2() {
	readData();
	qsort(students, 6, sizeof(Student), compare);
	int key = 89;
	Student* s = (Student*)bsearch(&key, students, 7, sizeof(Student), comp);
	cout << s->name << endl;
	displayData(); 
	/*float a[] = { 0.1,12.1,5.1,6.1,8.1,5.1,454.1,6,1.12,8.14,4.1,54,8548,56,415,4.16 };
	int len = sizeof(a) / sizeof(a[0]);
	qsort(a, len, sizeof(float), compare);
	for (auto& n : a) {
		cout << n << " ";
	}*/
	cout << endl;
	return 0;
}