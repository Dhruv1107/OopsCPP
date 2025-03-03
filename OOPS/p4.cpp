/*
It is about Rule of big 3 and Rule of big 2

Rule of big 3: If we write any one of our own constructor, destructor or copy constructor, then we need to write the 
other two implementations as well.
This is because of shallow copy, if we have a pointer as a class member then we need to allocate deallocate and create a custom copy constructor.

Law of the Big Two: If we have some datatype such as vector or smart pointers, then we don't need destructor.
Since here vector deallocates itself when the object is destroyed.
*/