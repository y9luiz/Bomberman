#include <memory>

#include <iostream>
template <class T>
/**
 * @brief this class is a circular list that's point to a custom data type
 * 
 */
class CircularList
{
    // foward declaration
    class Node;
    
    public:
        /**
         * @brief Construct a new Circular List object
         * this also initialize the list head with  nullptr
         * 
         */
        CircularList() : size_(0)
        {
                head_ = nullptr;
        }
        /**
         * create a CircularList with a head with a custom type data 
         * @param data is a template parameter
        **/
        CircularList(T data) : head_(new Node(data)), size_(1)
        {
                // set the first element equals to the next element
                head_->setNext(head_);
        }
        ~CircularList()
        {
                Node ** it = &(head_);
                Node * aux;
                while(size_>0)
                {
                        aux = (*it);
                        head_ = (*it)->getNext();
                        delete aux;   
                        it = &head_;
                        size_--;
                }

        }

        /**
         * @brief 
         *  push a data to the end of the list
         * @param data 
         *  Template parameter
         */
        void push_back(T data)
        {
                size_++;
                if(head_ == nullptr)
                {
                        head_ = new Node(data);
                        head_->setNext(head_);
                        return;
                }
                Node *  end_ptr = end();
                Node * n = new Node(data);
                end_ptr->setNext(n);
                end_ptr = end_ptr->getNext();
                end_ptr->setNext(head_);


        }
        /**
         * @brief 
         *      Get the address of the last element of the list
         * @return std::shared_ptr<Node> 
         */
        
        Node* end()
        {
                Node* it = nullptr;

                if(head_!=nullptr && head_->getNext()!=nullptr)
                {
                        it = head_;
                        while(it->getNext() != head_)
                        {
                                it = it->getNext();
                        }
                }
                else if(head_->getNext()==nullptr)
                {
                        it = head_;
                }
                return it;
        }
       
        void remove(Node *& n)
        {
               Node *ptr = searchNode(n,head_);
               n = nullptr;
               delete ptr;   
               size_--;
        }
        Node * head_;

    private:
        
        Node * searchNode(Node * n, Node * start_node)
        {
                Node* it = nullptr;
                if(start_node!=nullptr)
                {
                        it = start_node;
                        while(it->getNext() != start_node && it->getNext()!=nullptr)
                        {
                                it = it->getNext();
                        }

                }
                return it;
        }
        /**
         * @brief 
         * This class implement a list Node
         * 
         */
        class Node
        {
                public:
                        /**
                         * @brief Construct a new Node object is deleted to don't allow empty declarations 
                         * 
                         */
                        Node() = delete;
                        /**
                         * @brief Construct a new Node object
                         * 
                         * @param data 
                         */
                        Node(T data)
                        {
                                data_ = data;
                                next_ = nullptr;
                        }
                        /**
                         * @brief Set the Next object
                         * 
                         * @param n 
                         */
                        inline void setNext(Node *n)
                        {
                                next_ = n;
                        }
                        /**
                         * @brief Get the Next object
                         * 
                         * @return std::shared_ptr<Node> 
                         */
                        inline  Node*& getNext()
                        {
                                return next_;
                        }
                private:   
                        /**
                         * @brief data value of the node
                         * 
                         */
                        T data_;
                        /**
                         * @brief pointer to the next element
                         * 
                         */
                        Node * next_;
        };
        size_t size_;

};
