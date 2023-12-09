#include "IntArray.h"


void test_intArray_p1()
{
    intArray testvar;
    int pos, temp;
        
    testvar.printArrayContent();
    
    for(pos=0; pos<intArray::MAX_SIZE; pos++)
        testvar.insertItem(100+pos, pos);
    
    testvar.printArrayContent();
    
    cout << "  check response to attempt to access 'out of bounds' items " << endl;
    pos = intArray::MAX_SIZE + 5;
    if( !testvar.insertItem(10, pos) )
       cout << "  insetion not allowd;" << endl;

    pos = -1;
    if( !testvar.insertItem(20, pos) )
       cout << "  insetion not allowd;" << endl;     
           
    cout << "  check response to attempt to overwrite items " << endl;
    for(pos=0; pos<intArray::MAX_SIZE; pos++)
        if(testvar.insertItem(500+pos, pos))
           cout << "  item overwritten " << endl;
        else
           cout << "  item NOT overwritten " << endl;
    
    testvar.printArrayContent();
}


void test_intArray_p2()
{
    intArray testvar;
    int pos, temp;
    
    cout << "  tot valid items " << testvar.getTotValidItems() << endl;
    testvar.printArrayContent();
    
    for(pos=0; pos<intArray::MAX_SIZE; pos++)
        testvar.insertItem(100+pos, pos);
    
    cout << "  tot valid items " << testvar.getTotValidItems() << endl;
    testvar.printArrayContent();
    
    cout << "  check response to attempt to access 'out of bounds' items " << endl;
    pos = intArray::MAX_SIZE + 5;
    testvar.getItem(pos);
    pos = -1;
    testvar.getItem(pos);
    
    cout << "  removing half of the items " << endl;
    for(pos=0; pos<intArray::MAX_SIZE/2; pos++)
        testvar.removeItemVal(pos, temp);
        
    cout << "  tot valid items " << testvar.getTotValidItems() << endl;
    testvar.printArrayContent();
    

    cout << "  resetting the otehr half of the items " << endl;
    for(pos=intArray::MAX_SIZE/2; pos<intArray::MAX_SIZE; pos++)
        testvar.resetItem(pos);
        
    cout << "  tot valid items " << testvar.getTotValidItems() << endl;
    testvar.printArrayContent();
}


void test_intArray_p3()
{
    intArray testvar;
    int pos, temp;
    
    cout << "  tot valid items " << testvar.getTotValidItems() << endl;
    testvar.printArrayContent();
    
    for(int pos=0; pos<intArray::MAX_SIZE; pos++)
    {
        temp=rand()%100;
        testvar.insertItem(temp, pos);
     }
    
    cout << "  tot valid items " << testvar.getTotValidItems() << endl;
    testvar.printArrayContent();
    
    cout << "  sorting array ascendingly" << endl;
    testvar.sortArray();
    testvar.printArrayContent();
    
    cout << "  sorting array descendingly" << endl;
    testvar.sortArray(false);
    testvar.printArrayContent();
}


int main(int argc, char *argv[])
{

    //test_intArray_p1();
    //test_intArray_p2();
    test_intArray_p3();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
