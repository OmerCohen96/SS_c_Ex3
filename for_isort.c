# include <stdio.h>

int shift_element(int* arr, int i){

	while (i) {

		i--;
		*(arr+i+1)=*(arr+i);
		
	}

	return 0;
}


int insertion_sort (int* arr,int len){ 		

	int* p_arr = (arr+1); 						
	
	while (p_arr < (arr+len)) {

		if (*(p_arr-1) > *(p_arr))
		{
			int i = 1 , unsorted_element = *(p_arr);

			while ((p_arr-i-1) >= arr && *(p_arr-1-i) > unsorted_element)
			{
				i++;
			}
			
			shift_element((p_arr-i) , i);

			*(p_arr-i) = unsorted_element;

		}

		p_arr++;
		
	}

	return 0 ;
}

