// leetcode.com/problems/top-k-frequent-words/

#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::map;
using std::pair;
using std::sort;
using std::string;
using std::vector;

class Compare
{
public:
    bool operator()(const pair<string, int> &lvalue, const pair<string, int> &rvalue)
    {
        return lvalue.second < rvalue.second || lvalue.second == rvalue.second && lvalue.first > rvalue.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> word_count;
        for (auto word : words)
        {
            word_count[word]++;
        }

        vector<pair<string, int>> tmp(word_count.size());
        int index = 0;
        for (pair<string, int> word : word_count)
        {
            tmp.push_back(word);
            index++;
        }

        sort(tmp.begin(), tmp.end(), [](const pair<string, int> &lvalue, const pair<string, int> &rvalue)
             { return lvalue.second > rvalue.second || lvalue.second == rvalue.second && lvalue.first < rvalue.first; });

        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(tmp[i].first);
        }

        return ans;
    }

    // vector<string> topKFrequent(vector<string> &words, int k)
    // {
    //     map<string, int> word_count;
    //     for (auto word : words)
    //     {
    //         word_count[word]++;
    //     }

    //     priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pri_que;
    //     for (pair<string, int> word : word_count)
    //     {
    //         pri_que.push(word);
    //     }

    //     vector<string> ans;
    //     for (int i = 0; i < k; i++)
    //     {
    //         pair<string, int> top = pri_que.top();
    //         pri_que.pop();
    //         ans.push_back(top.first);
    //     }
    //     return ans;
    // }
};

int main()
{
    // vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    // const int k = 2;

    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    const int k = 4;

    Solution solution;
    auto ans = solution.topKFrequent(words, k);
    for (auto word : ans)
    {
        std::cout << word << ' ';
    }
}
