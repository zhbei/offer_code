#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class CharStatistics{
private:
	vector<int> record;
	int index;
public:
	CharStatistics():index(0){
		record = std::vector<int>(256,-1);
	}

	void insert(char ch){
		if(record[ch] == -1){
			record[ch] = index;
		}else if(record[ch] >= 0){
			record[ch] = -2;
		}
		++index;
	}
	char firstApperOnce(){
		int minIdx = 0x7fffffff;
		for(int i = 0; i < 256; ++i){
			if(record[i] >= 0 && record[i] < record[minIdx])
				minIdx = i;
		}
		return minIdx == 0x7fffffff ? '\0' : char(minIdx);
	}
};

// ====================测试代码====================
void Test(const char* testName, CharStatistics chars, char expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(chars.firstApperOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.insert('g');
    Test("Test2", chars, 'g');

    chars.insert('o');
    Test("Test3", chars, 'g');

    chars.insert('o');
    Test("Test4", chars, 'g');

    chars.insert('g');
    Test("Test5", chars, '\0');

    chars.insert('l');
    Test("Test6", chars, 'l');

    chars.insert('e');
    Test("Test7", chars, 'l');

    return 0;
}

