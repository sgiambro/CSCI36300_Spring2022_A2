//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_Queue_H_
#define _CS507_Queue_H_

#include <exception>

// COMMENT You should use aggregation instead of inheritance since logically a
// queue is not an array. Because you are using inheritence, you are force to hide
// methods that do not make sense to this class.
//
// SOLUTION: Switched to aggregation

/**
 * @class Queue
 *
 * Basic Queue for abitrary elements.
 */
template <typename T>
class Queue : public Array <T>
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the Queue is empty.
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
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & q);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * @brief adds the element to the end of the list;
   * 
   * @param element 
   */
  void enqueue (T element);

  /**
   * @brief removes the element at the front of the list.If there are not 
   * elements in the Queue, this method throws empty_exception, similar to 
   * the Queue;
   * 
   * @exception      empty_exception    The Queue is empty
   */
  T dequeue (void);

  /**
   * Test if the Queue is empty
   *
   * @retval         true          The Queue is empty
   * @retval         false         The Queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the Queue.
   *
   * @return         Size of the Queue.
   */
  size_t size (void) const;

  /// Remove all elements from the Queue.
  void clear (void);

private:
  // add member variable here

  // Array object for aggregation
  Array* array_;

  /// Where the last element of the Queue is 
  size_t last_;


};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_Queue_H_
