/********************************************************************
  G. Allen Johnson - 18 September, 2014
  CS 11, Section 0656, D. Harden
  FILE:  myString.h
  Assignment 2
  CLASS PROVIDED:  myString
  DESCRIPTION:  This class is designed to make working with sequences
                of characters a little more convenient and less
                error-prone than handling raw char *s, (although it
                will be implemented as a char* behind the scenes).
                The myString class will handle constructing strings,
                reading/printing, accessing characters, and some
                simple operators such as concatenation. In addition,
                the myString object will have the ability to make a
                full deep-copy of itself when copied.  All of the
                expected operators are provided, including stream
                extraction, stream insertion and relational operators.

  myString();
  post: A myString object with a char pointer set to an empty string, "",
        is created.

  myString(const char *inString);
  pre:  inString is assigned a value.
  post: A myString object holding the value of inString is created.

  myString(const myString& copyString);
  pre:  copyString is assigned a value.
  post: A copy of the myString object passed to the function parameter
        is created.

  ~myString();
  pre:  Dynamic memory has been allocated.
  post: Dynamic memory is deleted once execution of the code exits the
        scope of the function.

  int length() const;
  pre:  aString has been initialized with a string.
  post: An int value is returned equal to the number of chars held in
        the variable, aString, less the NULL character, '\0'.

  void read(std::istream& in, char delimiter);
  pre:  A myString object has been declared.  An input stream has been
        declared and opened.  The char delimiter has been assigned a
        value.
  post: A line of char is read into the aString variable, from in stream,
        delimited by the char variable - delimiter.

  char& operator [] (int index);
  pre:  A myString object has been declared and index has been
        assigned a value.
  post: The char at position: index is accessed.  NOTE:  The value at
        position: index can be changed using this function.

  char operator [] (int index) const;
  pre:  A myString object has been declared and index has been
        assigned a value.
  post: The char at position: index is accessed.

  myString operator = (const myString& rightString);
  pre:  rightString is assigned a value
  post: The calling object gets the value of rightString.

  myString operator += (const myString& second);
  pre:  Concatenation operator + is defined.  second is assigned a
        value.
  post: Calling object has second appended to it.

  friend myString operator + (const myString &first,
                              const myString &second);
  pre:  first and second are assigned values.
  post: A string is returned which is the concatenation of first and
        second.

  friend bool operator < (const myString &first,
                          const myString &second);
  pre:  first and second are assigned values.
  post: A boolean value is returned indicating the result of the
        comparison between string and char using lexicographic
        ordering.

  friend bool operator > (const myString &first,
                          const myString &second);
  pre:  first and second are assigned values.
  post: A boolean value is returned indicating the result of the
        comparison between string and char using lexicographic
        ordering.

  friend bool operator <= (const myString &first,
                           const myString &second);
  pre:  first and second are assigned values.
  post: A boolean value is returned indicating the result of the
        comparison between string and char using lexicographic
        ordering.

  friend bool operator >= (const myString &first,
                           const myString &second);
  pre:  first and second are assigned values.
  post: A boolean value is returned indicating the result of the
        comparison between string and char using lexicographic
        ordering.

  friend bool operator == (const myString &first,
                           const myString &second);
  pre:  first and second are assigned values.
  post: A boolean value is returned indicating the result of the
        comparison between string and char using lexicographic
        ordering.

  friend bool operator != (const myString &first,
                           const myString &second);
  pre:  first and second are assigned values.
  post: A boolean value is returned indicating the result of the
        comparison between string and char using lexicographic
        ordering.

  friend std::ostream& operator << (std::ostream& out,
                                    const myString& printOut);
  pre:  printOut is assigned a value.
  post: The value of printOut is pushed to the out stream.

  friend std::istream& operator >> (std::istream& in,
                                    myString& readMe);
  pre:  In stream is open and not in a fail state.  readMe has been
        assigned a value.
  post: A string value is read into the readMe, which allocates just
        enough space for that string. The readMe myString object is
        then pushed to the in stream, which is returned.

  Dynamic Memory usge by the myString class:
        If there is insufficient dynamic memory, the following
        functions throw bad_alloc:  the constructors, operator +=,
        operator +, the assignment operator, read, the relational
        comparison operators:  >, >=, <, <=, ==, and !=, and the
        extraction operator >>.

********************************************************************/

#ifndef gajohnsonCS11_myString_h
#define gajohnsonCS11_myString_h
#include <iostream>


namespace gajohnsonCS11{
    class myString{
    public:

        myString();                                                             // Default Constructor
        myString(const char *inString);                                         // Parameterized Constructor
        myString(const myString& copyString);                                   // Copy Constructor
        ~myString();                                                            // Destructor
        int length() const;
        void read(std::istream& in, char delimiter);
        char& operator [] (int index);
        char operator [] (int index) const;
        myString operator = (const myString& rightString);
        myString operator += (const myString& second);
        friend myString operator + (const myString &first,
                                    const myString &second);
        friend bool operator < (const myString &first,
                                const myString &second);
        friend bool operator > (const myString &first,
                                const myString &second);
        friend bool operator <= (const myString &first,
                                 const myString &second);
        friend bool operator >= (const myString &first,
                                 const myString &second);
        friend bool operator == (const myString &first,
                                 const myString &second);
        friend bool operator != (const myString &first,
                                 const myString &second);
        friend std::ostream& operator << (std::ostream& out,
                                          const myString& printOut);
        friend std::istream& operator >> (std::istream& in,
                                          myString& readMe);

    private:
        char *aString;
    };
}
#endif // gajohnsonCS11_myString_h
