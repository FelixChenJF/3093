#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <cstdlib>
#include <iostream>

using namespace std;

class intArray{
public:
         static const int MAX_SIZE=20;
private:
         // holds the content 
         int arrayItemContent[MAX_SIZE];
         // indicates if the element is empty
         bool arrayItemEmpty[MAX_SIZE];
         // tot non-empty items
         int tot_items;
        
         void resetArray()
         {
            for(int pos=0; pos<MAX_SIZE; pos++)
               resetItem(pos);
         }
                
         void sortedAppend(int val)
         {
           if(tot_items<MAX_SIZE)
           {  
              int insertion_point;
              // scan the array to find the insertion point
              // i.e.: where a larger item (or an empty item) is found 
              for(insertion_point=0; insertion_point<MAX_SIZE; insertion_point++)
                 if( isItemEmpty(insertion_point) || (getItem(insertion_point)>=val) )
                    break;
              // shift to the right all elements past the insertion point   
              for(int pos = tot_items-1; pos>=insertion_point; pos--)
              {
                  resetItem(pos+1);
                  insertItem(getItem(pos), pos+1);
              } 
              // perfrom insertion
              resetItem(insertion_point);
              insertItem(val, insertion_point);
           }  
        }
public:
	// constructor; upon construction the array is empty.
   intArray()
   {
         // set all elements as empty 
         for(int i=0; i<MAX_SIZE; i++)
            arrayItemEmpty[i]=true;
         tot_items=0;
   } 
   //If position pos is a valid position and corresponding item is empty, return true; false otherwise; 
   bool isItemEmpty(int pos)
   {
         if(checkPos(pos))
            return arrayItemEmpty[pos];
         return false;
   }
   //Check that position pos is a valid position for this array; if so return true; false otherwise; 
   bool checkPos(int pos)
   {
         if(pos>=0 && pos<MAX_SIZE)
            return true;
         return false;
   }
    //Insert val in position pos if this is a valid position and 
    // if the corresponding item is empty, then return true; false otherwise; 
   bool insertItem(int val, int pos)
   {
         //cout << "attempt to insert item pos " << pos;
         if(isItemEmpty(pos))
         {
             //cout << "done" << endl;
             arrayItemContent[pos] = val;
             arrayItemEmpty[pos] = false;
             tot_items++;  // return tot_items;
             return true;
         }
         return false;
   }
   int getItem(int pos)
   {
         int val=0;
         if(checkPos(pos)){
            if(!isItemEmpty(pos) ){   
               return arrayItemContent[pos];
            }else{ 
               cout << " Item is empty!" << endl;
            }
         }else{
            cout << " Position not valid " << endl;
         }  
         return val;
   }
   //Pint to screen position and value of all �non-empty� elements in the array. 
   void printArrayContent()
   {
         for(int pos=0; pos<MAX_SIZE; pos++)
         {
            cout << " Item pos " << pos << " is: ";
            if(isItemEmpty(pos))
                  cout << "Empty;" << endl;
            else
                  cout << getItem(pos) << endl;
         }
   } 
   //The number of non-empty items in the array (inserted so far by the user); 
   int getTotValidItems() {return tot_items;}
   // If a non-empty item is found in position pos, its value is written to val, 
   // the item becomes empty and true is returned; false otherwise; 
   bool removeItemVal(int pos, int& val)
   {
         bool result;
         result = (checkPos(pos) && (!isItemEmpty(pos)));
         if(result)
         {
            val=getItem(pos);
            resetItem(pos);
         }
         return result;
   }
   // If position pos is a valid position for this array, reset the corresponding item (so that it becomes empty); 
   bool resetItem(int pos)
   { 
      bool result=false;   
      if(checkPos(pos))        
      {
         if(!isItemEmpty(pos))
         {
            arrayItemEmpty[pos]=true;
            tot_items--;
         }
         result=true;  
      }
      return result;
   }
   void sortArray(bool ascending=true)
      {
         // temp; initially empty 
         intArray tempArray;
         int temp_tot_items=tot_items;
         int insertion_point;
         if(tot_items > 0)
         {
            // sorted insertion (ascending) of 
            // eacn non-empty element into temp
            for(int pos=0; pos<MAX_SIZE; pos++)
               if(!isItemEmpty(pos))               
                  tempArray.sortedAppend(getItem(pos));
            // reset the current array;
            resetArray();
            // fill the array from temp
            for(int pos=0; pos<temp_tot_items; pos++)
            {
                  // copy items in the same order as temp ==> this array is ascendingly sorted;
                  // copy items in the opposite order as temp ==> this array is decendingly sorted;
                  if(ascending)
                     insertion_point=pos;
                  else
                     insertion_point=temp_tot_items - pos -1;
                  insertItem(tempArray.getItem(pos), insertion_point);
            }
         }
    }
};


#endif
