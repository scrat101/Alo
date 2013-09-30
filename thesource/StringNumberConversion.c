#include "../include/StringNumberConversion.h" 


/*int abs(int num) { 
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
*/

static int getnumofdigits(int num, int base) { 
	int res = 0; 
	int currentnum = num;
	while (currentnum >= 1) { 
		res++; 
		currentnum = currentnum/base; 
	}; 
	return res; 
}; 

static int findchar(char *thechars, char pattern) { 
	int length = 0; 
	for (int count = 0; thechars[count] != '\0'; count++) { 
		length++;
	}; 
	length++;
	for (int count = 0; count <= length; count++) { 
		if (thechars[count] == pattern) { 
			return count; 
		}; 
	}; 
	return -1; 
}; 	

static int pow(int num, int thepow) { 
	int res = 1; 
	for (int count = 0; count < thepow; count++) { 
		res = num * res;
	}; 
	return res;
};	


static char* getjustnumdigits(char* thechars, char* res) { 
	int countfororiginal = 0;
	int countforres = 0;
	while (thechars[countfororiginal]) { 
		if (((thechars[countfororiginal] >= '0') && (thechars[countfororiginal] <= '9'))  || ((thechars[countfororiginal] >= 'A') && (thechars[countfororiginal] <= 'Z')) || ((thechars[countfororiginal] >= 'a') && (thechars[countfororiginal] <= 'z'))) { 
			 res[countforres] = thechars[countfororiginal];
			 countforres++;
		}; 
		countfororiginal++;
	};
	if (countforres > 0) { 
		*((char*)(countforres + res + 1)) = '\0'; 
		return res;
	} 
	else { 
		return 0; 
	};	
}; 	

int atoi(char* thechars, int base) { 
	int res = 0; 
	int count = 0;
	int pos = ((int)(strlen((const char*)thechars))) - 1;
	char reference[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	char possiblechars[40];
	if (!getjustnumdigits(thechars, possiblechars)) { 
		panic("String to number conversion failed!");
	};	
	while (pos >= 0) { 
		res = res + (findchar(reference, thechars[pos]) * pow(base, count));
		pos--;
		count++;
	};
	return res;
};		

char* itoa(int num, int base, char* chars) {
	if ((base < 2) || (base > 36)) { 
		return 0;
	};
	char* pos = chars; 
	int numberofdigits = getnumofdigits(num, base); 
	int currentnum = num; 
	int currentdigit = 1;
	int toadvanceby = (int)(chars + (numberofdigits - 1));
	char possiblechars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";   
	if (base > 10) { 
		*pos = '0'; 
		*(pos + 1) = 'x';
		pos = pos + 2;
		toadvanceby = toadvanceby + 2; 
	}; 
	if ((num < 0) && (base == 10)) { 
		*pos = '-';
		currentnum = -currentnum; 
		toadvanceby++; 
	};
	pos = (char*)toadvanceby;
	while (currentdigit <= numberofdigits) { 
		int oldnum = currentnum;
		currentnum = currentnum/base; 
		*pos = *(possiblechars + (oldnum - (currentnum*base))); 
		pos--; 
		currentdigit++; 
	}; 
	*((char*)(toadvanceby + 1)) = '\0';
	return chars;
};