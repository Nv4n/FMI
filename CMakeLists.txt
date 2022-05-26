cmake_minimum_required(VERSION 3.22)
project(Restaurant)
project(Ticket)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course1/OOP-Sem2/Week14)

add_executable(Restaurant
        Course1/OOP-Sem2/Week14/BBQ/main.cpp
        Course1/OOP-Sem2/Week14/BBQ/Queue.inl
        Course1/OOP-Sem2/Week14/BBQ/Queue.h
        Course1/OOP-Sem2/Week14/BBQ/Order.h
        )

add_executable(Ticket
        Course1/OOP-Sem2/Week14/TicketSystem/main.cpp
        Course1/OOP-Sem2/Week14/TicketSystem/Ticket.h
        Course1/OOP-Sem2/Week14/TicketSystem/StudentTicket.h
        Course1/OOP-Sem2/Week14/TicketSystem/RegularTicket.h
        Course1/OOP-Sem2/Week14/TicketSystem/GroupTicket.h
        )