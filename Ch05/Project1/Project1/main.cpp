/* 유클리드 호제법에 의해 최대공약수를 구합니다. */
#include <stdio.h> 
#pragma warning(disable:4996)

int pos[8];
int flag_a[8];
int flag_b[15];
int flag_c[15];

void print() {
	int i = 0;
	for (i = 0; i < 8; i++)
		printf("%2d", pos[i]);

	printf("\n");
}

void set(int i) {
	int j;
	for (j = 0; j < 8; j++) {
		if (!flag_a[j]) {
			pos[i] = j;

			if (i == 7)
				print();
			else {
				flag_a[j] = 1;
				set(i + 1);
				flag_a[j] = 0;
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < 8; i++)
		flag_a[i] = 0;

	for (int i = 0; i < 15; i++)
		flag_b[i] = flag_c[i]=0;
	set(0);

	return 0;
}