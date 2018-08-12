//
//  array.cpp
//  array
//
//  Created by Jonathan Goh on 11/2/17.
//  Copyright © 2017 Jonathan Goh. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);

int main()
{
    string h[7] = { "selina", "reed", "diana", "tony", "", "logan", "peter" };
    assert(lookup(h, 7, "logan") == 5);
    assert(lookup(h, 7, "diana") == 2);
    assert(lookup(h, 2, "diana") == -1);
    assert(positionOfMax(h, 7) == 3);
    
    string g[4] = { "selina", "reed", "peter", "sue" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "selina?" && g[3] == "sue?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "peter?" && g[3] == "reed?");
    
    string e[4] = { "diana", "tony", "", "logan" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "reed", "reed", "reed", "tony", "tony" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "peter", "diana", "steve" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "steve" && f[2] == "peter");
    assert(split(h, 7, "peter") == 3);
    
    string people[5] = { "clark", "peter", "diana", "tony", "selina" };
    assert(appendToAll(people, 5, "!!!") == 5);  // returns 5
    
    string hero[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
    assert(positionOfMax(hero, 6) == 3);   // returns 3, since  tony  is latest
    
    string super[5] = { "logan", "clark", "peter", "sue", "reed" };
    assert(rotateLeft(super, 5, 1) == 1);  // returns 1
    
    string list[9] = {"tony", "bruce", "steve", "steve", "diana", "diana", "diana", "steve", "steve"};
    assert(countRuns(list, 9) == 5);  //  returns 5
    
    string folks[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
    assert(flip(folks, 4) == 4);  // returns 4
    
    string jonny[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
    string group[5] = { "bruce", "steve", "clark", "", "tony" };
    assert(differ(jonny, 6, group, 5) == 2);  //  returns 2
    assert(differ(jonny, 2, group, 1) == 1);  //  returns 1
    
    string names[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
    string names1[10] = { "reed", "sue", "selina" };
    assert(subsequence(names, 6, names1, 3) == 1);  // returns 1
    string names2[10] = { "logan", "selina" };
    assert(subsequence(names, 5, names2, 2) == -1);  // returns -1
    
    string set[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
    string set1[10] = { "clark", "bruce", "selina", "reed" };
    assert(lookupAny(names, 6, set1, 4) == 1);  // returns 1 (a1 has "reed" there)
    string set2[10] = { "tony", "diana" };
    assert(lookupAny(names, 6, set2, 2) == -1);  // returns -1 (a1 has none)
    
    string hero1[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
    assert(split(hero, 6, "logan") == 3);  //  returns 3
    string hero2[4] = { "reed", "sue", "peter", "steve" };
    assert(split(hero2, 4, "steve") == 2);  //  returns 2
    
    cout << "All tests succeeded" << endl;
}

int appendToAll(string a[], int n, string value)
{
    if (n>=0) // check that n is not negative
    {
        for (int i=0; i<n; i++) // for every value in the array run the loop
        {
            a[i] += value; // add specified value to end of element
        }
        return n;
    }
    else
        return -1;
}
/*Append value to the end of each of the n elements of the array and return n. [Of course, in this and other functions, if n is negative, the paragraph above that starts "Notwithstanding" trumps this by requiring that the function return −1. Also, in the description of this function and the others, when we say "the array", we mean the n elements that the function is aware of.] For example:
string people[5] = { "clark", "peter", "diana", "tony", "selina" };
int j = appendToAll(people, 5, "!!!");  // returns 5
// now people[0] is "clark!!!", people[1] is "peter!!!", ...,
// and people[4] is "selina!!!"
 */


int lookup(const string a[], int n, string target)
{
    int equal=0;
    
    if (n>=0) // check that n is not negative
    {
        for (int i=0; i<n; i++)
        {
            if (a[i]==target) // if this element equals the specified target value
            {
                equal = i; // set i equal to the return value
            }
        }
        if (equal==0) // if there is no value for equals, then there was no target value located within the string
            return -1;
        else
            return equal; // returns position of target
    }
    else
        return -1;
}

/*Return the position of a string in the array that is equal to target; if there is more than one such string, return the smallest position number of such a matching string. Return −1 if there is no such string. As noted above, case matters: Do not consider "SUe" to be equal to "sUE".
 */

int positionOfMax(const string a[], int n)
{
    int max=0;
    
    if(n>0)
    {
        while (n > 0)
        {
            n--; // decrements n so that all values of the array are checked
            if (a[n] >= a[max]) // finds whether current element is larger than past element
                max = n; // sets value of max to most current position of largest number
        }
        return max;
    }
    else
        return -1;
}

/*Return the position of a string in the array such that that string is >= every string in the array. If there is more than one such string, return the smallest position in the array of such a string. Return −1 if the array has no elements. For example:
string hero[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
int k = positionOfMax(hero, 6);   // returns 3, since  tony  is latest
// in alphabetic order
 */



int rotateLeft(string a[], int n, int pos)
{
    string deleted = "";
    if(n>=0 && pos>=0 && pos<n)
    {
        deleted = a[pos]; // sets the point of rotation (pos) to deleted
        for(int i=0; i<(n-pos-1); i++)
        {
            a[pos+i]=a[pos+i+1]; // for all elements right of the deleted pos, move one left
        }
        a[n-1]=deleted; // sets last element of array to the deleted value
    }
    else
        return -1;
    return pos;
}
/*Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array. Return the original position of the item that was moved to the end. Here's an example:
string super[5] = { "logan", "clark", "peter", "sue", "reed" };
int m = rotateLeft(super, 5, 1);  // returns 1
// super now contains:  "logan", "peter", "sue", "reed", "clark"
*/


int countRuns(const string a[], int n)
{
    int counter=0;
    int numReset=1;
    if(n>=0)
    {
        for (int i=1; i<n; i++)
        {
            if (a[i]==a[i-1]) // checks for consecutive elements
                counter++;
            else
            {
                numReset++; // if not conseutive, then reset counter and increment number of times reset
                counter=0;
            }
                
        }
        return numReset; // returns how many times the consecutive element counter was reset
    }
    else
        return -1;
    return 0;
}
/*Return the number of sequences of one or more consecutive identical items in a.
string d[9] = {
    "tony", "bruce", "steve", "steve", "diana", "diana", "diana", "steve", "steve"
};
int p = countRuns(d, 9);  //  returns 5
//  The five sequences of consecutive identical items are
//    "tony"
//    "bruce"
//    "steve", "steve"
//    "diana", "diana", "diana"
//    "steve", "steve"
*/



int flip(string a[], int n)
{
    int starting = 0;
    int ending = n;
    string copy;
    
    if (n>=0)
    {
        while (ending > starting)
        {
            ending--;
            
            copy = a[starting]; // stores value of start
            a[starting] = a[ending]; // swaps start value with end value
            a[ending] = copy; // puts stored value at end
            
            starting++;
        }
        return n;
    }
    else
        return -1;
    
}
/*Reverse the order of the elements of the array and return n. For example,
string folks[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
int q = flip(folks, 4);  // returns 4
// folks now contains:  "tony"  ""  "steve"  "bruce"  "sue"  "clark"
*/



int differ(const string a1[], int n1, const string a2[], int n2)
{
    int lesser=0;
    int notEqual=-1;
    
    if(n1>=0 && n2>=0)
    {
        if (n1<=n2)
            lesser=n1; // if/else sets value for smallest
        else
            lesser=n2;
            
        for (int i=0; i<lesser; i++) // checks arrays up until the smallest n value
        {
            if (a1[i]!=a2[i]) // checks for first instance that the 2 arrays have diffeerent element values
            {
                notEqual=i;
                return notEqual; // returns position of elements that are not equal
            }
        }
        return lesser; // if all values are equal, then return the samllest n value
    }
    else
        return -1;
}
/*Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other. For example,
string folks[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
string group[5] = { "bruce", "steve", "clark", "", "tony" };
int r = differ(folks, 6, group, 5);  //  returns 2
int s = differ(folks, 2, group, 1);  //  returns 1
*/




int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if (n1<0 || n2<0 || n2>n1)
        return -1;
    else if (n2 == 0)
        return 0;
    
    for (int i=0; i<=(n1-n2); i++)
    {
        if (a1[i] == a2[0]) // if element of a1 equals the start of a2, then start for loop
        {
            for (int k=0; k<n2; k++)
            {
                if (a1[i+k]!=a2[k]) // check if not all of a2 is in a1
                    break;
                else if (k==(n2-1)) // if all of a2 is in a1, then return the value of the start of subsequence
                    return i;
            }
        }
    }
    return -1;
}

/*If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence. (Consider a sequence of 0 elements to be a subsequence of any sequence, even one with no elements, starting at position 0.) For example,
string names[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
string names1[10] = { "reed", "sue", "selina" };
int t = subsequence(names, 6, names1, 3);  // returns 1
string names2[10] = { "logan", "selina" };
int u = subsequence(names, 5, names2, 2);  // returns -1
*/


int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if(n1>=0 && n2>=0)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++) // checks all of a2 to see if value of a1 is located in the array
                if (a1[i] == a2[j])
                {
                    return i; // if value of a1 is located in a2, then return the position of first instance
                }
        }
        return -1;
    }
    else
        return -1;
}


/*Return the smallest position in a1 of an element that is equal to any of the elements in a2. Return −1 if no element of a1 is equal to any element of a2. For example,
string names[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
string set1[10] = { "clark", "bruce", "selina", "reed" };
int v = lookupAny(names, 6, set1, 4);  // returns 1 (a1 has "reed" there)
string set2[10] = { "tony", "diana" };
int w = lookupAny(names, 6, set2, 2);  // returns -1 (a1 has none)
*/



int split(string a[], int n, string splitter)
{
    if (n < 0)
        return -1;
    else if (n == 0)
        return 0;
    
    string temporary;
    int starting = 0;
    int ending = n - 1;
    
    while (starting < ending) // checks all values of array
    {
        if (a[starting] < splitter)
            starting++; // keeps value there and increments
        if (a[ending] > splitter)
            ending--; // keeps value there and decrements
        if (starting < ending)
        {
            temporary = a[starting]; // copies value into temporary strings
            a[starting] = a[ending];
            a[ending] = temporary;
        }
    }
    
    for (int i=0; i<n; i++)
        if (a[i] >= splitter) // checks for first element greater than or equal splitter
            return i; //
    
    return n; // if no value grater than or qual, returns n
}
    
/*Rearrange the elements of the array so that all the elements whose value is < splitter come before all the other elements, and all the elements whose value is > splitter come after all the other elements. Return the position of the first element that, after the rearrangement, is not < splitter, or n if there are no such elements. For example,
string hero[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
int x = split(hero, 6, "logan");  //  returns 3
// hero must now be
//      "clark"  "diana"  "bruce"  "peter"  "tony"  "reed"
// or   "diana"  "bruce"  "clark"  "reed"  "peter"  "tony"
// or one of several other orderings.
// All elements < "logan" (i.e., "diana", "bruce", and "clark")
//   come before all others
// All elements > "logan" (i.e., "tony", "peter", and "reed")
//   come after all others
string hero2[4] = { "reed", "sue", "peter", "steve" };
int y = split(hero2, 4, "steve");  //  returns 2
// hero2 must now be either
//      "reed"  "peter"  "steve"  "sue"
// or   "peter"  "reed"  "steve"  "sue"
// All elements < "steve" (i.e., "peter" and "reed") come
// before all others.
// All elements > "steve" (i.e., "sue") come after all others.
 */
