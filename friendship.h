#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define SIZE 20

class Relations { // ����� ������
public:
    struct Friend { // ��������� ����
        Friend();
        Friend(std::string name, int id) : name_(name), id_(id) {};
        Friend& operator=(const Friend& name);
        Friend(const Friend& name);
        std::string name_;
        int id_;
    };
    Relations();
    
    void addFriend(std::string name); // ���������� �����
    void delFriend(std::string name); // �������� �����
    void addFriendship(std::string name_1, std::string name_2); // ��������� ������ ����� ������
    void delFriendship(std::string name_1, std::string name_2); // �������� ������ ����� ������
    void threeHandShakes(); // ��� �����������
    
    bool friendOrNot(const std::string& name_1, const std::string& name_2); // ������� ������
    bool friendOr(const int name_1, const int name_2);
    Friend* attendName(const std::string& name); // ������� ��������
    std::vector<Friend> friendList; // ��������� ������
    int matrixFriend[SIZE][SIZE]; // ������� ������
};