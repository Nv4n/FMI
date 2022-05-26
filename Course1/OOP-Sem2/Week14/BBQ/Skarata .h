//
// Created by Sybatron on 5/26/2022.
//

#ifndef RESTAURANT_SKARATA_H
#define RESTAURANT_SKARATA_H
#include "Order.h"
#include "Queue.h"

class Skarata{
private:
    Queue<Order> orders;
public:
    void placeOrder(const Order& order){
        orders.push(order);
    };
    const Queue<Order>& getOrderQueue() const{
        return orders;
    }
    Order sendNextOrder(){
        Order ord= orders.front();
        orders.pop();
        return ord;
    };
};
#endif //RESTAURANT_SKARATA_H
