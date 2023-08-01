   // -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_Stack_H_
#define _CS507_Stack_H_

#include <exception>

// COMMENT You should use aggregation instead of inheritance since logically a
// stack is not an array. Because you are using inheritence, you are force to hide
// methods that do not make sense to this class.
//
// SOLUTION: Switched to aggregation

/**
 * @class Stack
 *
 * Basic Stack for abitrary elements.
 */
template <typename T>
class Stack
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the Stack is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception ()
      : std::exception () { }
  };

  /// Default constructor.
  Stack (void);

  /// Copy constructor.
  Stack (const Stack & s);

  /// Destructor.
  ~Stack (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Stack & operator = (const Stack & rhs);

  /**
   * Push a new \a element onto the Stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push (T element);

  /**
   * Remove the top-most element from the Stack.
   *
   * @exception      empty_exception    The Stack is empty.
   */
  void pop (void);

  /**
   * Get the top-most element on the Stack. If there are no element 
   * on the Stack, then the Stack_is_empty exception is thrown.
   *
   * @return         Element on top of the Stack.
   * @exception      empty_exception    The Stack is empty
   */
  T top (void) const;

  /**
   * Test if the Stack is empty
   *
   * @retval         true          The Stack is empty
   * @retval         false         The Stack is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the Stack.
   *
   * @return         Size of the Stack.
   */
  size_t size (void) const;

  /// Remove all elements from the Stack.
  void clear (void);

private:
  // add member variable here

  // Array object for aggregation
  Array* array_;

  // Where the top of the stack is 
  size_t sTop_;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif  // !defined _CS507_Stack_H_
