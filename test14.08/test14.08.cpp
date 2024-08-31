#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include<stack>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> rooms) {
        int m = rooms.size(), kolvo = 0;
        queue<int> que;
        que.push(0);

        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            for (int i = 0; i < rooms[cur].size(); i++) {
                int key = rooms[cur][i];
                if (key < m && !rooms[key].empty()) {
                    que.push(key);
                }
            }
            rooms[cur].clear();
            kolvo++;
        }
        return m == kolvo;
    }
};

class Person
{
public:
    Person(int data) :data(data) {}
    ~Person(){}
     int getData()const {
        return data;
    }
private:
    int data;
};

int main()
{
    /*vector<Person> vec = {
        Person(5),
        Person(6)
    };*/

    /*vec.front().getData();
    Solution s;
    cout << s.strStr("sadboy", "sad");

    auto f = [](int a) {
        cout << a;
    };*/
   /* auto res = find_if(vec.begin(), vec.end(), [](const Person& po){
        int a = po.getData();
        return a == 7;
        });

    if (res == vec.end()) {
        cout << "-";
    }
    else {
        cout << "+";
    }*/

    /*string s = "    Oleg    Rracs BO ";
    int i = 1;
    s.erase(remove_if(s.begin(), s.end(), [&i](const string& s) {
        s[i - 1] == s[i] == ' ';

        i++;
        }), s.end());

    cout << s;*/

    /*Solution s;
    cout << s.containsNearbyDuplicate({ 1,0,1,1}, 1);

    vector<int> vec;
    list<int> list;
    list.*/

    Solution s;
    int a = 4;
    cout<< ((4 > 5) ?0: 1);
    return 0;
}
