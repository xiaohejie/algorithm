#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	电话号码的字母组合：
		给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
		给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
class Solution {
public:
    //使用回溯法求解
    void backtrack(vector<string>& res, string digits, string ans, int index, unordered_map<char, string> phoneMap) {
        //中止条件:如果下标index等于号码长度
        if (index == digits.size()) {
            res.push_back(ans);
        }
        else {
            //记录当前号码
            char digit = digits[index];
            //从哈希表中找出对应的字符串
            const string str = phoneMap.at(digit);
            //遍历该字符串
            for (auto& ch : str) {
                ans.push_back(ch);
                backtrack(res, digits, ans, index + 1, phoneMap);
                ans.pop_back();
            }
        }
    }
	vector<string> letterCombinations(string digits) {
        vector<string>res;
        if (digits.empty()) {
            return res;
        }
        unordered_map<char, string> phoneMap{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string ans;     //子值
        backtrack(res,digits,ans,0,phoneMap);
        return res;

    //    vector<string> combinations;
    //    if (digits.empty()) {
    //        return combinations;
    //    }
    //    unordered_map<char, string> phoneMap{
    //        {'2', "abc"},
    //        {'3', "def"},
    //        {'4', "ghi"},
    //        {'5', "jkl"},
    //        {'6', "mno"},
    //        {'7', "pqrs"},
    //        {'8', "tuv"},
    //        {'9', "wxyz"}
    //    };
    //    string combination;
    //    backtrack(combinations, phoneMap, digits, 0, combination);
    //    return combinations;
    //}

    //void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
    //    /*
    //        combinations：结果数组
    //        phoneMap:数字对应哈希表
    //        digits：电话号码
    //        index：当前电话号码下标
    //        combination：
    //    */
    //    if (index == digits.length()) {
    //        //如果当前电话号码下标等于电话号码长度，则把当前字符串尾插近答案数组
    //        combinations.push_back(combination);
    //    }
    //    else {
    //        char digit = digits[index];
    //        const string& letters = phoneMap.at(digit);
    //        for (const char& letter : letters) {
    //            combination.push_back(letter);
    //            backtrack(combinations, phoneMap, digits, index + 1, combination);
    //            combination.pop_back();
    //        }
    //    }
	}
};