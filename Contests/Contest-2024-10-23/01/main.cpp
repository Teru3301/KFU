//
//
//
//
//	дичь какая то
//
//
//
//



#include <iostream>

int* new_array(int len, int value);
int set_new_length(int** array, int old_len, int new_len);
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array);
int dot(const int* a, const int* b, int len);
int* find(int* array, int len, int value);
void delete_array(int** array);

int main(){
    int len_first, len_second,
        first_init_val, second_init_val;
    std::cin >> len_first >> first_init_val >> len_second >> second_init_val;
    int* first  = new_array(len_first, first_init_val);
    int* second = new_array(len_second, second_init_val);
   
    int new_len_first;
    std::cin >> new_len_first;
    len_first = set_new_length(&first, len_first, new_len_first);
    for(int i=0; i < new_len_first; i++){
        int value;
        std::cin >> value;
        first[i] = value;
    }

    len_second = merge(&second, len_second, first, len_first);

    len_second = set_new_length(&second, len_second, len_first);

    int value = dot(first, second, len_first);

    int* value_ptr;
    while( (value_ptr = find(second, len_second, value)) != nullptr ){
        *value_ptr = 0;
    }

    for (int i=0; i < len_second; i++) std::cout << second[i] << ' ';

    delete_array(&first);
    delete_array(&first);  // Так и задумано
    delete_array(&second);
    delete_array(&second); // Так и задумано

	return 0;
}



//#include "functions.h"



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

