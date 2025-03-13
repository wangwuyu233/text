void _MergeSort(int* a, int left, int right,int* tmp)
{
    //������û��Ԫ��ʱ���ٺϲ�
	if (left >= right)
	{
		return;
	}
 
    //�������飬ÿ��һ��Ϊ��
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid,tmp);//����������
	_MergeSort(a, mid + 1, right,tmp);//����������
 
    //�ϲ���������
	int begin1 = left, end1 = mid;//��������1
	int begin2 = mid + 1, end2 = right;//��������2
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)//ע���������Ϊһ������Ϊ��ʱ��ֹͣ
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
 
    //�����в�����ͬʱΪ�գ���ʣ��Ԫ�غϲ�
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
 
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
 
    //���ϲ�������п�����ԭ������
    //����������ԭ���� ��֤���ص���һ��ݹ�������������е�Ԫ���������
	int j = 0;
	for (j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
}
 
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{
    assert(a);
    //��Ϊ��Ҫ�������������кϲ����������������
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}
 
	_MergeSort(a, 0, n - 1,tmp);
 
	free(tmp);
	tmp = NULL;
}
