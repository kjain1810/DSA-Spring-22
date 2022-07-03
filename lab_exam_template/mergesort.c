typedef int ElementType;

// Function used to compare two elements
// Should return 1 if the first argument is smaller or equal to the second
// Should return 0 if the second argument is smaller
// Change the type of arguments as requried
int comp(ElementType a, ElementType b)
{
	if (a <= b)
		return 1;
	else
		return 0;
}

// Recursive function to perform merge sort
// Does both division and merging in this function itself
// arr is our array to sort
// s is the starting index of this break (inclusive)
// e is the ending index of this break (inclusive)
// Call with merge_sort(arr, 0, size(arr)-1)
void merge_sort(ElementType *arr, int s, int e)
{
	if (s == e)
		return;
	int m = (s + e) / 2;
	merge_sort(arr, s, m);
	merge_sort(arr, m + 1, e);
	ElementType brr[e - s + 1];
	int i = s;
	int j = m + 1;
	int p = 0;
	while (i <= m && j <= e)
	{
		if (comp(arr[i], arr[j]))
			brr[p++] = arr[i++];
		else
			brr[p++] = arr[j++];
	}
	while (i <= m)
		brr[p++] = arr[i++];
	while (j <= e)
		brr[p++] = arr[j++];
	for (int k = s; k <= e; ++k)
		arr[k] = brr[k - s];
}
