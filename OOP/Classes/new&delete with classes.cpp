// pass pointers as the class private members

#include<bits/stdc++.h>
using namespace std;

class CRectangle
{
    int *height, *width;
public:
    CRectangle(int, int);  // constructor
    ~CRectangle();  // destructor
    int area()
    {
        return (*width * *height);
    }
};

CRectangle::CRectangle(int a, int b)
{
/*
    width = &a;
    height = &b;
*/             //OR

    width = new int;
    height = new int;
    *width = a;
    *height = b;

}

CRectangle::~CRectangle()
{
    delete width;
    delete height;
}

int main()
{
    CRectangle rect(3, 4), rectb(5, 6);
    cout << "Rect. area = " << rect.area() << endl;  //12
    cout << "Rectb. area = " << rectb.area() << endl;  // 30
}

// What happens if we initialized the pointer using 'new' and do not delete the memory pointed to by the pointer using the delete operator?
/*
This leads to the `memory leak`.
When you dynamically allocate memory using new, the memory is allocated on the heap and remains allocated until it is explicitly deallocated using the delete operator. If you do not deallocate the memory using delete, the memory will remain allocated and will not be released back to the heap. This can cause the program to run out of memory if many objects are created and dynamically allocated memory is not released.
It's important to note that each call to new should be matched with a corresponding call to delete, otherwise memory leaks can occur. If you dynamically allocate memory using new, you should always make sure to deallocate the memory using delete when it is no longer needed.
In C++, you can also use smart pointers like std::unique_ptr and std::shared_ptr to manage dynamic memory allocation and deallocation. Smart pointers provide automatic memory management by automatically deallocating memory when the object goes out of scope or is no longer needed. Using smart pointers can help avoid memory leaks and make your code more robust.
*/