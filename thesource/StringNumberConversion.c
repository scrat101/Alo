#include "../include/StringNumberConversion.h" 


int abs(int num) { 
	if (num < 0) { 
		return -num; 
	}; 
	return num; 
}; 	

char* integertochar(int num, char* str) { 
	char* pos = str; 
	int workwithnum = num;
	char thezero = '0'; 
	size_t len;
	if (num < 0) { 
		*pos = '-'; 
		pos++; 
		workwithnum = -workwithnum; 
	}; 
	while (true) { 
		if (workwithnum < 10) { 
			*pos = thezero + workwithnum; 
			pos++;
			break; 
		} 
		else { 
			int tocomparewith = workwithnum; 
			workwithnum = workwithnum/10; 
			*pos = thezero + (tocomparewith - (workwithnum * 10)); 
			pos++; 
		}; 
	}; 
	*pos = '\0';
	len = strlen(str); 
	for (int count = 0; str[count] != NULL; count++) { 
		char* otherpos = str[len - count];
		char save = (char)*otherpos; 
		str[len - count] = str[count]; 
		str[count] = save; 
	};  
	return str; 
}; 
