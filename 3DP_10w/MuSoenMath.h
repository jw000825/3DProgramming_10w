#pragma once			// �ߺ� ���� ���� ����
#include <iostream>		// c++ ������� ���� �������
using namespace std;	// c++�� ���� ���� ��ƾ�� �����ϴ� std�� �˷��� ���ӽ����̽��� ��� �ĺ��ڵ��� ���� �ڵ� ������ ���

class vec3 {		// vec3 Ŭ���� �����
public:
	float v[3][1] = { {1}, {1}, {1} };			// Vector���� �迭�� ���� (x, y, z)
	float v_col = sizeof(v[0]) / sizeof(float);	// �຤�Ͱ��� ũ��
	float v_row = sizeof(v) / sizeof(v[0]);		// �����Ͱ��� ũ��
	float p[3][3] = { 0 };						// ���� ����� �����
private:
};

class mat3 {		// mat3 Ŭ���� �����, TSR���� �� ������ ����
public:
	float Tr[3][3] = { 
					   {1, 0, 3},		// 3*3 Translate ���� �� ������ ����
					   {0, 1, 5},
					   {0, 0, 1}
					 };
	float Sc[3][3] = { 
					   {2, 0, 0},		// 3*3 Scale ���� �� ������ ����
					   {0, 2, 0},
					   {0, 0, 1} 
					 };
	float Pi = 3.14;					// ������ ����
	float cos30 = 0.15;					// cos 30�� ����
	float sin30 = 0.5;					// sin 30�� ����

	float Rt[3][3] = { 
					   { cos30, -sin30, 0 },	// 3*3 Rotate ���� �� ������ ����
					   { sin30,  cos30, 0 },
					   {     0,      0, 1 } 
					 };
private:
};

void header() 
{
	float a[3][3] = { 0 };				// ���� ��İ� �����͸� �����ϱ� ���� 3*3 ���
	float b[3][3] = { 0 };				// ���� ��İ� �����͸� �����ϱ� ���� 3*3 ���

	mat3 Translate, Rotate, Scale;		// mat3 ���� TSR�� �������� ���� ����
	vec3 Vector, P;						// vec3 ���� Vector, P�� �������� ���� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				a[i][j] += Scale.Sc[i][k] * Translate.Tr[k][j];
				// Scale ��� *  Translate ��� = ��� a ����
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				b[i][j] += Rotate.Rt[i][k] * a[k][j];
				// Rotate ��� * ���� ��� a(Sc * Tr) = ��� b ����
			}
		}
	}

	for (int i = 0; i < Vector.v_row; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < Vector.v_col; k++) {
				P.p[i][j] += Vector.v[i][k] * b[k][j];
				// Vector ��� * ���� ��� b(Tr * Sc * Rt) = vec3 p ��� ����
			}
		}
	}

	printf("vec3 p�� ���� ");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << P.p[i][j];
			if (j < 2) {
				cout << " ";
			}
		}
	}
}
