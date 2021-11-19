#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mirror(int n);

//  112 ������, �������� �����
//  ������ - ����� ������ N �����, � ������� ������ ����
//  �������� ���������� ������ �������
int main(void) {
	char filename[120];
	int N, i, k = 0;
	FILE* file;

	printf("Enter file path:\n");				//  ����� ��� �����
	scanf("%s", filename);

	if (!(file = fopen(filename, "r"))) {		//  ��������� ����
		printf("Failed to open the file\n");	//  ���� �� ������� �������, ������� ���������
		return 1;
	}
	
	if (fscanf(file, "%d", &N) != 1) {			//  ������ N � �����
		printf("Incorrect data\n");
		return 1;
	}

	printf("The first %d numbers, the first two bytes of which are mirrored:\n", N);
	for (i = 0; i < N; i++) {					//  ������� ������� �����
		if (!mirror(i)) {
			printf("%d ", i);
			k++;
			if (k % 10 == 0) printf("\n");		//  ������ ������ ����� ������ 10 �����
		}
	}

	return 0;
}

//  112 ������, �������� �����
//  ������� ���������, �������� �� ������ ���� �����
//  ���������� ������ �������, ������� 0, ���� ��, 1 - ���� ���
int mirror(int n) {
	int kbit = 8;		// �-�� ��� � �����
	int bit1, bit2;		// ����
	int i;

	for (i = 0; i < kbit; i++) {
		//  ���� i-� ��� ������� �����
		bit1 = 1;
		bit1 <<= i;
		bit1 &= n;
		bit1 >>= i;

		//  ���� i-� ��� ������� ����� �����
		bit2 = 1;
		bit2 <<= (i + kbit);
		bit2 &= n;
		bit2 >>= (i + kbit);

		//  ���� ��� �����, �.�. �� ��������� ���������� 1 
		if (bit1 == bit2) return 1;
	}
	return 0;
}