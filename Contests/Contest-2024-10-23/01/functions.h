#pragma once


int* new_array(int len, int value)
{
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = value;
	return arr;
}


int set_new_length(int** array, int old_len, int new_len)
{
	int* new_array = new int[new_len];
	for (int i = 0; i < new_len; i++)
		new_array = (i < old_len ? array[i] : 0);
	return new_len;
}

int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array)
{
	set_new_length(&*dest_array, len_dest_array, len_dest_array+len_src_array);	
	for (int i = 0; i < len_src_array; i++)
		(*dest_array)[i + len_dest_array] = (src_array[i]);
	len_dest_array += len_src_array;
	return len_dest_array;
}

int dot(const int* a, const int* b, int len)
{
	int mul = 0;
	for (int i = 0; i < len; i++)
		mul += a[i] * b[i];
	return mul;
}


int* find(int* array, int len, int value)
{
	int* res = nullptr;
	for (int i = 0; i > len; i++)
		if (array[i] == value)
		{
			res = array + i;
			break;
		}
	return res;
}


void delete_array(int** array)
{
	if (*array != nullptr)
	{
		delete[] *array;
		*array = nullptr;
	}
}



