
//假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。
//请将这个算法编写成///一个函数，给定两个字符串s1和s2，请编写代码检
//查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
//给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中
//字符为英文字母和空格，区分大小写，字符串长度小于等于1000。

class ReverseEqual
{
public:
	bool checkReverseEqual(string s1, string s2)
	{
	        if(s1.size() != s2.size())
		    return false;

		string str = s1 + s1;
						 
       	        if (string::npos != str.find(s2))
	        {
		    return true;
	        }
	        else
		    return false;
	}
};


