#include <cstdlib>
#include <iostream>
#include "Circle.h"

using namespace std;

void testPart1Circle()
{
    cout << "test part1 print" << endl;
    const int tot_items = 20;
    Circle testobj_array[tot_items];
    for (int i = 0; i < tot_items; i++){
        cout << "Test item i=" << i << endl;
        cout << "Init shape and init coordinates:" << endl;
        // testobj_array[i].inputSideAndCoordFromKeyboard();
        testobj_array[i].inputRandomSide();
        testobj_array[i].inputRandomCoord();
        testobj_array[i].printShapeAndCoordInfo();
    }
}

void testPart2Circle()
{
    static const int TOT_ITEMS = 5;
    Circle in_array[TOT_ITEMS], out_array[TOT_ITEMS];
    int tot_matching_items;
    Circle target;
    int ruleindex = 4;
    target.inputCoord(0.0, 0.0);
    target.inputSide(10.0);

    fillCircleArray(in_array, TOT_ITEMS);

    tot_matching_items = findMatchingCircles(target, in_array, out_array, TOT_ITEMS, ruleindex);
    cout << "Target: " << endl;
    target.printShapeAndCoordInfo();

    cout << endl << "ALL " << tot_matching_items << " matching items:" << endl;
    printCircleArray(out_array, tot_matching_items);
}

int main(int argc, char *argv[])
{
    // testPart1Circle();
    testPart2Circle();
    return 0;
}
