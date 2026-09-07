 #include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and profit of each item:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].profit;

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            double fraction = capacity / items[i].weight;

            totalProfit += items[i].profit * fraction;

            capacity = 0;
        }
    }

    cout << "Maximum profit = " << totalProfit << endl;

    return 0;
}