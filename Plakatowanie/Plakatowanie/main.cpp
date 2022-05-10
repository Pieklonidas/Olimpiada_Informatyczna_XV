#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <vector>

struct Node
{
    int value;
    Node* next = NULL;
    Node* previous = NULL;
};

struct Buildings
{
    int number;
    int height;
};

bool comp(Buildings b1, Buildings b2)
{
    if(b1.height > b2.height)
    {
        return true;
    }
    else if (b1.height == b2.height)
    {
        return b1.number < b2.number;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<Node> nodes(n);
    std::vector<Buildings> buildings(n);
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int dlugosc;
        int wysokosc;
        std::cin >> dlugosc >> wysokosc;
        buildings[i].number = i;
        buildings[i].height = wysokosc;
        if (i == 0)
        {
            nodes[i].next = &nodes[i+1];
            nodes[i].value = wysokosc;
        }
        else if(i == n-1)
        {
            nodes[i].previous = &nodes[i-1];
            nodes[i].value = wysokosc;
        }
        else
        {
            nodes[i].next = &nodes[i+1];
            nodes[i].previous = &nodes[i-1];
            nodes[i].value = wysokosc;
        }
    }

    std::sort(buildings.begin(), buildings.end(), comp);
    for (int i = 0; i < n; ++i)
    {
        int num = buildings[i].number;
        if(nodes[num].next && nodes[num].value != nodes[num].next->value)
        {
            ans++;
        }
        if(!nodes[num].next)
        {
            ans++;
        }
        if(nodes[num].next)
        {
            nodes[num].next->previous = nodes[num].previous;
        }
        if (nodes[num].previous)
        {
            nodes[num].previous->next = nodes[num].next;
        }
    }

    std::cout << ans << "\n";

    return 0;
}
