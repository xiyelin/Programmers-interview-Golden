
//题目描述：空格替换 
//请编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串有足够的空间存放新增的 
//字符，并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。 
//给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。 

//方法一：

class Replacement 
{ 
public: 
	string replaceSpace(string iniString, int length) 
	{ 
		int numspace = 0; 
		int i = 0;

		//统计空格
		while (iniString[i]) 
		{ 
			if(' ' == iniString[i++]) 
				++numspace; 
		}

		//将源字符串的内容复制到新的字符数组中去 
		char* newarr = new char[numspace * 3 + length + 1]; 
		i = 0; 
						 
		while (iniString[i]) 
		{ 
			newarr[i] = iniString[i]; 
			++i; 
		} 
		newarr[i] = '\0';

		//先找到字符串中的空格，然后将字符串的最后一个字符到该空格的所有字符 
		//向后以后两个字节，最后用“ %20”替换空格； 
		//字符串中有几个空格就循环几次
		char* pSpace = newarr; 
		char* tail = newarr; 
		i = 0; 
								 
		while (*tail != '\0') 
			++tail; 
										 
		while (numspace--) 
		{ 
			while (*pSpace != ' ') 
				++pSpace; 

			while (tail != pSpace) 
			{ 
				*(tail + 2) = *tail; 
				++tail; 
				tail -= 2; 
			} 

			*tail++ = '%'; 
			*tail++ = '2'; 
			*tail = '0'; 																	
			
			while (*tail)
				++tail; 
																											
		} 							
		return (string)newarr; 
	} 
};

//写法二：
//利用string的“ +=”操作符重载函数

class Replacement 
{ 
public: 
	string replaceSpace(string iniString, int length) 
	{ 
		string retString = ""; 
		
		for (int i = 0; i < length; ++i) 
		{ 
			if (' ' != iniString[i]) 
			{ 
				retString += iniString[i]; 
			} 
			else 
				retString += "%20"; 
		}

		return retString; 
	} 
};


//方法三：
//利用push_back()函数将每一个字符一次压入到新的字符串中

class Replacement 
{ 
public: 
	string replaceSpace(string iniString, int length) 
	{ 
		string retString = ""; 
				 
		for (int i = 0; i < length; ++i) 
		{ 
			if (' ' != iniString[i]) 
			{ 
				retString.push_back(iniString[i]); 
			} 
			else 
			{ 
				retString.push_back('%'); 
				retString.push_back('2'); 
				retString.push_back('0'); 
			} 
		} 

		return retString;
	} 
};
