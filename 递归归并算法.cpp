void _MergeSort(int* a, int left, int right,int* tmp)
{
    //区间中没有元素时不再合并
	if (left >= right)
	{
		return;
	}
 
    //划分数组，每次一分为二
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid,tmp);//划分左区间
	_MergeSort(a, mid + 1, right,tmp);//划分右区间
 
    //合并有序序列
	int begin1 = left, end1 = mid;//有序序列1
	int begin2 = mid + 1, end2 = right;//有序序列2
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)//注意结束条件为一个序列为空时就停止
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
 
    //两序列不可能同时为空，将剩余元素合并
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
 
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
 
    //将合并后的序列拷贝到原数组中
    //在这里拷贝的原因是 保证返回到上一层递归后两个子序列中的元素是有序的
	int j = 0;
	for (j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
}
 
// 归并排序递归实现
void MergeSort(int* a, int n)
{
    assert(a);
    //因为需要将两个有序序列合并，需借助额外数组
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
