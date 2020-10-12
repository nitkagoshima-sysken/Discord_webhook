#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void sort(int *a, unsigned int start, unsigned int end);

int main(void)
{
	unsigned int size = 10;
	int a[size];
	
	srand((unsigned)time(NULL));
	for(int i  =0; i < size; i++)
	{
		a[i] = rand();
		printf("%d : %d\n", i, a[i]);
	}
	
	sort(a, 0, size - 1);
	
	for(int i = 0; i < size; i++)
	{
		printf("%d : %d\n", i, a[i]);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *a, unsigned int start, unsigned int end)
{
	int pivot = a[start];
	int idx_start = start;
	int idx_end = end;
	int line;
	
	while(idx_start < idx_end)
	{
		// ¶‚©‚çpivotˆÈã‚Ì®”‚ð’T‚·
		while(idx_start < idx_end)
		{
			line = idx_start;
			if(pivot <= a[idx_start])
			{
				break;
			}
			idx_start++;
		}
		
		// ‰E‚©‚çpivot–¢–ž‚Ì®”‚ð’T‚·
		while(idx_start < idx_end)
		{
			if(pivot > a[idx_end])
			{
				break;
			}
			idx_end--;
		}
		
		if(idx_start < idx_end)
		{
			swap(&a[idx_start], &a[idx_end]);
		}
	}
	
	if(start < line)
	{
		sort(a, start, line);
	}
	
	if(line + 1 < end)
	{
		sort(a, line + 1, end);
	}
}