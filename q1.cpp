#include <iostream> 
#include <cstring>
using namespace std;

class CMyString{
public:
	CMyString(char * pData = NULL){
		m_pData = pData;
	}
	CMyString(const CMyString & str){
		*this = str;
	}
	~CMyString(){
		delete[]m_pData;
	}
	CMyString& operator=(const CMyString &str){
		if(&str == this){
			return *this;
		}
		delete []m_pData;

		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData,str.m_pData);
		return *this; 
	}
	// CMyString& operator=(const CMyString &str){
	// 	if(&str != this){
	// 		CMyString ts(str);

	// 		char *tp = ts.m_pData;

	// 		ts.m_pData = m_pData;
	// 		m_pData = tp;
	// 	}
	// 	return *this;
	// }
private:
	char* m_pData;
};

int main(){
	char * s = "asdf";
	CMyString str(s),str1,str2;
	str2 = str1 = str;
	str = str;
	return 0;
}